/*
 *  splashNav.h
 *
 *  Created by Ryan Raffa on 6/3/13.
 *
 */
#ifndef _splashNav
#define _splashNav


#include "ofMain.h"
#include "splashSection.h"

class splashNav {
	
	public:
        splashNav();
        ~splashNav();

		void update(int section);
		void draw();
    
        void makeSectionZero();
        void makeSectionOne();
        void makeSectionTwo();
        void makeSectionThree();
        void makeSectionFour();
        void makeSectionFive();
        void makeSectionSix();
    
        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);

        splashSection*  splashZero;
        splashSection*  splashOne;
        splashSection*  splashTwo;
        splashSection*  splashThree;
        splashSection*  splashFour;
        splashSection*  splashFive;
        splashSection*  splashSix;
    
        int section;
        
    
};

#endif
