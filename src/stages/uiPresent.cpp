/*
 *  uiPresent.cpp
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#include "uiPresent.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiPresent::~uiPresent() {
    
    //uiPresent elements
    delete scrubBox;
    delete scrubLocation;
    delete currentPos;
    
    
    delete playPauseButton;
    delete markerButton;
    
}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiPresent::uiPresent() {
    
    //set initial values for state
    
    scrubBox = new button;
    currentPos = new button;
    
    ofPoint pos;
    ofPoint size;
    ofColor color;
    
    float scrubHeight;
    scrubHeight = 50;
    
    
    //main scrub box
    pos.set(100, ofGetHeight()-scrubHeight);
    size.set(ofGetWidth()-pos.x, scrubHeight);
    color.set(170, 170, 170);
    scrubBox->setup(pos, size, color);
    
    
    //position indicator
    size.set(10, scrubHeight);
    color.set(0, 0, 170);
    currentPos->setup(pos, size, color);
    
    scrubLocation = new ofPoint;
    scrubLocation->set(pos);
    scrubPos.set(0, 0);
    
    
    //playback and flag
    playPauseButton = new button;
    markerButton = new button;
    
    color.set(170, 170, 170);
    
    ofPoint offSet;
    offSet.set(17, 15);
    ofImage play;
    play.loadImage("images/ui/glyphicons_173_play.png");
    ofImage pause;
    pause.loadImage("images/ui/glyphicons_174_pause.png");
    ofImage marker;
    marker.loadImage("images/ui/glyphicons_234_brush.png");
    
    pos.set(0, ofGetHeight()-scrubHeight);
    size.set(50, 50);
    playPauseButton->setup(pos, size, color, pause, play, offSet);
    
    offSet.set(16, 12);
    pos.set(50, ofGetHeight()-scrubHeight);
    markerButton->setup(pos, size, color, marker, offSet);
    
}


////////////////////////////////////////////////////////////////////
//      SET POINTS                                                //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::setPoints(vector <drawing> theDrawings, vector<flagState> theFlagStates) {

    this->theFlagStates = theFlagStates;

    drawThese.clear();
    scrubFeedback.clear();
    
    for (int i=0; i < theDrawings.size(); i++) {
        //this is the vector of drawing
        drawThese.push_back(theDrawings[i]);
    }
    
    endTime = 0;
    endTime = drawThese[0].thePoints[0].timeStamp;
    //final elapsed time of final point
    startTime = drawThese[0].thePoints[0].timeStamp;
    int drawTheseAmount = drawThese.size()-1;
    int thePointsAmount = drawThese[drawTheseAmount].thePoints.size()-1;
    endTime = drawThese[drawTheseAmount].thePoints[thePointsAmount].timeStamp;
    
    
    ofPoint mapTempPos;
    mapTempPos.y = 10;
    for (int i = 0; i < theDrawings.size(); i++){
        for (int h = 0; h < drawThese[i].thePoints.size(); h++){
            mapTempPos.x = ofMap(drawThese[i].thePoints[h].timeStamp, startTime, endTime, 100, ofGetWidth());
            mapTempPos.y *= -1;
            
            scrubFeedback.push_back(mapTempPos);
        }
    }
    
    for (int i = 0; i < scrubFeedback.size(); i++){
        scrubFeedback[i].y += ofGetHeight()-25;
    }
    
    printf(" endTime is: %d \n", endTime);
    printf(" scrubfeedback[0].x is: %f \n", scrubFeedback[0].x);
    printf(" scrubfeedback[0].y is: %f \n", scrubFeedback[0].y);

}


////////////////////////////////////////////////////////////////////
//      PLAY DATA                                                 //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::playData() {
    
    if (playPauseButton->toggle && drawThese.size() > 0) {
        
        int diff;
        currentTime = ofGetElapsedTimeMillis();
        diff =  currentTime - previousTime;
        
        //        printf(" diff is: %d \n", diff);
        
        //this advances the drawing
        if (scrubPos.x <= endTime) {
            scrubPos.x += diff;
        } else {
            scrubPos.x = startTime;
        }
        
        //        printf(" scrubPos is: %f \n", scrubPos.x);
        
        //this advances the currentPos scrubBox indicator
        scrubLocation->x = ofMap(scrubPos.x, startTime, endTime, 100, ofGetWidth());
        
        //        printf(" scrubLocation.x is: %f \n", scrubLocation->x);
        
        currentPos->update(*scrubLocation);
        
        previousTime = ofGetElapsedTimeMillis();
        
    } else {
        
        currentTime = previousTime = ofGetElapsedTimeMillis();
        scrubPos.x = ofMap(scrubLocation->x, 100, ofGetWidth(), startTime, endTime);
        
    }
    
}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::update() {
    
    playData();
    
    if (scrubBox->touching) {
        playPauseButton->toggle = false;
        scrubPos.x = ofMap(scrubLocation->x, 100, ofGetWidth(), startTime, endTime);
        currentPos->update(*scrubLocation);
    }
        
}



////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::draw(ofTrueTypeFont& basicFont) {
    
    playPauseButton->drawNoColorWithImageToggle();
    markerButton->drawNoColorWithImage();
    scrubBox->drawNoColor();
    currentPos->draw();
    
    ofSetLineWidth(2.0);
    //drawing from create
    ofSetColor(0, 0, 0);
    for (int i = 0; i < drawThese.size(); i++) {
        drawThese[i].draw(scrubPos.x);
    }
    
    ofSetLineWidth(1.0);
    if (scrubFeedback.size() > 0) {
        for (int i = 1; i < scrubFeedback.size(); i++) {
            ofLine(scrubFeedback[i-1].x, scrubFeedback[i-1].y, scrubFeedback[i].x, scrubFeedback[i].y);
        }
    }
    
    for (int i = 0; i < theFlagStates.size(); i++) {
        theFlagStates[i].draw(basicFont);
    }

    //-----------------------------------------------
    //Marker feedback
    ofSetColor(255, 220, 0);
    
    if (markerButton->toggle) {

        ofSetLineWidth(6.0);
        if (currentDrawing.size()>0) {
            for (int i = 1; i < currentDrawing.size(); i++) {
                ofLine(currentDrawing[i-1].x, currentDrawing[i-1].y, currentDrawing[i].x, currentDrawing[i].y);
            }
        }

    }
    
    //What is from marker
    
    for (int i = 0; i < markerThese.size(); i++) {
        markerThese[i].draw();
    }

    ofSetLineWidth(1.0);
    //    printf("theFlagStates.size(): %lu \n", theFlagStates.size());
}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::touchingDown(ofTouchEventArgs &touch) {
    
    playPauseButton->touchingDown(touch);
    markerButton->touchingDown(touch);
    scrubBox->touchingDown(touch);
    
    if (scrubBox->touching) {
        scrubLocation->set(touch.x, touch.y);
    }
    
    if (markerButton->toggle) {
        
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;
        
        currentDrawing.push_back(currentPos);
        thisDrawing.update(touch);
    }

    
}

//------------------------------------------------------------------
void uiPresent::touchingMove(ofTouchEventArgs &touch) {
    
    playPauseButton->touchingMove(touch);
    markerButton->touchingMove(touch);
    scrubBox->touchingMove(touch);
    
    if (scrubBox->touching && touch.x >= scrubBox->pos.x) {
        scrubLocation->set(touch.x, touch.y);
    }
    
    
    if (markerButton->toggle) {
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;
        
        currentDrawing.push_back(currentPos);
        thisDrawing.update(touch);
    }

    
}

//------------------------------------------------------------------
void uiPresent::touchingUp(ofTouchEventArgs &touch) {
    
    playPauseButton->touchingUp(touch);
    markerButton->touchingUp(touch);
    scrubBox->touchingUp(touch);
    
    if (scrubBox->thisRectangle.inside(touch.x, touch.y)) {
        scrubLocation->set(touch.x, touch.y);
    }
    
    if (markerButton->toggle) {
        currentDrawing.clear();
        markerThese.push_back(thisDrawing);
        thisDrawing.reset();
    }

}


//------------------------------------------------------------------
void uiPresent::doubleTap(ofTouchEventArgs &touch) {
    
    
}

//--------------------------------------------------------------
void uiPresent::exit() {
    
    
}

