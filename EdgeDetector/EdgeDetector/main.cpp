//
//  main.c
//  EdgeDetector
//
//  Created by 강진영 on 9/8/15.
//  Copyright (c) 2015 sensation. All rights reserved.
//

static const int INPUT_NUM=4;

#include <stdio.h>


void fileOpen();
int main(int argc, const char * argv[]) {

    // todo list
    // 1. input value module
    
//    if( argc != INPUT_NUM ) {
//        printf("You have to input correctly ! \n");
//        printf("Input value is 3 \n");
//        printf("File Name, width, height \n");
//        exit(1);
//    } else {
//        printf("You have to input correctly ! \n");
//        printf("Input value is 3 \n");
//        printf("File Name, width, height \n");
//    }
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
    
    int MaskSobelX[3][3] = { {-1,0,1},
                             {-2,0,2},
                             {-1,0,1}
                           };
    
    int MaskSobelY[3][3] = { {-1,0,1},
                             {-2,0,2},
                             {-1,0,1}
                           };

    
    if((imageFile = fopen("LONDON256.RAW", "rb")) == NULL) {
        printf( "File could not be opened\n" );
    } else {
        fread(inputImage, sizeof(char),256 * 256, imageFile);
    }
    
    fclose(imageFile);
    
    pImageSobelX = new int[height*width];
    pImageSobelY = new int[height*width];
    
    
    
    return 0;
}
