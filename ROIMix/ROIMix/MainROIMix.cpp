#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
using namespace std;
using namespace cv;
const int MaxValue = 100;
int CurrentValue = 30;
double WeightSrc1;
double WeighrSrc2;
void On_Trackbar(int, void*);
Mat src1ROI, src2ROI, src1, src2;
int main()
{
	src1 = imread("src1.jpg");
	src2 = imread("src2.jpg");
	if ((!src1.data) || (!src2.data))
	{
		cout << "Fail to load the images!" << endl;
		return -1;
	}
	int x = 60;
	int y = 60;
	int width = 100;
	int height = 100;
	src1ROI = src1(Rect(x, y, width, height));
	src2ROI = src2(Rect(178, 50, width, height));
	namedWindow("After Mixing", WINDOW_NORMAL);
	createTrackbar("Adjusting weights", "After Mixing", &CurrentValue, MaxValue, On_Trackbar);

	On_Trackbar(CurrentValue, 0);


	
	waitKey(0);

	return 0;
}

void On_Trackbar(int, void*)
{
	WeightSrc1 = (double)getTrackbarPos("Adjusting weights", "After Mixing") / MaxValue;
	WeighrSrc2 = 1.0 - WeightSrc1;
	addWeighted(src1ROI, WeightSrc1, src2ROI, WeighrSrc2, 0, src2ROI);
	imshow("After Mixing", src2);
}