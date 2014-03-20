/*
 *  problemMath.cpp
 *
 *  Created by Ryan Raffa on 9/2/13.
 *
 */

#include "problemMath.h"




////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
problemMath::~problemMath() {

    delete create;
    delete reflect;
    delete present;

    delete savingFeedback;

    delete theXMLParty;
    
}



////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
problemMath::problemMath(string _iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton, ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36) {
        
 
//-----------------------------------------------    
//setup math problem one
    
    create          = new uiCreate;
    reflect         = new uiReflect;
    present         = new uiPresent;
    
    savingFeedback  = new button;
    
    //for XML functions
    theXMLParty     = new xmlParty;
    
    loadedImage     = false;
    
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    ofColor colorTwo;
    ofColor textColor;
    ofColor textColorTwo;
    
    ofPoint posTwo;
    posTwo.set(101, 0);
    size.set(274, 50);
    offSet.set(84, 35);
    color.set(255, 54, 44, 245);
    colorTwo.set(200, 200, 200, 245);
    textColor.set(250, 250, 250, 245);
    textColorTwo.set(122, 122, 122, 245);
    createButton.setup(posTwo, size, offSet, "journey", color, colorTwo, textColor, textColorTwo);
    
    ofPoint posThree;
    posThree.set(375, 0);
    offSet.set(44, 35);
    color.set(57, 140, 209, 245);
    colorTwo.set(156, 156, 156, 245);
    textColor.set(232, 230, 226, 245);
    textColorTwo.set(122, 122, 122, 245);
    reflectButton.setup(posThree, size, offSet, "breadcrumbs", color, colorTwo, textColor, textColorTwo);
    
    posThree.set(649, 0);
    offSet.set(66, 35);
    color.set(240, 196, 25, 245);
    colorTwo.set(179, 179, 179, 245);
    textColor.set(232, 230, 226, 245);
    textColorTwo.set(122, 122, 122, 245);
    presentButton.setup(posThree, size, offSet, "storyteller", color, colorTwo, textColor, textColorTwo);
    
    ofPoint posFour;
    size.set(200, 200);
    posFour.set(ofGetWidth()/2-(size.x/2), ofGetHeight()/2-(size.x/2));
    color.set(0, 0, 0, 220);
    offSet.set(60, 100);
    savingFeedback->setup(posFour, size, offSet, "Saving...", colorTwo, color, textColor, textColor);
    saving = false;
    counter = 0;
    savingFontColor.set(255, 255, 255);
    
    createButton.selected = true;
    navStateCreate = true;
    navStateReflect = false;
    navStatePresent = false;
    
    theTextWrap.init(quicksandBook36);
    theTextWrap.setText( theXMLParty->getXMLString(_iOSDocumentsDirectory,_XMLOne, _XMLTwo, _mathButton) );
    theTextWrap.setColor(0, 0, 0, 0);
//    theTextWrap.setLineHeight(32.0f);
//    theTextWrap.setLetterSpacing(0.90);
    theTextWrap.wrapTextX(ofGetWidth()-50);


//    printf(" problemMath Setup ended \n ");

}


////////////////////////////////////////////////////////////////////
//      Load Image                                                //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
bool problemMath::loadImage(string imageLoc) {
    
    grid.loadImage(imageLoc);
    loadedImage = true;
    return true;
    
}


////////////////////////////////////////////////////////////////////
//      XML Setup Thang                                           //
////////////////////////////////////////////////////////////////////


//XML THANG USED TO BE HERE
//Please see xmlParty.h


////////////////////////////////////////////////////////////////////
//      Grab XML                                                  //
////////////////////////////////////////////////////////////////////

//Grab XML used to be here
//Please see xmlParty.h



////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------        
void problemMath::update(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton, ofPoint _currentLocation, ofPoint _speed, bool _panning) {
    
    
    //-----------------------------------------------
    //NAV state is sorted out
    
    if (createButton.selected) {
        navStateReflect = false;
        navStatePresent = false;
        navStateCreate = true;

        //set colors
        createButton.active = true;
        reflectButton.active = false;
        presentButton.active = false;
        
        createButton.selected=false;
        
        _mathButton.stage = 0;
        
    }
    
    //REFLECT
    if (reflectButton.selected) {
        navStateCreate = false;
        navStatePresent = false;
        navStateReflect = true;

        //set colors
        createButton.active = false;
        reflectButton.active = true;
        presentButton.active = false;

        
        //get value of drawing
        theXMLParty->setPoints(create->drawThese, reflect->drawThese, reflect->theFlagStates, reflect->scrubFeedback, reflect->startTime, reflect->endTime, reflect->scrubBox);
        
        _mathButton.stage = 1;

        reflectButton.selected=false;

//        saving = true;
//        counter++;
        //        printf("counter: %d \n", counter);
        //        printf("saving: %d \n", saving);
        
//        if (counter > 1) {
            //            printf("counter greater than 1 \n");
            //            printf("counter inside: %d \n", counter);
            
            //save XML file for later
//            theXMLParty->saveXML(iOSDocumentsDirectory, XMLOne, XMLTwo, _mathButton, create->drawThese, reflect->theFlagStates, theTextWrap.rawText);
            
//            reflectButton.selected=false;
//            saving = false;
//            counter = 0;
//        }
        
        
    }
    
    
    //PRESENT
    if (presentButton.selected) {
        navStateCreate = false;
        navStateReflect = false;
        navStatePresent = true;

        //set colors
        createButton.active = false;
        reflectButton.active = false;
        presentButton.active = true;

        _mathButton.stage = 2;

        saving = true;
        counter++;
//        printf("counter: %d \n", counter);
//        printf("saving: %d \n", saving);
        
        if (counter > 1) {
//            printf("counter greater than 1 \n");
//            printf("counter inside: %d \n", counter);
            
            //save XML file for later
            theXMLParty->setFileNameSave(iOSDocumentsDirectory, XMLOne, XMLTwo, _mathButton, create->drawThese, reflect->theFlagStates, theTextWrap.rawText);
                
            
            //save it first, and then load it
            //get value of drawing
            
            theXMLParty->getXML(XMLOne, XMLTwo, present->drawThese, present->theFlagStates, present->scrubFeedback, present->startTime, present->endTime, present->scrubBox);
            

//        printf("sending _mathButton");
            ftpUpload.uploadFile(iOSDocumentsDirectory, _mathButton.XMLFileOne);
            ftpUpload.uploadFile(iOSDocumentsDirectory, _mathButton.XMLFileTwo);
//        printf("_mathButton sent \n");
            
            presentButton.selected=false;
            saving = false;
            counter = 0;


        }
        
        
    }
    
//-----------------------------------------------
//What is done based on NAV state

    if (navStateCreate) create->update(_currentLocation, _speed, _panning);
    if (navStateReflect) reflect->update();
    if (navStatePresent) present->update();


}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void problemMath::draw(ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36) {

//-----------------------------------------------
//actual state
    
    if (navStateCreate) create->draw(loadedImage, grid);
    if (navStateReflect) reflect->draw(quicksandBold60, quicksandBold36, quicksandBook36, loadedImage, grid);
    if (navStatePresent) present->draw(quicksandBold60, quicksandBold36, quicksandBook36, loadedImage, grid);
    
//-----------------------------------------------
//The Question

    ofSetColor(0, 0, 0);

    theTextWrap.draw(30,96);
    //    quicksandBook36.drawString(theText, 30, 120);

    
//-----------------------------------------------
//Button UI
    
    createButton.drawTwoColors(quicksandBold60);
    reflectButton.drawTwoColors(quicksandBold60);
    presentButton.drawTwoColors(quicksandBold60);
    
    if (saving) {
//        printf("saving in draw \n");
        savingFeedback->drawTwoColorsRounded(quicksandBook36);

    }
        
}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void problemMath::touchingDown(ofTouchEventArgs &touch) {

    
    if (navStateCreate) {
        create->touchingDown(touch);
        reflectButton.touchingDown(touch);
    }
    
    if (navStateReflect) {
        reflect->touchingDown(touch);
        createButton.touchingDown(touch);
        presentButton.touchingDown(touch);
    }

    if (navStatePresent) {
        present->touchingDown(touch);
        reflectButton.touchingDown(touch);
    }
    
}

//------------------------------------------------------------------
void problemMath::touchingMove(ofTouchEventArgs &touch) {
    

    if (navStateCreate) {
        create->touchingMove(touch);
        reflectButton.touchingMove(touch);
    }
    if (navStateReflect) {
        reflect->touchingMove(touch);
        createButton.touchingMove(touch);
        presentButton.touchingMove(touch);
    }
    if (navStatePresent) {
        present->touchingMove(touch);
        reflectButton.touchingMove(touch);
    }
    
}

//------------------------------------------------------------------
void problemMath::touchingUp(ofTouchEventArgs &touch) {
    
    if (navStateCreate) {
        create->touchingUp(touch);
        reflectButton.touchingUp(touch);
    }
    if (navStateReflect) {
        reflect->touchingUp(touch);
        createButton.touchingUp(touch);
        presentButton.touchingUp(touch);
    }
    if (navStatePresent) {
        present->touchingUp(touch);
        reflectButton.touchingUp(touch);
    }
    
}

//------------------------------------------------------------------
void problemMath::doubleTap(ofTouchEventArgs &touch) {


    if (navStateCreate) {
        create->doubleTap(touch);
        reflectButton.doubleTap(touch);
    }
    if (navStateReflect) {
        reflect->doubleTap(touch);
        createButton.doubleTap(touch);
        presentButton.doubleTap(touch);
    }
    if (navStatePresent) {
        present->doubleTap(touch);
        reflectButton.doubleTap(touch);
    }
    
}

    

