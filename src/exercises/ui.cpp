/*
 *  ui.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *  Updated by Ryan Raffa on 4/23/13.
 *
 */

#include "ui.h"



//------------------------------------------------------------------
ui::~ui() {
    
    thisImage.reset();
    exit();
    delete thisText;

    //UI elements
    delete pencil;
    delete font;
    delete table;
    delete okSave;
    delete pencilBox;
    delete fontBox;
    delete tableBox;
    delete okSaveBox;

    delete pencilSelected;
    delete fontSelected;
    delete tableSelected;
    delete okSaveSelected;
    
}


//------------------------------------------------------------------
ui::ui() {
    
    sprintf (timeString, "time: %0.2i:%0.2i:%0.2i \nelapsed time %i", ofGetHours(), ofGetMinutes(), ofGetSeconds(), ofGetElapsedTimeMillis());
    
    sprintf(eventString, "touch = (%2.0f, %2.0f - id %i)", 0.0, 0.0, 0.0);

    thisImage.setup();
    thisText = new text();
    
    //load UI images
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

    pencilBox = new ofRectangle;
    fontBox = new ofRectangle;
    tableBox = new ofRectangle;
    okSaveBox = new ofRectangle;
    pencilBox->set(0, 300, pencil->getWidth()+20, pencil->getHeight()+20);
    fontBox->set(0, 345, pencil->getWidth()+20, pencil->getHeight()+20);
    tableBox->set(0, 390, pencil->getWidth()+20, pencil->getHeight()+20);
    okSaveBox->set(0, 435, pencil->getWidth()+20, pencil->getHeight()+20);
    
    theText = "Nick's daughter Penny has 25 dimes. She likes to arrange them\ninto three piles, putting an odd number of dimes into each pile. In\nhow many ways could she do this?\nSolve this problem before continuing. ";

    
}



//------------------------------------------------------------------
void ui::update() {

    if (*fontSelected) {
        thisText->update();
    }

        
}


//------------------------------------------------------------------
void ui::draw(ofTrueTypeFont& basicFont) {

    ofSetColor(255, 0, 0, 100);
    ofRect(0, ofGetHeight()/3, ofGetWidth(), 5);
    
    sprintf (timeString, "time: %0.2i:%0.2i:%0.2i \nelapsed time %i", ofGetHours(), ofGetMinutes(), ofGetSeconds(), ofGetElapsedTimeMillis());
	
    ofSetHexColor(0x000000);
	basicFont.drawString(timeString, 10,ofGetHeight()-90);
	basicFont.drawString(eventString, 10,ofGetHeight()-20);
    
    ofEnableAlphaBlending();
    
    ofSetColor(170, 170, 170);
    ofRect(*pencilBox);
    ofRect(*fontBox);
    ofRect(*tableBox);
    ofRect(*okSaveBox);
    
    ofSetHexColor(0x000000);

    pencil->draw(10, 310);
    font->draw(10, 355);
    table->draw(10, 400);
    okSave->draw(10, 445);

    if (*fontSelected) {
        basicFont.drawString(theText, 40, 40);
        thisText->draw(basicFont);
        basicFont.drawString("text selected", ofGetWidth()/2,ofGetHeight()/3);
        
        for (int i = 0; i < drawThese.size(); i++) {
            drawThese[i].draw();
        }

    }
    
    if (*pencilSelected) {

        basicFont.drawString(theText, 40, 40);
        thisText->draw(basicFont);
        basicFont.drawString("pencil selected", ofGetWidth()/2,ofGetHeight()/3);
        
        for (int i = 0; i < drawThese.size(); i++) {
            drawThese[i].draw();
        }
        
        if (currentDrawing.size()>0) {
            for (int i = 1; i < currentDrawing.size(); i++) {
                ofLine(currentDrawing[i-1].x, currentDrawing[i-1].y, currentDrawing[i].x, currentDrawing[i].y);
            }
        }
    }
    
    if (*tableSelected) {
        basicFont.drawString(theText, 40, 40);
        thisText->draw(basicFont);
        for (int i = 0; i < drawThese.size(); i++) {
            drawThese[i].draw();
        }
        basicFont.drawString("table selected", ofGetWidth()/2,ofGetHeight()/3);
    }

    if (*okSaveSelected) {
        basicFont.drawString(theText, 40, 40);
        thisText->draw(basicFont);
        for (int i = 0; i < drawThese.size(); i++) {
            drawThese[i].draw();
        }

        basicFont.drawString("ok save selected", ofGetWidth()/2,ofGetHeight()/3);
    }

    
    ofDisableAlphaBlending();

}

//------------------------------------------------------------------
void ui::touchingDown(ofTouchEventArgs &touch) {

    sprintf(eventString, "touchDown = (%2.0f, %2.0f - id %i)", touch.x, touch.y, touch.id);
    
    if (*fontSelected) {
        thisText->touchingDown(touch);
    }

    
    if (*pencilSelected) {

        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;

        if (currentPos.y > ofGetHeight()/3) {
            currentDrawing.push_back(currentPos);
            thisDrawing.update(touch);
        }
    }
}

//------------------------------------------------------------------
void ui::touchingMove(ofTouchEventArgs &touch) {

    sprintf(eventString, "touchMoved = (%2.0f, %2.0f - id %i)", touch.x, touch.y, touch.id);
    
    if (*fontSelected) {
        thisText->touchingMove(touch);
    }
    
    if (*pencilSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;

        if (currentPos.y > ofGetHeight()/3) {
            currentDrawing.push_back(currentPos);
            thisDrawing.update(touch);
        }
    }
    
}

//------------------------------------------------------------------
void ui::touchingUp(ofTouchEventArgs &touch) {

 	sprintf(eventString, "touchUp = (%2.0f, %2.0f - id %i)",touch.x, touch.y, touch.id);
    
    if (*fontSelected) {
        thisText->touchingUp(touch);
    }

    if (*pencilSelected) {
        currentDrawing.clear();
        drawThese.push_back(thisDrawing);
        thisDrawing.reset();
    }
    
    //figures out if something was selected
    if (fontBox->inside(touch.x, touch.y)) {
        //use draw tool
        *fontSelected = true;
        *pencilSelected = false;
        *tableSelected = false;
        *okSaveSelected = false;
        printf(" Font gui task called \n");
    }
    
    if (pencilBox->inside(touch.x, touch.y)) {
        //use draw tool
        *fontSelected = false;
        *pencilSelected = true;
        *tableSelected = false;
        *okSaveSelected = false;
        printf(" Pencil gui task called \n");
    }

    if (tableBox->inside(touch.x, touch.y)) {
        //use image tool
        printf(" Table gui task called \n");
        *fontSelected = false;
        *pencilSelected = false;
        *tableSelected = true;
        *okSaveSelected = false;
    }

    if (okSaveBox->inside(touch.x, touch.y)) {
        //use image tool
        printf(" Save gui task called \n");
        *fontSelected = false;
        *pencilSelected = false;
        *tableSelected = false;
        *okSaveSelected = true;
    }
    
}


//------------------------------------------------------------------
void ui::doubleTap(ofTouchEventArgs &touch) {


}

//--------------------------------------------------------------
void ui::exit() {


}

