/*
 *  drawing.cpp
 *
 *  Created by Ryan Raffa on 4/4/13.
 *
 */

#ifndef _drawing
#define _drawing


#include "ofMain.h"


typedef struct {
    
    ofPoint pos;
    int     timeStamp;
    
    ofPoint whereAreWe;
    bool    drawMe;
    
}	touchPoint;

class drawing {
	
	public:
    
        void setup();
    void update(ofTouchEventArgs &touch, ofColor color, float lineWidth);
    void update(ofTouchEventArgs &touch, ofColor color, float lineWidth, bool drawMe, ofPoint whereAreWe);
        void update(ofPoint &pos, ofColor color, float lineWidth, bool drawMe, ofPoint whereAreWe);
        void update(ofPoint &pos, int timeStamp, ofColor color, float lineWidth, bool drawMe, ofPoint whereAreWe);
        void draw();
		void draw(int currentTime);
        void reset();
        void drawMini(ofPoint newLocation);
        void drawMini(ofPoint newLocation, int currentPos);
    
        ofPoint returnMoveMe(int currentTime);

    
        ofColor color;
        float   lineWidth;

        vector <touchPoint> thePoints;
    
    
};

#endif
