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
    
//    printf(" flagState setup started \n");
    
    //-----------------------------------------------
    //set up the reflection flag
    
    theReflectionFlag.startPos.set(10, 10);
    theReflectionFlag.endPos.set(0, 0);
    theReflectionFlag.size.set(0, 0);
    
    theReflectionFlag.color.set(0, 255, 0);
    
    //has a state been names yet, if not, show list of selections
    theReflectionFlag.started = false;
    theReflectionFlag.ended = false;
    theReflectionFlag.selected = false;
    
    theReflectionFlag.removeFlagButton.selected = false;
    
    //determines if identifying, planning, walking, changing, verifying
    theReflectionFlag.state = 0;
    theReflectionFlag.stateMessage = "";
    
    theReflectionFlag.floor = 0;
    
//    printf(" flagState setup ended \n");
    
}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
flagState::flagState() {
    
//    printf(" flagState setup started \n");
    
//-----------------------------------------------
//set up the reflection flag
    
    theReflectionFlag.startPos.set(10, 10);
    theReflectionFlag.endPos.set(0, 0);
    theReflectionFlag.size.set(0, 0);
    
//    theReflectionFlag.color.set(0, 255, 0);
    
    //has a state been names yet, if not, show list of selections
    theReflectionFlag.started = false;
    theReflectionFlag.ended = false;
    theReflectionFlag.selected = false;
    
    //determines if identifying, planning, walking, changing, verifying
    theReflectionFlag.state = 0;
    theReflectionFlag.stateMessage = "";
    
    theReflectionFlag.floor = 0;
    
    
    //skip intro button
    ofImage removeFlagImage;
    removeFlagImage.loadImage("images/ui/glyphicons_207_remove_2.png");
    ofPoint pos;
    pos.set(0,0);
    ofPoint size;
    size.set(25,40);
    ofColor color;
    color.set(170, 170, 170, 120);
    ofPoint offSet;
    offSet.set(3,10);
    theReflectionFlag.removeFlagButton.setup(pos, size, color, removeFlagImage, offSet);
    
//    printf(" flagState setup ended \n");
    
}

		 
////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void flagState::updateStart(ofTouchEventArgs &touch, int startTime, int endTime, int startPos, int endPos) {

    theReflectionFlag.started = true;
    theReflectionFlag.selected = false;
    theReflectionFlag.ended = false;
    theReflectionFlag.size.x = 0;
    theReflectionFlag.color.set(0, 255, 0);
    
    theReflectionFlag.startPos.x = touch.x;
    theReflectionFlag.startPos.y = ofGetHeight()-50;
    
    theReflectionFlag.startTime = ofMap(theReflectionFlag.startPos.x, startPos, endPos, startTime, endTime);
    
}

//------------------------------------------------------------------
void flagState::update(ofTouchEventArgs &touch, int startTime, int endTime, int startPos, int endPos) {
    
    theReflectionFlag.endPos.x = touch.x;
    theReflectionFlag.endPos.y = ofGetHeight()-50;
    
    theReflectionFlag.size.x = theReflectionFlag.endPos.x - theReflectionFlag.startPos.x;
    theReflectionFlag.size.y = ofGetHeight()-50;
    
    theReflectionFlag.endTime = ofMap(theReflectionFlag.endPos.x, startPos, endPos, startTime, endTime);


}

//------------------------------------------------------------------
void flagState::updateEnd(ofTouchEventArgs &touch, int startTime, int endTime, float srubBoxPosBegin, float srubBoxPosEnd) {
    
    if (touch.x < srubBoxPosBegin) {
        theReflectionFlag.endPos.x = srubBoxPosBegin;
    } else if (touch.x > srubBoxPosEnd) {
        theReflectionFlag.endPos.x = srubBoxPosEnd;
    } else {
        theReflectionFlag.endPos.x = touch.x;
    }
    
    theReflectionFlag.endPos.y = ofGetHeight()-50;

    adjustTime();
    
    theReflectionFlag.startTime = ofMap(theReflectionFlag.startPos.x, srubBoxPosBegin, srubBoxPosEnd, startTime, endTime);
    theReflectionFlag.endTime = ofMap(theReflectionFlag.endPos.x, srubBoxPosBegin, srubBoxPosEnd, startTime, endTime);
    
    createButtons();
    
    theReflectionFlag.ended = true;

}


//------------------------------------------------------------------
void flagState::newStartEndTime(int& startTime, int& endTime, float& startPos, float& endPos) {
    
    theReflectionFlag.startPos.x = ofMap(theReflectionFlag.startTime, startTime, endTime, startPos, endPos);
    theReflectionFlag.endPos.x = ofMap(theReflectionFlag.endTime, startTime, endTime, startPos, endPos);

}


//------------------------------------------------------------------
void flagState::adjustTime() {
    
    if (theReflectionFlag.startPos.x > theReflectionFlag.endPos.x) {
        float temp = theReflectionFlag.startPos.x;
        float temp2 = theReflectionFlag.endPos.x;
        theReflectionFlag.startPos.x = temp2;
        theReflectionFlag.endPos.x = temp;
        theReflectionFlag.size.x = abs(theReflectionFlag.size.x);
        theReflectionFlag.textPos.x = theReflectionFlag.endPos.x+15;
    }
}

//------------------------------------------------------------------
void flagState::createButtons() {
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    string thisString;
    ofColor thisColor;
    
    pos.set(theReflectionFlag.startPos.x, ofGetHeight()-250);
    size.set(140, 40);
    offSet.set(15,25);
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

    taskBox.set (theReflectionFlag.startPos.x, ofGetHeight()-250, 140, 200);
    
}

//------------------------------------------------------------------
void flagState::selectingButton() {
    
    if (identifying.selected) {
        theReflectionFlag.color.set(250, 7, 0, 120);
        theReflectionFlag.stateMessage = "Identifying";
        theReflectionFlag.state = 1;
        theReflectionFlag.selected = true;
        theReflectionFlag.removeFlagButton.selected = false;
        makeMarker();
    }

    if (planning.selected) {
        theReflectionFlag.color.set(252, 161, 0, 120);
        theReflectionFlag.stateMessage = "Planning";
        theReflectionFlag.state = 2;
        theReflectionFlag.selected = true;
        theReflectionFlag.removeFlagButton.selected = false;
        makeMarker();
    }

    if (walking.selected) {
        theReflectionFlag.color.set(223, 250, 0, 120);
        theReflectionFlag.stateMessage = "Doing";
        theReflectionFlag.state = 3;
        theReflectionFlag.selected = true;
        theReflectionFlag.removeFlagButton.selected = false;
        makeMarker();
    }

    if (changing.selected) {
        theReflectionFlag.color.set(15, 77, 168, 120);
        theReflectionFlag.stateMessage = "Changing";
        theReflectionFlag.state = 4;
        theReflectionFlag.selected = true;
        theReflectionFlag.removeFlagButton.selected = false;
        makeMarker();
    }

    if (verifying.selected) {
        theReflectionFlag.color.set(140, 4, 168, 120);
        theReflectionFlag.stateMessage = "Verifying";
        theReflectionFlag.state = 4;
        theReflectionFlag.selected = true;
        theReflectionFlag.removeFlagButton.selected = false;
        makeMarker();
    }

}

//------------------------------------------------------------------
void flagState::makeMarker() {

    //set position of the text
    
    theReflectionFlag.textPos.x = theReflectionFlag.startPos.x+15;
    theReflectionFlag.textPos.y = theReflectionFlag.startPos.y-15;

    //adjust the size of the box frame
    theReflectionFlag.tabPos = theReflectionFlag.startPos;
    theReflectionFlag.tabPos.y-=40;
    theReflectionFlag.tabSize.x = 140;
    theReflectionFlag.tabSize.y = 40;
    
    theReflectionFlag.tabPostPos = theReflectionFlag.startPos;

    theReflectionFlag.tabPostSize.x = 10;
    theReflectionFlag.tabPostSize.y = 50;
    
    theReflectionFlag.size.y = 140;
    
    ofPoint updateRemoveFlagButton;
    updateRemoveFlagButton.set(theReflectionFlag.tabPos.x+115, theReflectionFlag.tabPos.y);
    theReflectionFlag.removeFlagButton.update(updateRemoveFlagButton);
    
    
    theReflectionFlag.presentCheck.set(theReflectionFlag.startPos.x, theReflectionFlag.startPos.y, theReflectionFlag.size.x, theReflectionFlag.size.y);
    
}

//------------------------------------------------------------------
void flagState::adjustMarker(int floor) {
    
//    theReflectionFlag.startPos.y-=25;
    theReflectionFlag.tabPos.y-=40*floor;
    theReflectionFlag.textPos.y-=40*floor;
    
    theReflectionFlag.tabPostPos.y -= 40*floor;
    theReflectionFlag.tabPostSize.y += 40*floor;
    
    ofPoint updateRemoveFlagButton;
    updateRemoveFlagButton.set(theReflectionFlag.tabPos.x+115, theReflectionFlag.tabPos.y);
    theReflectionFlag.removeFlagButton.update(updateRemoveFlagButton);
    
    theReflectionFlag.floor = floor;
    
    
}

//------------------------------------------------------------------
void flagState::draw(ofxRetinaTrueTypeFont& basicFont) {
    
    
    if (!theReflectionFlag.ended && !theReflectionFlag.selected) {
        
        ofSetColor(0,255,0, 120);        
        ofEnableAlphaBlending();
        //main box
        ofRect(theReflectionFlag.startPos.x, theReflectionFlag.startPos.y, theReflectionFlag.size.x, theReflectionFlag.size.y);
        
        ofDisableAlphaBlending();
    }
    
    else if (theReflectionFlag.ended && !theReflectionFlag.selected) {

        ofSetColor(255,255,255);
        ofRect(taskBox);
        
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
        
        ofSetColor(theReflectionFlag.color, 150);

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
void flagState::drawRemove(ofxRetinaTrueTypeFont& basicFont) {
    
    
    if (!theReflectionFlag.ended && !theReflectionFlag.selected) {
        
        ofSetColor(0,255,0, 120);
        ofEnableAlphaBlending();
        //main box
        ofRect(theReflectionFlag.startPos.x, theReflectionFlag.startPos.y, theReflectionFlag.size.x, theReflectionFlag.size.y);
        
        ofDisableAlphaBlending();
    }
    
    else if (theReflectionFlag.ended && !theReflectionFlag.selected) {
        
        ofSetColor(255,255,255);
        ofRect(theReflectionFlag.startPos.x, ofGetHeight()-250, 140, 200);
        
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
        
        theReflectionFlag.removeFlagButton.drawWithImage();
        
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

//    printf("started flag state touching down \n");
    
    if (theReflectionFlag.ended && !theReflectionFlag.selected) {
        identifying.touchingDown(touch);
        planning.touchingDown(touch);
        walking.touchingDown(touch);
        changing.touchingDown(touch);
        verifying.touchingDown(touch);
    }


    theReflectionFlag.removeFlagButton.touchingDown(touch);

//    printf("ended flag state touching down \n");
    
}

//------------------------------------------------------------------
void flagState::touchingMove(ofTouchEventArgs &touch) {
    
//    printf("started flag state touching move \n");
    
    if (theReflectionFlag.ended && !theReflectionFlag.selected) {
        identifying.touchingMove(touch);
        planning.touchingMove(touch);
        walking.touchingMove(touch);
        changing.touchingMove(touch);
        verifying.touchingMove(touch);
    }

    theReflectionFlag.removeFlagButton.touchingMove(touch);
    
//    printf("ended flag state touching move \n");

}

//------------------------------------------------------------------
void flagState::touchingUp(ofTouchEventArgs &touch) {
    
//    printf("started flag state touching up \n");
    
    if (theReflectionFlag.ended && !theReflectionFlag.selected) {
        identifying.touchingUp(touch);
        planning.touchingUp(touch);
        walking.touchingUp(touch);
        changing.touchingUp(touch);
        verifying.touchingUp(touch);
    }
    
    theReflectionFlag.started = false;
    theReflectionFlag.removeFlagButton.touchingUp(touch);
    
//    printf("ended flag state touching up \n");

}