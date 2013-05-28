/*
 *  problemMathThree.h
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#ifndef _problemMathThree
#define _problemMathThree


#include "ofMain.h"

#include "button.h"

#include "uiCreate.h"
#include "uiReflect.h"
#include "uiPresent.h"

class problemMathThree {
	
	public:
        
        problemMathThree();
        ~problemMathThree();
    
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
//        ofImage     grid;
    
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
