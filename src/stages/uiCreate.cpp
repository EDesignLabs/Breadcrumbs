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
    
    exit();

    //uiCreate elements
    delete moveButton;
    delete pencilButton;
    delete eraseButton;
    delete questionButton;
    
    delete moveSelected;
    delete pencilSelected;
    delete eraseSelected;
    
    delete FAQ;
    
}

////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiCreate::uiCreate() {
        
    //-----------------------------------------------
    //load uiCreate images
    ofImage    moveImageOne;
    ofImage    moveImageTwo;
    ofImage    pencilImageOne;
    ofImage    pencilImageTwo;
    ofImage    eraseImageOne;
    ofImage    eraseImageTwo;
    ofImage    questionImageOne;
    ofImage    questionImageTwo;
    
    moveImageOne.loadImage("images/ui/Arrows_Low.png");
    moveImageTwo.loadImage("images/ui/Arrows_Low_bw.png");
    pencilImageOne.loadImage("images/ui/Pencil_Low.png");
    pencilImageTwo.loadImage("images/ui/Pencil_Low_bw.png");
    eraseImageOne.loadImage("images/ui/Eraser_Low.png");
    eraseImageTwo.loadImage("images/ui/Eraser_Low_bw.png");
    questionImageOne.loadImage("images/ui/FAQ_Low.png");
    questionImageTwo.loadImage("images/ui/FAQ_Low_bw.png");
    
    FAQ = new ofImage;
    FAQ->loadImage("images/faq/FAQ1_Low.png");
    
    moveButton = new button;
    pencilButton = new button;
    eraseButton = new button;
    questionButton = new button;
    
    //set initial values for state
    moveSelected = new bool;
    pencilSelected = new bool;
    eraseSelected = new bool;
    
    *moveSelected = false;
    *pencilSelected = true;
    *eraseSelected = false;
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    
    size.set(moveImageOne.getWidth(), moveImageOne.getHeight());
    pos.set(15, 683);
    offSet.set(0, 0);
    color.set(200, 200, 200);
    moveButton->setup(pos, size, color, moveImageOne, moveImageTwo, offSet);
    
    size.set(pencilImageOne.getWidth(), pencilImageOne.getHeight());
    pos.set(100, 683);
    pencilButton->setup(pos, size, color, pencilImageOne, pencilImageTwo, offSet);
    pencilButton->toggle = true;
    
    size.set(eraseImageOne.getWidth(), eraseImageOne.getHeight());
    pos.set(185, 683);
    eraseButton->setup(pos, size, color, eraseImageOne, eraseImageTwo, offSet);
    
    //-----------------------------------------------
    //for question button
    size.set(questionImageOne.getWidth(), questionImageOne.getHeight());
    pos.set(ofGetWidth()-85, 15);
    offSet.set(0, 0);
    color.set(230, 230, 230, 245);
    questionButton->setup(pos, size, color, questionImageOne, questionImageTwo, offSet);
    
}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiCreate::update(ofPoint _currentLocation, ofPoint speed, bool panning) {

    //-----------------------------------------------
    //NAV state is sorted out

    if (moveButton->selected) {
        *eraseSelected = false;
        *pencilSelected = false;
        *moveSelected = true;
        moveButton->selected=false;
        pencilButton->toggle = false;
        eraseButton->toggle = false;
    }

    if (pencilButton->selected) {
        *eraseSelected = false;
        *moveSelected = false;
        *pencilSelected = true;
        pencilButton->selected=false;
        eraseButton->toggle = false;
        moveButton->toggle = false;
    }
    
    if (eraseButton->selected) {
        *pencilSelected = false;
        *moveSelected = false;
        *eraseSelected = true;
        eraseButton->selected=false;
        moveButton->toggle = false;
        pencilButton->toggle = false;
    }
    
    if (*moveSelected) {
        
        if (panning) {
            
            currentLocation = this->newLocation + _currentLocation;
        
            if (currentLocation.x > 1024) currentLocation.x = 1024;
            if (currentLocation.x < -1024) currentLocation.x = -1024;
            
            if (currentLocation.y > 768) currentLocation.y = 768;
            if (currentLocation.y < -768) currentLocation.y = -768;
        
        } else {
            
            this->newLocation = currentLocation;
            
        }
        
    }
        
}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------

void uiCreate::draw(bool loadedImage, ofImage& grid) {
    
    ofSetHexColor(0x000000);
    
    //-----------------------------------------------
    //Translate
    
    ofPushMatrix();
    ofTranslate(currentLocation.x, currentLocation.y);
    
    
    //-----------------------------------------------
    //What is created and saved
    
    for (int i = 0; i < drawThese.size(); i++) {
        ofSetColor(drawThese[i].color);
        ofSetLineWidth(drawThese[i].lineWidth);
        drawThese[i].draw();
    }
    
    
    
    //-----------------------------------------------
    //Drawings from Tools
    
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
    
    ofPopMatrix();
    
    
    //-----------------------------------------------
    //What is created
    
    ofSetLineWidth(1.0);
    ofSetColor(220, 220, 220, 220);
    ofRectRounded(871, 648, 138, 105, 5);
    
    ofPoint whereAreWeNowLocation;
    whereAreWeNowLocation.x = -currentLocation.x/23;
    whereAreWeNowLocation.y = -currentLocation.y/23;
    
    whereAreWeNowLocation.x += 45 + 872;
    whereAreWeNowLocation.y += 34 + 649;
    
    ofPoint newLocation;
    //44 + 873
    //33 + 650
    newLocation.set(918, 684);
    
    ofColor checkColor;
    checkColor.set(255, 255, 255);
    
    for (int i = 0; i < drawThese.size(); i++) {
        if (drawThese[i].color == checkColor ) {
            ofSetColor(220, 220, 220, 220);
        } else {
            ofSetColor(drawThese[i].color);
        }
        ofSetLineWidth(1.0);
        drawThese[i].drawMini(newLocation);
    }
    
    
    //-----------------------------------------------
    // Navigation view
    
    ofSetColor(250, 250, 250, 220);
//    ofRect(whereAreWeNowLocation.x, whereAreWeNowLocation.y, 45, 34);
    ofRectRounded(whereAreWeNowLocation.x, whereAreWeNowLocation.y, 46, 35, 5);
    ofSetLineWidth(2.0);
    
    
    //-----------------------------------------------
    //Tool Button UI
    
    ofSetHexColor(0xFFFFFF);
    
    ofEnableAlphaBlending();
    moveButton->drawTwoImages();
    pencilButton->drawTwoImages();
    eraseButton->drawTwoImages();

    
    //-----------------------------------------------
    //grid question
    
    if (loadedImage) {
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255);
        grid.draw(175, 300);
        ofDisableAlphaBlending();
    }
    
    
    //-----------------------------------------------
    //FAQ

    if (questionButton->toggle) {
        ofEnableAlphaBlending();
        ofSetColor(70, 70, 70, 180);
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
        ofSetColor(255, 255, 255, 255);
        FAQ->draw(0, 0);
        ofDisableAlphaBlending();
    }
    
    //question mark
    ofSetColor(230, 230, 230, 245);
    ofRect(923, 0, 101, 50);
    questionButton->drawTwoImages();
    ofDisableAlphaBlending();


    
}

////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiCreate::touchingDown(ofTouchEventArgs &touch) {
    
    moveButton->touchingDown(touch);
    pencilButton->touchingDown(touch);
    eraseButton->touchingDown(touch);
    questionButton->touchingDown(touch);
    
    if (*moveSelected) {

        ofPoint currentPos;
        currentPos.x = touch.x - (currentLocation.x);
        currentPos.y = touch.y - (currentLocation.y);
        
        ofColor theColor;
        theColor.set(255, 0, 0);
        float lineWidth;
        lineWidth = 2.0;
        bool drawMe;
        drawMe = false;
        
        currentDrawing.push_back(currentPos);
        thisDrawing.update(currentPos, theColor, lineWidth, drawMe, currentLocation);
        
    }
        
    if (*pencilSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x - (currentLocation.x);
        currentPos.y = touch.y - (currentLocation.y);
        
        ofColor theColor;
        theColor.set(0, 0, 0);
        float lineWidth;
        lineWidth = 2.0;
        bool drawMe;
        drawMe = true;
        
        currentDrawing.push_back(currentPos);
        thisDrawing.update(currentPos, theColor, lineWidth, drawMe, currentLocation);
    }


    if (*eraseSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x - (currentLocation.x);
        currentPos.y = touch.y - (currentLocation.y);
        
        ofPoint posOne;
        ofPoint posTwo;
        ofPoint posThree;
        ofPoint posFour;
        
        posOne = posTwo = posThree = posFour = currentPos;
        
        posOne.x+=10.0;
        posTwo.y+=10.0;
        posThree.x-=10.0;
        posFour.y-=10.0;
        
        ofColor theColor;
        theColor.set(255, 255, 255);
        float lineWidth;
        lineWidth = 20.0;
        bool drawMe;
        drawMe = true;
        
        currentDrawing.push_back(currentPos);
        currentDrawing.push_back(posOne);
        currentDrawing.push_back(posTwo);
        currentDrawing.push_back(posThree);
        currentDrawing.push_back(posFour);
        thisDrawing.update(currentPos, theColor, lineWidth, drawMe, currentLocation);
        thisDrawing.update(posOne, theColor, lineWidth, drawMe, currentLocation);
        thisDrawing.update(posTwo, theColor, lineWidth, drawMe, currentLocation);
        thisDrawing.update(posThree, theColor, lineWidth, drawMe, currentLocation);
        thisDrawing.update(posFour, theColor, lineWidth, drawMe, currentLocation);
    }

}

//------------------------------------------------------------------
void uiCreate::touchingMove(ofTouchEventArgs &touch) {
    
    moveButton->touchingMove(touch);
    pencilButton->touchingMove(touch);
    eraseButton->touchingMove(touch);
    questionButton->touchingMove(touch);
    
    if (*moveSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x - (currentLocation.x);
        currentPos.y = touch.y - (currentLocation.y);
        
        ofColor theColor;
        theColor.set(255, 0, 0);
        float lineWidth;
        lineWidth = 2.0;
        bool drawMe;
        drawMe = false;
        
        currentDrawing.push_back(currentPos);
        thisDrawing.update(currentPos, theColor, lineWidth, drawMe, currentLocation);
    }

    if (*pencilSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x - (currentLocation.x);
        currentPos.y = touch.y - (currentLocation.y);
        
        ofColor theColor;
        theColor.set(0, 0, 0);
        float lineWidth;
        lineWidth = 2.0;
        bool drawMe;
        drawMe = true;

        currentDrawing.push_back(currentPos);
        thisDrawing.update(currentPos, theColor, lineWidth, drawMe, currentLocation);
    }
    
    
    if (*eraseSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x - (currentLocation.x);
        currentPos.y = touch.y - (currentLocation.y);
        
        ofPoint posOne;
        ofPoint posTwo;
        ofPoint posThree;
        ofPoint posFour;
        
        posOne = posTwo = posThree = posFour = currentPos;
        
        posOne.x+=10.0;
        posTwo.y+=10.0;
        posThree.x-=10.0;
        posFour.y-=10.0;
        
        ofColor theColor;
        theColor.set(255, 255, 255);
        float lineWidth;
        lineWidth = 20.0;
        bool drawMe;
        drawMe = true;

        currentDrawing.push_back(currentPos);
        currentDrawing.push_back(posOne);
        currentDrawing.push_back(posTwo);
        currentDrawing.push_back(posThree);
        currentDrawing.push_back(posFour);
        thisDrawing.update(currentPos, theColor, lineWidth, drawMe, currentLocation);
        thisDrawing.update(posOne, theColor, lineWidth, drawMe, currentLocation);
        thisDrawing.update(posTwo, theColor, lineWidth, drawMe, currentLocation);
        thisDrawing.update(posThree, theColor, lineWidth, drawMe, currentLocation);
        thisDrawing.update(posFour, theColor, lineWidth, drawMe, currentLocation);
    }

}

//------------------------------------------------------------------
void uiCreate::touchingUp(ofTouchEventArgs &touch) {
    
    moveButton->touchingUp(touch);
    pencilButton->touchingUp(touch);
    eraseButton->touchingUp(touch);
    questionButton->touchingUp(touch);
    
    if (moveButton->selected == true) moveButton->toggle = true;
    if (pencilButton->selected == true) pencilButton->toggle = true;
    if (eraseButton->selected == true) eraseButton->toggle = true;
    
    if (*moveSelected) {
        currentDrawing.clear();
        drawThese.push_back(thisDrawing);
        thisDrawing.reset();
    }

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

    moveButton->doubleTap(touch);
    pencilButton->doubleTap(touch);
    eraseButton->doubleTap(touch);

}

//--------------------------------------------------------------
void uiCreate::exit() {


}

