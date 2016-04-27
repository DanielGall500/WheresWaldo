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

std::string imgFile = "/Users/dannyg/Desktop/WheresWaldoImageFinder/Resources/Wheres-Waldo.jpg";
std::string imgName = "Original", resultName = "Result";

std::string templFile =
"/Users/dannyg/Desktop/WheresWaldoImageFinder/Resources/WheresWaldoBasicTemp.jpg";

Mat img, gry_img, templ, gry_templ, result;

int match_method, max_Trackbar = 5;

void MatchingMethod(int, void*);

int main(int argc, const char * argv[]) {
    
    img = imread(imgFile, 1);
    templ = imread(templFile, 1);
    
    namedWindow(imgName, CV_WINDOW_AUTOSIZE);
    namedWindow(resultName, CV_WINDOW_AUTOSIZE);
    
    std::string trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED\n 4: TM COEFF \n 5: TM COEFF NORMED";

    //When a change is detected, MatchingMethod is called
    createTrackbar(trackbar_label, imgName, &match_method, max_Trackbar, MatchingMethod);
    
    MatchingMethod(0,0);
    
    waitKey();
    return 0;
}

void MatchingMethod(int, void*) {
    Mat img_display;
    
    img.copyTo(img_display);
    
    //Stores the matching template location results, creating result matrix
    int result_cols = img.cols - templ.cols + 1;
    int result_rows = img.rows - templ.rows + 1;
    
    result.create(result_rows, result_cols, CV_32FC1);
    
    matchTemplate(img, templ, result, match_method);
    normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
    
    double minVal, maxVal;
    Point minLoc, maxLoc;
    Point matchLoc;
    
    //Localize minimum and maximum values in the result matrix
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
    
    if(match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED)
    { matchLoc = minLoc; }
    else { matchLoc = maxLoc; }
    
    rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows),
              Scalar::all(0), 2, 8, 0);
    
    rectangle(result, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);
    
    imshow(imgName, img_display);
    imshow(resultName, result);
    
    return;
}

























