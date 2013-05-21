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
    
    ofColor color;
    
    //has a state been names yet, if not, show list of selections
    bool    ended;
    bool    selected;
    
    //determines if decoding, planning, doing, checking
    int     state;
    string  stateMessage;
	
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
    
        void draw(ofTrueTypeFont& basicFont);

        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);

        void reset();
    
        button  decoding;
        button  planning;
        button  doing;
        button  checking;
    
        reflectionFlag theReflectionFlag;
    
};

#endif
