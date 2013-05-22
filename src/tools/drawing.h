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
    ofColor color;
	float   lineWidth;
    
}	touchPoint;

class drawing {
	
	public:
    
        void setup();
        void update(ofTouchEventArgs &touch, ofColor color, float lineWidth);
		void draw();
		void draw(int currentPos);
        void reset();

        vector <touchPoint> thePoints;
    
    
};

#endif
