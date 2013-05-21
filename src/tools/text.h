/*
 *  text.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#ifndef _text
#define _text


#include "ofMain.h"

class text {
	
	public:
        
        text();
        ~text();

        void update();
		void draw(ofTrueTypeFont& basicFont);
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);

        ofTrueTypeFont verdana16;

};

#endif
