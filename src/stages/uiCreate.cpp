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
    delete font;
    delete table;
    delete okSave;

    delete pencilSelected;
    delete fontSelected;
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
    font = new ofImage;
    table = new ofImage;
    okSave = new ofImage;
    
    pencil->loadImage("images/ui/glyphicons_030_pencil.png");
    font->loadImage("images/ui/glyphicons_100_font.png");
    table->loadImage("images/ui/glyphicons_119_table.png");
    okSave->loadImage("images/ui/glyphicons_206_ok_2.png");
    
    //set initial values for state
    pencilSelected = new bool;
    fontSelected = new bool;
    tableSelected = new bool;
    okSaveSelected = new bool;
    
    *pencilSelected = true;
    *fontSelected = false;
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
    fontButton.setup(posTwo, size, color);
    
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
        *fontSelected = false;
        *tableSelected = false;
        *okSaveSelected = false;
        *pencilSelected = true;
        pencilButton.selected=false;
        fontButton.toggle = false;
        tableButton.toggle = false;
        okSaveButton.toggle = false;
    }
    
    if (fontButton.selected) {
        *pencilSelected = false;
        *tableSelected = false;
        *okSaveSelected = false;
        *fontSelected = true;
        fontButton.selected=false;
        pencilButton.toggle = false;
        tableButton.toggle = false;
        okSaveButton.toggle = false;
    }
    
    if (tableButton.selected) {
        *pencilSelected = false;
        *fontSelected = false;
        *okSaveSelected = false;
        *tableSelected = true;
        tableButton.selected=false;
        pencilButton.toggle = false;
        fontButton.toggle = false;
        okSaveButton.toggle = false;
    }
    
    if (okSaveButton.selected) {
        *pencilSelected = false;
        *fontSelected = false;
        *tableSelected = false;
        *okSaveSelected = true;
        okSaveButton.selected=false;
        pencilButton.toggle = false;
        fontButton.toggle = false;
        tableButton.toggle = false;
    }

    
    if (*fontSelected) {
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
        drawThese[i].draw();
    }
    
    
//-----------------------------------------------
//Tools
        
    if (*fontSelected) {
//        basicFont.drawString("text selected", 10, 500);
    }
    
    ofSetLineWidth(2.0);
    
    if (*pencilSelected) {
//        basicFont.drawString("pencil selected", 10, 500);
                
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

    
//-----------------------------------------------
//Tool Button UI

    pencilButton.drawToggle();
    fontButton.drawToggle();
    tableButton.drawToggle();
    okSaveButton.drawToggle();
    
    ofSetHexColor(0x000000);
    
    ofEnableAlphaBlending();
    pencil->draw(10, 310);
    font->draw(10, 355);
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
    fontButton.touchingDown(touch);
    tableButton.touchingDown(touch);
    okSaveButton.touchingDown(touch);
    
    if (*pencilSelected) {

        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;

        currentDrawing.push_back(currentPos);
        thisDrawing.update(touch);
    }
}

//------------------------------------------------------------------
void uiCreate::touchingMove(ofTouchEventArgs &touch) {
    
    pencilButton.touchingMove(touch);
    fontButton.touchingMove(touch);
    tableButton.touchingMove(touch);
    okSaveButton.touchingMove(touch);

    if (*pencilSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;

        currentDrawing.push_back(currentPos);
        thisDrawing.update(touch);
    }
    
}

//------------------------------------------------------------------
void uiCreate::touchingUp(ofTouchEventArgs &touch) {
    
    pencilButton.touchingUp(touch);
    fontButton.touchingUp(touch);
    tableButton.touchingUp(touch);
    okSaveButton.touchingUp(touch);

    if (*pencilSelected) {
        currentDrawing.clear();
        drawThese.push_back(thisDrawing);
        thisDrawing.reset();
    }
    
}


//------------------------------------------------------------------
void uiCreate::doubleTap(ofTouchEventArgs &touch) {

    pencilButton.doubleTap(touch);
    fontButton.doubleTap(touch);
    tableButton.doubleTap(touch);
    okSaveButton.doubleTap(touch);

}

//--------------------------------------------------------------
void uiCreate::exit() {


}

