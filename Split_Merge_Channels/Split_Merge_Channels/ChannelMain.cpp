#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\imgproc.hpp>
#include<opencv2\highgui.hpp>
#include<vector>
using namespace std;
using namespace cv;
void AddImage(Mat& SrcImg, Mat& GrayImg, vector<Mat>AllChannels, Mat BChannel, String title);
int main()
{
	Mat src2 = imread("smaller.jpg", IMREAD_GRAYSCALE);
	Mat src1 = imread("bigger.jpg");
	if ((!src1.data) || (!src2.data))
	{
		cout << "Fail to load the images!" << endl;
		return -1;
	}
	vector<Mat> AllChannels;
	split(src1, AllChannels);
	Mat BChannel; 
	BChannel = AllChannels.at(2);
	String title = "After Merging";

	AddImage(src1, src2, AllChannels, BChannel, title);
	
	return 0;
}

void AddImage(Mat& SrcImg, Mat& GrayImg, vector<Mat>AllChannels, Mat BChannel, String title)
{
	int i = 1;
	addWeighted(BChannel(Rect(350, 150, GrayImg.cols, GrayImg.rows)), 0.9, GrayImg,
		0.2, 0.0, BChannel(Rect(350, 150, GrayImg.cols, GrayImg.rows)));

	merge(AllChannels, SrcImg);
	imshow(title, SrcImg);
	waitKey(0);
}