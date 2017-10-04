#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat rawImg = imread(".//.//raw1.jpg", IMREAD_COLOR);
	// IMREAD_GRAYSCALE = 0 ��ͼ��ת��Ϊ��ͨ���Ҷ�ͼ
	// IMREAD_COLOR = 1 ����Ĭ��ֵ����ͼ��ת��Ϊ��ͨ��BGR��ɫͼ�� 
	//IMREAD_ANYDEPTH = 2 ������ͼ�����Ϊ16λ��32Ϊ�ͷ������Ӧ��ȣ�����ͼ��ת��Ϊ8λͼ�� 
	//IMREAD_ANYCOLOR = 4 ����ͼ��ԭ��ʽ�����Զ�ȡ������ܵĲ�ɫ��ʽ

	namedWindow("Readrawimage", WINDOW_AUTOSIZE);
	//WINDOW_NORMAL:���Ըı䴰�ڴ�С�������ƣ���Ҳ�ɽ�һ����������ת���ɳ��ô�С��
	//WINDOW_AUTOSIZE���������ݳ��������Զ�������С�Ҳ����ֶ����Ĵ��ڴ�С��
	//WINDOW_OPENGL������֧��OpenGL�Ĵ��ڣ�
	//WINDOW_FULLSCREEN������һ��������Ļ�Ĵ��ڣ�
	//WINDOW_FREETATIO��ͼ�񽫾�����չ��;
	//WINDOW_KEEPRATIO��ͼ������ܵ�Լ����

	//Show the rgb format
	imshow("Readrawimage", rawImg);

	//Show the gray format
	Mat grayImg;//���÷���ռ�
	cvtColor(rawImg, grayImg, CV_RGB2GRAY);
	namedWindow("Gray format image", WINDOW_AUTOSIZE);
	imshow("Gray format image", grayImg);
	imwrite("Rgn2Gray.jpg", grayImg);

	waitKey(0);

	return 0;
}