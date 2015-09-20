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
    delete IntermediateImage;
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
    
    showDeck();
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
        case 4:
            //apply normal algorism by derrick
            makeAppliedSobelAlgorithmImage(inputImage, finalImage, mWidth, mHeight, IntermediateImage);
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

void ImageReader::showDeck() {
    guideTable->showGuideMessage(DECK);
    guideTable->showGuideMessage(DECK);
};



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
    int sum = 0;
    int average = 0;
    if ((writef = fopen("result.raw", "wb")) == NULL) {
        guideTable->showGuideMessage(FILE_OPEN_ERROR);
        exit(1);
    }
    
    for (i = 0; i<height; i++)
    {
        for (j = 0; j<width; j++)
        {
            sum += result[i][j];
        }
        
    }
    average = sum / (width * height);
    
    guideTable->showThreshold(average);
    
    for (i = 0; i<height; i++)
    {
        for (j = 0; j<width; j++)
        {
            if(result[i][j] > average)
            {
                value = 255;
            } else
                value = 128;
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
    int sum = 0;
    int average = 0;
    
    if ((writef = fopen("result.raw", "wb")) == NULL) {
        guideTable->showGuideMessage(FILE_OPEN_ERROR);
        exit(1);
    }
    
    for (i = 0; i<height; i++)
    {
        for (j = 0; j<width; j++)
        {
            sum += result[i][j];
        }
        
    }
    average = sum / (width * height);
    
    //////////-------------------------------------------------------------//////////////////////
    //Creating a primary binary file
    
    for (i = 0; i<height; i++)
    {
        for (j = 0; j<width; j++)
        {
            if(result[i][j] > average)
            {
                value = 255;
            } else
                value = 128;
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
            if(midle[i][j] == 128)
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
            else if(result[i][j] > average)
            {
                final[i][j] =50;
            }
            else
            {
                final[i][j] =128;
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

void ImageReader::makeAppliedSobelAlgorithmImage(unsigned char **result, int ** midle,int width, int height , int ** final)
{
//    int sobelX[3][3]= {{-1,0,1},
//                       {-2,0,2},
//                       {-1,0,1}
//                      };
//    int sobelY[3][3]= { {1,2,1},
//                        {0,0,0},
//                        {-1,-2,-1}
//                      };
//    
//    int i,j,vmax,vmin;
//    int heightm1=height-1;
//    int widthm1=width-1;
//    int mr,mc;
//    int newValue;
//    
//    int *pImgSobelX,*pImgSobelY;
//    int min,max,where;
//    float constVal1,constVal2;
//    unsigned char OrgImg[256][256];
//    
//    FILE *writef;
//    if ((writef = fopen("result.raw", "wb")) == NULL) {
//        guideTable->showGuideMessage(FILE_OPEN_ERROR);
//        exit(1);
//    }
//    
//    fread(result, sizeof(char),256*256,writef);
//    fclose(writef);
//    
//    //정수값을 갖는 이미지 동적 메모리 할당
//    pImgSobelX=new int[height*width];
//    pImgSobelY=new int[height*width];
//    
//    //결과 이미지 0으로 초기화
//    for(i=0;i<height;i++)
//        for(j=0;j<width;j++)
//        {
//            OrgImg[i][j]=0;
//            where=i*width+j;
//            pImgSobelX[where]=0;
//            pImgSobelY[where]=0;
//        }
//    
//    //X 방향 에지 강도 계산
//    for(i=1; i<heightm1; i++)
//    {
//        for(j=1; j<widthm1; j++)
//        {
//            newValue=0; //0으로 초기화
//            for(mr=0;mr<3;mr++)
//                for(mc=0;mc<3;mc++)
//                    newValue += (sobelX[mr][mc]*
//                                 result[i+mr-1][j+mc-1]);
//            pImgSobelX[i*width+j]=newValue;
//        }
//    }
//    
//    //Y 방향 에지 강도 계산
//    for(i=1; i<heightm1; i++)
//    {
//        for(j=1; j<widthm1; j++)
//        {
//            newValue=0; //0으로 초기화
//            for(mr=0;mr<3;mr++)
//                for(mc=0;mc<3;mc++)
//                    newValue += (sobelY[mr][mc]*result[i+mr-1][j+mc-1]);
//            pImgSobelY[i*width+j]=newValue;
//        }
//    }
//    
//    for(i=1;i<heightm1;i++)
//        for(j=1;j<widthm1;j++)
//        {
//            where=i*width+j;
//            constVal1=pImgSobelX[where];
//            constVal2=pImgSobelY[where];
//            if(constVal1<0)
//                constVal1=-constVal1;
//            if(constVal2<0)
//                constVal2=-constVal2;
//            pImgSobelX[where]=constVal1+constVal2;
//        }
//    
//    min=(int)10e10;
//    max=(int)-10e10;
//    for(i=1; i<heightm1; i++)
//    {
//        for(j=1; j<widthm1; j++)
//        {
//            newValue=pImgSobelX[i*width+j];
//            if(newValue<min)
//                min=newValue;
//            if(newValue>max)
//                max=newValue;
//        }
//    }
//    
//    
    
    
    
    
};


 //////////-------------------------------------------------------------//////////////////////






