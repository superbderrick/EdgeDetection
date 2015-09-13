//
//  main.c
//  EdgeDetector
//
//  Created by 강진영 on 9/8/15.
//  Copyright (c) 2015 sensation. All rights reserved.
//



#include <stdio.h>
#include "main.h"
#include "ProjectConfig.h"
#include "GuideTable.h"


char fileName[20];
GuideTable * guideTable;

int main(int argc, const char * argv[]) {
    guideTable = new GuideTable;
 
    if( argc < INPUT_NUM ) {
        printf("%s \n" , argv[FILE_NAME]);
        
        if(argc == FILE_NAME+1 && strcmp(argv[FILE_NAME], "help") == 0 ) {
          guideTable->showGuideMessage(TEST);
        } else {
            showGuide();
        }
    } else {
        showSuccessGuide();
        strcpy(fileName,argv[FILE_NAME]);
        guideTable->inputedValues(fileName, atoi(argv[WIDTH]), atoi(argv[HEIGHT]), atoi(argv[EDGE_MODE]));
        
    }
    
    guideTable->showGuideMessage(START_PROGRAM);
    
    
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
    
    
    guideTable->showGuideMessage(DECK);
    guideTable->showGuideMessage(DECK);
    
    return 0;
}

void showDeck() {
    guideTable->showGuideMessage(DECK);
    guideTable->showGuideMessage(DECK);
};

void showGuide() {
    guideTable->showGuideMessage(INPUT_ERROR);
    guideTable->showGuideMessage(INPUT_LIST);
    guideTable->showGuideMessage(HELP_DETAIL);
    guideTable->showGuideMessage(HELP_DETAIL_command);
};

void showHelp() {
   
};

void showSuccessGuide() {
    guideTable->showGuideMessage(INPUT_SUCCESS);
    guideTable->showGuideMessage(INPUT_DATALIST);
};





