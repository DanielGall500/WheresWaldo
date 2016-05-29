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

std::string imgFile = "/Users/dannyg/Desktop/Projects/WheresWaldoImageFinder/Resources/Images/WW_Easy1.jpg";

std::string templFile =
"/Users/dannyg/Desktop/Projects/WheresWaldoImageFinder/Resources/Templates/BasicTemplateTwo.jpg";

std::string trackbarStr = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";

std::string mainWindow = "Main Window";
std::string resultWindow = "Result";

Mat img, gry_img, templ, gry_templ, result;

Mat templ_edges;

int match_method, max_Trackbar = 5;
int lowThreshold;
int ratio = 3;
int kernel_size = 3;
int maxTrackbar = 5;

void MatchingMethod(int, void*);
Mat applyCannyEdge(Mat &img);

int main(int argc, const char * argv[]) {
    
    img = imread(imgFile, 1);
    
    templ = imread(templFile, 1);
    
    templ_edges = applyCannyEdge(templ);
    
    namedWindow(mainWindow);
    namedWindow(resultWindow);
    
    createTrackbar(trackbarStr, resultWindow, &match_method, maxTrackbar, MatchingMethod);
    
    MatchingMethod(0, 0);
    
    waitKey();
    return 0;
}

void MatchingMethod(int, void*) {
    Mat display;
    
    img.copyTo(display);
    
    int resultCols = img.cols - templ.cols + 1;
    int resultRows = img.cols - templ.cols + 1;
    
    result.create(resultRows, resultCols, CV_32FC1);
    
    matchTemplate(img, templ, result, match_method);
    normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
    
    double minVal, maxVal;
    Point minLoc, maxLoc, matchLoc;
    
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc,Mat());
    
    if (match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED)
        matchLoc = minLoc;
    else
        matchLoc = maxLoc;
    
    rectangle(display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);
    rectangle(result, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8 , 0);
    
    imshow(mainWindow, display);
    imshow(resultWindow, result);
    
}

Mat applyCannyEdge(Mat &img)
{
    Mat detected_edges;
    
    blur(img, img, Size(kernel_size, kernel_size)); //Reduce noise
    
    Canny(img, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
    
    return detected_edges;
}



