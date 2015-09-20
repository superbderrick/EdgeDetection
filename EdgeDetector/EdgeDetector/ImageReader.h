//
//  ImageReader.h
//  EdgeDetector
//
//  Created by 강진영 on 9/13/15.
//  Copyright (c) 2015 sensation. All rights reserved.
//

#ifndef __EdgeDetector__ImageReader__
#define __EdgeDetector__ImageReader__

#include <stdio.h>
#include <string.h>

#include "GuideTable.h"


class ImageReader
{
    
private:
    GuideTable * guideTable;
    char * mFileName;
    int  mWidth;
    int  mHeight;
    
    std::multimap< int, int> lastNumbMap;

    unsigned int  ** arr;
    
public:
    ImageReader();
    ImageReader(char * fileName , unsigned int width , unsigned int height );
    ~ImageReader();
    
    int ** finalImage;
    unsigned char ** inputImage;
    unsigned char ** getImageData(unsigned char ** data);
    
    unsigned char ** allocateBinarizationImage( int width,  int height);
    int ** allocateEdgeImage( int width,  int height);
    
    void readfile(char *filename, unsigned char **source, int width, int height);
    void Writefile(char *filename, unsigned char **result, int ** finalImage,int width, int height);
    void start();
    
};

#endif /* defined(__EdgeDetector__ImageReader__) */
