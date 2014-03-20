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
    
//    printf(" drawing reset ended \n");
    
}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void drawing::setup() {
    
//    printf(" drawing setup started \n");

//-----------------------------------------------
//sample section

//    printf(" drawing setup ended \n");

}

		 
////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void drawing::update(ofTouchEventArgs &touch, ofColor color, float lineWidth) {
    
    touchPoint newLocation;
    newLocation.pos.x = touch.x;
    newLocation.pos.y = touch.y;
    
    this->color             = color;
    this->lineWidth         = lineWidth;
    
    newLocation.timeStamp   = ofGetElapsedTimeMillis();
    newLocation.drawMe      = true;
    newLocation.whereAreWe.set(0.0, 0.0);
    
    thePoints.push_back(newLocation);
    
}

//------------------------------------------------------------------
void drawing::update(ofTouchEventArgs &touch, ofColor color, float lineWidth, bool drawMe, ofPoint whereAreWe) {
    
    touchPoint newLocation;
    newLocation.pos.x = touch.x;
    newLocation.pos.y = touch.y;
    
    this->color             = color;
    this->lineWidth         = lineWidth;

    newLocation.timeStamp   = ofGetElapsedTimeMillis();
    newLocation.drawMe      = drawMe;
    newLocation.whereAreWe  = whereAreWe;
    
    thePoints.push_back(newLocation);

}

//------------------------------------------------------------------
void drawing::update(ofPoint &pos, ofColor color, float lineWidth, bool drawMe, ofPoint whereAreWe) {
    
    touchPoint newLocation;
    newLocation.pos = pos;
    
    this->color             = color;
    this->lineWidth         = lineWidth;
    
    newLocation.timeStamp   = ofGetElapsedTimeMillis();
    newLocation.drawMe      = drawMe;
    newLocation.whereAreWe  = whereAreWe;
    
    thePoints.push_back(newLocation);
    
}


//------------------------------------------------------------------
void drawing::update(ofPoint &pos, int timeStamp, ofColor color, float lineWidth, bool drawMe, ofPoint whereAreWe) {
    
    touchPoint newLocation;
    newLocation.pos = pos;
    
    this->color = color;
    this->lineWidth = lineWidth;
    
    newLocation.timeStamp = timeStamp;
    newLocation.drawMe = drawMe;
    newLocation.whereAreWe  = whereAreWe;
    
    thePoints.push_back(newLocation);
    
}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void drawing::draw() {
    
    if (thePoints.size() > 0) {
        if (thePoints[0].drawMe == true) {
            
            for (int i = 1; i < thePoints.size(); i++) {
                ofLine(thePoints[i-1].pos.x, thePoints[i-1].pos.y, thePoints[i].pos.x, thePoints[i].pos.y);
            }

        }
    }
}

//------------------------------------------------------------------
void drawing::draw(int currentTime) {
    
    if (thePoints.size() > 0) {
        
        if (thePoints[0].drawMe == true) {

            for (int i = 1; i < thePoints.size(); i++) {
                
                if (thePoints[i].timeStamp < currentTime) {
                    ofLine(thePoints[i-1].pos.x, thePoints[i-1].pos.y, thePoints[i].pos.x, thePoints[i].pos.y);
                }
            }

        }
    
    }
}

//------------------------------------------------------------------
void drawing::drawMini(ofPoint newLocation) {
    
    ofPushMatrix();
    ofTranslate(newLocation);
    
    if (thePoints.size() > 0) {
        if (thePoints[0].drawMe == true) {
            for (int i = 1; i < thePoints.size(); i++) {
                ofLine(thePoints[i-1].pos.x/23, thePoints[i-1].pos.y/23, thePoints[i].pos.x/23, thePoints[i].pos.y/23);
            }
        }
    }
    
    ofPopMatrix();
}

//------------------------------------------------------------------
void drawing::drawMini(ofPoint newLocation, int currentTime) {
    
    ofPushMatrix();
    ofTranslate(newLocation);
    
    if (thePoints.size() > 0) {
        if (thePoints[0].drawMe == true) {
            for (int i = 1; i < thePoints.size(); i++) {
                
                if (thePoints[i].timeStamp < currentTime) {
                    ofLine(thePoints[i-1].pos.x/23, thePoints[i-1].pos.y/23, thePoints[i].pos.x/23, thePoints[i].pos.y/23);
                }
            }
    
        }
    }
    
    ofPopMatrix();
}


//------------------------------------------------------------------
ofPoint drawing::returnMoveMe(int currentTime) {
    
    ofPoint moveMe;
    moveMe.set(0.0, 0.0);
    
    if (thePoints.size() > 0) {
        
        if (thePoints[0].drawMe == false) {
            
            for (int i = thePoints.size()-1; i > 1; i--) {
                if (thePoints[i].timeStamp < currentTime) {
                    
                    moveMe = thePoints[i].whereAreWe;
//                    printf(" MoveMe X break \n");
                    break;
                }
            }
        }
        
    }
    
//    printf(" MoveMe X: %f \n", moveMe.x);
//    printf(" MoveMe Y: %f \n", moveMe.y);

    return moveMe;
    
    //    sprintf(eventString, "alert - orientation change to %i", newOrientation);
}
