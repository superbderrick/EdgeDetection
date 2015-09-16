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
#include "ImageWriter.h"
#include "EdgeController.h"


char fileName[20];
GuideTable * guideTable;

int main(int argc, const char * argv[]) {
    guideTable = new GuideTable;
    
    guideTable->showGuideMessage(EDGEDETECTOR_START);
    showDeck();

    if( argc < INPUT_NUM ) {
        if( argc == FILE_NAME+1 && strcmp(argv[FILE_NAME], "help") == 0 ) {
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
    
   
    // debuging work.
//    EdgeController * Controller = new EdgeController(1 , imageReader->inputImage);
//
//    
//    ImageWriter * imageWriter = new ImageWriter(Controller->applyAlgorithm());
//    imageWriter->makeRawfile();
    
 
    showDeck();
    guideTable->showGuideMessage(EDGEDETECTOR_FINISH);
    
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

void deletelibs() {
    
};






