/*
 *  image.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#ifndef _image
#define _image


#include "ofMain.h"

class image {
	
	public:
    
        void setup();
        void update(ofTouchEventArgs &touch);
		void draw();
		void reset();
    
        ofImage * theImage;
    

};

#endif
