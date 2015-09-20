//
//  EdgeController.cpp
//  EdgeDetector
//
//  Created by 강진영 on 9/16/15.
//  Copyright (c) 2015 sensation. All rights reserved.
//

#include "EdgeController.h"

EdgeController::EdgeController(int mode , unsigned char ** inputImage)
{
    mMode = mode;
    applyImage = inputImage;
};

EdgeController::~EdgeController()
{
    
};

int ** EdgeController::applyAlgorithm()
{
    int value = 0;
    
    int ** test;
    
    
    
    if ((test = (int **)malloc(256 * sizeof(int*))) == NULL) {
       // guideTable->showGuideMessage(MEMORY_FAILURE);
       // exit(1);
    }
    
//    for (int i = 0; i<256; i++)
//    {
//        if ((test[i] = (unsigned char*)malloc(width * sizeof(unsigned char))) == NULL) {
//            guideTable->showGuideMessage(MEMORY_FAILURE);
//            exit(1);
//        }
//    }
    
    
    for (int i = 0; i<256; i++)
    {
        for (int j = 0; j<256; j++)
        {
            if(applyImage[i][j] > 128)
            {
                test[i][j] = 128;
            } else
                test[i][j] = 0;
            
           // printf("%d \n" , test[i][j]);
            //putc((unsigned char)value, writef);
        }
        
    }
    return test;
};