/*
 *  button.h
 *  Created by Ryan Raffa on 5/5/13.
 *
 */
#ifndef _button
#define _button


#include "ofMain.h"

class button {
	
public:
    void setup(ofPoint pos, ofPoint size, ofPoint offSet, string thisString, ofColor thisColor);
    void setup(ofPoint pos, ofPoint size, ofColor thisColor);
    void setup(ofPoint pos, ofPoint size, ofColor thisColor, ofImage theImage, ofPoint offset);
    void setup(ofPoint pos, ofPoint size, ofColor thisColor, ofImage theImageOne, ofImage theImageTwo, ofPoint offset);
    void update(ofPoint newPosition);
    void draw();
    void drawToggle();
    void draw(ofTrueTypeFont& basicFont);
    void draw(ofTrueTypeFont& basicFont, ofImage& basicImage);
    void drawTextColor(ofTrueTypeFont& basicFont, ofImage& basicImage, ofColor textColor);
    void drawNoColor();
    void drawNoColorWithImage();
    void drawNoColorWithImageToggle();
    
    //tracking touch events
    void touchingDown(ofTouchEventArgs &touch);
    void touchingUp(ofTouchEventArgs &touch);
    void touchingMove(ofTouchEventArgs &touch);
    void doubleTap(ofTouchEventArgs &touch);
    
    //buttons
    ofRectangle    thisRectangle;
    
    //button color
    ofColor        thisColor;
    
    //image
    ofImage        theImage;
    ofImage        theImageTwo;
    bool           toggle;
    
    //text for buttons
    ofTrueTypeFont* basicFont;                           //  Font used. May need to address alternative sizes.
    
    string          thisString;
    
    // used for touch fields on settings
    bool            touching;
    bool            selected;
    
    //reuse info
    ofPoint         pos;
    
    ofPoint         offSet;
    
    
};

#endif
