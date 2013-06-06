/*
 *  flagState.cpp
 *
 *  Created by Ryan Raffa on 5/3/13.
 *
 */

#ifndef _flagState
#define _flagState


#include "ofMain.h"
#include "button.h"


typedef struct {
    
    ofPoint startPos;
    ofPoint endPos;
    ofPoint size;
    
    ofPoint textPos;
    ofPoint tabPos;
    ofPoint tabSize;
    ofPoint tabPostPos;
    ofPoint tabPostSize;
    
    ofColor color;
    
    ofRectangle presentCheck;
    
    int     floor;
    
    //has a state been names yet, if not, show list of selections
    bool    started;
    bool    ended;
    bool    selected;
    
    //determines if decoding, planning, doing, checking
    int     state;
    string  stateMessage;
	
    button  removeFlagButton;
    
}	reflectionFlag;


class flagState {
	
	public:
    
        flagState();
        ~flagState();
    
        void updateStart(ofTouchEventArgs &touch);
        void update(ofTouchEventArgs &touch);
        void updateEnd(ofTouchEventArgs &touch);

        void createButtons();
        void selectingButton();
        void makeMarker();
        void adjustMarker(int floor);
    
        void draw(ofTrueTypeFont& basicFont);
        void drawRemove(ofTrueTypeFont& basicFont);
    
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);

        void reset();
    
        button  identifying;
        button  planning;
        button  walking;
        button  changing;
        button  verifying;
    
        ofRectangle    taskBox;
    
        reflectionFlag theReflectionFlag;
        
};

#endif
