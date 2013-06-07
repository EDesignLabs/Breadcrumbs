/*
 *  problemMathTwo.cpp
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#include "problemMathTwo.h"




////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
problemMathTwo::~problemMathTwo() {

    delete create;
    delete reflect;
    delete present;

}



////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
problemMathTwo::problemMathTwo() {
        
 
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
    questionButtonImage.loadImage("images/ui/glyphicons_194_circle_question_mark.png");
    
    size.set(questionButtonImage.getWidth()+20, questionButtonImage.getHeight()+20);
    pos.set(ofGetWidth()-45, 0);
    offSet.set(105, 32);
    color.set(170, 170, 170);
    questionButton.setup(pos, size, color);
    
    ofPoint posTwo;
    posTwo.set(46, 0);
    size.set(311, 46);
    color.set(200, 52, 70, 255);
    createButton.setup(posTwo, size, offSet, "Journey", color);
    
    ofPoint posThree;
    posThree.set(357, 0);
    color.set(68, 116, 176, 255);
    reflectButton.setup(posThree, size, offSet, "Breadcrumbs", color);
    
    ofPoint posFour;
    posThree.set(668, 0);
    color.set(230, 224, 47, 255);
    presentButton.setup(posThree, size, offSet, "Storyteller", color);
    
    navStateCreate = true;
    navStateReflect = false;
    navStatePresent = false;
    navStateQuestion = false;
    
//    grid.loadImage("images/grid2.jpg");
    
//-----------------------------------------------
//poor man's feedback
    
    feedbackBrickPos.set(50, 46);
    
//    printf(" problemMathTwo Setup ended \n ");

}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------        
void problemMathTwo::update(string iPhoneDocumentsDirectory) {
    
    
//-----------------------------------------------
//NAV state is sorted out
    
    if (createButton.selected) {
        navStateReflect = false;
        navStatePresent = false;
        navStateQuestion = false;
        navStateCreate = true;
        createButton.selected=false;
    }
    
    if (reflectButton.selected) {
        navStateCreate = false;
        navStatePresent = false;
        navStateQuestion = false;
        navStateReflect = true;
        reflectButton.selected=false;
        
        //set value of drawing
        reflect->setPoints(create->drawThese);
    }
    
    if (presentButton.selected) {
        navStateCreate = false;
        navStateReflect = false;
        navStateQuestion = false;
        navStatePresent = true;
        presentButton.selected=false;

        //set value of drawing
        present->setPoints(create->drawThese, reflect->theFlagStates);

        string xmlFileOne;
        string xmlFileTwo;
        xmlFileOne = "myCreateProbTwo.xml";
        xmlFileTwo = "myReflectProbTwo.xml";
        
        //save XML file for later
        present->xmlSetupThang(iPhoneDocumentsDirectory, xmlFileOne, xmlFileTwo);
        present->saveXML(iPhoneDocumentsDirectory, xmlFileOne,xmlFileTwo);

    }
    
    if (questionButton.selected) {        
        navStateCreate = false;
        navStateReflect = false;
        navStatePresent = false;
        navStateQuestion = true;
        questionButton.selected=false;
    }
    
//-----------------------------------------------
//What is done based on NAV state

    if (navStateCreate) create->update();
    if (navStateReflect) reflect->update();
    if (navStatePresent) present->update();

//-----------------------------------------------
//poor man's feedback

    if (navStateCreate) {
        distX = createButton.pos.x - feedbackBrickPos.x;
        feedbackBrickPos.x += distX/8.0;
    }
    
    if (navStateReflect) {
        distX = reflectButton.pos.x - feedbackBrickPos.x;
        feedbackBrickPos.x += distX/8.0;
    }
    
    if (navStatePresent) {
        distX = presentButton.pos.x - feedbackBrickPos.x;
        feedbackBrickPos.x += distX/8.0;
    }

    if (navStateQuestion) {
        distX = questionButton.pos.x - feedbackBrickPos.x;
        feedbackBrickPos.x += distX/8.0;
    }


}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void problemMathTwo::draw(ofTrueTypeFont& basicFont) {

//-----------------------------------------------
//poor man's feedback
    
    ofSetLineWidth(1.0);

    ofRect(feedbackBrickPos.x, feedbackBrickPos.y, 311, 5);

    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255);
//    grid.draw(175, ofGetHeight()/3+50);
    ofDisableAlphaBlending();
    
//-----------------------------------------------
//actual state
    
    if (navStateCreate) create->draw(basicFont);
    if (navStateReflect) reflect->draw(basicFont);
    if (navStatePresent) present->draw(basicFont);
    
//-----------------------------------------------
//The Question

    ofSetColor(0, 0, 0);
    basicFont.drawString(theText, 20, 90);
    
//-----------------------------------------------
//Feedback
    
//    if (navStateCreate) basicFont.drawString("create selected", ofGetWidth()/2, 60);
//    if (navStateReflect) basicFont.drawString("reflect selected", ofGetWidth()/2, 60);
//    if (navStatePresent) basicFont.drawString("present selected", ofGetWidth()/2, 60);
//    if (navStateQuestion) basicFont.drawString("question selected", ofGetWidth()/2, 60);

//-----------------------------------------------
//Button UI

    createButton.draw(basicFont);
    reflectButton.draw(basicFont);
    presentButton.draw(basicFont);
    questionButton.draw(basicFont);
    
    ofEnableAlphaBlending();
    questionButtonImage.draw(ofGetWidth()-35, 10);
    ofDisableAlphaBlending();
    
}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void problemMathTwo::touchingDown(ofTouchEventArgs &touch) {

    createButton.touchingDown(touch);
    reflectButton.touchingDown(touch);
    presentButton.touchingDown(touch);
    questionButton.touchingDown(touch);
    
    if (navStateCreate) create->touchingDown(touch);
    if (navStateReflect) reflect->touchingDown(touch);
    if (navStatePresent) present->touchingDown(touch);
    
}

//------------------------------------------------------------------
void problemMathTwo::touchingMove(ofTouchEventArgs &touch) {
    
    createButton.touchingMove(touch);
    reflectButton.touchingMove(touch);
    presentButton.touchingMove(touch);
    questionButton.touchingMove(touch);

    if (navStateCreate) create->touchingMove(touch);
    if (navStateReflect) reflect->touchingMove(touch);
    if (navStatePresent) present->touchingMove(touch);
    
}

//------------------------------------------------------------------
void problemMathTwo::touchingUp(ofTouchEventArgs &touch) {
    
    createButton.touchingUp(touch);
    reflectButton.touchingUp(touch);
    presentButton.touchingUp(touch);
    questionButton.touchingUp(touch);

    if (navStateCreate) create->touchingUp(touch);
    if (navStateReflect) reflect->touchingUp(touch);
    if (navStatePresent) present->touchingUp(touch);
    
}

//------------------------------------------------------------------
void problemMathTwo::doubleTap(ofTouchEventArgs &touch) {

    createButton.doubleTap(touch);
    reflectButton.doubleTap(touch);
    presentButton.doubleTap(touch);
    questionButton.doubleTap(touch);

    if (navStateCreate) create->doubleTap(touch);
    if (navStateReflect) reflect->doubleTap(touch);
    if (navStatePresent) present->doubleTap(touch);
    
}

    

