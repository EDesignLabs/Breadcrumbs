/*
 *  uiReflect.cpp
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#include "uiReflect.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiReflect::~uiReflect() {
    
    //uiReflect elements
    delete scrubBox;
    delete scrubLocation;
    delete currentPos;
    
    
    delete playPauseButton;
    delete flagButton;

}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiReflect::uiReflect() {
    
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
    flagButton = new button;

    color.set(170, 170, 170);
    
    ofPoint offSet;
    offSet.set(17, 15);
    ofImage play;
    play.loadImage("images/ui/glyphicons_173_play.png");
    ofImage pause;
    pause.loadImage("images/ui/glyphicons_174_pause.png");
    ofImage flag;
    flag.loadImage("images/ui/glyphicons_266_flag.png");

    pos.set(0, ofGetHeight()-scrubHeight);
    size.set(50, 50);
    playPauseButton->setup(pos, size, color, pause, play, offSet);

    offSet.set(16, 12);
    pos.set(50, ofGetHeight()-scrubHeight);
    flagButton->setup(pos, size, color, flag, offSet);
    
}



////////////////////////////////////////////////////////////////////
//      SET POINTS                                                //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::setPoints(vector <drawing> theDrawings) {
    
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
void uiReflect::playData() {
    
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
void uiReflect::update() {
    
    playData();
    
    if (scrubBox->touching) {
        playPauseButton->toggle = false;
        scrubPos.x = ofMap(scrubLocation->x, 100, ofGetWidth(), startTime, endTime);
        currentPos->update(*scrubLocation);
    }
    
    if (theFlagState.theReflectionFlag.ended) {
        
        theFlagState.selectingButton();
        
        if (theFlagState.theReflectionFlag.selected) {
            checkFlags();
            theFlagStates.push_back(theFlagState);
            theFlagState.reset();
        }
        
    }
    
}


//------------------------------------------------------------------
void uiReflect::checkFlags() {

                   // theFlagState.adjustMarker();
    bool    floor [20];
    
    for (int i = 0; i<20; i++) {
        floor[i] = false;
    }
    
    bool    chosen = 0;
    int     counter = 0;

    printf("theFlagStates.size = %ld \n", theFlagStates.size());

    //first get all the floors that are taken
    if (theFlagStates.size() >= 1) {
        for (int i = 0; i<theFlagStates.size(); i++) {
            
            float dist = theFlagStates[i].theReflectionFlag.startPos.x - theFlagState.theReflectionFlag.startPos.x;
            
            dist = abs(dist);
            printf("dist = %f \n", dist);
            
            if (dist < 96) {
                floor[theFlagStates[i].theReflectionFlag.floor] = true;
            }
        
        }
    
        for (int i = 0; i < 20; i++) {
            printf("floor: %d, ", i);
            printf("true/false: %d \n ", floor[i]);
        }
        
        while (chosen == false) {
            printf("chosen run: %d \n", counter);
            //check through each floor.
            //if true, go to next.
            //if false, assign the floor to current flag
            if (floor[counter]==true) {
                counter++;
            } else {
                theFlagState.adjustMarker(counter);
                chosen = true;
            }
        }
    }
}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::draw(ofTrueTypeFont& basicFont) {

    playPauseButton->drawNoColorWithImageToggle();
    flagButton->drawNoColorWithImage();
    scrubBox->drawNoColor();
    currentPos->draw();
    
//    ofSetLineWidth(2.0);
//    ofSetColor(0, 0, 0);
    for (int i = 0; i < drawThese.size(); i++) {
        ofSetColor(drawThese[i].thePoints[0].color);
        ofSetLineWidth(drawThese[i].thePoints[0].lineWidth);
        drawThese[i].draw(scrubPos.x);
    } 
    
    ofSetColor(0, 0, 0);
    ofSetLineWidth(1.0);
    if (scrubFeedback.size() > 0) {
        for (int i = 1; i < scrubFeedback.size(); i++) {
            ofLine(scrubFeedback[i-1].x, scrubFeedback[i-1].y, scrubFeedback[i].x, scrubFeedback[i].y);
        }
    }
    
    if (flagButton->toggle) {
        for (int i = 0; i < theFlagStates.size(); i++) {
            theFlagStates[i].draw(basicFont);
        }
        
        theFlagState.draw(basicFont);
    }

    
//    printf("theFlagStates.size(): %lu \n", theFlagStates.size());
}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::touchingDown(ofTouchEventArgs &touch) {

        playPauseButton->touchingDown(touch);
        flagButton->touchingDown(touch);
        scrubBox->touchingDown(touch);

        if (scrubBox->touching) {
            scrubLocation->set(touch.x, touch.y);
            theFlagState.updateStart(touch);
        }
    
        theFlagState.touchingDown(touch);
    
}

//------------------------------------------------------------------
void uiReflect::touchingMove(ofTouchEventArgs &touch) {

        playPauseButton->touchingMove(touch);
        flagButton->touchingMove(touch);
        scrubBox->touchingMove(touch);

        if (scrubBox->touching && touch.x >= scrubBox->pos.x) {
            scrubLocation->set(touch.x, touch.y);
            theFlagState.update(touch);
        }
    
        theFlagState.touchingMove(touch);
    
}

//------------------------------------------------------------------
void uiReflect::touchingUp(ofTouchEventArgs &touch) {

        playPauseButton->touchingUp(touch);
        flagButton->touchingUp(touch);
        scrubBox->touchingUp(touch);

        if (scrubBox->thisRectangle.inside(touch.x, touch.y)) {
            scrubLocation->set(touch.x, touch.y);
            theFlagState.updateEnd(touch);
        }

        theFlagState.touchingUp(touch);
}


//------------------------------------------------------------------
void uiReflect::doubleTap(ofTouchEventArgs &touch) {


}

//--------------------------------------------------------------
void uiReflect::exit() {


}

