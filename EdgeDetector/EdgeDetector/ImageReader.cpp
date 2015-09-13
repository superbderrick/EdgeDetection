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
    
    
    
    
    
  // todo list change to danamic array
 
};


ImageReader::~ImageReader()
{
    delete guideTable;
    delete mFileName;
};


void ImageReader::start()
{
    unsigned char testArray  [256][256];
    
    FILE *infile= fopen(mFileName,"rb");
    
    if(infile == NULL) {
        guideTable->showGuideMessage(FILE_OPEN_ERROR);
    }
    

    fread(testArray, sizeof(char),mWidth*mHeight,infile);
    fclose(infile);
    
};

