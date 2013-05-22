/*
 *  uiCreate.cpp
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#include "uiCreate.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiCreate::~uiCreate() {
    
    thisImage.reset();
    exit();

    //uiCreate elements
    delete pencil;
    delete erase;
    delete table;
    delete okSave;

    delete pencilSelected;
    delete eraseSelected;
    delete tableSelected;
    delete okSaveSelected;
    
}

////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiCreate::uiCreate(string theText) {
    
//    sprintf (timeString, "time: %0.2i:%0.2i:%0.2i \nelapsed time %i", ofGetHours(), ofGetMinutes(), ofGetSeconds(), ofGetElapsedTimeMillis());
//    
//    sprintf(eventString, "touch = (%2.0f, %2.0f - id %i)", 0.0, 0.0, 0.0);

    thisImage.setup();
    
    //load uiCreate images
    pencil = new ofImage;
    erase = new ofImage;
    table = new ofImage;
    okSave = new ofImage;
    
    pencil->loadImage("images/ui/glyphicons_030_pencil.png");
    erase->loadImage("images/ui/erase.png");
    table->loadImage("images/ui/glyphicons_119_table.png");
    okSave->loadImage("images/ui/glyphicons_206_ok_2.png");
    
    //set initial values for state
    pencilSelected = new bool;
    eraseSelected = new bool;
    tableSelected = new bool;
    okSaveSelected = new bool;
    
    *pencilSelected = true;
    *eraseSelected = false;
    *tableSelected = false;
    *okSaveSelected = false;

    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    
    size.set(pencil->getWidth()+20, pencil->getHeight()+20);
    pos.set(0, 300);
    offSet.set(0, 0);
    
    color.set(170, 170, 170);
    pencilButton.setup(pos, size, color);
    pencilButton.toggle = true;
    
    ofPoint posTwo;
    posTwo.set(0, 345);
    eraseButton.setup(posTwo, size, color);
    
    ofPoint posThree;
    posThree.set(0, 390);
    tableButton.setup(posThree, size, color);
    
    ofPoint posFour;
    posThree.set(0, 435);
    okSaveButton.setup(posThree, size, color);
    
    this->theText = theText;
}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiCreate::update() {

    //-----------------------------------------------
    //NAV state is sorted out
    
    if (pencilButton.selected) {
        *eraseSelected = false;
        *tableSelected = false;
        *okSaveSelected = false;
        *pencilSelected = true;
        pencilButton.selected=false;
        eraseButton.toggle = false;
        tableButton.toggle = false;
        okSaveButton.toggle = false;
    }
    
    if (eraseButton.selected) {
        *pencilSelected = false;
        *tableSelected = false;
        *okSaveSelected = false;
        *eraseSelected = true;
        eraseButton.selected=false;
        pencilButton.toggle = false;
        tableButton.toggle = false;
        okSaveButton.toggle = false;
    }
    
    if (tableButton.selected) {
        *pencilSelected = false;
        *eraseSelected = false;
        *okSaveSelected = false;
        *tableSelected = true;
        tableButton.selected=false;
        pencilButton.toggle = false;
        eraseButton.toggle = false;
        okSaveButton.toggle = false;
    }
    
    if (okSaveButton.selected) {
        *pencilSelected = false;
        *eraseSelected = false;
        *tableSelected = false;
        *okSaveSelected = true;
        okSaveButton.selected=false;
        pencilButton.toggle = false;
        eraseButton.toggle = false;
        tableButton.toggle = false;
    }

    
    if (*eraseSelected) {
    }

        
}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiCreate::draw(ofTrueTypeFont& basicFont) {

//    sprintf (timeString, "time: %0.2i:%0.2i:%0.2i \nelapsed time %i", ofGetHours(), ofGetMinutes(), ofGetSeconds(), ofGetElapsedTimeMillis());
	
    ofSetHexColor(0x000000);
//	basicFont.drawString(timeString, 10,ofGetHeight()-90);
//	basicFont.drawString(eventString, 10,ofGetHeight()-20);
    
//-----------------------------------------------
//What is created

    for (int i = 0; i < drawThese.size(); i++) {
        ofSetColor(drawThese[i].thePoints[0].color);
        ofSetLineWidth(drawThese[i].thePoints[0].lineWidth);
        drawThese[i].draw();
    }
    
    
//-----------------------------------------------
//Tools
        
    
//    ofSetLineWidth(2.0);
    
    if (*pencilSelected) {
        ofSetColor(0, 0, 0);
        ofSetLineWidth(2.0);
        if (currentDrawing.size()>0) {
            for (int i = 1; i < currentDrawing.size(); i++) {
                ofLine(currentDrawing[i-1].x, currentDrawing[i-1].y, currentDrawing[i].x, currentDrawing[i].y);
            }
        }
    }
    
    if (*eraseSelected) {
        ofSetColor(255, 255, 255);
        ofSetLineWidth(300.0);
        if (currentDrawing.size()>0) {
            for (int i = 1; i < currentDrawing.size(); i++) {
                ofLine(currentDrawing[i-1].x, currentDrawing[i-1].y, currentDrawing[i].x, currentDrawing[i].y);
            }
        }
    }

    
    if (*tableSelected) {
//        basicFont.drawString("table selected", 10, 500);
    }

    if (*okSaveSelected) {
//        basicFont.drawString("ok save selected", 10, 500);
    }

    ofSetLineWidth(2.0);

//-----------------------------------------------
//Tool Button UI

    
    pencilButton.drawToggle();
    eraseButton.drawToggle();
    tableButton.drawToggle();
    okSaveButton.drawToggle();
    
    ofSetHexColor(0xFFFFFF);
    
    ofEnableAlphaBlending();
    pencil->draw(10, 310);
    erase->draw(10, 355);
    table->draw(10, 400);
    okSave->draw(10, 445);
    ofDisableAlphaBlending();
    
}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiCreate::touchingDown(ofTouchEventArgs &touch) {
    
    pencilButton.touchingDown(touch);
    eraseButton.touchingDown(touch);
    tableButton.touchingDown(touch);
    okSaveButton.touchingDown(touch);
    
    if (*pencilSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;
        
        ofColor theColor;
        theColor.set(0, 0, 0);
        float lineWidth;
        lineWidth = 2.0;
        
        currentDrawing.push_back(currentPos);
        thisDrawing.update(touch, theColor, lineWidth);
    }


    if (*eraseSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;
        
        ofColor theColor;
        theColor.set(255, 255, 255);
        float lineWidth;
        lineWidth = 300.0;
        
        currentDrawing.push_back(currentPos);
        thisDrawing.update(touch, theColor, lineWidth);
    }

}

//------------------------------------------------------------------
void uiCreate::touchingMove(ofTouchEventArgs &touch) {
    
    pencilButton.touchingMove(touch);
    eraseButton.touchingMove(touch);
    tableButton.touchingMove(touch);
    okSaveButton.touchingMove(touch);

    if (*pencilSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;
        
        ofColor theColor;
        theColor.set(0, 0, 0);
        float lineWidth;
        lineWidth = 2.0;
        
        currentDrawing.push_back(currentPos);
        thisDrawing.update(touch, theColor, lineWidth);
    }
    
    
    if (*eraseSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;
        
        ofColor theColor;
        theColor.set(255, 255, 255);
        float lineWidth;
        lineWidth = 300.0;
        
        currentDrawing.push_back(currentPos);
        thisDrawing.update(touch, theColor, lineWidth);
    }

    
}

//------------------------------------------------------------------
void uiCreate::touchingUp(ofTouchEventArgs &touch) {
    
    pencilButton.touchingUp(touch);
    eraseButton.touchingUp(touch);
    tableButton.touchingUp(touch);
    okSaveButton.touchingUp(touch);

    if (*pencilSelected) {
        currentDrawing.clear();
        drawThese.push_back(thisDrawing);
        thisDrawing.reset();
    }
    
    
    if (*eraseSelected) {
        currentDrawing.clear();
        drawThese.push_back(thisDrawing);
        thisDrawing.reset();
    }
    
}


//------------------------------------------------------------------
void uiCreate::doubleTap(ofTouchEventArgs &touch) {

    pencilButton.doubleTap(touch);
    eraseButton.doubleTap(touch);
    tableButton.doubleTap(touch);
    okSaveButton.doubleTap(touch);

}

//--------------------------------------------------------------
void uiCreate::exit() {


}

