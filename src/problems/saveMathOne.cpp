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
    
    
    theText = "Four women live in different cities. One of the cities is San Francisco.\nDetermine which city each woman lives in.\n1. The woman from Charleston (South Carolina), the woman from Gainesville (Florida), and Riana are not related.\n2. Wendy and the woman from Provo are cousins.\n3. Neither Phyllis nor Wendy is from the West Coast.\n4. Ann is from a coastal city.";
    
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
    
    grid.loadImage("images/grid.png");
    
    string XMLFileOne;
    string XMLFileTwo;
    XMLFileOne = "myCreateProbOne.xml";
    XMLFileTwo = "myReflectProbOne.xml";
    present->xmlSetupThang(iPhoneDocumentsDirectory, XMLFileOne, XMLFileTwo);
    present->getXML(XMLFileOne, XMLFileTwo);
        
    printf(" saveMathOne Setup ended \n ");

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
    basicFont.drawString(theText, 10, 100);

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

    

