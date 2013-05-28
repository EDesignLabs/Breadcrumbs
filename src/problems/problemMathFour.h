/*
 *  problemMathFour.h
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#ifndef _problemMathFour
#define _problemMathFour


#include "ofMain.h"

#include "button.h"

#include "uiCreate.h"
#include "uiReflect.h"
#include "uiPresent.h"

class problemMathFour {
	
	public:
        
        problemMathFour();
        ~problemMathFour();
    
        void update();
		void draw(ofTrueTypeFont& basicFont);

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
        ofImage     equation;
    
//-----------------------------------------------
//UI State
    
        button             createButton;
        button             reflectButton;
        button             presentButton;
        button             questionButton;
        ofImage            questionButtonImage;
        
        bool               navStateCreate;
        bool               navStateReflect;
        bool               navStatePresent;
        bool               navStateQuestion;
    
    
//-----------------------------------------------
//Feedback (quick and dirty)
    
        ofPoint            feedbackBrickPos;
        float              distX;
    
};

#endif
