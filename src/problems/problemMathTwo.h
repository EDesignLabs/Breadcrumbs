/*
 *  problemMathTwo.h
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#ifndef _problemMathTwo
#define _problemMathTwo


#include "ofMain.h"

#include "button.h"

#include "uiCreate.h"
#include "uiReflect.h"
#include "uiPresent.h"

class problemMathTwo {
	
	public:
        
        problemMathTwo();
        ~problemMathTwo();
    
        void update(string iPhoneDocumentsDirectory);
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
//Saving feedback
    
    bool               saving;
    button*            savingFeedback;
    int                counter;
    ofColor            savingFontColor;
    

    
//-----------------------------------------------
//Feedback (quick and dirty)
    
        ofPoint            feedbackBrickPos;
        float              distX;
    
};

#endif
