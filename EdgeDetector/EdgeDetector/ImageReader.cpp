//
//  ImageReader.cpp
//  EdgeDetector
//
//  Created by 강진영 on 9/13/15.
//  Copyright (c) 2015 sensation. All rights reserved.
//

#include "ImageReader.h"

ImageReader::ImageReader()
{
    
};

ImageReader::ImageReader(char * fileName , unsigned int width , unsigned int height )
{
    guideTable = new GuideTable();
    mFileName = new char();
    
    strcpy(mFileName , fileName);
    mWidth = width;
    mHeight = height;
};


ImageReader::~ImageReader()
{
    delete guideTable;
    delete mFileName;
};


void ImageReader::start()
{
    int width = mWidth;
    int height = mHeight;
    
    unsigned char inputImage[width][height] ;
    
    FILE *infile= fopen(mFileName,"rb");
    
    if(infile == NULL) {
        guideTable->showGuideMessage(FILE_OPEN_ERROR);
    }
    
    
    fread(inputImage, sizeof(char),mWidth*mHeight,infile);
    fclose(infile);
    
    
    
    
};

