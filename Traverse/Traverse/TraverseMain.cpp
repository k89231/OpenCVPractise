#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
#include "UsingAt.h"
#include "UsingIndicator.h"
#include "UsingIterator.h"
using namespace std;
using namespace cv;

int main()
{
	Mat RawImg = imread("raw1.jpg");
	Mat AtImg = cvCreateMat(RawImg.rows, RawImg.cols, RawImg.type());
	Mat IndicatorImg = cvCreateMat(RawImg.rows, RawImg.cols, RawImg.type());
	Mat IteratorImg = cvCreateMat(RawImg.rows, RawImg.cols, RawImg.type());
	
	AtImg = TraverseUsingAt(RawImg, AtImg);
	IndicatorImg = TraverseUsingIndicator(RawImg, IndicatorImg);
	IteratorImg = TraverseUsingIterator(RawImg, IteratorImg);


	imshow("Using at", AtImg);
	imshow("Using indicator", IndicatorImg);
	imshow("Using iterator", IteratorImg);
	waitKey(0);

	return 0;
}