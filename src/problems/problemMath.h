/*
 *  problemMath.h
 *
 *  Created by Ryan Raffa on 9/2/13.
 *
 */

#ifndef _problemMath
#define _problemMath


#include "ofMain.h"

#include "button.h"

#include "uiCreate.h"
#include "uiReflect.h"
#include "uiPresent.h"

#include "ofxTextSuite.h"

#include "ofxRetinaTrueTypeFont.h"

#include "xmlParty.h"
#include "ofxXmlSettings.h"

//For FTP
#include "ofURLFileLoader.h"


class problemMath {
	
	public:
        
        problemMath(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton, ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36);
        ~problemMath();

        bool loadImage(string imageLoc);
    
        void update(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton, ofPoint _currentLocation, ofPoint _speed, bool _panning);
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
    
        uiCreate*           create;
        uiReflect*          reflect;
        uiPresent*          present;
    
        xmlParty*           theXMLParty;
    
        ofImage             grid;
        bool                loadedImage;
    
//-----------------------------------------------
//UI State
    
        button             createButton;
        button             reflectButton;
        button             presentButton;
        
        bool               navStateCreate;
        bool               navStateReflect;
        bool               navStatePresent;

    
//-----------------------------------------------
//Loading XML

        ofxXmlSettings     XMLOne;
        ofxXmlSettings     XMLTwo;
    
    
//-----------------------------------------------
//FTP files
    
        ofURLFileLoader     ftpUpload;

    
//-----------------------------------------------
//Wrapping text

        ofxTextBlock       theTextWrap;

    
//-----------------------------------------------
//Saving feedback
    
        bool               saving;
        button*            savingFeedback;
        int                counter;
        ofColor            savingFontColor;
    
};

#endif
