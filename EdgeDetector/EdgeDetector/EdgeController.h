//
//  EdgeController.h
//  EdgeDetector
//
//  Created by 강진영 on 9/16/15.
//  Copyright (c) 2015 sensation. All rights reserved.
//

#ifndef __EdgeDetector__EdgeController__
#define __EdgeDetector__EdgeController__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class EdgeController
{
private:

    
    int mMode;
    unsigned char ** applyImage;
public:
    EdgeController(int mode , unsigned char ** inputImage);
    
    ~EdgeController();
     int  ** applyAlgorithm();
};

#endif /* defined(__EdgeDetector__EdgeController__) */
