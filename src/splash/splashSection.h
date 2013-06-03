/*
 *  splashSection.h
 *
 *  Created by Ryan Raffa on 6/3/13.
 *
 */
#ifndef _splashSection
#define _splashSection


#include "ofMain.h"

typedef struct {
    
    int alphaValue;

    ofImage stage;
    
    int     pageStart;  //when page should start to be shown
    int     pageEnd;    //when page should fade out
    
    bool    turnOn;
    bool    turnOff;
    
}	splashPage;




class splashSection {
	
	public:
        splashSection();
        ~splashSection();

        void setup(ofImage stage, int pageStart, int pageEnd, bool turnOn, bool turnOff, int currentAlpha);
		void update();
		void slideTimer();
        void updatePage(splashPage &thePage);
        void draw();
    
        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);

        ofPoint pos;
        vector  <splashPage> section;

        float currentTime;
    
        float     sectionStart; //when section actually starts
        float     lastPageChange;
    
        bool      updated;
    
};

#endif
