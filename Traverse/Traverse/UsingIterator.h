#pragma once
#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
using namespace std;
using namespace cv;
Mat& TraverseUsingIterator(const Mat src, Mat& Dst)
{
	double duration, start, stop;
	start = static_cast<double>(getTickCount());

	MatIterator_<Vec3b> Dstit, Dstend;
	MatConstIterator_<Vec3b> Srcit, Srcend;        //源数据应采用const iterator
	for (Srcit = src.begin<Vec3b>(), Srcend = src.end<Vec3b>(), Dstit = Dst.begin<Vec3b>(), Dstend = Dst.end<Vec3b>();
		(Srcit != Srcend) && (Dstit != Dstend); Srcit++, Dstit++)
	{
		Dstit[0] = Srcit[0];
		Dstit[1] = Srcit[1];
		Dstit[2] = Srcit[2];
	}
	stop = static_cast<double>(getTickCount());
	duration = ((double)(stop - start)) / getTickFrequency();
	cout << "Traverse using iterator costs " << duration << " seconds." << endl;

	return Dst;
}