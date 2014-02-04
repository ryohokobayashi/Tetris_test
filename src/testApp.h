#pragma once

#include "ofMain.h"
#include "BlockPattern.h"


class testApp : public ofBaseApp{
	public:
        int gridSize;
        int gridWidth;
        int gridHeight;
    
        int counter;
        int fallFrames;
        float fallSpeed;
    
        int numPattern;

        bool **validGrid;
        BlockPattern *block;
    
        bool checkFallAbility();
        bool checkRotateAbility(int _direction);
        bool checkMoveAbility(int _moveX);
    
        int checkFillLine();
    
        void drawBlock(float _originX, float _originY, float _width, float _height, ofColor _fill, ofColor _stroke);
        void resetGrid();
    
        void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    


};

