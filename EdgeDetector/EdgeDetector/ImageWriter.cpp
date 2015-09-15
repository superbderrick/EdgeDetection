//
//  ImageWriter.cpp
//  EdgeDetector
//
//  Created by 강진영 on 9/16/15.
//  Copyright (c) 2015 sensation. All rights reserved.
//

#include "ImageWriter.h"

ImageWriter::ImageWriter(int ** sourceImage)
{
    GuideTable * guideTable = new GuideTable();
    outputImage = sourceImage;
};

ImageWriter::~ImageWriter()
{
    delete guideTable;
};

void ImageWriter::makeRawfile()
{
    FILE *writef;
    int value = 0;
    
    if ((writef = fopen("result.raw", "wb")) == NULL) {
        guideTable->showGuideMessage(FILE_OPEN_ERROR);
        exit(1);
    }
    
        for (int i = 0; i<256; i++)
        {
            for (int j = 0; j<256; j++)
            {
                if(outputImage[i][j] > 128)
                {
                    value = 128;
                } else
                    value = 0;
    
                
                putc((unsigned char)value, writef);
            }
            
        }
};
