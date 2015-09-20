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

ImageReader::ImageReader(char * fileName , unsigned int width , unsigned int height , unsigned int mode )
{
    guideTable = new GuideTable();
    
    mFileName = new char();
    strcpy(mFileName , fileName);
    
    mWidth = width;
    mHeight = height;
    mMode = mode;
};


ImageReader::~ImageReader()
{
    delete guideTable;
    delete mFileName;
    delete inputImage;
    delete finalImage;
};

unsigned char**  ImageReader::getImageData(unsigned char ** data) {
    
    return NULL;
}


void ImageReader::start()
{
    inputImage = allocateBinarizationImage(mWidth,mHeight);
    finalImage = allocateEdgeImage(mWidth, mHeight);
    
    IntermediateImage = allocateEdgeImage(mWidth, mHeight);
    
    readfile(mFileName, inputImage, mWidth, mHeight);
    
    guideTable->selectedValues(mMode);
    guideTable->checkEdgeMode(mMode);
    
    switch (mMode) {
            //normal Binarization Image
        case 1:
            makeBinarizationImage(inputImage, finalImage, mWidth, mHeight);
            break;
            //compare  Imagevalue by threshold value
        case 2:
            makeAppliedThresholdAlgorithmImage(inputImage, finalImage, mWidth, mHeight);
            break;
        case 3:
            //apply normal algorism by derrick
            makeAppliedNormalAlgorithmImage(inputImage, finalImage, mWidth, mHeight, IntermediateImage);
            break;
            
        default:
            break;
    }
    
};

unsigned char ** ImageReader::allocateBinarizationImage(int width, int height)
{
    int i, j;
    unsigned char **ptr;
    
    if ((ptr = (unsigned char**)malloc(height * sizeof(unsigned char*))) == NULL) {
        guideTable->showGuideMessage(MEMORY_FAILURE);
        exit(1);
    }
    
    for (i = 0; i<height; i++)
    {
        if ((ptr[i] = (unsigned char*)malloc(width * sizeof(unsigned char))) == NULL) {
            guideTable->showGuideMessage(MEMORY_FAILURE);
            exit(1);
        }
    }
    
    for (i = 0; i<height; i++)
        for (j = 0; j<width; j++)
            ptr[i][j] = 0;
    
    guideTable->showGuideMessage(MEMORY_SUCCESS);
    
    return ptr;
}

int ** ImageReader::allocateEdgeImage(int width, int height)
{
    int i, j;
    int **edge;
    
    if ((edge = (int**)malloc(height * sizeof(int*))) == NULL) {
        guideTable->showGuideMessage(MEMORY_FAILURE);
        exit(1);
    }
    
    for (i = 0; i<height; i++)
    {
        if ((edge[i] = (int*)malloc(width * sizeof(int))) == NULL) {
            guideTable->showGuideMessage(MEMORY_FAILURE);
            exit(1);
        }
    }
    
    for (i = 0; i<height; i++)
        for (j = 0; j<width; j++)
            edge[i][j] = 0;
    
    guideTable->showGuideMessage(MEMORY_SUCCESS);
    
    return edge;
}

void ImageReader::readfile(char *filename, unsigned char **source,int width, int height)
{
    int i, j;
    FILE *file;
    
    if ((file = fopen(filename, "rb")) == NULL) {
        guideTable->showGuideMessage(FILE_OPEN_ERROR);
        exit(1);
    }
    
    for (i = 0; i<height; i++)
        for (j = 0; j<width; j++)
            source[i][j] = (unsigned char)getc(file);
    
    guideTable->showGuideMessage(FILE_OPEN_SUCCESS);
    fclose(file);
    
    guideTable->showGuideMessage(FILE_READ_SUCCESS);
    
    
}


 //////////-------------------------------------------------------------//////////////////////
// 01 just Binarization Image

void ImageReader::makeBinarizationImage(unsigned char **result, int ** finalImage,int width, int height )
{
    int i, j;
    FILE *writef;
    int value = 0;
    if ((writef = fopen("result.raw", "wb")) == NULL) {
        guideTable->showGuideMessage(FILE_OPEN_ERROR);
        exit(1);
    }
    
    for (i = 0; i<height; i++)
    {
        for (j = 0; j<width; j++)
        {
            if(result[i][j] > 128)
            {
                value = 255;
            } else
                value = 0;
            finalImage[i][j] = value;
            
             putc((unsigned char)value, writef);
        }
        
    }
};

void ImageReader::makeAppliedThresholdAlgorithmImage(unsigned char **result, int ** finalImage,int width, int height )
{
    int i, j;
    FILE *writef;
    int value = 0;
    if ((writef = fopen("result.raw", "wb")) == NULL) {
        guideTable->showGuideMessage(FILE_OPEN_ERROR);
        exit(1);
    }
    
    for (i = 0; i<height; i++)
    {
        for (j = 0; j<width; j++)
        {
            if(result[i][j] > 128)
            {
                value = 255;
            } else
                value = 0;
            finalImage[i][j] = value;
            
            putc((unsigned char)value, writef);
        }
        
    }
}




void ImageReader:: makeAppliedNormalAlgorithmImage( unsigned char **result, int ** midle,int width, int height , int ** final)
{
    int i, j;
    FILE *writef;
    int value = 0;
    if ((writef = fopen("result.raw", "wb")) == NULL) {
        guideTable->showGuideMessage(FILE_OPEN_ERROR);
        exit(1);
    }
    
    //////////-------------------------------------------------------------//////////////////////
    //Creating a primary binary file
    
    for (i = 0; i<height; i++)
    {
        for (j = 0; j<width; j++)
        {
            if(result[i][j] > 128)
            {
                value = 128;
            } else
                value = 0;
            midle[i][j] = value;
        }
        
    }
    
    
    //////////-------------------------------------------------------------//////////////////////
    
    //    alorism part.. to make edge
    int offset = 0;
    int count = 0;
    int start = 0;
    bool isData = true;
    int end = 0;
    
    int DuplicateValuesArray [65536];
    
    for (int i = 0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if(midle[i][j] == 0)
            {
                if(offset == i)
                {
                    end = j;
                    for(int k = 0 ;k < count;k++)
                    {
                        if(j == DuplicateValuesArray[k])
                        {
                            isData = false;
                            break;
                        } else
                            isData = true;
                        
                    }
                    
                    if(isData)
                    {
                        final[offset][j] = 244;
                        DuplicateValuesArray[count] = j;
                        count++;
                        isData = true;
                    }
                    
                }
                else
                {
                   
                    final[offset][end] = 244;
                    
                    offset = i;
                    start = j;
                    final[offset][start] = 244;
                    
                    DuplicateValuesArray[count] = j;
                    count++;
                }
            }
        }
    }
    
    for (i = 0; i<height; i++)
    {
        for (j = 0; j<width; j++)
        {
            putc((unsigned char)final[i][j], writef);
        }
    }
    guideTable->showGuideMessage(FILE_WRITE_SUCCESS);
    fclose(writef);
}


 //////////-------------------------------------------------------------//////////////////////






