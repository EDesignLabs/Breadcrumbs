/*
 *  saveMathTwo.cpp
 *
 *  Created by Ryan Raffa on 6/6/13.
 *
 */

#include "saveMathTwo.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
saveMathTwo::~saveMathTwo() {
    
    delete create;
    delete reflect;
    delete present;
    
}



////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
saveMathTwo::saveMathTwo(string iPhoneDocumentsDirectory) {
    
    
    theText = "George and Diana's parents led them 1 mile into the woods. George dropped a breadcrumb\nat the front door of their cottage and then every 20ft. until they reached their destination.\nHow many breadcrumbs did George drop?\n\nDraw a diagram to help you solve the problem.";
    
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
    presentButton.setup(pos, size, offSet, "Storyteller", color);
    
    navStatePresent = true;
    
    string XMLFileOne;
    string XMLFileTwo;
    XMLFileOne = "myCreateProbTwo.xml";
    XMLFileTwo = "myReflectProbTwo.xml";
    present->xmlSetupThang(iPhoneDocumentsDirectory, XMLFileOne, XMLFileTwo);
    present->getXML(XMLFileOne, XMLFileTwo);
        
//    printf(" saveMathTwo Setup ended \n ");

}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------        
void saveMathTwo::update() {
    
    
//-----------------------------------------------
//What is done based on NAV state

    if (navStatePresent) present->update();



}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void saveMathTwo::draw(ofTrueTypeFont& basicFont) {

//-----------------------------------------------
//actual state
    
    if (navStatePresent) present->draw(basicFont);
    
//-----------------------------------------------
//The Question

    ofSetColor(0, 0, 0);
    basicFont.drawString(theText, 20, 90);

    
//-----------------------------------------------
//Button UI

    presentButton.draw(basicFont);

}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void saveMathTwo::touchingDown(ofTouchEventArgs &touch) {

    if (navStatePresent) present->touchingDown(touch);
    
}

//------------------------------------------------------------------
void saveMathTwo::touchingMove(ofTouchEventArgs &touch) {
    
    if (navStatePresent) present->touchingMove(touch);
    
}

//------------------------------------------------------------------
void saveMathTwo::touchingUp(ofTouchEventArgs &touch) {
    
    if (navStatePresent) present->touchingUp(touch);
    
}

//------------------------------------------------------------------
void saveMathTwo::doubleTap(ofTouchEventArgs &touch) {

    if (navStatePresent) present->doubleTap(touch);
    
}

    

