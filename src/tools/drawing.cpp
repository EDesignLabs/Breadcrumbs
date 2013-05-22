/*
 *  drawing.cpp
 *
 *  Created by Ryan Raffa on 4/4/13.
 *
 */

#include "drawing.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void drawing::reset() {
    
    thePoints.clear();
    
    printf(" drawing reset ended \n");
    
}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void drawing::setup() {
    
    printf(" drawing setup started \n");

//-----------------------------------------------
//sample section

    printf(" drawing setup ended \n");

}

		 
////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void drawing::update(ofTouchEventArgs &touch, ofColor color, float lineWidth) {
    
    touchPoint newLocation;
    newLocation.pos.x = touch.x;
    newLocation.pos.y = touch.y;
    
    newLocation.color = color;
    newLocation.lineWidth = lineWidth;
    
    newLocation.timeStamp = ofGetElapsedTimeMillis();
    
    thePoints.push_back(newLocation);

}


//------------------------------------------------------------------
void drawing::draw() {
    
    if (thePoints.size() > 0) {
        for (int i = 1; i < thePoints.size(); i++) {
            ofLine(thePoints[i-1].pos.x, thePoints[i-1].pos.y, thePoints[i].pos.x, thePoints[i].pos.y);
        }
    }
}

//------------------------------------------------------------------
void drawing::draw(int currentTime) {
    
    if (thePoints.size() > 0) {
        for (int i = 1; i < thePoints.size(); i++) {
            
            if (thePoints[i].timeStamp < currentTime) {
                ofLine(thePoints[i-1].pos.x, thePoints[i-1].pos.y, thePoints[i].pos.x, thePoints[i].pos.y);
            }
        }
    }
}

