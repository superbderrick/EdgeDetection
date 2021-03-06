//
//  GuideTable.h
//  EdgeDetector
//
//  Created by 강진영 on 9/13/15.
//  Copyright (c) 2015 sensation. All rights reserved.
//

#ifndef __EdgeDetector__GuideTable__
#define __EdgeDetector__GuideTable__

#include <stdio.h>
#include <map>
#include <string>
#include "GuideTableConfig.h"
#include <iostream>

class GuideTable{

public:

GuideTable();
~GuideTable();
void showGuideMessage(std::string);
void inputedValues(char * filename , int height , int width , int mode);
void selectedValues(int mode);
void checkEdgeMode(int mode);
void showThreshold(int mode);    
    
private:
std::map< std::string, std::string> guideMap;
void initStringTable();
void init();
};

#endif /* defined(__EdgeDetector__GuideTable__) */

