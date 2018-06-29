#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/video/tracking.hpp>
#include "math.h"



std::vector<cv::Point3d> markpoint(const cv::Mat io ,const cv::Mat ig,int mmin ,int mmax)
{
	// Open 

	std::vector<cv::Point2f> features;
	const int MAX_COUNT = 100;
	cv::Size winSize(10,10);

    cv::Mat image =io;
    cv::Mat image2 = io;
    cv::Mat imagem = io;
    cv::Mat imagegray = ig;
	
	double total=0;
	for(int i=0; i<imagegray.cols ;i++)
	{
		for(int j=0 ;j<imagegray.rows ; j++)
		{
			total=total+imagegray.at<uchar>(j,i);
		}
	}
	total=total/(imagegray.rows*imagegray.cols)+15;
	std::cout <<"阀值"<<total;
	cv::threshold(imagegray,imagegray,total,255,cv::THRESH_BINARY);
	
	cv::namedWindow("image");
	cv::imshow ("image",image);

	cv::namedWindow("gray");
	cv::imshow ("gray",imagegray);

	cv::waitKey ();
	cv::destroyWindow("image") ;
	cv::destroyWindow("gray") ;
	//找轮廓
	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(imagegray, 
		contours, // a vector of contours 
		CV_RETR_EXTERNAL, // retrieve the external contours
		CV_CHAIN_APPROX_NONE); // retrieve all pixels of each contours

	std::cout << "Contours: " << contours.size() << std::endl;
	std::vector<std::vector<cv::Point>>::const_iterator itContours= contours.begin();
	for ( ; itContours!=contours.end(); ++itContours) {

		std::cout << "Size: " << itContours->size() << std::endl;
	}

	int cmin=mmin;  // minimum contour length
	int cmax=mmax; // maximum contour length
	std::vector<std::vector<cv::Point>>::const_iterator itc= contours.begin();
	while (itc!=contours.end()) {

		if (itc->size() < cmin || itc->size() > cmax)
			itc= contours.erase(itc);
		else 
			++itc;
	}
	std::cout << "剩下的 \n";
	std::vector<std::vector<cv::Point>>::const_iterator its= contours.begin();
	for ( ; its!=contours.end(); ++its) {

		std::cout << "Size: " << its->size() << std::endl;
	}
	cv::Mat result(image.size(),CV_8U,cv::Scalar(0));
	cv::drawContours(result,contours,
		-1, // draw all contours
		cv::Scalar(255), // in black
		5); // with a thickness of 2
    cv::namedWindow("Contours");
	cv::imshow("Contours",result);
	cv::waitKey();
	cv::destroyWindow("Contours") ;
	//我找到了三个小三角，
	cv::goodFeaturesToTrack(result, features, MAX_COUNT, 0.3, 30, cv::Mat(), 3, false, 0.04);
	
	std::cout<<"未精简\n";
	std::vector<cv::Point2f>::const_iterator ita= features.begin();
	int g=4;
	for( int i=0; ita != features.end(); ++ita,i++)
	{
    std::cout<<"第"<<i+1<<"点：";
	std::cout<<"X="<<features[i].x<<";Y="<<features[i].y<<"\n";
	cv::rectangle (image2, cv::Rect ((int)features[i].x-g, (int)features[i].y-g,g*2,g*2), cvScalar(255,255,255),3);
	}
	cv::namedWindow("粗分");
	cv::imshow ("粗分",image2);
	cv::waitKey ();
	cv::destroyWindow("粗分") ;
	cv::cornerSubPix (result,features,winSize,cv::Size(-1,-1),
		cv::TermCriteria(cv::TermCriteria::MAX_ITER +
		cv::TermCriteria::EPS,
		30, // max number of iterations
		0.000001)); // min accuracy
	std::cout<<"精简	\n";
	double x[9]={0};
	double y[9]={0};
	int s1=1, s2=4, s3=6;
	int f=4;
	cv::Mat image1 =io;
	for(int i=0; i<9 ; i++)
	{
    std::cout<<"第"<<i+1<<"点：";
	std::cout<<"X="<<features[i].x<<";Y="<<features[i].y<<"\n";

	cv::rectangle (image1, cv::Rect ((int)features[i].x-f, (int)features[i].y-f,2*f,2*f), cvScalar(255,0,0),3);
	
	 
	if(x[0]==0 && y[0]==0)
	  {
		x[0]=features[i].x;
		y[0]=features[i].y;
		cv::rectangle (image, cv::Rect ((int)features[i].x-4, (int)features[i].y-4,8,8), cvScalar(255,0,0),2);
	  }
	
	else if (abs(x[0]-features[i].x)<200 && abs(y[0]-features[i].y)<200&&s1<3)
      {
		x[s1]=features[i].x;
		y[s1]=features[i].y; 
		s1++;
		cv::rectangle (image, cv::Rect ((int)features[i].x-4, (int)features[i].y-4,8,8), cvScalar(255,0,0),2);
	  }
	else if (x[3]==0 && y[3]==0)
	  {
		x[3]=features[i].x;
		y[3]=features[i].y;
		cv::rectangle (image, cv::Rect ((int)features[i].x-8, (int)features[i].y-4,8,8), cvScalar(0,255,0),2);
	  }
	else if (abs(x[3]-features[i].x)<200 && abs(y[3]-features[i].y)<200 && s2<6)
      {
		x[s2]=features[i].x;
		y[s2]=features[i].y; 
		s2++;
		cv::rectangle (image, cv::Rect ((int)features[i].x-4, (int)features[i].y-4,8,8), cvScalar(0,255,0),2);
	  }
	else
	  {
		x[s3]=features[i].x;
		y[s3]=features[i].y; 
		s3++;
		cv::rectangle (image, cv::Rect ((int)features[i].x-4, (int)features[i].y-4,8,8), cvScalar(0,0,255),2);
	  }
	}

	std::cout<<"分类\n";
	for(int i=0; i<9 ; i++)
	{
    std::cout<<"第"<<(i/3)+1<<"组点：";
	std::cout<<"X"<<i<<"="<<x[i]<<";Y"<<i<<"="<<y[i]<<"\n";
	}
	cv::namedWindow("分类");
	cv::imshow ("分类",image);
	
	cv::namedWindow("细分");
	cv::imshow ("细分",image1);
	cv::waitKey ();
	cv::destroyWindow("细分");
	cv::destroyWindow("分类");
	//计算标记点及其标量（面积）

	std::vector<cv::Point3d> mk;
	cv::Point3d mkk;
	int k = 0;

	for(int i=0; i<3 ; i++)
	{
		
		mkk.x=(x[k]+x[k+1]+x[k+2])/3;
		mkk.y=(y[k]+y[k+1]+y[k+2])/3;
		mkk.z=abs((x[k+1]-x[k])*(y[k+2]-y[k])-(x[k+2]-x[k])*(y[k+1]-y[k]));
		std::cout <<"标记点"<<i+1<<"x:"<<mkk.x<<",y:"<<mkk.y<<",面积*2:"<<mkk.z<<"\n";
		cv::rectangle (imagem, cv::Rect ((int)mkk.x-4, (int)mkk.y-4,8,8), cvScalar(0,0,255),2);
		mk.push_back(mkk);
		k=k+3;
	}
	cv::namedWindow("中心点");
	cv::imshow ("中心点",imagem);
	
	cv::waitKey ();
	cv::destroyWindow("中心点") ;

	//得到了标记点并记录
	return mk;
} 