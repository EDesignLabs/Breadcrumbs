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
#include "button.h"

class nav {
	
	public:
        void setup();
		void update(int section);
		void draw(ofTrueTypeFont& basicFont);

        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);

        button             mathButton;
        button             scienceButton;
        button             historyButton;
        button             mathAgainButton;
        button             homeButton;
        ofImage            home;
        button             skipIntroButton;
        ofImage            skipIntro;
    
        ofImage raleigh;
        ofImage sanFran;
        ofImage gainesville;
    
        splashNav*              splash;
        problemMathOne*         mathExercisesOne;
        problemMathTwo*         mathExercisesTwo;
        problemMathThree*       mathExercisesThree;
        problemMathFour*        mathExercisesFour;
    
        bool    navStateToc;
        bool    navStateSplash;
    
        bool    navStateExerciseOne;
        bool    navStateExerciseTwo;
        bool    navStateExerciseThree;
        bool    navStateExerciseFour;
        
};

#endif
