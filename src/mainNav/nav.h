/*
 *  nav.h
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */
#ifndef _nav
#define _nav


#include "ofMain.h"

//for different navigating
#include "splashNav.h"
//#include "userName.h"
#include "problemMath.h"
#include "saveMath.h"

#include "button.h"

#include "ofxRetinaTrueTypeFont.h"

#include "xmlParty.h"
#include "ofxXmlSettings.h"

//For FTP
//#include "ofURLFileLoader.h"


class nav {
	
	public:
        void setup(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo);
		void update(int section, string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, ofPoint _currentLocation, ofPoint speed, bool panning, ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36);
		void draw(ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36);

//        void setUserName(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, string _setUserName);
        void setFileName(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo);
    
        void starsDraw(float x, float y, int difficulty);
        void sendDraw(button mathButton);
        void resetDraw(button resetButton);
    
        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);
    
    
//-----------------------------------------------
//for XML
    
        xmlParty            theXMLParty;

//-----------------------------------------------
//various buttons for each stage
    
    
        button              welcomeButton;
    
        button              mathOneButton;
        button              mathTwoButton;
        button              mathThreeButton;
        button              mathFourButton;
        button              mathFiveButton;
        button              mathSixButton;
    
        button              greyStartButton;

        button              homeButton;
        ofImage             homeImageOne;
        ofImage             homeImageTwo;
        ofImage             editImage;
    
        ofColor             startColor;
        ofPoint             startOffset;
        string              startString;
    
        ofColor             continueColor;
        string              continueString;
        ofPoint             continueOffset;

        ofColor             viewColor;
        string              viewString;
        ofPoint             viewOffset;


//-----------------------------------------------
//for skipping intro

        button              skipIntroButton;
        button              skipIntroTwoButton;
    

//-----------------------------------------------
//for user name
    
//        button              startUserNameButton;
//        button              submitUserNameButton;

    
//-----------------------------------------------
//the different states

        splashNav*          splash;
//        userName*           theUserName;
//        string              userNameSet;

        problemMath*        mathOne;
        problemMath*        mathTwo;
        problemMath*        mathThree;
        problemMath*        mathFour;
        problemMath*        mathFive;
        problemMath*        mathSix;
    
        saveMath*           savedMathOne;
        saveMath*           savedMathTwo;
        saveMath*           savedMathThree;
        saveMath*           savedMathFour;
        saveMath*           savedMathFive;
        saveMath*           savedMathSix;


//-----------------------------------------------
//checks NAV state

        bool                navStateToc;
        bool                navStateSplash;
//        bool                navStateUserName;

        bool                navStateMathOne;
        bool                navStateMathTwo;
        bool                navStateMathThree;
        bool                navStateMathFour;
        bool                navStateMathFive;
        bool                navStateMathSix;

        bool                navStateSavedMathOne;
        bool                navStateSavedMathTwo;
        bool                navStateSavedMathThree;
        bool                navStateSavedMathFour;
        bool                navStateSavedMathFive;
        bool                navStateSavedMathSix;
    
        bool                navStateNewTextMathSix;;
    
    
        
//-----------------------------------------------
//Loading feedback
    
        bool                loading;
        button              loadingFeedback;
        int                 counter;

//-----------------------------------------------
//FAQ
    
        button              questionButton;
        ofImage             FAQ;

//-----------------------------------------------
//Metrics
    
        button              metricsButton;
        button              metricsButton2;
        ofImage             metrics;


//-----------------------------------------------
//Stars
    
        ofImage             starNormal;
        ofImage             starBlackWhite;


//-----------------------------------------------
//Grey Refresh
    
        ofImage             greyRefresh;
    
//-----------------------------------------------
//FTP files
    
//        ofURLFileLoader     ftpUpload;

//        button              sendMathOneButton;
//        button              sendMathTwoButton;
//        button              sendMathThreeButton;
//        button              sendMathFourButton;
//        button              sendMathFiveButton;
//        button              sendMathSixButton;


//-----------------------------------------------
//Reset files
    
        button              resetMathOneButton;
        button              resetMathTwoButton;
        button              resetMathThreeButton;
        button              resetMathFourButton;
        button              resetMathFiveButton;
        button              resetMathSixButton;
    
    
//-----------------------------------------------
//Problem strings

        string              probOne;
        string              probTwo;
        string              probThree;
        string              probFour;
        string              probFive;
        string              probSix;
};

#endif
