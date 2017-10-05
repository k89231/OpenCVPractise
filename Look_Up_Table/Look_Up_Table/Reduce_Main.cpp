#include<iostream>
#include<opencv2\highgui.hpp>
#include<opencv2\core.hpp>
#include<opencv2\imgproc.hpp>
using namespace std;
using namespace cv;
Mat RawImg;
Mat DstImg;
const int MaxWidth = 100;
const int MaxAlpha = 40;
const int MaxBeta = 100;
int CurrentWidth = 1;
int CurrentAlpha = 20;
int CurrentBeta = 50;
Mat lut(1, 256, CV_8U); //´´½¨Look-up table
void OnAllTrackbar(int, void*);
int main()
{
	RawImg = imread("raw1.jpg", IMREAD_COLOR);
	imshow("Raw", RawImg);

	DstImg.create(RawImg.size(), RawImg.type());	                	



	namedWindow("Change brightness, contrast and Compress using LUT", WINDOW_AUTOSIZE);
	char AlphaBarName[50];
	char BetaBarName[50];
	char WidthBarName[50];
	sprintf_s(AlphaBarName, "Brightness %d", MaxAlpha);
	sprintf_s(BetaBarName, "Contrast %d", MaxBeta);
	sprintf_s(WidthBarName, "Width %d", MaxWidth);

	createTrackbar(AlphaBarName, "Change brightness, contrast and Compress using LUT", &CurrentAlpha, MaxAlpha, OnAllTrackbar);
	createTrackbar(BetaBarName, "Change brightness, contrast and Compress using LUT", &CurrentBeta, MaxBeta, OnAllTrackbar);
	createTrackbar(WidthBarName, "Change brightness, contrast and Compress using LUT", &CurrentWidth, MaxWidth, OnAllTrackbar);

	OnAllTrackbar(CurrentWidth, 0);
	OnAllTrackbar(CurrentAlpha, 0);
	OnAllTrackbar(CurrentBeta, 0);

	
	waitKey(0);
	
	return 0;
}
void OnAllTrackbar(int, void*)
{
	if (CurrentWidth == 0)      //The width must be larger than 0
	{
		cout << "The width is illegal!" << endl;
		return;
	}
	for (int i = 0; i < 256; i++)
		lut.data[i] = CurrentWidth * (i / CurrentWidth);
	LUT(RawImg, lut, DstImg);
	int rows = DstImg.rows; int cols = DstImg.cols;
	double DoubleAlpha = (double)CurrentAlpha / 10;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				DstImg.at<Vec3b>(i, j)[k] = saturate_cast<uchar>(DoubleAlpha * DstImg.at<Vec3b>(i, j)[k] + CurrentBeta);
			}
		}
	}
	imshow("Change brightness, contrast and Compress using LUT", DstImg);
}