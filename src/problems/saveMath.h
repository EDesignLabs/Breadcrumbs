/*
 *  saveMath.h
 *
 *  Created by Ryan Raffa on 9/2/13.
 *
 */

#ifndef _saveMath
#define _saveMath


#include "ofMain.h"

#include "button.h"
#include "uiCreate.h"
#include "uiReflect.h"
#include "uiPresent.h"

#include "ofxTextSuite.h"

#include "ofxRetinaTrueTypeFont.h"

#include "xmlParty.h"
#include "ofxXmlSettings.h"

class saveMath {
	
	public:
        
        saveMath(string iOSDocumentsDirectory, button& _mathButton, ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36);
        ~saveMath();
    
        bool loadImage(string imageLoc);

        string getXMLString ();

        void update();
		void draw(ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36);
    
        void next();
        void switchScene();
        void updateWhichScene();

        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);


//-----------------------------------------------
//Create, Reflect, Present
    
        uiPresent*  present;
    
        ofImage     grid;
        bool        loadedImage;
    
    
//-----------------------------------------------
//Loading XML
    
        ofxXmlSettings     XMLOne;
        ofxXmlSettings     XMLTwo;
        xmlParty*          theXMLParty;

//-----------------------------------------------
//UI State
    
        button             presentButton;        
        bool               navStatePresent;
    
//-----------------------------------------------
//Wrapping text
    
        ofxTextBlock        theTextWrap;
    
    
    
//-----------------------------------------------
//Used for saving the performance
   
        string              message;

    
};

#endif
