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
#include "image.h"
#include "text.h"


class uiCreate {
	
	public:
    
        uiCreate(string theText);
        ~uiCreate();
    
		void update();
		void draw(ofTrueTypeFont& basicFont);

        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);
        void exit();

        vector <ofPoint> currentDrawing;
        
        //This is the drawing that is tracked and then pushed on the stack
        vector <drawing> drawThese;
    
        //how initial spots are drawn
        drawing thisDrawing;

        image thisImage;

        char eventString[255];
        char timeString[255];
    
        //for text
        string theText;
    
        //uiCreate
        ofImage*    pencil;
        ofImage*    erase;

        button      pencilButton;
        button      eraseButton;
    
        bool*       pencilSelected;
        bool*       eraseSelected;
        
};

#endif
