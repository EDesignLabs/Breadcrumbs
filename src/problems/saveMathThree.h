/*
 *  saveMathThree.h
 *
 *  Created by Ryan Raffa on 6/6/13.
 *
 */

#ifndef _saveMathThree
#define _saveMathThree


#include "ofMain.h"

#include "button.h"
#include "uiCreate.h"
#include "uiReflect.h"
#include "uiPresent.h"

#include "ofxXmlSettings.h"


class saveMathThree {
	
	public:
        
        saveMathThree(string iPhoneDocumentsDirectory);
        ~saveMathThree();
    
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
