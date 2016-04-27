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

int main(int argc, const char * argv[]) {
    
    std::string imgFile = "/Users/dannyg/Desktop/WheresWaldoImageFinder/Resources/Wheres-Waldo.jpg";
    std::string templFile = ""; //GET TEMPLATE
    
    std::string imgName = "Original", resultName = "Result";
    
    Mat img, templ, result;
    
    int match_method;
    int max_Trackbar = 5;
    
    img = imread(imgFile);
    
    templ = imread(templFile);
    
    namedWindow(imgName, CV_WINDOW_AUTOSIZE);
    namedWindow(resultName, CV_WINDOW_AUTOSIZE);
    
    std::string trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED\n 4: TM COEFF \n 5: TM COEFF NORMED";

    createTrackbar(trackbar_label, imgName, &match_method, max_Trackbar, MatchingMethod);
    
    MatchingMethod(0,0);
    
    waitKey();
    return 0;
}
