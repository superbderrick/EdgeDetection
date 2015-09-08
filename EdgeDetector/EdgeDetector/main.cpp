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
    
    FILE * fp;
    char array[256][256];
    if((fp = fopen("LONDON256.RAW", "rb")) == NULL) {
        printf( "File  could not be opened\n" );
    } else {
        fread(array, 1, 65536, fp);
    }
    
   
    
    fclose(fp);
    
    
    return 0;
}
