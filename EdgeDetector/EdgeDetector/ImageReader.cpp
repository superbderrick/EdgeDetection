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
    mHeight =  height;
    
    
};


ImageReader::~ImageReader()
{
    delete guideTable;
    delete mFileName;
};

unsigned char**  ImageReader::getImageData(unsigned char ** data) {
    
    return NULL;
}


void ImageReader::start()
{
    unsigned char **image;
    
    image = allocateImage(mWidth,mHeight);
    readfile(mFileName, image, mWidth, mHeight);
    Writefile("result.raw", image, mWidth, mHeight);
};

unsigned char ** ImageReader::allocateImage(int width, int height)
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

void ImageReader::readfile(char *filename, unsigned char **source, int width, int height)
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
    
}
void ImageReader:: Writefile(char *filename, unsigned char **result, int width, int height)
{
    int i, j;
    FILE *writef;
    int value = 0;
    if ((writef = fopen(filename, "wb")) == NULL) {
        guideTable->showGuideMessage(FILE_OPEN_ERROR);
        exit(1);
    }
    
    for (i = 0; i<height; i++)
    {
        for (j = 0; j<width; j++)
        {
            if(result[i][j] > 128)
            {
                value = 128;
            } else
                value = 0;
            
            printf("%d \n" , value);
            putc((unsigned char)value, writef);
        }
        
    }
    
    
    guideTable->showGuideMessage(FILE_WRITE_SUCCESS);
    fclose(writef);
}






