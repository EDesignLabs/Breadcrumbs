/*
 *  flagState.cpp
 *
 *  Created by Ryan Raffa on 5/3/13.
 *
 */

#include "flagState.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
flagState::~flagState() {
    
}


//------------------------------------------------------------------
void flagState::reset() {
    
    printf(" flagState setup started \n");
    
    //-----------------------------------------------
    //set up the reflection flag
    
    theReflectionFlag.startPos.set(10, 10);
    theReflectionFlag.endPos.set(0, 0);
    theReflectionFlag.size.set(0, 0);
    
    theReflectionFlag.color.set(0, 255, 0);
    
    //has a state been names yet, if not, show list of selections
    theReflectionFlag.ended = false;
    theReflectionFlag.selected = false;
    
    //determines if decoding, planning, doing, checking
    theReflectionFlag.state = 0;
    theReflectionFlag.stateMessage = "";
    
    printf(" flagState setup ended \n");
    
}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
flagState::flagState() {
    
    printf(" flagState setup started \n");
    
//-----------------------------------------------
//set up the reflection flag
    
    theReflectionFlag.startPos.set(10, 10);
    theReflectionFlag.endPos.set(0, 0);
    theReflectionFlag.size.set(0, 0);
    
    theReflectionFlag.color.set(0, 255, 0);
    
    //has a state been names yet, if not, show list of selections
    theReflectionFlag.ended = false;
    theReflectionFlag.selected = false;
    
    //determines if decoding, planning, doing, checking
    theReflectionFlag.state = 0;
    theReflectionFlag.stateMessage = "";
    
    printf(" flagState setup ended \n");

    
    
}

		 
////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void flagState::updateStart(ofTouchEventArgs &touch) {
    
    theReflectionFlag.selected = false;
    theReflectionFlag.ended = false;
    theReflectionFlag.size.x = 0;
    theReflectionFlag.color.set(0, 255, 0);
    
    theReflectionFlag.startPos.x = touch.x;
    theReflectionFlag.startPos.y = ofGetHeight()-50;
    
}

//------------------------------------------------------------------
void flagState::update(ofTouchEventArgs &touch) {
    
    theReflectionFlag.endPos.x = touch.x;
    theReflectionFlag.endPos.y = ofGetHeight()-50;
    
    theReflectionFlag.size.x = theReflectionFlag.endPos.x - theReflectionFlag.startPos.x;
    theReflectionFlag.size.y = ofGetHeight()-50;


}

//------------------------------------------------------------------
void flagState::updateEnd(ofTouchEventArgs &touch) {
    
    theReflectionFlag.endPos.x = touch.x;
    theReflectionFlag.endPos.y = ofGetHeight()-50;

    createButtons();

    theReflectionFlag.ended = true;

}


//------------------------------------------------------------------
void flagState::createButtons() {
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    string thisString;
    ofColor thisColor;
    
    pos.set(theReflectionFlag.startPos.x, ofGetHeight()-210);
    size.set(100, 40);
    offSet.set(10,20);
    thisString = "Decoding";
    thisColor.set(255, 128, 128);
    decoding.setup(pos, size, offSet, thisString, thisColor);   

    pos.y += 40;
    thisString = "Planning";
    thisColor.set(252, 214, 129);
    planning.setup(pos, size, offSet, thisString, thisColor);
    
    pos.y += 40;
    thisString = "Doing";
    thisColor.set(250, 255, 159);
    doing.setup(pos, size, offSet, thisString, thisColor);
    
    pos.y += 40;
    thisString = "Checking";
    thisColor.set(252, 139, 244);
    checking.setup(pos, size, offSet, thisString, thisColor);

}

//------------------------------------------------------------------
void flagState::selectingButton() {
    
    if (decoding.selected) {
        theReflectionFlag.color.set(255, 128, 128);
        theReflectionFlag.stateMessage = "Decoding";
        theReflectionFlag.state = 1;
        theReflectionFlag.selected = true;
    }

    if (planning.selected) {
        theReflectionFlag.color.set(252, 214, 129);
        theReflectionFlag.stateMessage = "Planning";
        theReflectionFlag.state = 2;
        theReflectionFlag.selected = true;
    }

    if (doing.selected) {
        theReflectionFlag.color.set(250, 255, 159);
        theReflectionFlag.stateMessage = "Doing";
        theReflectionFlag.state = 3;
        theReflectionFlag.selected = true;
    }

    if (checking.selected) {
        theReflectionFlag.color.set(252, 139, 244);
        theReflectionFlag.stateMessage = "Checking";
        theReflectionFlag.state = 4;
        theReflectionFlag.selected = true;
    }
    
}

//------------------------------------------------------------------
void flagState::draw(ofTrueTypeFont& basicFont) {
    
    if (theReflectionFlag.ended && !theReflectionFlag.selected) {
        decoding.draw(basicFont);
        planning.draw(basicFont);
        doing.draw(basicFont);
        checking.draw(basicFont);
    }
    
    ofEnableAlphaBlending();
    ofSetColor(0,0,0);
    basicFont.drawString(theReflectionFlag.stateMessage, theReflectionFlag.startPos.x, theReflectionFlag.startPos.y-5);
    ofSetColor(theReflectionFlag.color, 120);
    ofRect(theReflectionFlag.startPos.x, theReflectionFlag.startPos.y, theReflectionFlag.size.x, theReflectionFlag.size.y);
    ofDisableAlphaBlending();
    
}



//------------------------------------------------------------------
void flagState::touchingDown(ofTouchEventArgs &touch) {

    if (theReflectionFlag.ended) {
        decoding.touchingDown(touch);
        planning.touchingDown(touch);
        doing.touchingDown(touch);
        checking.touchingDown(touch);
    }

}

//------------------------------------------------------------------
void flagState::touchingMove(ofTouchEventArgs &touch) {
    
    if (theReflectionFlag.ended) {
        decoding.touchingMove(touch);
        planning.touchingMove(touch);
        doing.touchingMove(touch);
        checking.touchingMove(touch);
    }

}

//------------------------------------------------------------------
void flagState::touchingUp(ofTouchEventArgs &touch) {
    
    if (theReflectionFlag.ended) {
        decoding.touchingUp(touch);
        planning.touchingUp(touch);
        doing.touchingUp(touch);
        checking.touchingUp(touch);
    }

}