#pragma once
//棋盘图 栅格图
#include "opencv.h"
    //校正
  cv::Mat cali( cv::Mat img0 , cv::Mat map1,  cv::Mat map2)
  { 
    
        
        cv::Mat img0r;
       
		cv::remap( img0, img0r, map1, map2, cv::INTER_LINEAR);
        
	    img0 = img0r;
        
	    return img0;
       
    }	


//分水岭
  cv::Mat WatershedsS(cv::Mat imgxx, cv::Mat imgx, int min ,int max)
  {
	 
	
	cv::threshold(imgx,imgx,128,255,cv::THRESH_BINARY);
    cv::Mat fg;
	cv::erode(imgx,fg,cv::Mat(),cv::Point(-1,-1),3);
    cv::namedWindow("fg");
	cv::imshow("fg",fg);
	cv::waitKey ();

	cv::Mat bg;
	cv::dilate(imgx,bg,cv::Mat(),cv::Point(-1,-1),1);
	cv::threshold(bg,bg,1,128,cv::THRESH_BINARY_INV);
    cv::namedWindow("bg");
	cv::imshow("bg",bg);
   	cv::waitKey ();

    cv::Mat markers(imgx.size(),CV_8U,cv::Scalar(0));
	markers= fg+bg;
	cv::namedWindow("Markers");
	cv::imshow("Markers",markers);
	cv::waitKey ();


	cv::Mat imgG(imgx.size(),CV_8U,cv::Scalar(0));
   
	
   
	markers.convertTo(markers,CV_32S);
    cv::watershed(imgxx,markers);
	
	imgG = markers;
	imgG.convertTo(imgG,CV_8U);

	cv::namedWindow("Segmentation");
	cv::imshow("Segmentation",imgG);
    cv::waitKey ();
	cv::destroyWindow ("fg");
	cv::destroyWindow ("bg");
	cv::destroyWindow ("Markers");
	cv::destroyWindow ("Segmentation");



	cv::threshold(imgG,imgG,150,255,cv::THRESH_BINARY_INV);
	//cv::threshold(image,image,150,255,cv::THRESH_BINARY);
	cv::namedWindow("Binary ImageG");
	cv::imshow("Binary ImageG",imgG);
   
	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(imgG, 
		contours, // a vector of contours 
		CV_RETR_EXTERNAL, // retrieve the external contours
		CV_CHAIN_APPROX_NONE); // retrieve all pixels of each contours

	// Print contours' length
	std::cout << "Contours: " << contours.size() << std::endl;
	std::vector<std::vector<cv::Point>>::const_iterator itContours= contours.begin();
	for ( ; itContours!=contours.end(); ++itContours) {

		std::cout << "Size: " << itContours->size() << std::endl;
	}
	
	int cmin= min;  // minimum contour length
	int cmax= max; // maximum contour length
	std::vector<std::vector<cv::Point>>::iterator itc= contours.begin();
	while (itc!=contours.end()) {

		if (itc->size() < cmin || itc->size() > cmax)
			itc= contours.erase(itc);
		else 
			++itc;
	}

	// draw black contours on white image
	cv::Mat result(imgG.size(),CV_8U,cv::Scalar(255));
	cv::drawContours(result,contours,
		-1, // draw all contours
		cv::Scalar(0), // in black
		-1); // with a thickness of 2

	cv::namedWindow("Contours");
	cv::imshow("Contours",result);

    cv::Mat original = imgx;
	cv::threshold(original,original,128,255,cv::THRESH_BINARY);

 
	cv::namedWindow("Contours2");
	cv::imshow("Contours2",original);  
    cv::waitKey ();
	original=original+result;
	cv::namedWindow("ContoursLAST");
	cv::imshow("ContoursLAST",original);
	cv::waitKey ();
	cv::destroyWindow ("Binary ImageG");
	cv::destroyWindow ("Contours");
	cv::destroyWindow ("ContoursLAST");
    cv::destroyWindow ("Contours2");
	return original;
  }

   double b[2000][2000];
   double c[2000][2000];