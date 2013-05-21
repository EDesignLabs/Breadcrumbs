/*
 *  exercisesMath.h
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#ifndef _exercisesMath
#define _exercisesMath


#include "ofMain.h"

#include "problemMathOne.h"

class exercisesMath {
	
	public:
        
        exercisesMath();
        ~exercisesMath();
    
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
//Math Problems
    
        problemMathOne* problemOne;

        
};

#endif
