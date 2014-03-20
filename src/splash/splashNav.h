/*
 *  splashNav.h
 *
 *  Created by Ryan Raffa on 6/3/13.
 *
 */
#ifndef _splashNav
#define _splashNav


#include "ofMain.h"
#include "button.h"

typedef struct {
    
    ofPoint     pos;
    
    ofPoint     pageStage0;  //when page should start to be shown
    ofPoint     pageStage1;  //when page should start to be shown
    ofPoint     pageStage2;  //when page should start to be shown
    ofPoint     pageStage3;  //when page should start to be shown
    ofPoint     pageStage4;  //when page should start to be shown
    ofPoint     pageStage5;  //when page should start to be shown
    
}	splashPage;


class splashNav {
	
	public:
        splashNav();
        ~splashNav();

		void update(int section, bool panning, ofPoint _currentLocation);
		void draw();
    
        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);

        void getThere(ofPoint& current, ofPoint& ideal);
        
        int section;
    
        splashPage      splashPageOne;
        splashPage      splashPageTwo;
    
        ofImage*        layerOne;
        ofImage*        layerTwoA;
        ofImage*        layerTwoB;
        ofImage*        layerTwoC;
        ofImage*        layerTwoD;
        ofImage*        layerTwoE;
        ofImage*        layerTwoF;
    
        ofPoint         locationB;
        ofPoint         locationC;
        ofPoint         locationD;
        ofPoint         locationE;
        ofPoint         locationF;
    
        ofPoint*        storyAction;
        ofPoint*        storyZeroActive;
        ofPoint*        storyOneActive;
        ofPoint*        storyTwoActive;
        ofPoint*        storyThreeActive;
        ofPoint*        storyFourActive;
        ofPoint*        storyFiveActive;

        //for monitoring when pan stops
        ofPoint         newLocation;
        bool            previousState;

};

#endif
