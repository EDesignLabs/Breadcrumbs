/*
 *  saveMathThree.cpp
 *
 *  Created by Ryan Raffa on 6/6/13.
 *
 */

#include "saveMathThree.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
saveMathThree::~saveMathThree() {
    
    delete create;
    delete reflect;
    delete present;
    
}



////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
saveMathThree::saveMathThree(string iPhoneDocumentsDirectory) {
    
    
    theText = "A candy shop in the forest has 22 types of candy. If 8 of the types of candy are bon-bons\nand 6 of the candies are flavored strawberry, and 10 of the candies are neither bon-bons\nnor strawberry, how many strawberry bon-bons does he have on his lot?";
    
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
    XMLFileOne = "myCreateProbThree.xml";
    XMLFileTwo = "myReflectProbThree.xml";
    present->xmlSetupThang(iPhoneDocumentsDirectory, XMLFileOne, XMLFileTwo);
    present->getXML(XMLFileOne, XMLFileTwo);
        
//    printf(" saveMathThree Setup ended \n ");

}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------        
void saveMathThree::update() {
    
    
//-----------------------------------------------
//What is done based on NAV state

    if (navStatePresent) present->update();



}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void saveMathThree::draw(ofTrueTypeFont& basicFont) {

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
void saveMathThree::touchingDown(ofTouchEventArgs &touch) {

    if (navStatePresent) present->touchingDown(touch);
    
}

//------------------------------------------------------------------
void saveMathThree::touchingMove(ofTouchEventArgs &touch) {
    
    if (navStatePresent) present->touchingMove(touch);
    
}

//------------------------------------------------------------------
void saveMathThree::touchingUp(ofTouchEventArgs &touch) {
    
    if (navStatePresent) present->touchingUp(touch);
    
}

//------------------------------------------------------------------
void saveMathThree::doubleTap(ofTouchEventArgs &touch) {

    if (navStatePresent) present->doubleTap(touch);
    
}

    

