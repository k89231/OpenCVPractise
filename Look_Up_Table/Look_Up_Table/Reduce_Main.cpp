#include<iostream>
#include<opencv2\highgui.hpp>
#include<opencv2\core.hpp>
#include<opencv2\imgproc.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat RawImg = imread("raw1.jpg", IMREAD_COLOR);
	imshow("Raw", RawImg);
	waitKey(0);
	int CompressWidth = 0;
	cout << "Input the width for dividing"; //用以压缩的空间宽度（像素值 = (像素值/width) * width，width为整数
	cin >> CompressWidth;

	if (!CompressWidth) //显然要使宽度为正整数
	{
		cout << "The width is illegal!" << endl;
		return -1;
	}
	Mat DstImg;
	DstImg.create(RawImg.size(), RawImg.type());
	uchar* LUTable = new uchar[256];
	Mat lut(1, 256, CV_8U);                 //创建Look-up table
	

	for (int i = 0; i < 256; i++)
		lut.data[i] = CompressWidth * (i / CompressWidth);
	LUT(RawImg, lut, DstImg);
	imshow("After compressing using LUT", DstImg);
	waitKey(0);
	
	return 0;
}