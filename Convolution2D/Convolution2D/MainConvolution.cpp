#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
using namespace std;
using namespace cv;
//起到锐化的效果
int main()
{
	Mat RawImg = imread("Noise1.png");
	Mat DstImg;
	if (!RawImg.data)
	{
		cout << "Fail to load the image!" << endl;
		return -1;
	}
	imshow("Raw image", RawImg);
	Mat kernal = (Mat_<char>(3, 3) << -1, -1, -1, -1, 9, -1, -1, -1, -1);
	filter2D(RawImg, DstImg, RawImg.depth(), kernal);
	imshow("After convolution", DstImg);
	waitKey(0);
	return 0;
}