/*
 *  nav.h
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */
#ifndef _nav
#define _nav


#include "ofMain.h"

//for different navigating
#include "splashNav.h"
#include "problemMathOne.h"
#include "problemMathTwo.h"
#include "problemMathThree.h"

#include "saveMathOne.h"
#include "saveMathTwo.h"
#include "saveMathThree.h"

#include "button.h"

class nav {
	
	public:
        void setup();
		void update(int section, string iPhoneDocumentsDirectory);
		void draw(ofTrueTypeFont& basicFont);

        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);

        button             birdsButton;
        button             breadcrumbsButton;
        button             candyButton;
    
        button             myWorkButton;
        button             myWorkBirds;
        button             myWorkBreadcrumb;
        button             myWorkCandy;
    
        button             homeButton;
        ofImage            home;
        button             skipIntroButton;
        button             skipIntroTwoButton;
        ofImage            skipIntro;
    
        ofImage birds;
        ofImage breadcrumbs;
        ofImage candy;
        ofImage myWork;
    
        splashNav*              splash;
        problemMathOne*         mathExercisesOne;
        problemMathTwo*         mathExercisesTwo;
        problemMathThree*       mathExercisesThree;
        saveMathOne*            savedMathOne;
        saveMathTwo*            savedMathTwo;
        saveMathThree*          savedMathThree;
    
        bool    navStateToc;
        bool    navStateSplash;
    
        bool    navStateExerciseOne;
        bool    navStateExerciseTwo;
        bool    navStateExerciseThree;
        bool    navStateSavedMathOne;
        bool    navStateSavedMathTwo;
        bool    navStateSavedMathThree;
    
    
//-----------------------------------------------
//Loading feedback
    
    bool               loading;
    button             loadingFeedback;
    int                counter;

};

#endif
