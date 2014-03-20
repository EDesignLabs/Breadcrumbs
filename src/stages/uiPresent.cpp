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
    
    
    //uiReflect elements
    delete currentPos;
    delete leftSide;
    delete rightSide;
    
    delete playPauseButton;
    delete markerButton;

    delete questionButton;
    delete FAQ;

}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiPresent::uiPresent() {
    
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
    markerButton = new button;
    questionButton = new button;
    
    color.set(200, 200, 200, 200);
    
    ofPoint offSet;
    offSet.set(0,0);
    ofImage play;
    ofImage pause;
    ofImage marker;
    ofImage markerTwo;
    
    play.loadImage("images/ui/Play_Low.png");
    pause.loadImage("images/ui/Pause_Low.png");
    marker.loadImage("images/ui/Marker_Low.png");
    markerTwo.loadImage("images/ui/Marker_Low_bw.png");
    
    pos.set(15, 683);
    size.set(play.getWidth(), play.getHeight());
    playPauseButton->setup(pos, size, color, pause, play, offSet);
    
    pos.set(100, 683);
    markerButton->setup(pos, size, color, marker, markerTwo,offSet);
    
    //-----------------------------------------------
    //for question button
    
    ofImage    questionImageOne;
    ofImage    questionImageTwo;
    questionImageOne.loadImage("images/ui/FAQ_Low.png");
    questionImageTwo.loadImage("images/ui/FAQ_Low_bw.png");
    
    FAQ = new ofImage;
    FAQ->loadImage("images/faq/FAQ3_Low.png");
    
    size.set(questionImageOne.getWidth(), questionImageOne.getHeight());
    pos.set(ofGetWidth()-85, 15);
    offSet.set(0, 0);
    color.set(230, 230, 230, 245);
    questionButton->setup(pos, size, color, questionImageOne, questionImageTwo, offSet);
    
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
        scrubLocation.x = ofMap(scrubPos.x, startTime, endTime, scrubBox.pos.x, _srubBoxPosEnd);
        
        //        printf(" scrubLocation.x is: %f \n", scrubLocation->x);
        
        currentPos->update(scrubLocation.x);
        
        previousTime = ofGetElapsedTimeMillis();
        
    } else {
        
        currentTime = previousTime = ofGetElapsedTimeMillis();
        scrubPos.x = ofMap(scrubLocation.x, scrubBox.pos.x, _srubBoxPosEnd, startTime, endTime);
        
    }
    
}


////////////////////////////////////////////////////////////////////
//      XML Setup Thang                                           //
////////////////////////////////////////////////////////////////////

//XML Setup Thang used to be here
//Use XML Setup Thang from xmlParty.h

////////////////////////////////////////////////////////////////////
//      Get XML                                                   //
////////////////////////////////////////////////////////////////////

//Get XML used to be here
//Use get XML from xmlParty.h

////////////////////////////////////////////////////////////////////
//      SAVE XML                                                  //
////////////////////////////////////////////////////////////////////

//Save XML used to be here
//Use Save XML from xmlParty.h



////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::update() {
    
    playData();
    
    if (scrubBox.touching) {
        playPauseButton->toggle = false;
        scrubPos.x = ofMap(scrubLocation.x, scrubBox.pos.x, _srubBoxPosEnd, startTime, endTime);
        currentPos->update(scrubLocation.x);
    }
 
}



////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::draw(ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36, bool loadedImage, ofImage& grid) {
    
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
    //What is from marker
    
    for (int i = 0; i < markerThese.size(); i++) {
        ofSetColor(markerThese[i].color);
        ofSetLineWidth(markerThese[i].lineWidth);
        markerThese[i].draw();
    }
    
    //-----------------------------------------------
    //Marker feedback
    
    ofSetColor(255, 220, 0);
    
    ofSetLineWidth(6.0);
    if (currentDrawing.size()>0) {
        for (int i = 1; i < currentDrawing.size(); i++) {
            ofLine(currentDrawing[i-1].x, currentDrawing[i-1].y, currentDrawing[i].x, currentDrawing[i].y);
        }
    }
    ofSetLineWidth(1.0);
    
    //-----------------------------------------------
    //Scrub Box Feedback
    
    leftSide->drawNoColorTransparency();
    rightSide->drawNoColorTransparency();
    scrubBox.drawNoColorTransparency();
    currentPos->draw();
    
    //-----------------------------------------------
    //Tool Button UI
    
    playPauseButton->drawTwoImages();
    markerButton->drawTwoImages();
    
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
    //Reflection flags

    for (int i = 0; i < theFlagStates.size(); i++) {
        theFlagStates[i].draw(quicksandBold36);
    }
    
    
    //-----------------------------------------------
    //if image
    
    if (loadedImage) {
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255);
        grid.draw(175, 300);
        ofDisableAlphaBlending();
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
void uiPresent::touchingDown(ofTouchEventArgs &touch) {
    
    playPauseButton->touchingDown(touch);
    markerButton->touchingDown(touch);
    scrubBox.touchingDown(touch);
    questionButton->touchingDown(touch);
    
    if (scrubBox.touching) {
        scrubLocation.set(touch.x, touch.y);
    }
    
    if (markerButton->toggle) {
        
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;
        
        currentDrawing.push_back(currentPos);
        
        //checks to see what flag we're in
        for (int i = 0; i < theFlagStates.size(); i++) {
        
            if (theFlagStates[i].theReflectionFlag.presentCheck.inside(scrubLocation.x, scrubLocation.y)){
        
                markerColor.set(theFlagStates[i].theReflectionFlag.color);
//                printf(" found a color that matches! \n ");
                break;
            } else {
                markerColor.set(0,255,0);
            }
        }
        
        float lineWidth;
        lineWidth = 6.0;
        thisDrawing.update(touch, markerColor, lineWidth);
    }

    
}

//------------------------------------------------------------------
void uiPresent::touchingMove(ofTouchEventArgs &touch) {
    
    playPauseButton->touchingMove(touch);
    markerButton->touchingMove(touch);
    scrubBox.touchingMove(touch);
    questionButton->touchingMove(touch);
    
    if (scrubBox.touching && touch.x >= scrubBox.pos.x && touch.x < _srubBoxPosEnd && touch.y > scrubBox.pos.y) {
        scrubLocation.set(touch.x, touch.y);
    }

    
    if (markerButton->toggle) {
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;
        
        currentDrawing.push_back(currentPos);
        
        ofColor thisColor;
        thisColor.set(255, 220, 0);
        float lineWidth;
        lineWidth = 6.0;
        
        for (int i = 0; i < theFlagStates.size(); i++) {
            
            if (theFlagStates[i].theReflectionFlag.presentCheck.inside(scrubLocation.x, scrubLocation.y)){
                
                markerColor.set(theFlagStates[i].theReflectionFlag.color);
//                printf(" found a color that matches! \n ");
                break;
            } else {
                markerColor.set(0,255,0);
            }
        }

        
        thisDrawing.update(touch, markerColor, lineWidth);
    }

    
}

//------------------------------------------------------------------
void uiPresent::touchingUp(ofTouchEventArgs &touch) {
    
    playPauseButton->touchingUp(touch);
    markerButton->touchingUp(touch);
    scrubBox.touchingUp(touch);
    questionButton->touchingUp(touch);
    
    if (scrubBox.thisRectangle.inside(touch.x, touch.y)) {
        scrubLocation.set(touch.x, touch.y);
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
