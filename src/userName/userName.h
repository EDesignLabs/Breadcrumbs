/*
 *  userName.h
 *
 *  Created by Ryan Raffa on 9/25/13.
 *
 */
#ifndef _userName
#define _userName


#include "ofMain.h"
#include "button.h"

class userName {
	
	public:
        userName();
        ~userName();

		void update(string _theUserName);
		void draw();
        
        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);


        ofImage*    breadCrumbsImage;
    
    
};

#endif
