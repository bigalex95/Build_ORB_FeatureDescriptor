#include <stdlib.h>
#include "fast.hpp"

using namespace std;

vector<KeyPoint> fast9_detect_nonmax(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners)
{
	vector<KeyPoint> corners;
	int num_corners;
	int *scores;
	vector<KeyPoint> nonmax;

	corners = fast9_detect(im, cols, rows, bytes_per_row, b, &num_corners);
	scores = fast9_score(im, bytes_per_row, corners, num_corners, b);
	nonmax = nonmax_suppression(corners, scores, num_corners, ret_num_corners);

	corners = vector<KeyPoint>();
	free(scores);

	return nonmax;
}

vector<KeyPoint> fast10_detect_nonmax(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners)
{
	vector<KeyPoint> corners;
	int num_corners;
	int *scores;
	vector<KeyPoint> nonmax;

	corners = fast10_detect(im, cols, rows, bytes_per_row, b, &num_corners);
	scores = fast10_score(im, bytes_per_row, corners, num_corners, b);
	nonmax = nonmax_suppression(corners, scores, num_corners, ret_num_corners);

	corners = vector<KeyPoint>();
	free(scores);

	return nonmax;
}

vector<KeyPoint> fast11_detect_nonmax(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners)
{
	vector<KeyPoint> corners;
	int num_corners;
	int *scores;
	vector<KeyPoint> nonmax;

	corners = fast11_detect(im, cols, rows, bytes_per_row, b, &num_corners);
	scores = fast11_score(im, bytes_per_row, corners, num_corners, b);
	nonmax = nonmax_suppression(corners, scores, num_corners, ret_num_corners);

	corners = vector<KeyPoint>();
	free(scores);

	return nonmax;
}

vector<KeyPoint> fast12_detect_nonmax(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners)
{
	vector<KeyPoint> corners;
	int num_corners;
	int *scores;
	vector<KeyPoint> nonmax;

	corners = fast12_detect(im, cols, rows, bytes_per_row, b, &num_corners);
	scores = fast12_score(im, bytes_per_row, corners, num_corners, b);
	nonmax = nonmax_suppression(corners, scores, num_corners, ret_num_corners);

	corners = vector<KeyPoint>();
	free(scores);

	return nonmax;
}
