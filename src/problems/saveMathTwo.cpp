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
    
    
    theText = "A certain state is considering changing the arrangement of letters and numbers on its license plates.\nThe two options the state is considering are:\n\nOption 1: three letters followed by a four-digit number with repetition of both letters and digits allowed\nOption 2: four letters followed by a three-digit number without repetition of either letters or digits\n[Zero may be chosen as the first digit of the number in either option.]\n\nWhich option will enable the state to issue more license plates? How many more\ndifferent license plates will that option yield?";
    
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
    basicFont.drawString(theText, 10, 100);

    
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

    

