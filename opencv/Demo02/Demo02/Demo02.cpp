// Demo02.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;

void test01() {
	// ����һ��ͼƬ����Ϸԭ���� 
	Mat img = imread("E:\\1.jpg");

	Mat src = img.clone();
	Mat src1 = img.clone();
	Mat img2 = img.clone();
	/*
	// ����һ����Ϊ "��Ϸԭ��"����
	namedWindow("��Ϸԭ��");
	// �ڴ�������ʾ��Ϸԭ��
	imshow("��Ϸԭ��", img);
	// �ȴ�6000 ms�󴰿��Զ��ر�
	waitKey(6000);
	*/

	//Canny(img2, img2, 3, 9, 3);
	//Canny(img2, img2, 150, 100, 3);
	//imshow("Canny��Ե���", img2);

	/* Canny��Ե��� Begin */
	Mat dst, edge, gray;

	// ��1��������srcͬ���ͺʹ�С�ľ���(dst)   
	dst.create(src1.size(), src1.type());

	// ��2����ԭͼ��ת��Ϊ�Ҷ�ͼ��   
	cvtColor(src1, gray, CV_BGR2GRAY);

	imshow("�Ҷ�ͼ��", gray);

	// ��3������ʹ�� 3x3�ں�������   
	blur(gray, edge, Size(3, 3));

	imshow("����", edge);

	// ��4������Canny����  
	Canny(edge, edge, 3, 9, 3);

	imshow("canny����", edge);

	//��5����g_dstImage�ڵ�����Ԫ������Ϊ0    
	dst = Scalar::all(0);

	//��6��ʹ��Canny��������ı�Եͼg_cannyDetectedEdges��Ϊ���룬����ԭͼg_srcImage����Ŀ��ͼg_dstImage��   
	src1.copyTo(dst, edge);

	//��7����ʾЧ��ͼ    
	imshow("��Ч��ͼ��Canny��Ե���2", dst);

	/* canny��Ե��� END */


	/* ����Sobel������ʵ������ */
	//��0������ grad_x �� grad_y ����   
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	//��2����ʾԭʼͼ    
	imshow("��ԭʼͼ��sobel��Ե���", src);

	//��3���� X�����ݶ�   
	Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	imshow("��Ч��ͼ�� X����Sobel", abs_grad_x);

	//��4����Y�����ݶ�   
	Sobel(src, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	imshow("��Ч��ͼ��Y����Sobel", abs_grad_y);

	//��5���ϲ��ݶ�(����)   
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
	imshow("��Ч��ͼ�����巽��Sobel", dst);


	waitKey(6000000);
}

//�ı�ͼ���С
void test02() {
	//����ԭʼͼ     
	Mat srcImage = imread("E:\\1.jpg");  //����Ŀ¼��Ӧ����һ����Ϊ1.jpg���ز�ͼ  
	Mat tmpImage, dstImage1, dstImage2;//��ʱ������Ŀ��ͼ�Ķ���  
	tmpImage = srcImage;//��ԭʼͼ������ʱ����  

						//��ʾԭʼͼ    
	imshow("��ԭʼͼ��", srcImage);

	//���гߴ��������  
	resize(tmpImage, dstImage1, Size(tmpImage.cols / 2, tmpImage.rows / 2), (0, 0), (0, 0), 3);
	resize(tmpImage, dstImage2, Size(tmpImage.cols * 2, tmpImage.rows * 2), (0, 0), (0, 0), 3);

	//��ʾЧ��ͼ    
	imshow("��Ч��ͼ��֮һ", dstImage1);
	imshow("��Ч��ͼ��֮��", dstImage2);

	waitKey(1000000);
}
//pyrUP����ʾ��
void test03() {
	//����ԭʼͼ     
	Mat srcImage = imread("E:\\1.jpg");  //����Ŀ¼��Ӧ����һ����Ϊ1.jpg���ز�ͼ  
	Mat tmpImage, dstImage;//��ʱ������Ŀ��ͼ�Ķ���  
	tmpImage = srcImage;//��ԭʼͼ������ʱ����  

						//��ʾԭʼͼ    
	imshow("��ԭʼͼ��", srcImage);
	//��������ȡ������  
	pyrUp(tmpImage, dstImage, Size(tmpImage.cols * 2, tmpImage.rows * 2));
	//��ʾЧ��ͼ    
	imshow("��Ч��ͼ��", dstImage);

	waitKey(99999990);
}

//
void test04() {
	Mat srcImage = imread("E:\\2.jpg");
	imshow("ԭʼͼ", srcImage);
	waitKey(99999990);
}

int main() {
	Mat srcImage = imread("E:\\1.jpg");
	imshow("��ԭʼͼ��", srcImage);
	//colorSplit(srcImage);

	return 0;
}