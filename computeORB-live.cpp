#include <opencv2/opencv.hpp>
#include "fast/fast.hpp"
#include "orb.hpp"
#include "iostream"
#include <opencv2/highgui/highgui.hpp>

string first_file = "../1.png";
// string second_file = "../3.png";

int main(int argc, char **argv)
{

  // 载入图片
  cv::Mat first_image = cv::imread(first_file, 0); //使用灰度图
  cv::resize(first_image, first_image, cv::Size(first_image.cols, first_image.rows), 0, 0);

  std::cout << first_image.rows << "===" << first_image.cols << endl;

  // 检测关键点 threshold=40
  vector<cv::KeyPoint> keypoints;
  cv::FAST(first_image, keypoints, 40);
  cout << "keypoints: " << keypoints.size() << endl;

  uint totalElements = first_image.total() * first_image.channels(); // Note: image.total() == rows*cols.
  cv::Mat flat = first_image.reshape(1, totalElements);              // 1xN mat of 1 channel, O(1) operation
  if (!first_image.isContinuous())
  {
    flat = flat.clone(); // O(N),
  }
  // flat.data is your array pointer
  auto *arr = flat.data;

  vector<KeyPoint> corners;
  int num_corners;
  auto bytes_per_row = first_image.cols * sizeof(uchar);
  auto threshold = 40;

  corners = fast9_detect_nonmax(arr, first_image.cols, first_image.rows, bytes_per_row, threshold, &num_corners);
  cout << "corners: " << corners.size() << "--" << num_corners << endl;

  // 计算每个关键点的角度
  computeAngle(arr, first_image.cols, first_image.rows, bytes_per_row, corners);

  // 计算ORB描述子
  vector<DescType> descriptors;
  computeORBDesc(arr, first_image.cols, first_image.rows, bytes_per_row, corners, descriptors);

  for (int tmpi = 0; tmpi < keypoints.size(); tmpi++)
  {
    keypoints[tmpi].pt.x = corners[tmpi].x;
    keypoints[tmpi].pt.y = corners[tmpi].y;
    keypoints[tmpi].angle = corners[tmpi].angle;
  }

  // open the first webcam plugged in the computer
  cv::VideoCapture camera(0);
  if (!camera.isOpened())
  {
    std::cerr << "ERROR: Could not open camera" << std::endl;
    return 1;
  }

  // create a window to display the images from the webcam
  // cv::namedWindow("Webcam", cv::WindowFlags::WINDOW_AUTOSIZE);
  cv::namedWindow("matches", cv::WindowFlags::WINDOW_AUTOSIZE);

  // this will contain the image from the webcam
  cv::Mat frame;
  cv::Mat second_image;
  cv::Mat image_show;

  vector<DMatch> matches;
  vector<cv::DMatch> tmpMatches;
  vector<cv::KeyPoint> keypoints2;
  vector<KeyPoint> corners2;
  vector<DescType> descriptors2;

  // display the frame until you press a key
  while (1)
  {
    // capture the next frame from the webcam
    camera >> frame;
    // show the image on the window
    // cv::imshow("Webcam", frame);
    cv::cvtColor(frame, second_image, cv::COLOR_BGR2GRAY);

    // 用描述子进行匹配
    cv::FAST(second_image, keypoints2, 40);
    // cout << "keypoints2: " << keypoints2.size() << endl;

    uint totalElements2 = second_image.total() * second_image.channels(); // Note: image.total() == rows*cols.
    cv::Mat flat2 = second_image.reshape(1, totalElements2);              // 1xN mat of 1 channel, O(1) operation
    if (!second_image.isContinuous())
    {
      flat2 = flat2.clone(); // O(N),
    }
    // flat.data is your array pointer
    auto *arr2 = flat2.data;

    int num_corners2;
    auto bytes_per_row2 = second_image.cols * sizeof(uchar);
    auto threshold2 = 40;

    auto start = std::chrono::system_clock::now();
    corners2 = fast9_detect_nonmax(arr2, second_image.cols, second_image.rows, bytes_per_row2, threshold2, &num_corners2);

    cout << "corners: " << corners.size() << "--" << num_corners << endl;
    cout << "corners2: " << corners2.size() << "--" << num_corners2 << endl;

    // 计算每个关键点的角度
    computeAngle(arr2, second_image.cols, second_image.rows, bytes_per_row2, corners2);

    // 计算ORB描述子
    computeORBDesc(arr2, second_image.cols, second_image.rows, bytes_per_row2, corners2, descriptors2);

    // 进行匹配
    bfMatch(descriptors, descriptors2, matches);
    cout << "matches: " << matches.size() << endl;
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end - start;
    std::cout << "elapsed time: " << elapsed_seconds2.count() << endl;

    // convert to opencv variable formats for drawing
    if (corners2.size() > 0)
    {
      for (int tmpi = 0; tmpi < keypoints2.size(); tmpi++)
      {
        keypoints2[tmpi].pt.x = corners2[tmpi].x;
        keypoints2[tmpi].pt.y = corners2[tmpi].y;
        keypoints2[tmpi].angle = corners2[tmpi].angle;
      }
    }

    if (matches.size() > 0)
    {
      for (auto tmp : matches)
      {
        cv::DMatch temp_match;
        temp_match.queryIdx = tmp.queryIdx;
        temp_match.trainIdx = tmp.trainIdx;
        temp_match.distance = tmp.distance;
        temp_match.imgIdx = tmp.imgIdx;
        tmpMatches.push_back(temp_match);
      }
    }

    cv::drawMatches(first_image, keypoints, second_image, keypoints2, tmpMatches, image_show);
    cv::imshow("matches", image_show);

    // wait (1ms) for a key to be pressed
    if (cv::waitKey(1) >= 0)
    {
      break;
    }

    tmpMatches.clear();
    tmpMatches.shrink_to_fit();
    matches.clear();
    matches.shrink_to_fit();
    keypoints2.clear();
    keypoints2.shrink_to_fit();
    corners2.clear();
    corners2.shrink_to_fit();
    descriptors2.clear();
    descriptors2.shrink_to_fit();
  }

  cout << "done." << endl;
  return 0;
}
