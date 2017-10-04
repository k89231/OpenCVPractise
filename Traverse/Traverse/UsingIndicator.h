#pragma once
#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
using namespace std;
using namespace cv;
Mat& TraverseUsingIndicator(const Mat src, Mat& Dst)
{
	double duration, start, stop;
	start = static_cast<double>(getTickCount());

	int rows = Dst.rows;
	int columns = Dst.cols;
	for (int i = 0; i < rows; i++)
	{
		Vec3b* Ptr = Dst.ptr<Vec3b>(i);
		for (int j = 0; j < columns; j++)
		{
			Ptr[j][0] = src.ptr<Vec3b>(i)[j][0];
			Ptr[j][1] = src.ptr<Vec3b>(i)[j][1];
			Ptr[j][2] = src.ptr<Vec3b>(i)[j][2];
		}
	}

	stop = static_cast<double>(getTickCount());
	duration = ((double)(stop - start)) / getTickFrequency();
	cout << "Traverse using indicator costs " << duration << " seconds." << endl;

	return Dst;
}