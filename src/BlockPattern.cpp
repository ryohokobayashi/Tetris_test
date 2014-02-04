//
//  BlockPattern.cpp
//  tetrisTest
//
//  Created by Ryoho Kobayashi on 1/28/14.
//
//

#include "BlockPattern.h"

BlockPattern::BlockPattern(int _originX, int _originY, int _pattern) {
    originX = _originX;
    originY = _originY;
    
    valid = new bool*[4];
    for (int i = 0; i < 4; i++) {
        valid[i] = new bool[4];
    }
    
    switch (_pattern) {
        case 0:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (i == 1 && j == 1) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;

        case 1:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 1) || (i == 2 && j == 1)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 2)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
            
        case 3:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 2)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
            
        default:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    *(*(valid+i)+j) = FALSE;
                }
            }
            break;
    }
}

BlockPattern::BlockPattern(int _gridWidth, int _pattern) {
    
    originX = _gridWidth / 2 - 2;
    originY = -4;
    
    valid = new bool*[4];
    for (int i = 0; i < 4; i++) {
        valid[i] = new bool[4];
    }
    
    switch (_pattern) {
        case 0:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (i == 1 && j == 1) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
            
        case 1:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 1) || (i == 2 && j == 1)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 2)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
            
        case 3:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 2)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;

        case 4:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 0 && j == 1) || (i == 1 && j == 1) || (i == 2 && j == 1) || (i == 3 && j == 1)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
            
        case 5:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1) || (i == 3 && j == 1)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
            
        case 6:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 1) || (i == 2 && j == 1) || (i == 2 && j == 2) || (i == 3 && j == 1)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
            
        case 7:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 1) || (i == 2 && j == 1) || (i == 3 && j == 1) || (i == 3 && j == 2)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
            
        case 8:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 1) || (i == 2 && j == 1) || (i == 2 && j == 2) || (i == 3 && j == 2)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
            
        case 9:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 2) || (i == 2 && j == 1) || (i == 2 && j == 2) || (i == 3 && j == 1)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
            
        case 10:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((i == 1 && j == 1) || (i == 2 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 2)) {
                        valid[i][j] = TRUE;
                    } else {
                        valid[i][j] = FALSE;
                    }
                }
            }
            break;
            
        default:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    *(*(valid+i)+j) = FALSE;
                }
            }
            break;
    }
    
    for (int i = 0; i < (int)ofRandom(4); i++) {
        rotateBlock(1);
    }
    
    int j = 0;
    
    for (int i = 3; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            if (valid[i][j]) {
                break;
            }
        }
        if (valid[i][j]) {
            break;
        }
        originY++;
    }
}


BlockPattern::~BlockPattern() {
    for (int i = 0; i < 4; i++) {
        delete[] valid[i];
    }
    delete[] valid;
}

void BlockPattern::rotateBlock(int _direction) {
    bool tmpPattern[4][4];
    
    for (int i = 0; i < 4; i++) {
        memcpy(tmpPattern[i], valid[i], sizeof(bool) * 4);
    }
    
    if (_direction > 0) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                valid[j][3-i] = tmpPattern[i][j];
            }
        }
    } else {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                valid[3-j][i] = tmpPattern[i][j];
            }
        }
    }
    
    
}