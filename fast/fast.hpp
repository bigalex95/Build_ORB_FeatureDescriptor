#ifndef FAST_H
#define FAST_H
#include <vector>

using namespace std;

typedef struct
{
    int x, y;
    float angle;
} KeyPoint;
typedef unsigned char byte;

int fast9_corner_score(const byte *p, const int pixel[], int bstart);
int fast10_corner_score(const byte *p, const int pixel[], int bstart);
int fast11_corner_score(const byte *p, const int pixel[], int bstart);
int fast12_corner_score(const byte *p, const int pixel[], int bstart);

vector<KeyPoint> fast9_detect(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners);
vector<KeyPoint> fast10_detect(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners);
vector<KeyPoint> fast11_detect(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners);
vector<KeyPoint> fast12_detect(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners);

int *fast9_score(const byte *i, int bytes_per_row, vector<KeyPoint> corners, int num_corners, int b);
int *fast10_score(const byte *i, int bytes_per_row, vector<KeyPoint> corners, int num_corners, int b);
int *fast11_score(const byte *i, int bytes_per_row, vector<KeyPoint> corners, int num_corners, int b);
int *fast12_score(const byte *i, int bytes_per_row, vector<KeyPoint> corners, int num_corners, int b);

vector<KeyPoint> fast9_detect_nonmax(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners);
vector<KeyPoint> fast10_detect_nonmax(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners);
vector<KeyPoint> fast11_detect_nonmax(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners);
vector<KeyPoint> fast12_detect_nonmax(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners);

vector<KeyPoint> nonmax_suppression(const vector<KeyPoint> corners, const int *scores, int num_corners, int *ret_num_nonmax);

#endif
