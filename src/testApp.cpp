#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    gridSize = 30;
    gridWidth = 10;
    gridHeight = 20;
    
    counter = 0;
    fallSpeed = 50.;
    fallFrames = (int)(300. / fallSpeed);
    
    numPattern = 11;
    
    validGrid = new bool*[gridHeight];
    
    for (int i = 0; i < gridHeight; i++) {
        validGrid[i] = new bool[gridWidth];
        
        for (int j = 0; j < gridWidth; j++) {
                validGrid[i][j] = FALSE;
        }
    }
    
    ofBackground(128);
    
    block = new BlockPattern(gridWidth, (int)ofRandom(numPattern));
    
}

//--------------------------------------------------------------
void testApp::update(){
    if (block && counter == fallFrames) {
        if (checkFallAbility()) {
            block->originY += 1;
        } else {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (block->valid[i][j] && (block->originY + i) >= 0) {
                        validGrid[block->originY + i][block->originX + j] = TRUE; // fix block
                    }
                }
            }
            checkFillLine();
            delete block;
            block = new BlockPattern(gridWidth, (int)ofRandom(numPattern)); // make new block
            if (!checkFallAbility()) { // died
                
                //幅を広げる
                gridWidth++;
                for (int i = 0; i < gridHeight; i++) {
                    validGrid[i] = new bool[gridWidth];
                        
                    for (int j = 0; j < gridWidth; j++) {
                        validGrid[i][j] = FALSE;
                    }
                }
            }
        }
        counter = 0;
    }
    counter++; // count the number of frames
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // draw valid grids
    for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            if(validGrid[i][j]) {
                drawBlock(gridSize * j, gridSize * i, gridSize, gridSize, ofColor(255), ofColor(0));
            }
        }
    }
    
    
    
    // draw falling block
    if (block) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if(block->valid[i][j]) {
                    drawBlock(gridSize * (j + block->originX), gridSize * (i + block->originY), gridSize, gridSize, ofColor(255), ofColor(0));
                }
            }
        }
    }

    // outer frame
    drawBlock(0, 0, gridSize * gridWidth, gridSize * gridHeight, ofColor(0, 0), ofColor(0));
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == OF_KEY_RIGHT) {
        if (checkMoveAbility(1)) {
            block->originX++; // right
        }
    }
    if (key == OF_KEY_LEFT) {
        if (checkMoveAbility(-1)) {
            block->originX--; // left
        }
    }
    if (key == OF_KEY_UP) {
        if (checkRotateAbility(1)) {
            block->rotateBlock(1); // clockwise
        }
    }
    if (key == OF_KEY_DOWN) {
        if (checkRotateAbility(-1)) {
            block->rotateBlock(-1); // counterclockwise
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}


bool testApp::checkFallAbility() {
    
    if (block) { // block exists
        for (int i = 3; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (block->valid[i][j]) {
                    if ((block->originY + (i + 1)) >= 0) { // ignore outside
                        if ((block->originY + (i + 1)) >= gridHeight) { // blocked by bottom
                            return FALSE;
                        }
                        if (validGrid[block->originY + (i + 1)][block->originX + j]) { // blocked by existing grid
                            return FALSE;
                        }
                    }
                }
            }
        }
    
        return TRUE;
        
    } else {
        return FALSE;
    }

}


//1行調べて削除
int testApp::checkFillLine(){
    int x,y,line_count,fill_line=0;
    
    for(y=gridHeight-1;y>=0;y--){
        line_count = 0;
        for(x=0; x<gridWidth;x++){
            line_count+=(int)validGrid[y][x];
        }
        
        if(line_count == 0) break;
        if(line_count != gridWidth) continue;
        
        fill_line++;
        for(x=0;x<gridWidth;x++){
            validGrid[y][x] = 0;
        }
    }
    for(y=gridHeight-1;y>=0 && fill_line>0; ){
        int lineCount=0;
        for(x=0;x<gridWidth;x++){
            lineCount+=validGrid[y][x];
        }
        
        if(lineCount!=0){
            y--;
            continue;
        }
        
        // 一行詰める
        fill_line--;
        for(int iy=y;iy>=0;iy--){
            for(x=0;x<gridWidth;x++){
                if(iy-1>=0){
                    validGrid[iy][x]=validGrid[iy-1][x];
                }else{
                    validGrid[0][x]=0;    /* 0 行より上はないので 0 で埋める */
                }
            }
        }
    }

}


bool testApp::checkRotateAbility(int _direction) {
    
    if (block) { // block exists
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (block->valid[i][j]) {
                    if (_direction > 0) {
                        if ((block->originY + j) >= gridHeight) { // blocked by bottom
                            return FALSE;
                        }
                        if ((block->originX + (3 - i)) < 0 || (block->originX + (3 - i)) >= gridWidth) { // blocked by side
                            return FALSE;
                        }
                        if (block->originY + j >= 0) { // ignore outside
                            if (validGrid[block->originY + j][block->originX + (3 - i)]) { // blocked by existing grid
                                return FALSE;
                            }
                        }
                    } else {
                        if ((block->originY + (3 - j)) >= gridHeight) { // blocked by bottom
                            return FALSE;
                        }
                        if ((block->originX + i) < 0 || (block->originX + i) >= gridWidth) { // blocked by side
                            return FALSE;
                        }
                        if ((block->originY + (3 - j)) >= 0) { // ignore outside
                            if (validGrid[block->originY + (3 -j)][block->originX + i]) { // blocked by existing grid
                                return FALSE;
                            }
                        }
                    }
                }
            }
        }
        
        return TRUE;
        
    } else {
        return FALSE;
    }
}

bool testApp::checkMoveAbility(int _moveX) {
    
    if (block) { // block exists
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (block->valid[i][j]) {
                    if ((block->originX + (j + _moveX)) < 0 || (block->originX + (j + _moveX)) >= gridWidth) { // blocked by side
                        return FALSE;
                    }
                    if (block->originY + i >= 0) { // ignore outside
                        if (validGrid[block->originY + i][block->originX + (j + _moveX)]) { // blocked by existing grid
                                return FALSE;
                        }
                    }
                }
            }
        }
        
        return TRUE;
        
    } else {
        return FALSE;
    }
    
}


void testApp::drawBlock(float _originX, float _originY, float _width, float _height, ofColor _fill, ofColor _stroke) {
    ofPath blockRect; // new path
    
    blockRect.rectangle(_originX, _originY, _width, _height); // make rectangle
    blockRect.setFilled(TRUE);
    blockRect.setFillColor(_fill); // fill with _fill color
    blockRect.setStrokeWidth(1);
    blockRect.setStrokeColor(_stroke); // stroke with _stroke color
    blockRect.draw();
    
}

void testApp::resetGrid() {
    for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            validGrid[i][j] = FALSE;
        }
    }
}