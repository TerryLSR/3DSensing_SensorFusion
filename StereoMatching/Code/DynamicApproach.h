#pragma once
#ifndef  __DYNAMIC__
#define __DYNAMIC__

#include <opencv2/opencv.hpp>
#include <iostream>
#include <omp.h>
#include <Windows.h>

class Dynamic {
public:
	Dynamic(cv::Mat& image1, cv::Mat& image2, int window_size, float weight, int dmin,
			double focal_length, double baseline, double cx_d, double cy_d, double doffs);
	void DynamicApproachCalculation();

private:
	int winSize, dmin;
	double cx_d, cy_d, doffs, focal_length, baseline;
	float occlusion;
	cv::Mat img1, img2;

	float DisparitySpaceImage(int row, int lr, int rr);
	
	enum MatchParams
	{
		Match = 0,				
		LeftOcc = 1,
		RightOcc = 2
	};
};

#endif // ! __DYNAMIC__

