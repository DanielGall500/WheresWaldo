//
//  main.cpp
//  WheresWaldoImageFinder
//
//  Created by Daniel Gallagher on 26/04/2016.
//  Copyright (c) 2016 Developer Co. All rights reserved.
//
//  He is Wally where I come from but most say Waldo so...


#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

std::string imgFile = "/Users/dannyg/Desktop/Projects/WheresWaldoImageFinder/Resources/Images/WW_Easy4.jpg";
std::string imgName = "Original", resultName = "Result";

std::string templFile =
"/Users/dannyg/Desktop/WheresWaldoImageFinder/Resources/Templates/WheresWallyTemplateScreenshot.png";

Mat img, gry_img, templ, gry_templ, result;

Mat templ_edges;

int match_method, max_Trackbar = 5;
int lowThreshold;
int ratio = 3;
int kernel_size = 3;

void MatchingMethod(int, void*);
Mat applyCannyEdge(Mat &img);

int main(int argc, const char * argv[]) {
    
    img = imread(imgFile);
    templ = imread(templFile);
    
    templ_edges = applyCannyEdge(templ);
    
    waitKey();
    return 0;
}

void MatchingMethod(int, void*) {
    
}

Mat applyCannyEdge(Mat &img)
{
    Mat detected_edges;
    
    blur(img, img, Size(kernel_size, kernel_size)); //Reduce noise
    
    Canny(img, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
    
    return detected_edges;
}














