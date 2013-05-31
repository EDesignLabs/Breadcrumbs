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
    
    //determines if identifying, planning, walking, changing, verifying
    theReflectionFlag.state = 0;
    theReflectionFlag.stateMessage = "";
    
    theReflectionFlag.floor = 0;
    
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
    
//    theReflectionFlag.color.set(0, 255, 0);
    
    //has a state been names yet, if not, show list of selections
    theReflectionFlag.ended = false;
    theReflectionFlag.selected = false;
    
    //determines if identifying, planning, walking, changing, verifying
    theReflectionFlag.state = 0;
    theReflectionFlag.stateMessage = "";
    
    theReflectionFlag.floor = 0;
    
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
    
    
    if (theReflectionFlag.startPos.x > theReflectionFlag.endPos.x) {
        float temp = theReflectionFlag.startPos.x;
        float temp2 = theReflectionFlag.endPos.x;
        theReflectionFlag.startPos.x = temp2;
        theReflectionFlag.endPos.x = temp;
        theReflectionFlag.size.x = abs(theReflectionFlag.size.x);
        theReflectionFlag.textPos.x = theReflectionFlag.endPos.x+5;
    }
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    string thisString;
    ofColor thisColor;
    
    pos.set(theReflectionFlag.startPos.x, ofGetHeight()-250);
    size.set(100, 40);
    offSet.set(6,25);
    thisString = "Identifying";
    thisColor.set(250, 7, 0, 120);
    identifying.setup(pos, size, offSet, thisString, thisColor);   

    pos.y += 40;
    thisString = "Planning";
    thisColor.set(252, 161, 0, 120);
    planning.setup(pos, size, offSet, thisString, thisColor);
    
    pos.y += 40;
    thisString = "Doing";
    thisColor.set(223, 250, 0, 120);
    walking.setup(pos, size, offSet, thisString, thisColor);
    
    pos.y += 40;
    thisString = "Changing";
    thisColor.set(15, 77, 168, 120);
    changing.setup(pos, size, offSet, thisString, thisColor);

    pos.y += 40;
    thisString = "Verifying";
    thisColor.set(140, 4, 168, 120);
    verifying.setup(pos, size, offSet, thisString, thisColor);

}

//------------------------------------------------------------------
void flagState::selectingButton() {
    
    if (identifying.selected) {
        theReflectionFlag.color.set(250, 7, 0, 120);
        theReflectionFlag.stateMessage = "Identifying";
        theReflectionFlag.state = 1;
        theReflectionFlag.selected = true;
        makeMarker();
    }

    if (planning.selected) {
        theReflectionFlag.color.set(252, 161, 0, 120);
        theReflectionFlag.stateMessage = "Planning";
        theReflectionFlag.state = 2;
        theReflectionFlag.selected = true;
        makeMarker();
    }

    if (walking.selected) {
        theReflectionFlag.color.set(223, 250, 0, 120);
        theReflectionFlag.stateMessage = "Doing";
        theReflectionFlag.state = 3;
        theReflectionFlag.selected = true;
        makeMarker();
    }

    if (changing.selected) {
        theReflectionFlag.color.set(15, 77, 168, 120);
        theReflectionFlag.stateMessage = "Changing";
        theReflectionFlag.state = 4;
        theReflectionFlag.selected = true;
        makeMarker();
    }

    if (verifying.selected) {
        theReflectionFlag.color.set(140, 4, 168, 120);
        theReflectionFlag.stateMessage = "Verifying";
        theReflectionFlag.state = 4;
        theReflectionFlag.selected = true;
        makeMarker();
    }

    theReflectionFlag.presentCheck.set(theReflectionFlag.startPos.x, theReflectionFlag.startPos.y, theReflectionFlag.size.x, theReflectionFlag.size.y);
    
}

//------------------------------------------------------------------
void flagState::makeMarker() {

    //set position of the text
    
    theReflectionFlag.textPos.x = theReflectionFlag.startPos.x+5;
    theReflectionFlag.textPos.y = theReflectionFlag.startPos.y-7;

    //adjust the size of the box frame
    theReflectionFlag.tabPos = theReflectionFlag.startPos;
    theReflectionFlag.tabPos.y-=25;
    theReflectionFlag.tabSize.x = 96;
    theReflectionFlag.tabSize.y = 25;
    
    theReflectionFlag.tabPostPos = theReflectionFlag.startPos;

    theReflectionFlag.tabPostSize.x = 10;
    theReflectionFlag.tabPostSize.y = 50;
    
    theReflectionFlag.size.y = 100;
    
}

//------------------------------------------------------------------
void flagState::adjustMarker(int floor) {
    
//    theReflectionFlag.startPos.y-=25;
    theReflectionFlag.tabPos.y-=25*floor;
    theReflectionFlag.textPos.y-=25*floor;
    
    theReflectionFlag.tabPostPos.y -= 25*floor;
    theReflectionFlag.tabPostSize.y += 25*floor;
    
    theReflectionFlag.floor = floor;
        
}

//------------------------------------------------------------------
void flagState::draw(ofTrueTypeFont& basicFont) {
    
    
    if (!theReflectionFlag.ended && !theReflectionFlag.selected) {
        
        ofSetColor(0,255,0, 120);        
        ofEnableAlphaBlending();
        //main box
        ofRect(theReflectionFlag.startPos.x, theReflectionFlag.startPos.y, theReflectionFlag.size.x, theReflectionFlag.size.y);
        
        ofDisableAlphaBlending();
    }
    
    else if (theReflectionFlag.ended && !theReflectionFlag.selected) {

        ofSetColor(255,255,255);
        ofRect(theReflectionFlag.startPos.x, ofGetHeight()-250, 100, 200);
        
        identifying.draw(basicFont);
        planning.draw(basicFont);
        walking.draw(basicFont);
        changing.draw(basicFont);
        verifying.draw(basicFont);
        
        ofSetColor(0,255,0, 120);

        ofEnableAlphaBlending();
        //main box
        ofRect(theReflectionFlag.startPos.x, theReflectionFlag.startPos.y, theReflectionFlag.size.x, theReflectionFlag.size.y);
        
        ofDisableAlphaBlending();

    } else {

        ofSetColor(theReflectionFlag.color, 120);

        ofEnableAlphaBlending();
        //main box
        ofRect(theReflectionFlag.startPos.x+10, theReflectionFlag.startPos.y, theReflectionFlag.size.x-10, theReflectionFlag.size.y);
        //tab
        ofRect(theReflectionFlag.tabPos.x, theReflectionFlag.tabPos.y, theReflectionFlag.tabSize.x, theReflectionFlag.tabSize.y);
        //post
        ofRect(theReflectionFlag.tabPostPos.x, theReflectionFlag.tabPostPos.y, theReflectionFlag.tabPostSize.x, theReflectionFlag.tabPostSize.y);

        ofSetColor(0,0,0);
        basicFont.drawString(theReflectionFlag.stateMessage, theReflectionFlag.textPos.x, theReflectionFlag.textPos.y);
        
        ofDisableAlphaBlending();
    }
}



//------------------------------------------------------------------
void flagState::touchingDown(ofTouchEventArgs &touch) {

    if (theReflectionFlag.ended && !theReflectionFlag.selected) {
        identifying.touchingDown(touch);
        planning.touchingDown(touch);
        walking.touchingDown(touch);
        changing.touchingDown(touch);
        verifying.touchingDown(touch);
    }

}

//------------------------------------------------------------------
void flagState::touchingMove(ofTouchEventArgs &touch) {
    
    if (theReflectionFlag.ended && !theReflectionFlag.selected) {
        identifying.touchingMove(touch);
        planning.touchingMove(touch);
        walking.touchingMove(touch);
        changing.touchingMove(touch);
        verifying.touchingMove(touch);
    }

}

//------------------------------------------------------------------
void flagState::touchingUp(ofTouchEventArgs &touch) {
    
    if (theReflectionFlag.ended && !theReflectionFlag.selected) {
        identifying.touchingUp(touch);
        planning.touchingUp(touch);
        walking.touchingUp(touch);
        changing.touchingUp(touch);
        verifying.touchingUp(touch);
    }

}