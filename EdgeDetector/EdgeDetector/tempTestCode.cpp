////
////  tempTestCode.cpp
////  EdgeDetector
////
////  Created by 강진영 on 9/15/15.
////  Copyright (c) 2015 sensation. All rights reserved.
////
//
//#include <stdio.h>
//
////    unsigned char ** p;
////
////    int j;
////    int height = 256;
////    int width = 256;
////
////    p = (unsigned char **)malloc(height*sizeof(unsigned char*));
////    for(j=0;j<height;j++)
////        p[j]=(unsigned char*)malloc(width*sizeof(unsigned char));
////
////    unsigned char **Buffer;
////    Buffer = new unsigned char *[10];
////    for(int i=0; i<10; i++)
////        Buffer[i] = new unsigned char[20];
////
////    memset(Buffer , 0, sizeof(char)*10*10);
//
//
////getImageData(testArray);
////
////
//////
//
//void ImageReader:: Writefile( unsigned char **result, int ** finalImage,int width, int height , int mode)
//{
//    int ** temp; // debug later I have to change name
//    
//    int i, j;
//    FILE *writef;
//    int value = 0;
//    if ((writef = fopen("result.raw", "wb")) == NULL) {
//        guideTable->showGuideMessage(FILE_OPEN_ERROR);
//        exit(1);
//    }
//    
//    // debug later I have to change to function
//    //////////-------------------------------------------------------------//////////////////////
//    if ((temp = (int**)malloc(height * sizeof(int*))) == NULL) {
//        guideTable->showGuideMessage(MEMORY_FAILURE);
//        exit(1);
//    }
//    
//    for (i = 0; i<height; i++)
//    {
//        if ((temp[i] = (int*)malloc(width * sizeof(int))) == NULL) {
//            guideTable->showGuideMessage(MEMORY_FAILURE);
//            exit(1);
//        }
//    }
//    
//    for (i = 0; i<height; i++)
//        for (j = 0; j<width; j++)
//            temp[i][j] = 0;
//    
//    
//    
//    //////////-------------------------------------------------------------//////////////////////
//    // to bieaniery file.
//    
//    for (i = 0; i<height; i++)
//    {
//        for (j = 0; j<width; j++)
//        {
//            if(result[i][j] > 128)
//            {
//                value = 128;
//            } else
//                value = 0;
//            finalImage[i][j] = value;
//            //printf("%d \n" , value);
//            //debug
//            // putc((unsigned char)value, writef);
//        }
//        
//    }
//    
//    
//    //////////-------------------------------------------------------------//////////////////////
//    
//    //    alorism part.. to make edge
//    int offset = 0;
//    int count = 0;
//    int start = 0;
//    int end = 0;
//    bool isData = true;
//    int dd = 0;
//    
//    bool checkoverlab = false;
//    
//    
//    int testArray [65536];
//    
//    for (int i = 0; i<height; i++) {
//        for (int j=0; j<width; j++) {
//            if(finalImage[i][j] == 0)
//            {
//                if(offset == i)
//                {
//                    dd = j;
//                    checkoverlab = true;
//                    
//                    //     lastNumbMap.insert(std::make_pair(i, j));
//                    
//                    
//                    for(int k = 0 ;k < count;k++)
//                    {
//                        if(j == testArray[k])
//                        {
//                            isData = false;
//                            break;
//                        } else
//                            isData = true;
//                        
//                    }
//                    
//                    if(isData)
//                    {
//                        temp[offset][j] = 244;
//                        testArray[count] = j;
//                        count++;
//                        isData = true;
//                    }
//                    
//                }
//                else
//                {
//                    checkoverlab = false;
//                    temp[offset][dd] = 244;
//                    
//                    offset = i;
//                    start = j;
//                    temp[offset][start] = 244;
//                    testArray[count] = j;
//                    count++;
//                }
//                
//                //                std::pair<std::map<int,int>::iterator, std::map<int,int>::iterator> iter_pair;
//                //                iter_pair = lastNumbMap.equal_range(i);
//                //
//                //                for (std::multimap<int,int>::iterator iter = iter_pair.first; iter != iter_pair.second ; iter++) {
//                //                    printf("test %d , %d\n" ,iter->first ,iter->second);
//                //                }
//                
//            }
//            
//            
//        }
//    }