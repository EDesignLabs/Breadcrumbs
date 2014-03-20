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
    active = false;

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
    active = false;
    
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
    active = false;
    
    this->pos = pos;
    //    pos.set(100, 100);
    
}

//for two button/text color
//------------------------------------------------------------------
void button::setup(ofPoint pos, ofPoint size, ofPoint offSet, string thisString, ofColor thisColor, ofColor thisColorTwo, ofColor thisTextColor, ofColor thisTextColorTwo) {
    
    this->thisString = thisString;
    
    this->thisColor = thisColor;
    this->thisColorTwo = thisColorTwo;
    this->thisTextColor = thisTextColor;
    this->thisTextColorTwo = thisTextColorTwo;
    
    this->offSet = offSet;
    
    thisRectangle.set(pos.x, pos.y, size.x, size.y);
    
    //    thisRectangle.set(pos.x, pos.y, 625, 75);
    
    touching = false;
    selected = false;
    toggle = false;
    active = false;    
    
    this->pos = pos;
    //    pos.set(100, 100);
    
}

//for two Image
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
    active = false;
    
    this->pos = pos;
    //    pos.set(100, 100);
    
}


//------------------------------------------------------------------
void button::update(float newPosition) {
    
    thisRectangle.setPosition(newPosition, pos.y);
//    printf(" newPosition.x is: %d \n", newPosition.x);

}


//------------------------------------------------------------------
void button::update(ofPoint newPosition) {
    
    pos.set(newPosition.x, newPosition.y);
    thisRectangle.setPosition(newPosition.x, newPosition.y);
    //    printf(" newPosition.x is: %d \n", newPosition.x);
    
}

//------------------------------------------------------------------
void button::update(ofColor newColor, string newText, ofPoint newOffset) {
    
    thisColorTwo.set(newColor);
    thisString = newText;
    offSet.set(newOffset);
    
}



//------------------------------------------------------------------
void button::draw() {

    ofEnableAlphaBlending();
    if (touching) ofSetColor(255, 0, 0,250);
    if (toggle) ofSetColor(90, 90, 90);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    ofDisableAlphaBlending();

}

//------------------------------------------------------------------
void button::drawOnTop() {
    
    ofEnableAlphaBlending();
    if (touching) {
        ofSetColor(255, 0, 0,250);
        ofRect(thisRectangle);
    }
    ofDisableAlphaBlending();
    
}


//------------------------------------------------------------------
void button::draw(ofxRetinaTrueTypeFont& basicFont) {
    
    ofEnableAlphaBlending();
    if (touching) ofSetColor(255, 0, 0,250);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
    ofSetColor(0, 0, 0);
    basicFont.drawString(thisString, thisRectangle.x+offSet.x, thisRectangle.y+offSet.y);
    ofSetLineWidth(1.0);

}

//------------------------------------------------------------------
void button::draw(ofImage& basicImage) {
    
    ofEnableAlphaBlending();
    if (touching) ofSetColor(255, 0, 0,250);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
    basicImage.draw(pos.x, pos.y);
        
    ofDisableAlphaBlending();
}

//------------------------------------------------------------------
void button::draw(ofxRetinaTrueTypeFont& basicFont, ofImage& basicImage) {
    
    ofEnableAlphaBlending();
    if (touching) ofSetColor(255, 0, 0,250);
    else ofSetColor(thisColor);
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
void button::drawTextColor(ofxRetinaTrueTypeFont& basicFont, ofColor textColor) {
    
    ofEnableAlphaBlending();
    if (touching) ofSetColor(255, 0, 0,250);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
    ofSetColor(textColor);
    basicFont.drawString(thisString, thisRectangle.x+offSet.x, thisRectangle.y+offSet.y);
    
    ofDisableAlphaBlending();
}


//------------------------------------------------------------------
void button::drawTextColorImage(ofxRetinaTrueTypeFont& basicFont, ofImage& basicImage, ofColor textColor) {
    
    ofEnableAlphaBlending();
    if (touching) ofSetColor(255, 0, 0,250);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
    basicImage.draw(pos.x, pos.y);
    
    ofSetColor(textColor);
    basicFont.drawString(thisString, thisRectangle.x+offSet.x, thisRectangle.y+offSet.y);
    
    ofSetColor(0, 0, 0);
    ofNoFill();
    ofRect(thisRectangle);
    ofFill();
    
    ofDisableAlphaBlending();
}

//------------------------------------------------------------------
void button::drawNoColor() {
    
    ofEnableAlphaBlending();
    
    if (touching) ofSetColor(90, 90, 90);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofRect(thisRectangle);
    ofFill();

    ofDisableAlphaBlending();
}

//------------------------------------------------------------------
void button::drawNoColorTransparency() {
    
    ofEnableAlphaBlending();
    
    if (touching) ofSetColor(90, 90, 90, 200);
    else ofSetColor(thisColor,220);
    ofRect(thisRectangle);
    
    ofDisableAlphaBlending();
}

//------------------------------------------------------------------
void button::drawNoColorWithImage() {
    
    ofEnableAlphaBlending();

    if (touching) ofSetColor(90, 90, 90, 200);
    else ofSetColor(thisColor, 220);
    if (toggle) ofSetColor(90, 90, 90, 200);
    else ofSetColor(thisColor, 220);
    
    ofRect(thisRectangle);
    
    ofSetColor(thisColor);
    theImage.draw(pos.x+offSet.x, pos.y+offSet.y);
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofRect(thisRectangle);
    ofFill();

    ofDisableAlphaBlending();

}

//------------------------------------------------------------------
void button::drawNoColorWithImageToggle() {
    
    ofEnableAlphaBlending();
    if (touching) ofSetColor(90, 90, 90, 200);
    else ofSetColor(thisColor, 220);
    if (toggle) ofSetColor(90, 90, 90, 200);
    else ofSetColor(thisColor, 220);
    ofRect(thisRectangle);

    ofSetColor(thisColor);
    if (toggle) theImage.draw(pos.x+offSet.x, pos.y+offSet.y);
    else theImageTwo.draw(pos.x+offSet.x, pos.y+offSet.y);
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofRect(thisRectangle);
    ofFill();

    ofDisableAlphaBlending();
    
//    printf(" toggle is: %d \n", toggle);
    
}

//------------------------------------------------------------------
void button::drawWithImage() {
    
    ofEnableAlphaBlending();
    if (touching) ofSetColor(255, 0, 0,250);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
    theImage.draw(pos.x+offSet.x, pos.y+offSet.y);
    
    ofDisableAlphaBlending();
    
}

//------------------------------------------------------------------
void button::drawTwoColors(ofxRetinaTrueTypeFont& basicFont) {
    
    ofEnableAlphaBlending();
    if (touching) ofSetColor(thisColor);
    else if (active) ofSetColor(thisColor);
    else ofSetColor(thisColorTwo);
    ofRect(thisRectangle);
    
    if (touching) ofSetColor(thisTextColor);
    else if (active) ofSetColor(thisTextColor);
    else ofSetColor(thisTextColorTwo);
    basicFont.drawString(thisString, thisRectangle.x+offSet.x, thisRectangle.y+offSet.y);
    
    ofDisableAlphaBlending();
    
}

//------------------------------------------------------------------
void button::drawTwoColorsRounded(ofxRetinaTrueTypeFont& basicFont) {
    
    ofEnableAlphaBlending();
    if (touching) ofSetColor(thisColor);
    else if (active) ofSetColor(thisColor);
    else ofSetColor(thisColorTwo);
    ofRectRounded(thisRectangle, 5);
    
    if (touching) ofSetColor(thisTextColor);
    else if (active) ofSetColor(thisTextColor);
    else ofSetColor(thisTextColorTwo);
    basicFont.drawString(thisString, thisRectangle.x+offSet.x, thisRectangle.y+offSet.y);
    
    ofDisableAlphaBlending();
    
}


//------------------------------------------------------------------
void button::drawTwoImages() {
    
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255);
    if (touching) theImage.draw(pos.x+offSet.x, pos.y+offSet.y);
    else if (toggle) theImage.draw(pos.x+offSet.x, pos.y+offSet.y);
    else theImageTwo.draw(pos.x+offSet.x, pos.y+offSet.y);    
    ofDisableAlphaBlending();
    
}



//------------------------------------------------------------------
void button::touchingDown(ofTouchEventArgs &touch) {

    if (touch.id == 0) {
        if (thisRectangle.inside(touch.x, touch.y)){
            touching = true;
        }
    }
}

//------------------------------------------------------------------
void button::touchingMove(ofTouchEventArgs &touch) {
        
}


//------------------------------------------------------------------
void button::touchingUp(ofTouchEventArgs &touch) {
    
    if (touch.id == 0) {

        if (thisRectangle.inside(touch.x, touch.y) && touching) {
            //this is specific locations of selections made when lifting finger
            touching = false;
            selected = true;
            toggle = !toggle;
        }

        //this is only checking if you lift your finger
        touching = false;
    }
}


//------------------------------------------------------------------
void button::doubleTap(ofTouchEventArgs &touch) {
    
    
    
}
