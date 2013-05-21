/*
 *  exercisesMath.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#include "exercisesMath.h"




////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
exercisesMath::~exercisesMath() {

    delete problemOne;

}



////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
exercisesMath::exercisesMath() {
        
 
//-----------------------------------------------    
//setup math problem one
    
    problemOne = new problemMathOne();
    
    printf(" exercisesMath Setup ended \n ");

}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------        
void exercisesMath::update() {

    problemOne->update();
    
}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void exercisesMath::draw(ofTrueTypeFont& basicFont) {
    
    problemOne->draw(basicFont);

}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void exercisesMath::touchingDown(ofTouchEventArgs &touch) {

    problemOne->touchingDown(touch);

}

//------------------------------------------------------------------
void exercisesMath::touchingMove(ofTouchEventArgs &touch) {
    
    problemOne->touchingMove(touch);

}

//------------------------------------------------------------------
void exercisesMath::touchingUp(ofTouchEventArgs &touch) {
    
    problemOne->touchingUp(touch);

}

//------------------------------------------------------------------
void exercisesMath::doubleTap(ofTouchEventArgs &touch) {

    problemOne->doubleTap(touch);
    
}

    

