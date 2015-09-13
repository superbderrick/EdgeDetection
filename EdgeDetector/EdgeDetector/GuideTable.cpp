//
//  GuideTable.cpp
//  EdgeDetector
//
//  Created by 강진영 on 9/13/15.
//  Copyright (c) 2015 sensation. All rights reserved.
//


//introduction
#include "GuideTable.h"



GuideTable::GuideTable()
{
    init();
}

GuideTable::~GuideTable()
{
    
}
void GuideTable::init()
{
    initStringTable();
};

void GuideTable::initStringTable()
{
    // Inputs guide strings
    if(guideMap.empty())
    {

        
        guideMap.insert(std::pair<std::string, std::string>(INTRODUCTION_PROGRAM, INTRODUCTION_PROGRAM));
        guideMap.insert(std::pair<std::string, std::string>(INPUT_LIST, INPUT_LIST));
        guideMap.insert(std::pair<std::string, std::string>(DECK, DECK));
        guideMap.insert(std::pair<std::string, std::string>(START_PROGRAM, START_PROGRAM));
        guideMap.insert(std::pair<std::string, std::string>(END_PROGRAM, END_PROGRAM));
        guideMap.insert(std::pair<std::string, std::string>(INPUT_ERROR, INPUT_ERROR));
        guideMap.insert(std::pair<std::string, std::string>(INPUT_SUCCESS, INPUT_SUCCESS));
        guideMap.insert(std::pair<std::string, std::string>(INPUT_DATALIST, INPUT_DATALIST));
        guideMap.insert(std::pair<std::string, std::string>(HELP_DETAIL, HELP_DETAIL));
        guideMap.insert(std::pair<std::string, std::string>(HELP_DETAIL_command, HELP_DETAIL_command));
        guideMap.insert(std::pair<std::string, std::string>(TEST, TEST));        
    }
    
    
    
};

void GuideTable::showGuideMessage(std::string guide)
{
    
    std::cout <<  guideMap[guide] << std::endl;
    
};


void GuideTable::inputedValues(char *filename, int height, int width, int mode)
{
    
std::cout <<  filename << std::endl;
std::cout <<  height << std::endl;
std::cout <<  width << std::endl;
std::cout <<  mode << std::endl;
    
};
