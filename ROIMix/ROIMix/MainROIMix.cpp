#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat src1 = imread("src1.jpg");
	Mat src2 = imread("src2.jpg");
	if ((!src1.data) || (!src2.data))
	{
		cout << "Fail to load the images!" << endl;
		return -1;
	}
	int x = 60;
	int y = 60;
	int width = 100;
	int height = 100;
	double alpha = 0.5; double beta = 1 - alpha;
	Mat src1ROI = src1(Rect(x, y, width, height));
	Mat src2ROI = src2(Rect(178, 50, width, height));
	addWeighted(src1ROI, 0.3, src2ROI, 0.7, 0, src2ROI);
	imshow("After alpha mixing", src2);
	waitKey(0);

	return 0;
}