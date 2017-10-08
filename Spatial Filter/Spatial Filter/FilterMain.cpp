#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
using namespace std;
using namespace cv;

Mat RawImg, Gaussian, Mean, Median, Bilateral;


//Gaussian filtering
const int MaxGaussKernalWidth = 11;
const int MaxGaussKernalHeight = 11;
const int MaxGaussSigmaX = 9.0;
const int MaxGaussSigmaY = 9.0;
int CurrentGaussKernalWidth = 1;
int CurrentGaussKernalHeight = 1;
int GaussSigmaX = 1; 
int GaussSigmaY = 1;
void On_TrackBarChanged_Gaussian(int, void*);

//Mean filtering
const int MaxMeanKernalWidth = 11;
int CurrentMeanKernalWidth = 1;
void On_TrackBarChanged_Mean(int, void*);

//Median filtering
const int MaxMedianKernal = 5;
int CurrentMedianKernal = 1;
void On_TrackBarChanged_Median(int, void*);

//Bilateral filtering
const int Maxdsize = 100;
const int MaxSpaceSigma = 200;
const int MaxPixelSigma = 200;
int Currentdsize = 10;
int CurrentSpaceSigma = 20;
int CurrentPixelSigma = 20;
void On_TrackBarChanged_Bilateral(int, void*);
int main()
{
	RawImg = imread("Raw.png");
	if (!RawImg.data)
	{
		cout << "Fail to load the image!" << endl;
		return -1;
	}
	imshow("Raw Image", RawImg);
	namedWindow("Gaussian Filtering", WINDOW_AUTOSIZE);
	namedWindow("Mean Filtering", WINDOW_AUTOSIZE);
	namedWindow("Median Filtering", WINDOW_AUTOSIZE);
	namedWindow("Bilateral Filtering", WINDOW_AUTOSIZE);

	//Gaussian Filtering
	char GaussKernalWidthName[30];
	char GaussKernalHeightName[30];
	char GaussSigmaXName[30];
	char GaussSigmaYName[30];
	sprintf_s(GaussKernalWidthName, "(Width-1)/2: %d", MaxGaussKernalWidth);
	sprintf_s(GaussKernalHeightName, "(Height-1)/2: %d", MaxGaussKernalHeight);
	sprintf_s(GaussSigmaXName, "SigmaX: %d", MaxGaussSigmaX);
	sprintf_s(GaussSigmaYName, "SigmaY: %d", MaxGaussSigmaY);
	createTrackbar(GaussKernalWidthName, "Gaussian Filtering", &CurrentGaussKernalWidth, MaxGaussKernalWidth, On_TrackBarChanged_Gaussian);
	On_TrackBarChanged_Gaussian(CurrentGaussKernalWidth, 0);
	createTrackbar(GaussKernalHeightName, "Gaussian Filtering", &CurrentGaussKernalHeight, MaxGaussKernalHeight, On_TrackBarChanged_Gaussian);
	On_TrackBarChanged_Gaussian(CurrentGaussKernalHeight, 0);
	createTrackbar(GaussSigmaXName, "Gaussian Filtering", &GaussSigmaX, MaxGaussSigmaX, On_TrackBarChanged_Gaussian);
	On_TrackBarChanged_Gaussian(GaussSigmaX, 0);
	createTrackbar(GaussSigmaYName, "Gaussian Filtering", &GaussSigmaY, MaxGaussSigmaY, On_TrackBarChanged_Gaussian);
	On_TrackBarChanged_Gaussian(GaussSigmaY, 0);

	//Mean filtering
	char MeanKernalWidthName[30];
	sprintf_s(MeanKernalWidthName, "(Width-1)/2: %d", MaxMeanKernalWidth);
	createTrackbar(MeanKernalWidthName, "Mean Filtering", &CurrentMeanKernalWidth, MaxMeanKernalWidth, On_TrackBarChanged_Mean);
	On_TrackBarChanged_Mean(CurrentMeanKernalWidth, 0);

	//Median filtering
	if ((RawImg.depth() < 0) || (RawImg.depth() > 255))             //图像深度必须在0~255之间才能使用中值滤波
		return -1;
	char MedianKernalWidthName[30];
	sprintf_s(MedianKernalWidthName, "(Width-1)/2: %d", MaxMedianKernal);
	createTrackbar(MedianKernalWidthName, "Median Filtering", &CurrentMedianKernal, MaxMedianKernal, On_TrackBarChanged_Median);
	On_TrackBarChanged_Median(CurrentMedianKernal, 0);

	//Bilateral filtering
	char BilateraldsizeName[30];
	char BilateralSpaceSigmaName[30];
	char BilateralPixelSigmaName[30];
	sprintf_s(BilateraldsizeName, "邻域边长: %d", Maxdsize);
	sprintf_s(BilateralSpaceSigmaName, "SigmaSpace: %d", MaxSpaceSigma);
	sprintf_s(BilateralPixelSigmaName, "SigmaColor: %d", MaxPixelSigma);
	createTrackbar(BilateraldsizeName, "Bilateral Filtering", &Currentdsize, Maxdsize, On_TrackBarChanged_Bilateral);
	On_TrackBarChanged_Bilateral(Currentdsize, 0);
	createTrackbar(BilateralSpaceSigmaName, "Bilateral Filtering", &CurrentSpaceSigma, MaxSpaceSigma, On_TrackBarChanged_Bilateral);
	On_TrackBarChanged_Bilateral(CurrentSpaceSigma, 0);
	createTrackbar(BilateralPixelSigmaName, "Bilateral Filtering", &CurrentPixelSigma, MaxPixelSigma, On_TrackBarChanged_Bilateral);
	On_TrackBarChanged_Bilateral(CurrentPixelSigma, 0);

	waitKey(0);
	return 0;
}

void On_TrackBarChanged_Gaussian(int, void*)
{
	int width = 2 * CurrentGaussKernalWidth + 1;
	int height = 2 * CurrentGaussKernalHeight + 1;
	GaussianBlur(RawImg, Gaussian, Size(width, height), (double)GaussSigmaX, (double)GaussSigmaY);
	imshow("Gaussian Filtering", Gaussian);
}

void On_TrackBarChanged_Mean(int, void*)
{
	int width = 2 * CurrentMeanKernalWidth + 1;
	int height = 2 * CurrentMeanKernalWidth + 1;
	blur(RawImg, Mean, Size(width, height));
	imshow("Mean Filtering", Mean);
}

void On_TrackBarChanged_Median(int, void*)
{
	int KernalSize = 2 * CurrentMedianKernal + 1;
	medianBlur(RawImg, Median, KernalSize);
	imshow("Median Filtering", Median);
}

void On_TrackBarChanged_Bilateral(int, void*)
{
	bilateralFilter(RawImg, Bilateral, Currentdsize, CurrentPixelSigma, CurrentSpaceSigma);
	imshow("Bilateral Filtering", Bilateral);
}