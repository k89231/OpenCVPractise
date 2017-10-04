#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat rawImg = imread(".//.//raw1.jpg", IMREAD_COLOR);
	// IMREAD_GRAYSCALE = 0 将图像转换为单通道灰度图
	// IMREAD_COLOR = 1 函数默认值，将图像转化为三通道BGR彩色图像 
	//IMREAD_ANYDEPTH = 2 若载入图像深度为16位或32为就返回其对应深度，否则将图像转换为8位图像 
	//IMREAD_ANYCOLOR = 4 保持图像原格式，可以读取任意可能的彩色格式

	namedWindow("Readrawimage", WINDOW_AUTOSIZE);
	//WINDOW_NORMAL:可以改变窗口大小（无限制），也可将一个满屏窗口转换成常用大小；
	//WINDOW_AUTOSIZE：程序会根据呈现内容自动调整大小且不能手动更改窗口大小；
	//WINDOW_OPENGL：创建支持OpenGL的窗口；
	//WINDOW_FULLSCREEN：创建一个充满屏幕的窗口；
	//WINDOW_FREETATIO：图像将尽可能展开;
	//WINDOW_KEEPRATIO：图像比例受到约束。

	//Show the rgb format
	imshow("Readrawimage", rawImg);

	//Show the gray format
	Mat grayImg;//不用分配空间
	cvtColor(rawImg, grayImg, CV_RGB2GRAY);
	namedWindow("Gray format image", WINDOW_AUTOSIZE);
	imshow("Gray format image", grayImg);
	imwrite("Rgn2Gray.jpg", grayImg);

	waitKey(0);

	return 0;
}