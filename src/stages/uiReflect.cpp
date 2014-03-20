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
    delete currentPos;
    delete leftSide;
    delete rightSide;    
    
    delete playPauseButton;
    delete flagButton;
    delete questionButton;
    delete FAQ;

}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiReflect::uiReflect() {
    
    //-----------------------------------------------
    //scrubBox
    currentPos = new button;
    leftSide = new button;
    rightSide = new button;
    
    ofPoint pos;
    ofPoint size;
    ofColor color;
    
    scrubHeight = 50;
    
    scrubWidth = ofGetWidth()-(2*185);
    
    //-----------------------------------------------
    //main scrub box
    pos.set(185, ofGetHeight()-scrubHeight);
    size.set(scrubWidth, scrubHeight);
    color.set(230, 230, 230, 245);
    scrubBox.setup(pos, size, color);

    _srubBoxPosEnd = scrubBox.pos.x + scrubBox.thisRectangle.getWidth();
    
    //position indicator
    size.set(3, scrubHeight);
    color.set(91, 138, 205);
    currentPos->setup(pos, size, color);
    
    scrubLocation.set(pos);
    scrubPos.set(0, 0);
    
    pos.set(0, ofGetHeight()-scrubHeight);
    size.set(scrubBox.pos.x, scrubHeight);
    color.set(230, 230, 230, 245);
    leftSide->setup(pos, size, color);
    
    pos.set(_srubBoxPosEnd, ofGetHeight()-scrubHeight);
    size.set(185, scrubHeight);
    color.set(230, 230, 230, 245);
    rightSide->setup(pos, size, color);
    
    
    //-----------------------------------------------
    //playback and flag
    playPauseButton = new button;
    flagButton = new button;
    questionButton = new button;

    color.set(200, 200, 200, 200);
    
    ofPoint offSet;
    offSet.set(0,0);
    ofImage play;
    ofImage pause;
    ofImage flag;
    ofImage flagTwo;
    
    play.loadImage("images/ui/Play_Low.png");
    pause.loadImage("images/ui/Pause_Low.png");
    flag.loadImage("images/ui/Flag_Low.png");
    flagTwo.loadImage("images/ui/Flag_Low_bw.png");
    
    pos.set(15, 683);
    size.set(play.getWidth(), play.getHeight());
    playPauseButton->setup(pos, size, color, pause, play, offSet);
    
    pos.set(100, 683);
    flagButton->setup(pos, size, color, flag, offSet);
    flagButton->setup(pos, size, color, flag, flagTwo, offSet);
    flagButton->toggle = true;
    
    //-----------------------------------------------
    //for question button
    
    ofImage    questionImageOne;
    ofImage    questionImageTwo;
    questionImageOne.loadImage("images/ui/FAQ_Low.png");
    questionImageTwo.loadImage("images/ui/FAQ_Low_bw.png");

    FAQ = new ofImage;
    FAQ->loadImage("images/faq/FAQ2_Low.png");
    
    size.set(questionImageOne.getWidth(), questionImageOne.getHeight());
    pos.set(ofGetWidth()-85, 15);
    offSet.set(0, 0);
    color.set(230, 230, 230, 245);
    questionButton->setup(pos, size, color, questionImageOne, questionImageTwo, offSet);
    
}



////////////////////////////////////////////////////////////////////
//      SET POINTS                                                //
////////////////////////////////////////////////////////////////////

//Set Points used to be here
//Use Set Points from xmlParty.h



////////////////////////////////////////////////////////////////////
//      PLAY DATA                                                 //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::playData() {
    
    if (playPauseButton->toggle && drawThese.size() > 0) {
        
        int diff;
        currentTime = ofGetElapsedTimeMillis();
        diff =  currentTime - previousTime;
            
        //-----------------------------------------------
        //this advances the drawing
        if (scrubPos.x <= endTime) {
            scrubPos.x += diff;
        } else {
            scrubPos.x = startTime;
        }

        
        //-----------------------------------------------
        //this advances the currentPos scrubBox indicator

        scrubLocation.x = ofMap(scrubPos.x, startTime, endTime, scrubBox.pos.x, _srubBoxPosEnd);
        currentPos->update(scrubLocation.x);
        previousTime = ofGetElapsedTimeMillis();
   
    } else {
        
        currentTime = previousTime = ofGetElapsedTimeMillis();
        scrubPos.x = ofMap(scrubLocation.x, scrubBox.pos.x, _srubBoxPosEnd, startTime, endTime);

    }
    
}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::update() {
    
    playData();
    
    //-----------------------------------------------
    //Check the scrubBox

    if (scrubBox.touching) {
        playPauseButton->toggle = false;
        scrubPos.x = ofMap(scrubLocation.x, scrubBox.pos.x, _srubBoxPosEnd, startTime, endTime);
        currentPos->update(scrubLocation.x);
    }
    
    if (theFlagState.theReflectionFlag.ended) {
        
        theFlagState.selectingButton();
        
        if (theFlagState.theReflectionFlag.selected) {
            checkFlags();
            theFlagStates.push_back(theFlagState);
            theFlagState.reset();
        }
    }
    
    for (int i = 0; i < theFlagStates.size(); i++){
        if (theFlagStates[i].theReflectionFlag.removeFlagButton.selected) {
            theFlagStates.erase( theFlagStates.begin()+i );
        }
    }

}


////////////////////////////////////////////////////////////////////
//      CHECKED FLAGS                                             //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::checkFlags() {

    bool    floor [100];
    
    for (int i = 0; i<100; i++) {
        floor[i] = false;
    }
    
    bool    chosen = 0;
    int     counter = 0;

    //-----------------------------------------------
    //first get all the floors that are taken

    if (theFlagStates.size() >= 1) {
        for (int i = 0; i<theFlagStates.size(); i++) {
            
            float dist = theFlagStates[i].theReflectionFlag.startPos.x - theFlagState.theReflectionFlag.startPos.x;
            
            dist = abs(dist);
            
            if (dist < 140) {
                floor[theFlagStates[i].theReflectionFlag.floor] = true;
            }
        }
    
        while (chosen == false) {
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
//      CHECKED SAVED FLAGS                                       //
////////////////////////////////////////////////////////////////////

//Checked Saved Flags used to be here
//Use Checked Save Flags from xmlParty.h



////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::draw(ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36, bool loadedImage, ofImage& grid) {
    

    //-----------------------------------------------
    //calculating translate
    
    ofPushMatrix();
    ofPoint moveMe, start;
    moveMe.set(0, 0);
    start.set(0, 0);
    
    int drawingTheseOnes = drawThese.size();
    drawingTheseOnes--;
    
    for (int i = drawingTheseOnes; i >= 0; i--) {
        
        moveMe = drawThese[i].returnMoveMe(scrubPos.x);
        
        if (moveMe != start) {
//            printf(" MoveMeMain X: %f \n", moveMe.x);
//            printf(" MoveMeMain Y: %f \n", moveMe.y);
            break;
        }
        
    }
    
    ofTranslate(moveMe.x, moveMe.y);
    
    
    //-----------------------------------------------
    //actual drawing
    
    for (int i = 0; i < drawThese.size(); i++) {
        ofSetColor(drawThese[i].color);
        ofSetLineWidth(drawThese[i].lineWidth);
        drawThese[i].draw(scrubPos.x);
    }
    
    ofPopMatrix();
    
    //-----------------------------------------------
    //Scrub Box Feedback
    
    leftSide->drawNoColorTransparency();
    rightSide->drawNoColorTransparency();
    scrubBox.drawNoColorTransparency();
    currentPos->draw();

    //-----------------------------------------------
    //Tool Button UI
    
    playPauseButton->drawTwoImages();
    flagButton->drawTwoImages();
    
    //-----------------------------------------------
    //Boundaries of the scrubBox
    ofSetColor(0, 0, 0);
    ofRect(scrubBox.pos.x-1, scrubBox.pos.y, 3, scrubHeight);
    ofRect(rightSide->pos.x, rightSide->pos.y, 3, scrubHeight);
    
    ofSetColor(0, 0, 0);
    ofSetLineWidth(1.0);
    if (scrubFeedback.size() > 0) {
        for (int i = 1; i < scrubFeedback.size(); i++) {
            ofLine(scrubFeedback[i-1].x, scrubFeedback[i-1].y, scrubFeedback[i].x, scrubFeedback[i].y);
        }
    }
    
    
    //-----------------------------------------------
    //grid
    
    if (loadedImage) {
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255);
        grid.draw(175, 300);
        ofDisableAlphaBlending();        
    }

    
    //-----------------------------------------------
    //flags
    
    if (flagButton->toggle) {
        for (int i = 0; i < theFlagStates.size(); i++) {
            theFlagStates[i].drawRemove(quicksandBold36);
        }
        
        theFlagState.drawRemove(quicksandBold36);
        
    } else {
        
        for (int i = 0; i < theFlagStates.size(); i++) {
            theFlagStates[i].draw(quicksandBold36);
        }
    }
    
    
    //-----------------------------------------------
    //FAQ

    ofSetColor(255,255,255);
    if (questionButton->toggle) {
        ofEnableAlphaBlending();
        ofSetColor(70, 70, 70, 180);
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
        ofSetColor(255, 255, 255, 255);
        FAQ->draw(0, 0);
        ofDisableAlphaBlending();
    }

    //-----------------------------------------------
    //question mark
    ofSetColor(230, 230, 230, 245);
    ofRect(923, 0, 101, 50);
    questionButton->drawTwoImages();
    ofDisableAlphaBlending();

    
}

////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::touchingDown(ofTouchEventArgs &touch) {

//        printf("started UI Reflect touching down \n");

        playPauseButton->touchingDown(touch);
//        flagButton->touchingDown(touch);
        scrubBox.touchingDown(touch);
        questionButton->touchingDown(touch);
        
        if (scrubBox.touching) {
            scrubLocation.set(touch.x, touch.y);
            theFlagState.updateStart(touch, startTime, endTime, scrubBox.pos.x, _srubBoxPosEnd);
        } else if (theFlagState.theReflectionFlag.ended && !theFlagState.taskBox.inside(touch.x, touch.y)) {
            theFlagState.theReflectionFlag.ended = false;
        }
    
        theFlagState.touchingDown(touch);
    
        if (flagButton->toggle && !theFlagState.theReflectionFlag.ended) {
            for (int i = 0; i < theFlagStates.size(); i++) {
                theFlagStates[i].touchingDown(touch);
            }
        }

//        printf("ended UI Reflect touching down \n");
    
}

//------------------------------------------------------------------
void uiReflect::touchingMove(ofTouchEventArgs &touch) {

//        printf("started UI Reflect touching move \n");
    
        playPauseButton->touchingMove(touch);
//        flagButton->touchingMove(touch);
        scrubBox.touchingMove(touch);
        questionButton->touchingMove(touch);
    
        if (scrubBox.touching && touch.x >= scrubBox.pos.x && touch.x < _srubBoxPosEnd && touch.y > scrubBox.pos.y) {
            scrubLocation.set(touch.x, touch.y);
            theFlagState.update(touch, startTime, endTime, scrubBox.pos.x, _srubBoxPosEnd);
        }
    
        theFlagState.touchingMove(touch);
    

        if (flagButton->toggle && !theFlagState.theReflectionFlag.ended) {
            for (int i = 0; i < theFlagStates.size(); i++) {
                theFlagStates[i].touchingMove(touch);
            }
        }
    
//        printf("ended UI Reflect touching move \n");

}

//------------------------------------------------------------------
void uiReflect::touchingUp(ofTouchEventArgs &touch) {

    
//        printf("started UI Reflect touching up \n");
    
        //first check to see if we are inside the scrubBox
        if (scrubBox.thisRectangle.inside(touch.x, touch.y) && theFlagState.theReflectionFlag.started) {
            scrubLocation.set(touch.x, touch.y);
            theFlagState.updateEnd(touch, startTime, endTime, scrubBox.pos.x, _srubBoxPosEnd);
        }
        
        else if (rightSide->thisRectangle.inside(touch.x, touch.y) && theFlagState.theReflectionFlag.started) {
            scrubLocation.set(touch.x, touch.y);
            theFlagState.updateEnd(touch, startTime, endTime, scrubBox.pos.x, _srubBoxPosEnd);
        }
        
        else if (leftSide->thisRectangle.inside(touch.x, touch.y) && theFlagState.theReflectionFlag.started) {
            scrubLocation.set(touch.x, touch.y);
            theFlagState.updateEnd(touch, startTime, endTime, scrubBox.pos.x, _srubBoxPosEnd);
        }

        //then we release the scrubBox
        playPauseButton->touchingUp(touch);
//        flagButton->touchingUp(touch);
        scrubBox.touchingUp(touch);
        questionButton->touchingUp(touch);
    

    
        theFlagState.touchingUp(touch);

        if (flagButton->toggle && !theFlagState.theReflectionFlag.ended) {
            for (int i = 0; i < theFlagStates.size(); i++) {
                theFlagStates[i].touchingUp(touch);
            }
        }

//        printf("ended UI Reflect touching move \n");
    
}


//------------------------------------------------------------------
void uiReflect::doubleTap(ofTouchEventArgs &touch) {


}

//--------------------------------------------------------------
void uiReflect::exit() {


}

