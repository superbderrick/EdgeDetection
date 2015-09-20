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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#include "GuideTable.h"


class ImageReader
{
    
private:
    GuideTable * guideTable;
    char * mFileName;
    
    int  mWidth;
    int  mHeight;
    int mMode;
    
    //test
    std::multimap< int, int> lastNumbMap;
    unsigned int  ** arr;
    
    void showDeck();
    
public:
    ImageReader();
    ImageReader(char * fileName , unsigned int width , unsigned int height ,unsigned int mode );
    ~ImageReader();
    
    int ** finalImage;
    unsigned char ** inputImage;
    unsigned char ** outputImage;
    int ** IntermediateImage;
    
    unsigned char ** getImageData(unsigned char ** data);
    
    unsigned char ** allocateBinarizationImage( int width,  int height);
    
    int ** allocateEdgeImage( int width,  int height);
    
    void readfile(char *filename, unsigned char **source, int width, int height);
    
    
    
    
    void start();
    
    // algorsim
    void makeBinarizationImage(unsigned char **result, int ** finalImage,int width, int height);
    void makeAppliedThresholdAlgorithmImage(unsigned char **result, int ** finalImage,int width, int height);
    void makeAppliedNormalAlgorithmImage( unsigned char **result, int ** finalImage,int width, int height , int** inter);
    void makeAppliedSobelAlgorithmImage( unsigned char **result, unsigned char **output,int width, int height);
};

#endif /* defined(__EdgeDetector__ImageReader__) */
