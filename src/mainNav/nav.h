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
#include "problemMathFour.h"

#include "saveMathOne.h"

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
        button             homeButton;
        ofImage            home;
        button             skipIntroButton;
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
    
        bool    navStateToc;
        bool    navStateSplash;
    
        bool    navStateExerciseOne;
        bool    navStateExerciseTwo;
        bool    navStateExerciseThree;
        bool    navStateSavedMath;
        
};

#endif
