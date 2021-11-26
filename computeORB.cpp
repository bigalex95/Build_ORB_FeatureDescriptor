#include <opencv2/opencv.hpp>
#include "fast/fast.hpp"
#include "orb.hpp"

string first_file = "../img.png";
string second_file = "../img2.png";

int main(int argc, char **argv)
{

  // 载入图片
  cv::Mat first_image = cv::imread(first_file, 0); //使用灰度图
  cv::Mat second_image = cv::imread(second_file, 0);
  // cv::resize(second_image, second_image, cv::Size(first_image.cols, first_image.rows), 0, 0);

  std::cout << first_image.rows << "===" << first_image.cols << endl;
  std::cout << second_image.rows << "===" << second_image.cols << endl;

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
  computeORBDesc(arr, second_image.cols, second_image.rows, bytes_per_row, corners, descriptors);

  // 用描述子进行匹配
  vector<cv::KeyPoint> keypoints2;
  cv::FAST(second_image, keypoints2, 40);
  cout << "keypoints: " << keypoints2.size() << endl;

  uint totalElements2 = second_image.total() * second_image.channels(); // Note: image.total() == rows*cols.
  cv::Mat flat2 = second_image.reshape(1, totalElements2);              // 1xN mat of 1 channel, O(1) operation
  if (!second_image.isContinuous())
  {
    flat2 = flat2.clone(); // O(N),
  }
  // flat.data is your array pointer
  auto *arr2 = flat2.data;

  vector<KeyPoint> corners2;
  int num_corners2;
  auto bytes_per_row2 = second_image.cols * sizeof(uchar);
  auto threshold2 = 40;

  corners2 = fast9_detect_nonmax(arr2, second_image.cols, second_image.rows, bytes_per_row2, threshold2, &num_corners2);
  cout << "corners: " << corners2.size() << "--" << num_corners2 << endl;

  // 计算每个关键点的角度
  computeAngle(arr2, second_image.cols, second_image.rows, bytes_per_row2, corners2);

  // 计算ORB描述子
  vector<DescType> descriptors2;
  computeORBDesc(arr2, second_image.cols, second_image.rows, bytes_per_row2, corners2, descriptors2);

  // auto end2 = std::chrono::system_clock::now();
  // std::chrono::duration<double> elapsed_seconds2 = end2-start2;
  // std::cout << "elapsed time: " << elapsed_seconds2.count() << endl;

  // 进行匹配
  vector<DMatch> matches;
  bfMatch(descriptors, descriptors2, matches);
  cout << "matches: " << matches.size() << endl;

  // convert to opencv variable formats for drawing
  for (int tmpi = 0; tmpi < keypoints.size(); tmpi++)
  {
    keypoints[tmpi].pt.x = corners[tmpi].x;
    keypoints[tmpi].pt.y = corners[tmpi].y;
    keypoints[tmpi].angle = corners[tmpi].angle;
  }

  for (int tmpi = 0; tmpi < keypoints2.size(); tmpi++)
  {
    keypoints2[tmpi].pt.x = corners2[tmpi].x;
    keypoints2[tmpi].pt.y = corners2[tmpi].y;
    keypoints2[tmpi].angle = corners2[tmpi].angle;
  }

  vector<cv::DMatch> tmpMatches;
  for (auto tmp : matches)
  {
    cv::DMatch temp_match;
    temp_match.queryIdx = tmp.queryIdx;
    temp_match.trainIdx = tmp.trainIdx;
    temp_match.distance = tmp.distance;
    temp_match.imgIdx = tmp.imgIdx;
    tmpMatches.push_back(temp_match);
  }

  // preview all images and processing
  cv::imshow("first image", first_image);
  cv::imshow("second image", second_image);
  cv::waitKey(0);

  cv::Mat image_show;
  cv::Mat image_show2;
  cv::drawKeypoints(first_image, keypoints, image_show, cv::Scalar::all(-1),
                    cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
  cv::drawKeypoints(second_image, keypoints2, image_show2, cv::Scalar::all(-1),
                    cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
  cv::imshow("features", image_show);
  cv::imwrite("feat1.png", image_show);
  cv::imshow("features2", image_show2);
  cv::imwrite("feat2.png", image_show2);
  cv::waitKey(0);

  cv::drawMatches(first_image, keypoints, second_image, keypoints2, tmpMatches, image_show);
  cv::imshow("matches", image_show);
  cv::imwrite("matches.png", image_show);
  cv::waitKey(0);

  cout << "done." << endl;
  return 0;
}
