/*
 *  userName.cpp
 *
 *  Created by Ryan Raffa on 9/25/13.
 *
 */

#include "userName.h"


//------------------------------------------------------------------
userName::~userName() {

    
    delete breadCrumbsImage;

//    printf(" userName deconstructor \n");
    
}

//------------------------------------------------------------------
userName::userName() {

//    printf(" userName setup started \n");    
    
    breadCrumbsImage = new ofImage;
    
    breadCrumbsImage->loadImage("images/login/login.png");


    
}

//------------------------------------------------------------------
void userName::update(string _theUserName) {
    

}

//------------------------------------------------------------------
void userName::draw() {
    
    ofSetHexColor(0xFFFFFF);
    
    ofEnableAlphaBlending();
        breadCrumbsImage->draw(0, 0);
    ofDisableAlphaBlending();
    
}



//------------------------------------------------------------------
void userName::touchingDown(ofTouchEventArgs &touch) {
    
}

//------------------------------------------------------------------
void userName::touchingMove(ofTouchEventArgs &touch) {

}

//------------------------------------------------------------------
void userName::touchingUp(ofTouchEventArgs &touch) {

}

//------------------------------------------------------------------
void userName::doubleTap(ofTouchEventArgs &touch) {
    
}


