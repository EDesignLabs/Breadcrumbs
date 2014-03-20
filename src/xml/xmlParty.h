/*
 *  xmlParty.h
 *
 *  Created by Ryan Raffa on 9/26/13.
 *
 */

#ifndef _xmlParty
#define _xmlParty


#include "ofMain.h"

#include "button.h"
#include "drawing.h"
#include "flagState.h"

#include "ofxXmlSettings.h"

class xmlParty {
	
public:
    
    xmlParty();
    ~xmlParty();
    
    
//-----------------------------------------------
//XML

    void xmlSetupThang(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton);

    //this saves the XML after breadcrumbs
    void saveXML(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton, vector <drawing>& _drawThese, vector<flagState>& _theFlagStates, string& theText);

    void setFileNameSave(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& mathButton, vector <drawing>& _drawThese, vector<flagState>& _theFlagStates, string& theText);
    
    void saveXMLText(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton);
    
    void setPoints(vector <drawing>& _drawTheseIn, vector <drawing>& _drawTheseOut, vector<flagState>& _theFlagStates, vector <ofPoint>& _scrubFeedback, int& _startTime, int& _endTime, button& _scrubBox);

    void getXML (ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, vector <drawing>& _drawThese, vector<flagState>& _theFlagStates, vector <ofPoint>& _scrubFeedback, int& _startTime, int& _endTime, button& _scrubBox);
    
    void getPoints(vector <drawing> _drawThese, vector<flagState>& _theFlagStates, vector <ofPoint>& _scrubFeedback, int& _startTime, int& _endTime, button& _scrubBox);
    
    void checkSavedFlags(vector<flagState>& _theFlagStates);
    
    
    void resetXML(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton, button& resetMathButton);

    
    string getXMLString(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton);
    int getXMLStage(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton);
    
//    ofxXmlSettings XMLOne;
//    ofxXmlSettings XMLTwo;
    string messageOne;
    string messageTwo;
    
    int lastTagNumberDrawing;
    int lastTagNumberTouchPoint;
    int lastTagNumberFlagstate;
    
};

#endif
