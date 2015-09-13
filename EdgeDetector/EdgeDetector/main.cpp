//
//  main.c
//  EdgeDetector
//
//  Created by 강진영 on 9/8/15.
//  Copyright (c) 2015 sensation. All rights reserved.
//



#include <stdio.h>
#include "ProjectConfig.h"
#include "GuideTable.h"



int main(int argc, const char * argv[]) {
    
    // Create Guide Table
    GuideTable * guideTable;
    guideTable = new GuideTable;
    
    guideTable->showGuideMessage(DECK);
    guideTable->showGuideMessage(DECK);
    
    guideTable->showGuideMessage(START_PROGRAM);

    
    
    
    if( argc < INPUT_NUM ) {
        printf("You have to input correctly ! \n");
        printf("File Name, width, height \n");
    } else {
        printf("You have to input correctly ! \n");
        printf("Input value is 3 \n");
        printf("File Name, width, height \n");
    }
    
    
////    char fileName[20];
////    
////    strcpy(fileName,argv[1]);
////    
//
//  //  printf("file name :  %s /n",fileName);
  
    
    // todo list
    // 2. Dynamically changing the value.
    
    
    
    FILE * imageFile;
    
    int height = 256;
    int width  = 256;
    
    int *pImageSobelX,*pImageSobelY;
    
    unsigned char inputImage[256][256];
    
  

//    
//    if((imageFile = fopen("LONDON256.RAW", "rb")) == NULL) {
//        printf( "File could not be opened\n" );
//    } else {
//        fread(inputImage, sizeof(char),256 * 256, imageFile);
//    }
//    
//    fclose(imageFile);
//    
//    int value = 0;
//    for(int i = 0 ; i < height ; i++)
//    {
//        for (int j = 0 ; j< width; j++) {
//        value =   inputImage[i][j];
//        }
//    }
//    
//    
//    
    
    return 0;
}
