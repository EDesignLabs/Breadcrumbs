/*
 *  saveMath.cpp
 *
 *  Created by Ryan Raffa on 9/2/13.
 *
 */

#include "saveMath.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
saveMath::~saveMath() {
    
    delete present;
    delete theXMLParty;
}



////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
saveMath::saveMath(string _iOSDocumentsDirectory, button& _mathButton, ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36) {
    
    //-----------------------------------------------
    //setup math problem one
    
    present = new uiPresent;
    theXMLParty = new xmlParty;
    
    loadedImage = false;
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    
    pos.set(101, 0);
    size.set(822, 50);
    offSet.set(320, 35);
    color.set(240, 196, 25, 200);
    presentButton.setup(pos, size, offSet, "storyteller", color);
    
    navStatePresent = true;
    
    
    theXMLParty->xmlSetupThang(_iOSDocumentsDirectory, XMLOne, XMLTwo, _mathButton);
    theXMLParty->getXML(XMLOne, XMLTwo, present->drawThese, present->theFlagStates, present->scrubFeedback, present->startTime, present->endTime, present->scrubBox);    
    
    theTextWrap.init(quicksandBook36);
    theTextWrap.setText( theXMLParty->getXMLString(_iOSDocumentsDirectory, XMLOne, XMLTwo, _mathButton) );
    theTextWrap.setColor(0, 0, 0, 0);
    //    theTextWrap.setLineHeight(32.0f);
    //    theTextWrap.setLetterSpacing(0.90);
    theTextWrap.wrapTextX(ofGetWidth()-50);
    
//    printf(" saveMath Setup ended \n ");

}


////////////////////////////////////////////////////////////////////
//      Load Image                                                //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
bool saveMath::loadImage(string imageLoc) {
    
    grid.loadImage(imageLoc);
    
    loadedImage = true;
    return true;
    
}



////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------        
void saveMath::update() {
    
    
//-----------------------------------------------
//What is done based on NAV state

    if (navStatePresent) present->update();



}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void saveMath::draw(ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36) {

//-----------------------------------------------
//actual state
    
    if (navStatePresent) present->draw(quicksandBold60, quicksandBold36, quicksandBook36, loadedImage, grid);
    
//-----------------------------------------------
//The Question

    ofSetColor(0, 0, 0);
//    quicksandBook36.drawString(theText, 30, 120);
    theTextWrap.draw(30,96);
    
//-----------------------------------------------
//Button UI

    presentButton.draw(quicksandBold60);

}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void saveMath::touchingDown(ofTouchEventArgs &touch) {

    if (navStatePresent) present->touchingDown(touch);
    
}

//------------------------------------------------------------------
void saveMath::touchingMove(ofTouchEventArgs &touch) {
    
    if (navStatePresent) present->touchingMove(touch);
    
}

//------------------------------------------------------------------
void saveMath::touchingUp(ofTouchEventArgs &touch) {
    
    if (navStatePresent) present->touchingUp(touch);
    
}

//------------------------------------------------------------------
void saveMath::doubleTap(ofTouchEventArgs &touch) {

    if (navStatePresent) present->doubleTap(touch);
    
}

    

