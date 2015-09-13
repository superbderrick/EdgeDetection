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
#include "ImageReader.h"


char fileName[20];
GuideTable * guideTable;

int main(int argc, const char * argv[]) {
    guideTable = new GuideTable;

    //printf("%d \n" , argc); debug
    if( argc < INPUT_NUM ) {
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
    
    ImageReader * imageReader = new ImageReader(fileName, atoi(argv[WIDTH]), atoi(argv[HEIGHT]));
    
   
    imageReader->start();
    
    
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
    
    exit(1);
};

void showHelp() {
   
};

void showSuccessGuide() {
    guideTable->showGuideMessage(INPUT_SUCCESS);
    guideTable->showGuideMessage(INPUT_DATALIST);
};





