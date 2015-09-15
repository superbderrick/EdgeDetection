//
//  ImageWriter.h
//  EdgeDetector
//
//  Created by 강진영 on 9/16/15.
//  Copyright (c) 2015 sensation. All rights reserved.
//

#ifndef __EdgeDetector__ImageWriter__
#define __EdgeDetector__ImageWriter__

#include <stdio.h>
#include "GuideTable.h"
#include <string.h>

class ImageWriter
{
private:
    int ** outputImage;
      GuideTable * guideTable;
public:
    
    void makeRawfile();
    ImageWriter(int ** test);
    ~ImageWriter();
    
};

#endif /* defined(__EdgeDetector__ImageWriter__) */
