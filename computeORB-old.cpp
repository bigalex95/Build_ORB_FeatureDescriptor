#include <opencv2/opencv.hpp>
#include <cmath>
#include <string>
#include <chrono>
// #include "fast-C-src/fast.h"
#include <stdlib.h>
#include <typeinfo>

using namespace std;

string first_file = "../1.png";
string second_file = "../3.png";

const double pi = 3.1415926;
typedef struct
{
  int x, y;
} KeyPoint;
typedef unsigned char byte;

vector<KeyPoint> fast9_detect(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners);

void computeAngle(const cv::Mat &image, vector<cv::KeyPoint> &keypoints);

typedef vector<bool> DescType; // 256 bools

void computeORBDesc(const cv::Mat &image, vector<cv::KeyPoint> &keypoints, vector<DescType> &desc);

void bfMatch(const vector<DescType> &desc1, const vector<DescType> &desc2, vector<cv::DMatch> &matches);

int main(int argc, char **argv)
{

  // 载入图片
  cv::Mat first_image = cv::imread(first_file, 0); //使用灰度图
  cv::Mat second_image = cv::imread(second_file, 0);
  // cv::resize(second_image, second_image, cv::Size(first_image.cols, first_image.rows), 0, 0);

  // 绘制图片
  cv::imshow("first image", first_image);
  cv::imshow("second image", second_image);
  cv::waitKey(0);

  // cout << first_image.type() << endl;
  // cout << static_cast<unsigned>(arr[700]) << endl;
  // cout << static_cast<unsigned>(first_image.at<uchar>(0, 700)) << endl;

  // cout << first_image.size() << " -- " << length << " -- " << first_image.total() <<  " -- " << first_image.channels() << endl;

  std::cout << first_image.rows << "===" << first_image.cols << endl;
  std::cout << second_image.rows << "===" << second_image.cols << endl;

  // auto start = std::chrono::system_clock::now();
  // 检测关键点 threshold=40
  vector<cv::KeyPoint> keypoints;
  cv::FAST(first_image, keypoints, 40);
  cout << "keypoints: " << keypoints.size() << endl;

  // auto end = std::chrono::system_clock::now();
  // std::chrono::duration<double> elapsed_seconds = end-start;
  // std::cout << "elapsed time: " << elapsed_seconds.count() << endl;

  uint totalElements = first_image.total() * first_image.channels(); // Note: image.total() == rows*cols.
  cv::Mat flat = first_image.reshape(1, totalElements);              // 1xN mat of 1 channel, O(1) operation
  if (!first_image.isContinuous())
  {
    flat = flat.clone(); // O(N),
  }
  // flat.data is your array pointer
  auto *arr = flat.data;

  auto start = std::chrono::system_clock::now();
  vector<KeyPoint> corners;
  int num_corners;
  auto bytes_per_row = first_image.cols * sizeof(uchar);
  // cout << bytes_per_row << endl;
  auto threshold = 60;

  corners = fast9_detect(arr, first_image.cols, first_image.rows, bytes_per_row, threshold, &num_corners);
  cout << "corners: " << corners.size() << "--" << num_corners << endl;
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "elapsed time: " << elapsed_seconds.count() << endl;

  for (int tmpi = 0; tmpi < keypoints.size(); tmpi++)
  {
    keypoints[tmpi].pt.x = corners[tmpi].x;
    keypoints[tmpi].pt.y = corners[tmpi].y;
  }

  // for (auto &kp : keypoints) {
  //     cout << kp.pt.x << "x" << kp.pt.y << endl;
  // }

  // 计算每个关键点的角度
  computeAngle(first_image, keypoints);

  // 计算ORB描述子
  vector<DescType> descriptors;
  computeORBDesc(first_image, keypoints, descriptors);

  // auto end = std::chrono::system_clock::now();
  // std::chrono::duration<double> elapsed_seconds = end-start;
  // std::cout << "elapsed time: " << elapsed_seconds.count() << endl;

  // 绘制关键点
  cv::Mat image_show;
  cv::drawKeypoints(first_image, keypoints, image_show, cv::Scalar::all(-1),
                    cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
  cv::imshow("features", image_show);
  cv::imwrite("feat1.png", image_show);
  cv::waitKey(0);

  // vector<cv::KeyPoint> keypoints_corners;
  // keypoints_corners = keypoints;
  // // int tmpi = 0;
  // for (int tmpi = 0; tmpi < keypoints_corners.size(); tmpi++)
  // {
  //     cout << "before -- " << keypoints_corners[tmpi].pt.x << " = " << corners[tmpi].x << endl;
  //     keypoints_corners[tmpi].pt.x = corners[tmpi].x;
  //     keypoints_corners[tmpi].pt.y = corners[tmpi].y;
  //     cout << "after -- " << keypoints_corners[tmpi].pt.x<< " = " << corners[tmpi].x << endl;
  //     tmpi++;
  // }
  // cout << keypoints_corners[0].pt.x << endl;
  // cv::Mat image_show_corners;
  // cv::drawKeypoints(first_image, keypoints_corners, image_show_corners, cv::Scalar::all(-1),
  //                   cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
  // cv::imshow("features2", image_show_corners);
  // cv::imwrite("feat2.png", image_show_corners);
  // cv::waitKey(0);

  // auto start2 = std::chrono::system_clock::now();
  // 用描述子进行匹配
  vector<cv::KeyPoint> keypoints2;
  cv::FAST(second_image, keypoints2, 40);
  cout << "keypoints: " << keypoints2.size() << endl;
  // auto end2 = std::chrono::system_clock::now();
  // std::chrono::duration<double> elapsed_seconds2 = end2-start2;
  // std::cout << "elapsed time: " << elapsed_seconds2.count() << endl;

  uint totalElements2 = second_image.total() * second_image.channels(); // Note: image.total() == rows*cols.
  cv::Mat flat2 = second_image.reshape(1, totalElements2);              // 1xN mat of 1 channel, O(1) operation
  if (!second_image.isContinuous())
  {
    flat2 = flat2.clone(); // O(N),
  }
  // flat.data is your array pointer
  auto *arr2 = flat2.data;

  auto start2 = std::chrono::system_clock::now();
  vector<KeyPoint> corners2;
  int num_corners2;
  auto bytes_per_row2 = second_image.cols * sizeof(uchar);
  // cout << bytes_per_row << endl;
  auto threshold2 = 60;

  corners2 = fast9_detect(arr2, second_image.cols, second_image.rows, bytes_per_row2, threshold2, &num_corners2);
  cout << "corners: " << corners2.size() << "--" << num_corners2 << endl;
  auto end2 = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
  std::cout << "elapsed time: " << elapsed_seconds2.count() << endl;

  for (int tmpi = 0; tmpi < keypoints2.size(); tmpi++)
  {
    keypoints2[tmpi].pt.x = corners2[tmpi].x;
    keypoints2[tmpi].pt.y = corners2[tmpi].y;
  }
  cv::Mat image_show2;
  cv::drawKeypoints(second_image, keypoints2, image_show2, cv::Scalar::all(-1),
                    cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
  cv::imshow("features2", image_show2);
  cv::imwrite("feat2.png", image_show2);
  cv::waitKey(0);

  // 计算每个关键点的角度
  computeAngle(second_image, keypoints2);

  // 计算ORB描述子
  vector<DescType> descriptors2;
  computeORBDesc(second_image, keypoints2, descriptors2);

  // auto end2 = std::chrono::system_clock::now();
  // std::chrono::duration<double> elapsed_seconds2 = end2-start2;
  // std::cout << "elapsed time: " << elapsed_seconds2.count() << endl;

  // 进行匹配
  vector<cv::DMatch> matches;
  bfMatch(descriptors, descriptors2, matches);
  cout << "matches: " << matches.size() << endl;

  // 绘制匹配
  cv::drawMatches(first_image, keypoints, second_image, keypoints2, matches, image_show);
  cv::imshow("matches", image_show);
  cv::imwrite("matches.png", image_show);
  cv::waitKey(0);

  cout << "done." << endl;
  return 0;
}

// -------------------------------------------------------------------------------------------------- //

// 计算角度
void computeAngle(const cv::Mat &image, vector<cv::KeyPoint> &keypoints)
{
  int half_patch_size = 8;
  int h = 0;
  double temp = 0;
  for (auto &kp : keypoints)
  {

    kp.angle = 0;

    double sum_m10 = 0;
    double sum_m01 = 0;

    for (int i = -half_patch_size; i < half_patch_size; i++)
    {
      for (int j = -half_patch_size; j < half_patch_size; j++)
      {

        if (cvRound(kp.pt.x) + i < 0 || cvRound(kp.pt.x) + i > image.rows || cvRound(kp.pt.y) + j < 0 || cvRound(kp.pt.y) + j > image.cols)
          //防止越界，注意x对应cols,y对应rows
          continue;
        sum_m10 += i * image.at<uchar>(cvRound(kp.pt.y) + j, cvRound(kp.pt.x) + i); //image.at<uchar>(y,x),注意顺序
        // int cvRound (double value) 对一个double型的数进行四舍五入，并返回一个整型数！
        // 以特征点为中心旋转而不是全局坐标
        sum_m01 += j * image.at<uchar>(cvRound(kp.pt.y) + j, cvRound(kp.pt.x) + i);
        //sum_m00 += image.at<uchar>(cvRound(kp.pt.x)+i,cvRound(kp.pt.x)+j);  //公式中约去了
      }
    }

    kp.angle = std::atan2(sum_m01, sum_m10) * 180 / pi; //角度转换,openCV用角度制保存atan2(y,x)
                                                        //kp.angle = std::atan(temp)*180/pi;            //atan(y/x)
  }

  return;
}

// -------------------------------------------------------------------------------------------------- //
// ORB pattern
int ORB_pattern[256 * 4] = {
    8, -3, 9, 5 /*mean (0), correlation (0)*/,
    4, 2, 7, -12 /*mean (1.12461e-05), correlation (0.0437584)*/,
    -11, 9, -8, 2 /*mean (3.37382e-05), correlation (0.0617409)*/,
    7, -12, 12, -13 /*mean (5.62303e-05), correlation (0.0636977)*/,
    2, -13, 2, 12 /*mean (0.000134953), correlation (0.085099)*/,
    1, -7, 1, 6 /*mean (0.000528565), correlation (0.0857175)*/,
    -2, -10, -2, -4 /*mean (0.0188821), correlation (0.0985774)*/,
    -13, -13, -11, -8 /*mean (0.0363135), correlation (0.0899616)*/,
    -13, -3, -12, -9 /*mean (0.121806), correlation (0.099849)*/,
    10, 4, 11, 9 /*mean (0.122065), correlation (0.093285)*/,
    -13, -8, -8, -9 /*mean (0.162787), correlation (0.0942748)*/,
    -11, 7, -9, 12 /*mean (0.21561), correlation (0.0974438)*/,
    7, 7, 12, 6 /*mean (0.160583), correlation (0.130064)*/,
    -4, -5, -3, 0 /*mean (0.228171), correlation (0.132998)*/,
    -13, 2, -12, -3 /*mean (0.00997526), correlation (0.145926)*/,
    -9, 0, -7, 5 /*mean (0.198234), correlation (0.143636)*/,
    12, -6, 12, -1 /*mean (0.0676226), correlation (0.16689)*/,
    -3, 6, -2, 12 /*mean (0.166847), correlation (0.171682)*/,
    -6, -13, -4, -8 /*mean (0.101215), correlation (0.179716)*/,
    11, -13, 12, -8 /*mean (0.200641), correlation (0.192279)*/,
    4, 7, 5, 1 /*mean (0.205106), correlation (0.186848)*/,
    5, -3, 10, -3 /*mean (0.234908), correlation (0.192319)*/,
    3, -7, 6, 12 /*mean (0.0709964), correlation (0.210872)*/,
    -8, -7, -6, -2 /*mean (0.0939834), correlation (0.212589)*/,
    -2, 11, -1, -10 /*mean (0.127778), correlation (0.20866)*/,
    -13, 12, -8, 10 /*mean (0.14783), correlation (0.206356)*/,
    -7, 3, -5, -3 /*mean (0.182141), correlation (0.198942)*/,
    -4, 2, -3, 7 /*mean (0.188237), correlation (0.21384)*/,
    -10, -12, -6, 11 /*mean (0.14865), correlation (0.23571)*/,
    5, -12, 6, -7 /*mean (0.222312), correlation (0.23324)*/,
    5, -6, 7, -1 /*mean (0.229082), correlation (0.23389)*/,
    1, 0, 4, -5 /*mean (0.241577), correlation (0.215286)*/,
    9, 11, 11, -13 /*mean (0.00338507), correlation (0.251373)*/,
    4, 7, 4, 12 /*mean (0.131005), correlation (0.257622)*/,
    2, -1, 4, 4 /*mean (0.152755), correlation (0.255205)*/,
    -4, -12, -2, 7 /*mean (0.182771), correlation (0.244867)*/,
    -8, -5, -7, -10 /*mean (0.186898), correlation (0.23901)*/,
    4, 11, 9, 12 /*mean (0.226226), correlation (0.258255)*/,
    0, -8, 1, -13 /*mean (0.0897886), correlation (0.274827)*/,
    -13, -2, -8, 2 /*mean (0.148774), correlation (0.28065)*/,
    -3, -2, -2, 3 /*mean (0.153048), correlation (0.283063)*/,
    -6, 9, -4, -9 /*mean (0.169523), correlation (0.278248)*/,
    8, 12, 10, 7 /*mean (0.225337), correlation (0.282851)*/,
    0, 9, 1, 3 /*mean (0.226687), correlation (0.278734)*/,
    7, -5, 11, -10 /*mean (0.00693882), correlation (0.305161)*/,
    -13, -6, -11, 0 /*mean (0.0227283), correlation (0.300181)*/,
    10, 7, 12, 1 /*mean (0.125517), correlation (0.31089)*/,
    -6, -3, -6, 12 /*mean (0.131748), correlation (0.312779)*/,
    10, -9, 12, -4 /*mean (0.144827), correlation (0.292797)*/,
    -13, 8, -8, -12 /*mean (0.149202), correlation (0.308918)*/,
    -13, 0, -8, -4 /*mean (0.160909), correlation (0.310013)*/,
    3, 3, 7, 8 /*mean (0.177755), correlation (0.309394)*/,
    5, 7, 10, -7 /*mean (0.212337), correlation (0.310315)*/,
    -1, 7, 1, -12 /*mean (0.214429), correlation (0.311933)*/,
    3, -10, 5, 6 /*mean (0.235807), correlation (0.313104)*/,
    2, -4, 3, -10 /*mean (0.00494827), correlation (0.344948)*/,
    -13, 0, -13, 5 /*mean (0.0549145), correlation (0.344675)*/,
    -13, -7, -12, 12 /*mean (0.103385), correlation (0.342715)*/,
    -13, 3, -11, 8 /*mean (0.134222), correlation (0.322922)*/,
    -7, 12, -4, 7 /*mean (0.153284), correlation (0.337061)*/,
    6, -10, 12, 8 /*mean (0.154881), correlation (0.329257)*/,
    -9, -1, -7, -6 /*mean (0.200967), correlation (0.33312)*/,
    -2, -5, 0, 12 /*mean (0.201518), correlation (0.340635)*/,
    -12, 5, -7, 5 /*mean (0.207805), correlation (0.335631)*/,
    3, -10, 8, -13 /*mean (0.224438), correlation (0.34504)*/,
    -7, -7, -4, 5 /*mean (0.239361), correlation (0.338053)*/,
    -3, -2, -1, -7 /*mean (0.240744), correlation (0.344322)*/,
    2, 9, 5, -11 /*mean (0.242949), correlation (0.34145)*/,
    -11, -13, -5, -13 /*mean (0.244028), correlation (0.336861)*/,
    -1, 6, 0, -1 /*mean (0.247571), correlation (0.343684)*/,
    5, -3, 5, 2 /*mean (0.000697256), correlation (0.357265)*/,
    -4, -13, -4, 12 /*mean (0.00213675), correlation (0.373827)*/,
    -9, -6, -9, 6 /*mean (0.0126856), correlation (0.373938)*/,
    -12, -10, -8, -4 /*mean (0.0152497), correlation (0.364237)*/,
    10, 2, 12, -3 /*mean (0.0299933), correlation (0.345292)*/,
    7, 12, 12, 12 /*mean (0.0307242), correlation (0.366299)*/,
    -7, -13, -6, 5 /*mean (0.0534975), correlation (0.368357)*/,
    -4, 9, -3, 4 /*mean (0.099865), correlation (0.372276)*/,
    7, -1, 12, 2 /*mean (0.117083), correlation (0.364529)*/,
    -7, 6, -5, 1 /*mean (0.126125), correlation (0.369606)*/,
    -13, 11, -12, 5 /*mean (0.130364), correlation (0.358502)*/,
    -3, 7, -2, -6 /*mean (0.131691), correlation (0.375531)*/,
    7, -8, 12, -7 /*mean (0.160166), correlation (0.379508)*/,
    -13, -7, -11, -12 /*mean (0.167848), correlation (0.353343)*/,
    1, -3, 12, 12 /*mean (0.183378), correlation (0.371916)*/,
    2, -6, 3, 0 /*mean (0.228711), correlation (0.371761)*/,
    -4, 3, -2, -13 /*mean (0.247211), correlation (0.364063)*/,
    -1, -13, 1, 9 /*mean (0.249325), correlation (0.378139)*/,
    7, 1, 8, -6 /*mean (0.000652272), correlation (0.411682)*/,
    1, -1, 3, 12 /*mean (0.00248538), correlation (0.392988)*/,
    9, 1, 12, 6 /*mean (0.0206815), correlation (0.386106)*/,
    -1, -9, -1, 3 /*mean (0.0364485), correlation (0.410752)*/,
    -13, -13, -10, 5 /*mean (0.0376068), correlation (0.398374)*/,
    7, 7, 10, 12 /*mean (0.0424202), correlation (0.405663)*/,
    12, -5, 12, 9 /*mean (0.0942645), correlation (0.410422)*/,
    6, 3, 7, 11 /*mean (0.1074), correlation (0.413224)*/,
    5, -13, 6, 10 /*mean (0.109256), correlation (0.408646)*/,
    2, -12, 2, 3 /*mean (0.131691), correlation (0.416076)*/,
    3, 8, 4, -6 /*mean (0.165081), correlation (0.417569)*/,
    2, 6, 12, -13 /*mean (0.171874), correlation (0.408471)*/,
    9, -12, 10, 3 /*mean (0.175146), correlation (0.41296)*/,
    -8, 4, -7, 9 /*mean (0.183682), correlation (0.402956)*/,
    -11, 12, -4, -6 /*mean (0.184672), correlation (0.416125)*/,
    1, 12, 2, -8 /*mean (0.191487), correlation (0.386696)*/,
    6, -9, 7, -4 /*mean (0.192668), correlation (0.394771)*/,
    2, 3, 3, -2 /*mean (0.200157), correlation (0.408303)*/,
    6, 3, 11, 0 /*mean (0.204588), correlation (0.411762)*/,
    3, -3, 8, -8 /*mean (0.205904), correlation (0.416294)*/,
    7, 8, 9, 3 /*mean (0.213237), correlation (0.409306)*/,
    -11, -5, -6, -4 /*mean (0.243444), correlation (0.395069)*/,
    -10, 11, -5, 10 /*mean (0.247672), correlation (0.413392)*/,
    -5, -8, -3, 12 /*mean (0.24774), correlation (0.411416)*/,
    -10, 5, -9, 0 /*mean (0.00213675), correlation (0.454003)*/,
    8, -1, 12, -6 /*mean (0.0293635), correlation (0.455368)*/,
    4, -6, 6, -11 /*mean (0.0404971), correlation (0.457393)*/,
    -10, 12, -8, 7 /*mean (0.0481107), correlation (0.448364)*/,
    4, -2, 6, 7 /*mean (0.050641), correlation (0.455019)*/,
    -2, 0, -2, 12 /*mean (0.0525978), correlation (0.44338)*/,
    -5, -8, -5, 2 /*mean (0.0629667), correlation (0.457096)*/,
    7, -6, 10, 12 /*mean (0.0653846), correlation (0.445623)*/,
    -9, -13, -8, -8 /*mean (0.0858749), correlation (0.449789)*/,
    -5, -13, -5, -2 /*mean (0.122402), correlation (0.450201)*/,
    8, -8, 9, -13 /*mean (0.125416), correlation (0.453224)*/,
    -9, -11, -9, 0 /*mean (0.130128), correlation (0.458724)*/,
    1, -8, 1, -2 /*mean (0.132467), correlation (0.440133)*/,
    7, -4, 9, 1 /*mean (0.132692), correlation (0.454)*/,
    -2, 1, -1, -4 /*mean (0.135695), correlation (0.455739)*/,
    11, -6, 12, -11 /*mean (0.142904), correlation (0.446114)*/,
    -12, -9, -6, 4 /*mean (0.146165), correlation (0.451473)*/,
    3, 7, 7, 12 /*mean (0.147627), correlation (0.456643)*/,
    5, 5, 10, 8 /*mean (0.152901), correlation (0.455036)*/,
    0, -4, 2, 8 /*mean (0.167083), correlation (0.459315)*/,
    -9, 12, -5, -13 /*mean (0.173234), correlation (0.454706)*/,
    0, 7, 2, 12 /*mean (0.18312), correlation (0.433855)*/,
    -1, 2, 1, 7 /*mean (0.185504), correlation (0.443838)*/,
    5, 11, 7, -9 /*mean (0.185706), correlation (0.451123)*/,
    3, 5, 6, -8 /*mean (0.188968), correlation (0.455808)*/,
    -13, -4, -8, 9 /*mean (0.191667), correlation (0.459128)*/,
    -5, 9, -3, -3 /*mean (0.193196), correlation (0.458364)*/,
    -4, -7, -3, -12 /*mean (0.196536), correlation (0.455782)*/,
    6, 5, 8, 0 /*mean (0.1972), correlation (0.450481)*/,
    -7, 6, -6, 12 /*mean (0.199438), correlation (0.458156)*/,
    -13, 6, -5, -2 /*mean (0.211224), correlation (0.449548)*/,
    1, -10, 3, 10 /*mean (0.211718), correlation (0.440606)*/,
    4, 1, 8, -4 /*mean (0.213034), correlation (0.443177)*/,
    -2, -2, 2, -13 /*mean (0.234334), correlation (0.455304)*/,
    2, -12, 12, 12 /*mean (0.235684), correlation (0.443436)*/,
    -2, -13, 0, -6 /*mean (0.237674), correlation (0.452525)*/,
    4, 1, 9, 3 /*mean (0.23962), correlation (0.444824)*/,
    -6, -10, -3, -5 /*mean (0.248459), correlation (0.439621)*/,
    -3, -13, -1, 1 /*mean (0.249505), correlation (0.456666)*/,
    7, 5, 12, -11 /*mean (0.00119208), correlation (0.495466)*/,
    4, -2, 5, -7 /*mean (0.00372245), correlation (0.484214)*/,
    -13, 9, -9, -5 /*mean (0.00741116), correlation (0.499854)*/,
    7, 1, 8, 6 /*mean (0.0208952), correlation (0.499773)*/,
    7, -8, 7, 6 /*mean (0.0220085), correlation (0.501609)*/,
    -7, -4, -7, 1 /*mean (0.0233806), correlation (0.496568)*/,
    -8, 11, -7, -8 /*mean (0.0236505), correlation (0.489719)*/,
    -13, 6, -12, -8 /*mean (0.0268781), correlation (0.503487)*/,
    2, 4, 3, 9 /*mean (0.0323324), correlation (0.501938)*/,
    10, -5, 12, 3 /*mean (0.0399235), correlation (0.494029)*/,
    -6, -5, -6, 7 /*mean (0.0420153), correlation (0.486579)*/,
    8, -3, 9, -8 /*mean (0.0548021), correlation (0.484237)*/,
    2, -12, 2, 8 /*mean (0.0616622), correlation (0.496642)*/,
    -11, -2, -10, 3 /*mean (0.0627755), correlation (0.498563)*/,
    -12, -13, -7, -9 /*mean (0.0829622), correlation (0.495491)*/,
    -11, 0, -10, -5 /*mean (0.0843342), correlation (0.487146)*/,
    5, -3, 11, 8 /*mean (0.0929937), correlation (0.502315)*/,
    -2, -13, -1, 12 /*mean (0.113327), correlation (0.48941)*/,
    -1, -8, 0, 9 /*mean (0.132119), correlation (0.467268)*/,
    -13, -11, -12, -5 /*mean (0.136269), correlation (0.498771)*/,
    -10, -2, -10, 11 /*mean (0.142173), correlation (0.498714)*/,
    -3, 9, -2, -13 /*mean (0.144141), correlation (0.491973)*/,
    2, -3, 3, 2 /*mean (0.14892), correlation (0.500782)*/,
    -9, -13, -4, 0 /*mean (0.150371), correlation (0.498211)*/,
    -4, 6, -3, -10 /*mean (0.152159), correlation (0.495547)*/,
    -4, 12, -2, -7 /*mean (0.156152), correlation (0.496925)*/,
    -6, -11, -4, 9 /*mean (0.15749), correlation (0.499222)*/,
    6, -3, 6, 11 /*mean (0.159211), correlation (0.503821)*/,
    -13, 11, -5, 5 /*mean (0.162427), correlation (0.501907)*/,
    11, 11, 12, 6 /*mean (0.16652), correlation (0.497632)*/,
    7, -5, 12, -2 /*mean (0.169141), correlation (0.484474)*/,
    -1, 12, 0, 7 /*mean (0.169456), correlation (0.495339)*/,
    -4, -8, -3, -2 /*mean (0.171457), correlation (0.487251)*/,
    -7, 1, -6, 7 /*mean (0.175), correlation (0.500024)*/,
    -13, -12, -8, -13 /*mean (0.175866), correlation (0.497523)*/,
    -7, -2, -6, -8 /*mean (0.178273), correlation (0.501854)*/,
    -8, 5, -6, -9 /*mean (0.181107), correlation (0.494888)*/,
    -5, -1, -4, 5 /*mean (0.190227), correlation (0.482557)*/,
    -13, 7, -8, 10 /*mean (0.196739), correlation (0.496503)*/,
    1, 5, 5, -13 /*mean (0.19973), correlation (0.499759)*/,
    1, 0, 10, -13 /*mean (0.204465), correlation (0.49873)*/,
    9, 12, 10, -1 /*mean (0.209334), correlation (0.49063)*/,
    5, -8, 10, -9 /*mean (0.211134), correlation (0.503011)*/,
    -1, 11, 1, -13 /*mean (0.212), correlation (0.499414)*/,
    -9, -3, -6, 2 /*mean (0.212168), correlation (0.480739)*/,
    -1, -10, 1, 12 /*mean (0.212731), correlation (0.502523)*/,
    -13, 1, -8, -10 /*mean (0.21327), correlation (0.489786)*/,
    8, -11, 10, -6 /*mean (0.214159), correlation (0.488246)*/,
    2, -13, 3, -6 /*mean (0.216993), correlation (0.50287)*/,
    7, -13, 12, -9 /*mean (0.223639), correlation (0.470502)*/,
    -10, -10, -5, -7 /*mean (0.224089), correlation (0.500852)*/,
    -10, -8, -8, -13 /*mean (0.228666), correlation (0.502629)*/,
    4, -6, 8, 5 /*mean (0.22906), correlation (0.498305)*/,
    3, 12, 8, -13 /*mean (0.233378), correlation (0.503825)*/,
    -4, 2, -3, -3 /*mean (0.234323), correlation (0.476692)*/,
    5, -13, 10, -12 /*mean (0.236392), correlation (0.475462)*/,
    4, -13, 5, -1 /*mean (0.236842), correlation (0.504132)*/,
    -9, 9, -4, 3 /*mean (0.236977), correlation (0.497739)*/,
    0, 3, 3, -9 /*mean (0.24314), correlation (0.499398)*/,
    -12, 1, -6, 1 /*mean (0.243297), correlation (0.489447)*/,
    3, 2, 4, -8 /*mean (0.00155196), correlation (0.553496)*/,
    -10, -10, -10, 9 /*mean (0.00239541), correlation (0.54297)*/,
    8, -13, 12, 12 /*mean (0.0034413), correlation (0.544361)*/,
    -8, -12, -6, -5 /*mean (0.003565), correlation (0.551225)*/,
    2, 2, 3, 7 /*mean (0.00835583), correlation (0.55285)*/,
    10, 6, 11, -8 /*mean (0.00885065), correlation (0.540913)*/,
    6, 8, 8, -12 /*mean (0.0101552), correlation (0.551085)*/,
    -7, 10, -6, 5 /*mean (0.0102227), correlation (0.533635)*/,
    -3, -9, -3, 9 /*mean (0.0110211), correlation (0.543121)*/,
    -1, -13, -1, 5 /*mean (0.0113473), correlation (0.550173)*/,
    -3, -7, -3, 4 /*mean (0.0140913), correlation (0.554774)*/,
    -8, -2, -8, 3 /*mean (0.017049), correlation (0.55461)*/,
    4, 2, 12, 12 /*mean (0.01778), correlation (0.546921)*/,
    2, -5, 3, 11 /*mean (0.0224022), correlation (0.549667)*/,
    6, -9, 11, -13 /*mean (0.029161), correlation (0.546295)*/,
    3, -1, 7, 12 /*mean (0.0303081), correlation (0.548599)*/,
    11, -1, 12, 4 /*mean (0.0355151), correlation (0.523943)*/,
    -3, 0, -3, 6 /*mean (0.0417904), correlation (0.543395)*/,
    4, -11, 4, 12 /*mean (0.0487292), correlation (0.542818)*/,
    2, -4, 2, 1 /*mean (0.0575124), correlation (0.554888)*/,
    -10, -6, -8, 1 /*mean (0.0594242), correlation (0.544026)*/,
    -13, 7, -11, 1 /*mean (0.0597391), correlation (0.550524)*/,
    -13, 12, -11, -13 /*mean (0.0608974), correlation (0.55383)*/,
    6, 0, 11, -13 /*mean (0.065126), correlation (0.552006)*/,
    0, -1, 1, 4 /*mean (0.074224), correlation (0.546372)*/,
    -13, 3, -9, -2 /*mean (0.0808592), correlation (0.554875)*/,
    -9, 8, -6, -3 /*mean (0.0883378), correlation (0.551178)*/,
    -13, -6, -8, -2 /*mean (0.0901035), correlation (0.548446)*/,
    5, -9, 8, 10 /*mean (0.0949843), correlation (0.554694)*/,
    2, 7, 3, -9 /*mean (0.0994152), correlation (0.550979)*/,
    -1, -6, -1, -1 /*mean (0.10045), correlation (0.552714)*/,
    9, 5, 11, -2 /*mean (0.100686), correlation (0.552594)*/,
    11, -3, 12, -8 /*mean (0.101091), correlation (0.532394)*/,
    3, 0, 3, 5 /*mean (0.101147), correlation (0.525576)*/,
    -1, 4, 0, 10 /*mean (0.105263), correlation (0.531498)*/,
    3, -6, 4, 5 /*mean (0.110785), correlation (0.540491)*/,
    -13, 0, -10, 5 /*mean (0.112798), correlation (0.536582)*/,
    5, 8, 12, 11 /*mean (0.114181), correlation (0.555793)*/,
    8, 9, 9, -6 /*mean (0.117431), correlation (0.553763)*/,
    7, -4, 8, -12 /*mean (0.118522), correlation (0.553452)*/,
    -10, 4, -10, 9 /*mean (0.12094), correlation (0.554785)*/,
    7, 3, 12, 4 /*mean (0.122582), correlation (0.555825)*/,
    9, -7, 10, -2 /*mean (0.124978), correlation (0.549846)*/,
    7, 0, 12, -2 /*mean (0.127002), correlation (0.537452)*/,
    -1, -6, 0, -11 /*mean (0.127148), correlation (0.547401)*/
};

// 计算描述子
void computeORBDesc(const cv::Mat &image, vector<cv::KeyPoint> &keypoints, vector<DescType> &desc)
{
  for (auto &kp : keypoints)
  {
    DescType d(256, false);                    //typedef vector<bool> DescType;   //int ORB_pattern[256 * 4]
    double Angle = kp.angle * 3.1415926 / 180; //cmath的sin操作的是弧度，而openCV中存的是角度，需要转换
    for (int i = 0; i < 256; i++)
    {

      if (kp.pt.x + ORB_pattern[4 * i] < 0 || kp.pt.x + ORB_pattern[4 * i] > image.rows || kp.pt.y + ORB_pattern[4 * i + 1] < 0 || kp.pt.y + ORB_pattern[4 * i + 1] > image.cols || kp.pt.x + ORB_pattern[4 * i + 2] < 0 || kp.pt.x + ORB_pattern[4 * i + 2] > image.rows || kp.pt.y + ORB_pattern[4 * i + 3] < 0 || kp.pt.y + ORB_pattern[4 * i + 3] > image.cols) //判断全局坐标pu,pv,qu,qv是否越界
      {
        d.clear(); // 如果kp出界,设置d.clear()
        break;
      }

      double up_1 = ORB_pattern[4 * i] * cos(Angle) - ORB_pattern[4 * i + 1] * sin(Angle);
      double vp_1 = ORB_pattern[4 * i] * sin(Angle) + ORB_pattern[4 * i + 1] * cos(Angle);
      double uq_1 = ORB_pattern[4 * i + 2] * cos(Angle) - ORB_pattern[4 * i + 3] * sin(Angle);
      double vq_1 = ORB_pattern[4 * i + 2] * sin(Angle) + ORB_pattern[4 * i + 3] * cos(Angle); //仅对16*16方块旋转，不是对全局坐标

      int gray_p_1 = image.at<uchar>(kp.pt.y + cvRound(vp_1), kp.pt.x + cvRound(up_1)); //提取灰度时要用全局坐标
      int gray_q_1 = image.at<uchar>(kp.pt.y + cvRound(vq_1), kp.pt.x + cvRound(uq_1));

      if (gray_p_1 > gray_q_1)
        d[i] = 0;
      else
        d[i] = 1;
    }

    desc.push_back(d);
  }

  int bad = 0;
  for (auto &d : desc)
  {
    if (d.empty())
      bad++;
  }
  cout << "bad/total: " << bad << "/" << desc.size() << endl;
  return;
}

// 暴力匹配
void bfMatch(const vector<DescType> &desc1, const vector<DescType> &desc2, vector<cv::DMatch> &matches)
{
  int d_max = 50;
  //在信息论中，两个等长字符串之间的汉明距离是两个字符串对应位置的不同字符的个数。换句话说，它就是将一个字符串变换成另外一个字符串所需要替换的字符个数。例如：

  //DescType d(256, false);  //typedef vector<bool> DescType;   //int ORB_pattern[256 * 4]
  int queryIdx = 0;
  for (auto desc1_temp : desc1)
  {
    int trainIdx = 0, min_count = 256, min_trainIdx = -1;
    for (auto desc2_temp : desc2)
    {
      vector<bool> desc1_temp_1 = desc1_temp;
      vector<bool> desc2_temp_2 = desc2_temp;
      if (desc1_temp_1.empty() || desc2_temp_2.empty())
      {
        trainIdx++;
        continue;
      }
      int count = 0;
      for (int i = 0; i < 256; i++)
      {
        if (desc1_temp_1[i] != desc2_temp_2[i])
          count++;
      }
      if (count < min_count && count <= d_max)
      {
        min_count = count;
        min_trainIdx = trainIdx;
      }
      trainIdx++;
    }
    if (min_trainIdx == -1)
    {
      queryIdx++;
      continue;
    }
    else
    {
      cv::DMatch temp_match;
      temp_match.queryIdx = queryIdx;
      temp_match.trainIdx = min_trainIdx;
      temp_match.distance = min_count;
      matches.push_back(temp_match);
      queryIdx++;
    }
  }

  // for (auto &m: matches) {
  //     cout << m.queryIdx << ", " << m.trainIdx << ", " << m.distance << endl;
  // }
  return;
}

static void make_offsets(int pixel[], int row_bytes_per_row)
{
  pixel[0] = 0 + row_bytes_per_row * 3;
  pixel[1] = 1 + row_bytes_per_row * 3;
  pixel[2] = 2 + row_bytes_per_row * 2;
  pixel[3] = 3 + row_bytes_per_row * 1;
  pixel[4] = 3 + row_bytes_per_row * 0;
  pixel[5] = 3 + row_bytes_per_row * -1;
  pixel[6] = 2 + row_bytes_per_row * -2;
  pixel[7] = 1 + row_bytes_per_row * -3;
  pixel[8] = 0 + row_bytes_per_row * -3;
  pixel[9] = -1 + row_bytes_per_row * -3;
  pixel[10] = -2 + row_bytes_per_row * -2;
  pixel[11] = -3 + row_bytes_per_row * -1;
  pixel[12] = -3 + row_bytes_per_row * 0;
  pixel[13] = -3 + row_bytes_per_row * 1;
  pixel[14] = -2 + row_bytes_per_row * 2;
  pixel[15] = -1 + row_bytes_per_row * 3;
}

vector<KeyPoint> fast9_detect(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners)
{
  int num_corners = 0;
  vector<KeyPoint> ret_corners;
  KeyPoint posxy;
  // int rsize=512;
  int pixel[16];
  int x, y;

  // ret_corners = (xy*)malloc(sizeof(xy)*rsize);

  make_offsets(pixel, bytes_per_row);

  for (y = 3; y < rows - 3; y++)
    for (x = 3; x < cols - 3; x++)
    {
      const byte *p = im + y * bytes_per_row + x;

      int cb = *p + b;
      int c_b = *p - b;
      if (p[pixel[0]] > cb)
        if (p[pixel[1]] > cb)
          if (p[pixel[2]] > cb)
            if (p[pixel[3]] > cb)
              if (p[pixel[4]] > cb)
                if (p[pixel[5]] > cb)
                  if (p[pixel[6]] > cb)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                      {
                      }
                      else if (p[pixel[15]] > cb)
                      {
                      }
                      else
                        continue;
                    else if (p[pixel[7]] < c_b)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                        {
                        }
                        else
                          continue;
                      else if (p[pixel[14]] < c_b)
                        if (p[pixel[8]] < c_b)
                          if (p[pixel[9]] < c_b)
                            if (p[pixel[10]] < c_b)
                              if (p[pixel[11]] < c_b)
                                if (p[pixel[12]] < c_b)
                                  if (p[pixel[13]] < c_b)
                                    if (p[pixel[15]] < c_b)
                                    {
                                    }
                                    else
                                      continue;
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[14]] > cb)
                      if (p[pixel[15]] > cb)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[6]] < c_b)
                    if (p[pixel[15]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                        {
                        }
                        else
                          continue;
                      else if (p[pixel[13]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                            if (p[pixel[9]] < c_b)
                              if (p[pixel[10]] < c_b)
                                if (p[pixel[11]] < c_b)
                                  if (p[pixel[12]] < c_b)
                                    if (p[pixel[14]] < c_b)
                                    {
                                    }
                                    else
                                      continue;
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                        if (p[pixel[9]] < c_b)
                          if (p[pixel[10]] < c_b)
                            if (p[pixel[11]] < c_b)
                              if (p[pixel[12]] < c_b)
                                if (p[pixel[13]] < c_b)
                                  if (p[pixel[14]] < c_b)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[13]] > cb)
                    if (p[pixel[14]] > cb)
                      if (p[pixel[15]] > cb)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[13]] < c_b)
                    if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                        if (p[pixel[9]] < c_b)
                          if (p[pixel[10]] < c_b)
                            if (p[pixel[11]] < c_b)
                              if (p[pixel[12]] < c_b)
                                if (p[pixel[14]] < c_b)
                                  if (p[pixel[15]] < c_b)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[5]] < c_b)
                  if (p[pixel[14]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[15]] > cb)
                        {
                        }
                        else if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                            if (p[pixel[8]] > cb)
                              if (p[pixel[9]] > cb)
                                if (p[pixel[10]] > cb)
                                  if (p[pixel[11]] > cb)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[12]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                            if (p[pixel[9]] < c_b)
                              if (p[pixel[10]] < c_b)
                                if (p[pixel[11]] < c_b)
                                  if (p[pixel[13]] < c_b)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[14]] < c_b)
                    if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                        if (p[pixel[9]] < c_b)
                          if (p[pixel[10]] < c_b)
                            if (p[pixel[11]] < c_b)
                              if (p[pixel[12]] < c_b)
                                if (p[pixel[13]] < c_b)
                                  if (p[pixel[6]] < c_b)
                                  {
                                  }
                                  else if (p[pixel[15]] < c_b)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[6]] < c_b)
                    if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                        if (p[pixel[9]] < c_b)
                          if (p[pixel[10]] < c_b)
                            if (p[pixel[11]] < c_b)
                              if (p[pixel[12]] < c_b)
                                if (p[pixel[13]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[12]] > cb)
                  if (p[pixel[13]] > cb)
                    if (p[pixel[14]] > cb)
                      if (p[pixel[15]] > cb)
                      {
                      }
                      else if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                            if (p[pixel[9]] > cb)
                              if (p[pixel[10]] > cb)
                                if (p[pixel[11]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[12]] < c_b)
                  if (p[pixel[7]] < c_b)
                    if (p[pixel[8]] < c_b)
                      if (p[pixel[9]] < c_b)
                        if (p[pixel[10]] < c_b)
                          if (p[pixel[11]] < c_b)
                            if (p[pixel[13]] < c_b)
                              if (p[pixel[14]] < c_b)
                                if (p[pixel[6]] < c_b)
                                {
                                }
                                else if (p[pixel[15]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[4]] < c_b)
                if (p[pixel[13]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                        {
                        }
                        else if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                            if (p[pixel[8]] > cb)
                              if (p[pixel[9]] > cb)
                                if (p[pixel[10]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[5]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                            if (p[pixel[8]] > cb)
                              if (p[pixel[9]] > cb)
                                if (p[pixel[10]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[11]] < c_b)
                    if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                            if (p[pixel[9]] < c_b)
                              if (p[pixel[10]] < c_b)
                                if (p[pixel[12]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[13]] < c_b)
                  if (p[pixel[7]] < c_b)
                    if (p[pixel[8]] < c_b)
                      if (p[pixel[9]] < c_b)
                        if (p[pixel[10]] < c_b)
                          if (p[pixel[11]] < c_b)
                            if (p[pixel[12]] < c_b)
                              if (p[pixel[6]] < c_b)
                                if (p[pixel[5]] < c_b)
                                {
                                }
                                else if (p[pixel[14]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else if (p[pixel[14]] < c_b)
                                if (p[pixel[15]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[5]] < c_b)
                  if (p[pixel[6]] < c_b)
                    if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                        if (p[pixel[9]] < c_b)
                          if (p[pixel[10]] < c_b)
                            if (p[pixel[11]] < c_b)
                              if (p[pixel[12]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[11]] > cb)
                if (p[pixel[12]] > cb)
                  if (p[pixel[13]] > cb)
                    if (p[pixel[14]] > cb)
                      if (p[pixel[15]] > cb)
                      {
                      }
                      else if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                            if (p[pixel[9]] > cb)
                              if (p[pixel[10]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                            if (p[pixel[9]] > cb)
                              if (p[pixel[10]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[11]] < c_b)
                if (p[pixel[7]] < c_b)
                  if (p[pixel[8]] < c_b)
                    if (p[pixel[9]] < c_b)
                      if (p[pixel[10]] < c_b)
                        if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                            if (p[pixel[6]] < c_b)
                              if (p[pixel[5]] < c_b)
                              {
                              }
                              else if (p[pixel[14]] < c_b)
                              {
                              }
                              else
                                continue;
                            else if (p[pixel[14]] < c_b)
                              if (p[pixel[15]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[3]] < c_b)
              if (p[pixel[10]] > cb)
                if (p[pixel[11]] > cb)
                  if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                        {
                        }
                        else if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                            if (p[pixel[8]] > cb)
                              if (p[pixel[9]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[5]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                            if (p[pixel[8]] > cb)
                              if (p[pixel[9]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[4]] > cb)
                      if (p[pixel[5]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                            if (p[pixel[8]] > cb)
                              if (p[pixel[9]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[10]] < c_b)
                if (p[pixel[7]] < c_b)
                  if (p[pixel[8]] < c_b)
                    if (p[pixel[9]] < c_b)
                      if (p[pixel[11]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[5]] < c_b)
                            if (p[pixel[4]] < c_b)
                            {
                            }
                            else if (p[pixel[12]] < c_b)
                              if (p[pixel[13]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else if (p[pixel[12]] < c_b)
                            if (p[pixel[13]] < c_b)
                              if (p[pixel[14]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                            if (p[pixel[14]] < c_b)
                              if (p[pixel[15]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[10]] > cb)
              if (p[pixel[11]] > cb)
                if (p[pixel[12]] > cb)
                  if (p[pixel[13]] > cb)
                    if (p[pixel[14]] > cb)
                      if (p[pixel[15]] > cb)
                      {
                      }
                      else if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                            if (p[pixel[9]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                            if (p[pixel[9]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[4]] > cb)
                    if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                            if (p[pixel[9]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[10]] < c_b)
              if (p[pixel[7]] < c_b)
                if (p[pixel[8]] < c_b)
                  if (p[pixel[9]] < c_b)
                    if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[5]] < c_b)
                            if (p[pixel[4]] < c_b)
                            {
                            }
                            else if (p[pixel[13]] < c_b)
                            {
                            }
                            else
                              continue;
                          else if (p[pixel[13]] < c_b)
                            if (p[pixel[14]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                            if (p[pixel[15]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[2]] < c_b)
            if (p[pixel[9]] > cb)
              if (p[pixel[10]] > cb)
                if (p[pixel[11]] > cb)
                  if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                        {
                        }
                        else if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                            if (p[pixel[8]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[5]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                            if (p[pixel[8]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[4]] > cb)
                      if (p[pixel[5]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                            if (p[pixel[8]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[3]] > cb)
                    if (p[pixel[4]] > cb)
                      if (p[pixel[5]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                            if (p[pixel[8]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[9]] < c_b)
              if (p[pixel[7]] < c_b)
                if (p[pixel[8]] < c_b)
                  if (p[pixel[10]] < c_b)
                    if (p[pixel[6]] < c_b)
                      if (p[pixel[5]] < c_b)
                        if (p[pixel[4]] < c_b)
                          if (p[pixel[3]] < c_b)
                          {
                          }
                          else if (p[pixel[11]] < c_b)
                            if (p[pixel[12]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[11]] < c_b)
                          if (p[pixel[12]] < c_b)
                            if (p[pixel[13]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[11]] < c_b)
                        if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                            if (p[pixel[14]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                            if (p[pixel[15]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[9]] > cb)
            if (p[pixel[10]] > cb)
              if (p[pixel[11]] > cb)
                if (p[pixel[12]] > cb)
                  if (p[pixel[13]] > cb)
                    if (p[pixel[14]] > cb)
                      if (p[pixel[15]] > cb)
                      {
                      }
                      else if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[4]] > cb)
                    if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[3]] > cb)
                  if (p[pixel[4]] > cb)
                    if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[9]] < c_b)
            if (p[pixel[7]] < c_b)
              if (p[pixel[8]] < c_b)
                if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[6]] < c_b)
                      if (p[pixel[5]] < c_b)
                        if (p[pixel[4]] < c_b)
                          if (p[pixel[3]] < c_b)
                          {
                          }
                          else if (p[pixel[12]] < c_b)
                          {
                          }
                          else
                            continue;
                        else if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[1]] < c_b)
          if (p[pixel[8]] > cb)
            if (p[pixel[9]] > cb)
              if (p[pixel[10]] > cb)
                if (p[pixel[11]] > cb)
                  if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                        {
                        }
                        else if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[5]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[4]] > cb)
                      if (p[pixel[5]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[3]] > cb)
                    if (p[pixel[4]] > cb)
                      if (p[pixel[5]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[2]] > cb)
                  if (p[pixel[3]] > cb)
                    if (p[pixel[4]] > cb)
                      if (p[pixel[5]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[7]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[8]] < c_b)
            if (p[pixel[7]] < c_b)
              if (p[pixel[9]] < c_b)
                if (p[pixel[6]] < c_b)
                  if (p[pixel[5]] < c_b)
                    if (p[pixel[4]] < c_b)
                      if (p[pixel[3]] < c_b)
                        if (p[pixel[2]] < c_b)
                        {
                        }
                        else if (p[pixel[10]] < c_b)
                          if (p[pixel[11]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[10]] < c_b)
                        if (p[pixel[11]] < c_b)
                          if (p[pixel[12]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[10]] < c_b)
                      if (p[pixel[11]] < c_b)
                        if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[10]] < c_b)
                    if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[8]] > cb)
          if (p[pixel[9]] > cb)
            if (p[pixel[10]] > cb)
              if (p[pixel[11]] > cb)
                if (p[pixel[12]] > cb)
                  if (p[pixel[13]] > cb)
                    if (p[pixel[14]] > cb)
                      if (p[pixel[15]] > cb)
                      {
                      }
                      else if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[4]] > cb)
                    if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[3]] > cb)
                  if (p[pixel[4]] > cb)
                    if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[2]] > cb)
                if (p[pixel[3]] > cb)
                  if (p[pixel[4]] > cb)
                    if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[8]] < c_b)
          if (p[pixel[7]] < c_b)
            if (p[pixel[9]] < c_b)
              if (p[pixel[10]] < c_b)
                if (p[pixel[6]] < c_b)
                  if (p[pixel[5]] < c_b)
                    if (p[pixel[4]] < c_b)
                      if (p[pixel[3]] < c_b)
                        if (p[pixel[2]] < c_b)
                        {
                        }
                        else if (p[pixel[11]] < c_b)
                        {
                        }
                        else
                          continue;
                      else if (p[pixel[11]] < c_b)
                        if (p[pixel[12]] < c_b)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[11]] < c_b)
                  if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else
          continue;
      else if (p[pixel[0]] < c_b)
        if (p[pixel[1]] > cb)
          if (p[pixel[8]] > cb)
            if (p[pixel[7]] > cb)
              if (p[pixel[9]] > cb)
                if (p[pixel[6]] > cb)
                  if (p[pixel[5]] > cb)
                    if (p[pixel[4]] > cb)
                      if (p[pixel[3]] > cb)
                        if (p[pixel[2]] > cb)
                        {
                        }
                        else if (p[pixel[10]] > cb)
                          if (p[pixel[11]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[10]] > cb)
                        if (p[pixel[11]] > cb)
                          if (p[pixel[12]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[10]] > cb)
                      if (p[pixel[11]] > cb)
                        if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[10]] > cb)
                    if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[8]] < c_b)
            if (p[pixel[9]] < c_b)
              if (p[pixel[10]] < c_b)
                if (p[pixel[11]] < c_b)
                  if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                        {
                        }
                        else if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[5]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[4]] < c_b)
                      if (p[pixel[5]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[3]] < c_b)
                    if (p[pixel[4]] < c_b)
                      if (p[pixel[5]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[2]] < c_b)
                  if (p[pixel[3]] < c_b)
                    if (p[pixel[4]] < c_b)
                      if (p[pixel[5]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[1]] < c_b)
          if (p[pixel[2]] > cb)
            if (p[pixel[9]] > cb)
              if (p[pixel[7]] > cb)
                if (p[pixel[8]] > cb)
                  if (p[pixel[10]] > cb)
                    if (p[pixel[6]] > cb)
                      if (p[pixel[5]] > cb)
                        if (p[pixel[4]] > cb)
                          if (p[pixel[3]] > cb)
                          {
                          }
                          else if (p[pixel[11]] > cb)
                            if (p[pixel[12]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[11]] > cb)
                          if (p[pixel[12]] > cb)
                            if (p[pixel[13]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[11]] > cb)
                        if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                            if (p[pixel[14]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                            if (p[pixel[15]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[9]] < c_b)
              if (p[pixel[10]] < c_b)
                if (p[pixel[11]] < c_b)
                  if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                        {
                        }
                        else if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                            if (p[pixel[8]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[5]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                            if (p[pixel[8]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[4]] < c_b)
                      if (p[pixel[5]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                            if (p[pixel[8]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[3]] < c_b)
                    if (p[pixel[4]] < c_b)
                      if (p[pixel[5]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                            if (p[pixel[8]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[2]] < c_b)
            if (p[pixel[3]] > cb)
              if (p[pixel[10]] > cb)
                if (p[pixel[7]] > cb)
                  if (p[pixel[8]] > cb)
                    if (p[pixel[9]] > cb)
                      if (p[pixel[11]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[5]] > cb)
                            if (p[pixel[4]] > cb)
                            {
                            }
                            else if (p[pixel[12]] > cb)
                              if (p[pixel[13]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else if (p[pixel[12]] > cb)
                            if (p[pixel[13]] > cb)
                              if (p[pixel[14]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                            if (p[pixel[14]] > cb)
                              if (p[pixel[15]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[10]] < c_b)
                if (p[pixel[11]] < c_b)
                  if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                        {
                        }
                        else if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                            if (p[pixel[8]] < c_b)
                              if (p[pixel[9]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[5]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                            if (p[pixel[8]] < c_b)
                              if (p[pixel[9]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[4]] < c_b)
                      if (p[pixel[5]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                            if (p[pixel[8]] < c_b)
                              if (p[pixel[9]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[3]] < c_b)
              if (p[pixel[4]] > cb)
                if (p[pixel[13]] > cb)
                  if (p[pixel[7]] > cb)
                    if (p[pixel[8]] > cb)
                      if (p[pixel[9]] > cb)
                        if (p[pixel[10]] > cb)
                          if (p[pixel[11]] > cb)
                            if (p[pixel[12]] > cb)
                              if (p[pixel[6]] > cb)
                                if (p[pixel[5]] > cb)
                                {
                                }
                                else if (p[pixel[14]] > cb)
                                {
                                }
                                else
                                  continue;
                              else if (p[pixel[14]] > cb)
                                if (p[pixel[15]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[13]] < c_b)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                            if (p[pixel[9]] > cb)
                              if (p[pixel[10]] > cb)
                                if (p[pixel[12]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                        {
                        }
                        else if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                            if (p[pixel[8]] < c_b)
                              if (p[pixel[9]] < c_b)
                                if (p[pixel[10]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[5]] < c_b)
                        if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                            if (p[pixel[8]] < c_b)
                              if (p[pixel[9]] < c_b)
                                if (p[pixel[10]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[5]] > cb)
                  if (p[pixel[6]] > cb)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                        if (p[pixel[9]] > cb)
                          if (p[pixel[10]] > cb)
                            if (p[pixel[11]] > cb)
                              if (p[pixel[12]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[4]] < c_b)
                if (p[pixel[5]] > cb)
                  if (p[pixel[14]] > cb)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                        if (p[pixel[9]] > cb)
                          if (p[pixel[10]] > cb)
                            if (p[pixel[11]] > cb)
                              if (p[pixel[12]] > cb)
                                if (p[pixel[13]] > cb)
                                  if (p[pixel[6]] > cb)
                                  {
                                  }
                                  else if (p[pixel[15]] > cb)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[14]] < c_b)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                            if (p[pixel[9]] > cb)
                              if (p[pixel[10]] > cb)
                                if (p[pixel[11]] > cb)
                                  if (p[pixel[13]] > cb)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[15]] < c_b)
                        {
                        }
                        else if (p[pixel[6]] < c_b)
                          if (p[pixel[7]] < c_b)
                            if (p[pixel[8]] < c_b)
                              if (p[pixel[9]] < c_b)
                                if (p[pixel[10]] < c_b)
                                  if (p[pixel[11]] < c_b)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[6]] > cb)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                        if (p[pixel[9]] > cb)
                          if (p[pixel[10]] > cb)
                            if (p[pixel[11]] > cb)
                              if (p[pixel[12]] > cb)
                                if (p[pixel[13]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[5]] < c_b)
                  if (p[pixel[6]] > cb)
                    if (p[pixel[15]] < c_b)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                            if (p[pixel[9]] > cb)
                              if (p[pixel[10]] > cb)
                                if (p[pixel[11]] > cb)
                                  if (p[pixel[12]] > cb)
                                    if (p[pixel[14]] > cb)
                                    {
                                    }
                                    else
                                      continue;
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                        if (p[pixel[9]] > cb)
                          if (p[pixel[10]] > cb)
                            if (p[pixel[11]] > cb)
                              if (p[pixel[12]] > cb)
                                if (p[pixel[13]] > cb)
                                  if (p[pixel[14]] > cb)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[6]] < c_b)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[8]] > cb)
                          if (p[pixel[9]] > cb)
                            if (p[pixel[10]] > cb)
                              if (p[pixel[11]] > cb)
                                if (p[pixel[12]] > cb)
                                  if (p[pixel[13]] > cb)
                                    if (p[pixel[15]] > cb)
                                    {
                                    }
                                    else
                                      continue;
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                      {
                      }
                      else if (p[pixel[15]] < c_b)
                      {
                      }
                      else
                        continue;
                    else if (p[pixel[14]] < c_b)
                      if (p[pixel[15]] < c_b)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[13]] > cb)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                        if (p[pixel[9]] > cb)
                          if (p[pixel[10]] > cb)
                            if (p[pixel[11]] > cb)
                              if (p[pixel[12]] > cb)
                                if (p[pixel[14]] > cb)
                                  if (p[pixel[15]] > cb)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[13]] < c_b)
                    if (p[pixel[14]] < c_b)
                      if (p[pixel[15]] < c_b)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[12]] > cb)
                  if (p[pixel[7]] > cb)
                    if (p[pixel[8]] > cb)
                      if (p[pixel[9]] > cb)
                        if (p[pixel[10]] > cb)
                          if (p[pixel[11]] > cb)
                            if (p[pixel[13]] > cb)
                              if (p[pixel[14]] > cb)
                                if (p[pixel[6]] > cb)
                                {
                                }
                                else if (p[pixel[15]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[12]] < c_b)
                  if (p[pixel[13]] < c_b)
                    if (p[pixel[14]] < c_b)
                      if (p[pixel[15]] < c_b)
                      {
                      }
                      else if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                            if (p[pixel[9]] < c_b)
                              if (p[pixel[10]] < c_b)
                                if (p[pixel[11]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[11]] > cb)
                if (p[pixel[7]] > cb)
                  if (p[pixel[8]] > cb)
                    if (p[pixel[9]] > cb)
                      if (p[pixel[10]] > cb)
                        if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                            if (p[pixel[6]] > cb)
                              if (p[pixel[5]] > cb)
                              {
                              }
                              else if (p[pixel[14]] > cb)
                              {
                              }
                              else
                                continue;
                            else if (p[pixel[14]] > cb)
                              if (p[pixel[15]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[11]] < c_b)
                if (p[pixel[12]] < c_b)
                  if (p[pixel[13]] < c_b)
                    if (p[pixel[14]] < c_b)
                      if (p[pixel[15]] < c_b)
                      {
                      }
                      else if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                            if (p[pixel[9]] < c_b)
                              if (p[pixel[10]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                            if (p[pixel[9]] < c_b)
                              if (p[pixel[10]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[10]] > cb)
              if (p[pixel[7]] > cb)
                if (p[pixel[8]] > cb)
                  if (p[pixel[9]] > cb)
                    if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                        if (p[pixel[6]] > cb)
                          if (p[pixel[5]] > cb)
                            if (p[pixel[4]] > cb)
                            {
                            }
                            else if (p[pixel[13]] > cb)
                            {
                            }
                            else
                              continue;
                          else if (p[pixel[13]] > cb)
                            if (p[pixel[14]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                            if (p[pixel[15]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[10]] < c_b)
              if (p[pixel[11]] < c_b)
                if (p[pixel[12]] < c_b)
                  if (p[pixel[13]] < c_b)
                    if (p[pixel[14]] < c_b)
                      if (p[pixel[15]] < c_b)
                      {
                      }
                      else if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                            if (p[pixel[9]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                            if (p[pixel[9]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[4]] < c_b)
                    if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                            if (p[pixel[9]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[9]] > cb)
            if (p[pixel[7]] > cb)
              if (p[pixel[8]] > cb)
                if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[6]] > cb)
                      if (p[pixel[5]] > cb)
                        if (p[pixel[4]] > cb)
                          if (p[pixel[3]] > cb)
                          {
                          }
                          else if (p[pixel[12]] > cb)
                          {
                          }
                          else
                            continue;
                        else if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[9]] < c_b)
            if (p[pixel[10]] < c_b)
              if (p[pixel[11]] < c_b)
                if (p[pixel[12]] < c_b)
                  if (p[pixel[13]] < c_b)
                    if (p[pixel[14]] < c_b)
                      if (p[pixel[15]] < c_b)
                      {
                      }
                      else if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[4]] < c_b)
                    if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[3]] < c_b)
                  if (p[pixel[4]] < c_b)
                    if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[8]] > cb)
          if (p[pixel[7]] > cb)
            if (p[pixel[9]] > cb)
              if (p[pixel[10]] > cb)
                if (p[pixel[6]] > cb)
                  if (p[pixel[5]] > cb)
                    if (p[pixel[4]] > cb)
                      if (p[pixel[3]] > cb)
                        if (p[pixel[2]] > cb)
                        {
                        }
                        else if (p[pixel[11]] > cb)
                        {
                        }
                        else
                          continue;
                      else if (p[pixel[11]] > cb)
                        if (p[pixel[12]] > cb)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[11]] > cb)
                  if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[8]] < c_b)
          if (p[pixel[9]] < c_b)
            if (p[pixel[10]] < c_b)
              if (p[pixel[11]] < c_b)
                if (p[pixel[12]] < c_b)
                  if (p[pixel[13]] < c_b)
                    if (p[pixel[14]] < c_b)
                      if (p[pixel[15]] < c_b)
                      {
                      }
                      else if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[4]] < c_b)
                    if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[3]] < c_b)
                  if (p[pixel[4]] < c_b)
                    if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[2]] < c_b)
                if (p[pixel[3]] < c_b)
                  if (p[pixel[4]] < c_b)
                    if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                        {
                        }
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else
          continue;
      else if (p[pixel[7]] > cb)
        if (p[pixel[8]] > cb)
          if (p[pixel[9]] > cb)
            if (p[pixel[6]] > cb)
              if (p[pixel[5]] > cb)
                if (p[pixel[4]] > cb)
                  if (p[pixel[3]] > cb)
                    if (p[pixel[2]] > cb)
                      if (p[pixel[1]] > cb)
                      {
                      }
                      else if (p[pixel[10]] > cb)
                      {
                      }
                      else
                        continue;
                    else if (p[pixel[10]] > cb)
                      if (p[pixel[11]] > cb)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[10]] > cb)
                    if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[10]] > cb)
                if (p[pixel[11]] > cb)
                  if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[10]] > cb)
              if (p[pixel[11]] > cb)
                if (p[pixel[12]] > cb)
                  if (p[pixel[13]] > cb)
                    if (p[pixel[14]] > cb)
                      if (p[pixel[15]] > cb)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else
          continue;
      else if (p[pixel[7]] < c_b)
        if (p[pixel[8]] < c_b)
          if (p[pixel[9]] < c_b)
            if (p[pixel[6]] < c_b)
              if (p[pixel[5]] < c_b)
                if (p[pixel[4]] < c_b)
                  if (p[pixel[3]] < c_b)
                    if (p[pixel[2]] < c_b)
                      if (p[pixel[1]] < c_b)
                      {
                      }
                      else if (p[pixel[10]] < c_b)
                      {
                      }
                      else
                        continue;
                    else if (p[pixel[10]] < c_b)
                      if (p[pixel[11]] < c_b)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[10]] < c_b)
                    if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[10]] < c_b)
                if (p[pixel[11]] < c_b)
                  if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[10]] < c_b)
              if (p[pixel[11]] < c_b)
                if (p[pixel[12]] < c_b)
                  if (p[pixel[13]] < c_b)
                    if (p[pixel[14]] < c_b)
                      if (p[pixel[15]] < c_b)
                      {
                      }
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else
          continue;
      else
        continue;
      // if(num_corners == rsize)
      // {
      // 	rsize*=2;
      // 	ret_corners = (xy*)realloc(ret_corners, sizeof(xy)*rsize);
      // }
      // cout << "x = " << x << endl;
      // cout << "y = " << y << endl;
      // ret_corners[num_corners].x = x;
      // ret_corners[num_corners].y = y;

      posxy.x = x;
      posxy.y = y;
      ret_corners.push_back(posxy);
      num_corners++;
    }

  *ret_num_corners = num_corners;
  return ret_corners;
}
