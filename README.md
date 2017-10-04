# OpenCVPractise
My OpenCV codes for Practise(2.4.13)

利用LUT进行压缩图片
-
Raw Image

![Ex1](/Markdown/LUT1.png)

使用压缩尺寸为220的Look-up Table的压缩结果

![Ex1](/Markdown/LUT2.png)

分别使用At、指针、STL迭代器遍历图像元素
-
使用3种方法计算得到的耗时

![Ex1](/Markdown/Traverse.png)

可以看出用指针进行遍历速度最快，但不安全，用OpenCV自带的迭代器(应该是继承自STL)速度最慢，但不会出现越界等危险

利用AddWeighted进行ROI区域叠加
-
源图1

![Ex1](/Markdown/ROI1.png)

源图2

![Ex1](/Markdown/ROI2.png)

各自权重分别为0.3和0.7的叠加结果(丑的一笔)

![Ex1](/Markdown/ROI3.png)