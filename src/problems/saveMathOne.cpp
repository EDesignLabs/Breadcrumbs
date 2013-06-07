/*
 *  saveMathOne.cpp
 *
 *  Created by Ryan Raffa on 6/4/13.
 *
 */

#include "saveMathOne.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
saveMathOne::~saveMathOne() {
    
    delete create;
    delete reflect;
    delete present;
    
}



////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
saveMathOne::saveMathOne(string iPhoneDocumentsDirectory) {
    
    
    theText = "Four birds live in different parts of the forest. Determine which part of the forest each bird lives in.\n1. Amelia does not live near the water.\n2. Wendy has fear of heights.\n3. Phylis likes to watch the sunrise across the lake.\n4. Amelia and Phylis always go to Ann's to watch TV.";
    
    //-----------------------------------------------
    //setup math problem one
    
    create = new uiCreate(theText);
    reflect = new uiReflect;
    present = new uiPresent;
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    
    pos.set(0, 0);
    size.set(ofGetWidth(), 46);
    offSet.set(ofGetWidth()/2 - 15, 32);
    color.set(230, 224, 47, 255);
    presentButton.setup(pos, size, offSet, "Present", color);
    
    navStatePresent = true;
    
    grid.loadImage("images/gridTwo.png");
    
    string XMLFileOne;
    string XMLFileTwo;
    XMLFileOne = "myCreateProbOne.xml";
    XMLFileTwo = "myReflectProbOne.xml";
    present->xmlSetupThang(iPhoneDocumentsDirectory, XMLFileOne, XMLFileTwo);
    present->getXML(XMLFileOne, XMLFileTwo);
        
//    printf(" saveMathOne Setup ended \n ");

}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------        
void saveMathOne::update() {
    
    
//-----------------------------------------------
//What is done based on NAV state

    if (navStatePresent) present->update();



}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void saveMathOne::draw(ofTrueTypeFont& basicFont) {

//-----------------------------------------------
//actual state
    
    if (navStatePresent) present->draw(basicFont);
    
//-----------------------------------------------
//The Question

    ofSetColor(0, 0, 0);
    basicFont.drawString(theText, 20, 90);

    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255);
    grid.draw(175, ofGetHeight()/3+50);
    ofDisableAlphaBlending();

    
//-----------------------------------------------
//Button UI

    presentButton.draw(basicFont);

}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void saveMathOne::touchingDown(ofTouchEventArgs &touch) {

    if (navStatePresent) present->touchingDown(touch);
    
}

//------------------------------------------------------------------
void saveMathOne::touchingMove(ofTouchEventArgs &touch) {
    
    if (navStatePresent) present->touchingMove(touch);
    
}

//------------------------------------------------------------------
void saveMathOne::touchingUp(ofTouchEventArgs &touch) {
    
    if (navStatePresent) present->touchingUp(touch);
    
}

//------------------------------------------------------------------
void saveMathOne::doubleTap(ofTouchEventArgs &touch) {

    if (navStatePresent) present->doubleTap(touch);
    
}

    

