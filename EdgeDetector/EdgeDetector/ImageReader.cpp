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
    
    readfile(mFileName, inputImage, mWidth, mHeight);
    
    guideTable->selectedValues(mMode);
    guideTable->checkEdgeMode(mMode);
    
    switch (mMode) {
            //normal Binarization Image
        case 1:
            makeBinarizationImage(inputImage, finalImage, mWidth, mHeight);
            break;
        case 2:
            Writefile(inputImage, finalImage, mWidth, mHeight, mMode);
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
void ImageReader:: Writefile( unsigned char **result, int ** finalImage,int width, int height , int mode)
{
    int ** temp; // debug later I have to change name
    
    int i, j;
    FILE *writef;
    int value = 0;
    if ((writef = fopen("result.raw", "wb")) == NULL) {
        guideTable->showGuideMessage(FILE_OPEN_ERROR);
        exit(1);
    }
    
    // debug later I have to change to function
    //////////-------------------------------------------------------------//////////////////////
    if ((temp = (int**)malloc(height * sizeof(int*))) == NULL) {
        guideTable->showGuideMessage(MEMORY_FAILURE);
        exit(1);
    }
    
    for (i = 0; i<height; i++)
    {
        if ((temp[i] = (int*)malloc(width * sizeof(int))) == NULL) {
            guideTable->showGuideMessage(MEMORY_FAILURE);
            exit(1);
        }
    }
    
    for (i = 0; i<height; i++)
        for (j = 0; j<width; j++)
            temp[i][j] = 0;
    
    
    
   //////////-------------------------------------------------------------//////////////////////
    // to bieaniery file.
    
    for (i = 0; i<height; i++)
    {
        for (j = 0; j<width; j++)
        {
            if(result[i][j] > 128)
            {
                value = 128;
            } else
                value = 0;
            finalImage[i][j] = value;
            //printf("%d \n" , value);
            //debug
          // putc((unsigned char)value, writef);
        }
        
    }
    
    
    //////////-------------------------------------------------------------//////////////////////
    
    //    alorism part.. to make edge
    int offset = 0;
    int count = 0;
    int start = 0;
    int end = 0;
    bool isData = true;
    int dd = 0;
    
    bool checkoverlab = false;

    
    int testArray [65536];
    
    for (int i = 0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if(finalImage[i][j] == 0)
            {
                if(offset == i)
                {
                    dd = j;
                    checkoverlab = true;
                   
               //     lastNumbMap.insert(std::make_pair(i, j));
                   
                    
                    for(int k = 0 ;k < count;k++)
                    {
                        if(j == testArray[k])
                        {
                            isData = false;
                            break;
                        } else
                            isData = true;
                            
                    }
                    
                    if(isData)
                    {
                        temp[offset][j] = 244;
                        testArray[count] = j;
                        count++;
                        isData = true;
                    }
                    
                }
                else
                {
                    checkoverlab = false;
                    temp[offset][dd] = 244;
                    
                    offset = i;
                    start = j;
                    temp[offset][start] = 244;
                    testArray[count] = j;
                    count++;
                }
        
//                std::pair<std::map<int,int>::iterator, std::map<int,int>::iterator> iter_pair;
//                iter_pair = lastNumbMap.equal_range(i);
//                
//                for (std::multimap<int,int>::iterator iter = iter_pair.first; iter != iter_pair.second ; iter++) {
//                    printf("test %d , %d\n" ,iter->first ,iter->second);
//                }
       
            }
           
           
        }
    }
    

    for (i = 0; i<height; i++)
    {
        for (j = 0; j<width; j++)
        {
            
            //printf("%d \n" ,temp[i][j] );
            putc((unsigned char)temp[i][j], writef);
        }
        
    }
    
    guideTable->showGuideMessage(FILE_WRITE_SUCCESS);
    fclose(writef);
    
    /// file wirter part/
    //////////-------------------------------------------------------------//////////////////////
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

 //////////-------------------------------------------------------------//////////////////////






