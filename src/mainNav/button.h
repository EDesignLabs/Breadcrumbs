/*
 *  button.h
 *  Created by Ryan Raffa on 5/5/13.
 *
 */
#ifndef _button
#define _button


#include "ofMain.h"

#include "ofxRetinaTrueTypeFont.h"

class button {
	
public:
    void setup(ofPoint pos, ofPoint size, ofPoint offSet, string thisString, ofColor thisColor);
    void setup(ofPoint pos, ofPoint size, ofColor thisColor);
    void setup(ofPoint pos, ofPoint size, ofColor thisColor, ofImage theImage, ofPoint offset);

    //for two color button
    void setup(ofPoint pos, ofPoint size, ofPoint offSet, string thisString, ofColor thisColor, ofColor thisColorTwo, ofColor thisTextColor, ofColor thisTextColorTwo);
    //for two Image
    void setup(ofPoint pos, ofPoint size, ofColor thisColor, ofImage theImageOne, ofImage theImageTwo, ofPoint offset);
    
    void update(float newPosition);
    void update(ofPoint newPosition);
    void update(ofColor newColor, string newText, ofPoint newOffset);
    void draw();
    void drawOnTop();
    void draw(ofxRetinaTrueTypeFont& basicFont);
    void draw(ofImage& basicImage);
    void draw(ofxRetinaTrueTypeFont& basicFont, ofImage& basicImage);
    void drawTextColor(ofxRetinaTrueTypeFont& basicFont, ofColor textColor);
    
    //for NAV TOC
    void drawTextColorImage(ofxRetinaTrueTypeFont& basicFont, ofImage& basicImage, ofColor textColor);

    void drawNoColor();
    void drawNoColorTransparency();
    void drawNoColorWithImage();
    void drawNoColorWithImageToggle();
    void drawWithImage();
    
    void drawTwoColors(ofxRetinaTrueTypeFont& basicFont);
    void drawTwoColorsRounded(ofxRetinaTrueTypeFont& basicFont);
    void drawTwoImages();
    
//-----------------------------------------------
//tracking touch events

    void touchingDown(ofTouchEventArgs &touch);
    void touchingUp(ofTouchEventArgs &touch);
    void touchingMove(ofTouchEventArgs &touch);
    void doubleTap(ofTouchEventArgs &touch);
    
//-----------------------------------------------
//buttons

    ofRectangle    thisRectangle;
    
//-----------------------------------------------
//button color

    ofColor        thisColor;
    ofColor        thisColorTwo;

//-----------------------------------------------
//text color

    ofColor        thisTextColor;
    ofColor        thisTextColorTwo;

    
//-----------------------------------------------
//image

    ofImage        theImage;
    ofImage        theImageTwo;
    bool           toggle;
        
    string         thisString;
    
//-----------------------------------------------
// used for touch fields on settings

    bool            touching;
    bool            active;
    bool            selected;
    
//-----------------------------------------------
//reuse info

    ofPoint         pos;
    
    ofPoint         offSet;
    
//-----------------------------------------------
//for problem stages only!!!
    
    int             stage;
    string          XMLFileOne;
    string          XMLFileTwo;
    
    string          myCreateProbRefresh;
    string          myReflectProbRefresh;
    
    string          problemText;
    int             difficulty;

    
};

#endif
