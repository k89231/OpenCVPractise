#pragma once
#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
using namespace std;
using namespace cv;
Mat& TraverseUsingAt(const Mat src, Mat& Dst)
{
	double duration, start, stop;
	start = static_cast<double>(getTickCount());

	int rows = Dst.rows;
	int columns = Dst.cols;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			Dst.at<Vec3b>(i, j)[0] = src.at<Vec3b>(i, j)[0];
			Dst.at<Vec3b>(i, j)[1] = src.at<Vec3b>(i, j)[1];
			Dst.at<Vec3b>(i, j)[2] = src.at<Vec3b>(i, j)[2];
		}
	}

	stop = static_cast<double>(getTickCount());
	duration = ((double)(stop - start)) / getTickFrequency();
	cout << "Traverse using At costs " << duration << " seconds." << endl;

	return Dst;
}