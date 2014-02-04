//
//  BlockPattern.h
//  tetrisTest
//
//  Created by Ryoho Kobayashi on 1/28/14.
//
//

#ifndef __tetrisTest__BlockPattern__
#define __tetrisTest__BlockPattern__

#include "ofMain.h"

#endif /* defined(__tetrisTest__BlockPattern__) */

class BlockPattern {
    public:
        BlockPattern(int _originX, int _originY, int _pattern);
        BlockPattern(int _grindWidth, int _pattern);
        ~BlockPattern();
    
        void rotateBlock(int _direction);
    
        int originX;
        int originY;
        bool **valid;
};