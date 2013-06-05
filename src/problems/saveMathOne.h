/*
 *  saveMathOne.h
 *
 *  Created by Ryan Raffa on 6/4/13.
 *
 */

#ifndef _saveMathOne
#define _saveMathOne


#include "ofMain.h"

#include "button.h"
#include "uiCreate.h"
#include "uiReflect.h"
#include "uiPresent.h"

#include "ofxXmlSettings.h"


class saveMathOne {
	
	public:
        
        saveMathOne(string iPhoneDocumentsDirectory);
        ~saveMathOne();
    
        void update();
		void draw(ofTrueTypeFont& basicFont);

        void xmlSetupThang();
    
        void next();
        void switchScene();
        void updateWhichScene();

        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);


//-----------------------------------------------
//Create, Reflect, Present
    
        uiCreate*   create;
        uiReflect*  reflect;
        uiPresent*  present;
    
        string      theText;
        ofImage     grid;
    
//-----------------------------------------------
//UI State
    
        button             presentButton;        
        bool               navStatePresent;
    
    
    
//-----------------------------------------------
//Used for saving the performance
   
        ofxXmlSettings      XMLOne;
        ofxXmlSettings      XMLTwo;
        string              message;

    
};

#endif
