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
#include "exercisesMath.h"
#include "button.h"

class nav {
	
	public:
        void setup();
		void update();
		void draw(ofTrueTypeFont& basicFont);

        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);

        button             mathButton;
        button             scienceButton;
        button             historyButton;
        button             homeButtonRect;
        ofImage            homeButton;
    
        ofImage raleigh;
        ofImage sanFran;
        ofImage gainesville;
    
        exercisesMath*         mathExercises;

        bool    navStateToc;
        bool    navStateExercises;
    
        bool    endSplash;
    
};

#endif
