#ifndef ORB_H
#define ORB_H
#include <opencv2/opencv.hpp>
#include "fast/fast.hpp"

using namespace std;

const double pi = 3.1415926;
typedef vector<bool> DescType; // 256 bools
typedef struct
{
    int queryIdx; //!< query descriptor index
    int trainIdx; //!< train descriptor index
    int imgIdx;   //!< train image index

    float distance;
} DMatch;

void computeAngle(const byte *im, int cols, int rows, int bytes_per_row, vector<KeyPoint> &keypoints);

void computeORBDesc(const byte *im, int cols, int rows, int bytes_per_row, vector<KeyPoint> &keypoints, vector<DescType> &desc);

void bfMatch(const vector<DescType> &desc1, const vector<DescType> &desc2, vector<DMatch> &matches);

#endif