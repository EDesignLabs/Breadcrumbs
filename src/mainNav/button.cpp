/*
 *  button.cpp
 *  Created by Ryan Raffa on 5/5/13.
 *
 */

#include "button.h"


//------------------------------------------------------------------
void button::setup(ofPoint pos, ofPoint size, ofPoint offSet, string thisString, ofColor thisColor) {
    
    this->thisString = thisString;
    this->thisColor = thisColor;
    this->offSet = offSet;
    
    thisRectangle.set(pos.x, pos.y, size.x, size.y);

//    thisRectangle.set(pos.x, pos.y, 625, 75);
    
    touching = false;
    selected = false;
    toggle = false;

    this->pos = pos;
//    pos.set(100, 100);

}


//------------------------------------------------------------------
void button::setup(ofPoint pos, ofPoint size, ofColor thisColor) {
    
    this->thisColor = thisColor;
    this->offSet = offSet;
    
    thisRectangle.set(pos.x, pos.y, size.x, size.y);
    
    //    thisRectangle.set(pos.x, pos.y, 625, 75);
    
    touching = false;
    selected = false;
    toggle = false;
    
    this->pos = pos;
//    pos.set(100, 100);
    
}

//------------------------------------------------------------------
void button::setup(ofPoint pos, ofPoint size, ofColor thisColor, ofImage theImage, ofPoint offSet) {
    
    this->thisColor = thisColor;
    this->offSet = offSet;
    this->theImage = theImage;
    
    thisRectangle.set(pos.x, pos.y, size.x, size.y);
    
    //    thisRectangle.set(pos.x, pos.y, 625, 75);
    
    touching = false;
    selected = false;
    toggle = false;
    
    this->pos = pos;
    //    pos.set(100, 100);
    
}

//------------------------------------------------------------------
void button::setup(ofPoint pos, ofPoint size, ofColor thisColor, ofImage theImageOne, ofImage theImageTwo, ofPoint offSet) {
    
    this->thisColor = thisColor;
    this->offSet = offSet;
    this->theImage = theImageOne;
    this->theImageTwo = theImageTwo;
    
    thisRectangle.set(pos.x, pos.y, size.x, size.y);
    
    //    thisRectangle.set(pos.x, pos.y, 625, 75);
    
    touching = false;
    selected = false;
    toggle = false;
    
    this->pos = pos;
    //    pos.set(100, 100);
    
}


//------------------------------------------------------------------
void button::update(ofPoint newPosition) {
    
    thisRectangle.setPosition(newPosition.x, pos.y);
//    printf(" newPosition.x is: %d \n", newPosition.x);

}



//------------------------------------------------------------------
void button::draw() {

    if (touching) ofSetColor(255, 0, 0,250);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
}

//------------------------------------------------------------------
void button::drawToggle() {
    
    if (touching) ofSetColor(255, 0, 0,250);
    if (toggle) ofSetColor(90, 90, 90);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
}


//------------------------------------------------------------------
void button::draw(ofTrueTypeFont& basicFont) {
    
    if (touching) ofSetColor(255, 0, 0,250);
    else ofSetColor(thisColor, 120);
    ofRect(thisRectangle);
    
    ofSetColor(0, 0, 0);
    basicFont.drawString(thisString, thisRectangle.x+offSet.x, thisRectangle.y+offSet.y);

    ofNoFill();
    ofRect(thisRectangle);
    ofFill();
    
}

//------------------------------------------------------------------
void button::draw(ofTrueTypeFont& basicFont, ofImage& basicImage) {
    
    ofEnableAlphaBlending();
    if (touching) ofSetColor(255, 0, 0,250);
    else ofSetColor(thisColor, 120);
    ofRect(thisRectangle);
    
    basicImage.draw(pos.x, pos.y);
    
    ofSetColor(0, 0, 0);
    basicFont.drawString(thisString, thisRectangle.x+offSet.x, thisRectangle.y+offSet.y);
    
    ofNoFill();
    ofRect(thisRectangle);
    ofFill();
    
    ofDisableAlphaBlending();
}


//------------------------------------------------------------------
void button::drawNoColor() {
    
    if (touching) ofSetColor(90, 90, 90);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofRect(thisRectangle);
    ofFill();
}

//------------------------------------------------------------------
void button::drawNoColorWithImage() {
    
    if (touching) ofSetColor(90, 90, 90);
    else ofSetColor(thisColor);
    if (toggle) ofSetColor(90, 90, 90);
    else ofSetColor(thisColor);
    
    ofRect(thisRectangle);
    
    ofEnableAlphaBlending();
    theImage.draw(pos.x+offSet.x, pos.y+offSet.y);
    ofDisableAlphaBlending();
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofRect(thisRectangle);
    ofFill();
}

//------------------------------------------------------------------
void button::drawNoColorWithImageToggle() {
    
    if (touching) ofSetColor(90, 90, 90);
    else ofSetColor(thisColor);
    if (toggle) ofSetColor(90, 90, 90);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);

    ofEnableAlphaBlending();
    if (toggle) theImage.draw(pos.x+offSet.x, pos.y+offSet.y);
    else theImageTwo.draw(pos.x+offSet.x, pos.y+offSet.y);
    ofDisableAlphaBlending();
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofRect(thisRectangle);
    ofFill();
    
    printf(" toggle is: %d \n", toggle);
    
}


//------------------------------------------------------------------
void button::touchingDown(ofTouchEventArgs &touch) {

    if (thisRectangle.inside(touch.x, touch.y)){
        touching = true;
    }
    
}

//------------------------------------------------------------------
void button::touchingMove(ofTouchEventArgs &touch) {
        
}


//------------------------------------------------------------------
void button::touchingUp(ofTouchEventArgs &touch) {
    
    if (thisRectangle.inside(touch.x, touch.y) && touching) {
        //this is specific locations of selections made when lifting finger
        touching = false;
        selected = true;
        toggle = !toggle;
    }

    //this is only checking if you lift your finger
    touching = false;
    
}

//------------------------------------------------------------------
void button::doubleTap(ofTouchEventArgs &touch) {
    
    
    
}
