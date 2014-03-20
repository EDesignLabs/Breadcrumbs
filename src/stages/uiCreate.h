/*
 *  uiCreate.h
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#ifndef _uiCreate
#define _uiCreate


#include "ofMain.h"

#include "button.h"
#include "drawing.h"

#include "ofxXmlSettings.h"
#include "xmlParty.h"

class uiCreate {
	
	public:
    
        uiCreate();
        ~uiCreate();
    
		void update(ofPoint _currentLocation, ofPoint speed, bool panning);
		void draw(bool loadedImage, ofImage& grid);
    
        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);
        void exit();

        vector <ofPoint> currentDrawing;
        
//-----------------------------------------------
//This is the drawing that is tracked and then pushed on the stack

        vector <drawing> drawThese;
    
//-----------------------------------------------
//how initial spots are drawn

        drawing         thisDrawing;

        char            eventString[255];
        char            timeString[255];
    
//-----------------------------------------------
//for text
        string          theText;
    
    
//-----------------------------------------------
//for flagging process
//no data is stored here
    
        vector<flagState> theFlagStates;

//-----------------------------------------------
//uiCreate
    
        button*         moveButton;
        button*         pencilButton;
        button*         eraseButton;
        button*         questionButton;
    
        bool*           moveSelected;
        bool*           pencilSelected;
        bool*           eraseSelected;
    
        ofPoint         pointOfDeparture;
        ofPoint         amountMoved;
    
        ofPoint         currentLocation;
        ofPoint         newLocation;
    
//-----------------------------------------------
//FAQ

        ofImage*        FAQ;
    

};

#endif
