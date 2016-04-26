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
    
    Mat img = imread(imgFile, CV_LOAD_IMAGE_COLOR);
    
    
}
