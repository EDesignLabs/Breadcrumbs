/*
 *  xmlParty.cpp
 *
 *  Created by Ryan Raffa on 9/26/13.
 *
 */

#include "xmlParty.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
xmlParty::~xmlParty() {
    
    
    //uiReflect elements


}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
xmlParty::xmlParty() {
    

    
}


////////////////////////////////////////////////////////////////////
//      XML Setup Thang                                           //
////////////////////////////////////////////////////////////////////

//This takes the location of the XML file
//and loads it into the ofxXMLSettings container
//------------------------------------------------------------------
void xmlParty::xmlSetupThang(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton) {
    
    
    //-----------
	//the string is printed at the top of the app
	//to give the user some feedback
	messageOne = "loading mySettings.xml";
    string messageTwo;

    _XMLOne.clear();
    _XMLTwo.clear();
    
	//we load our settings file
	//initially we do this from the data/ folder
	//but when we save we are saving to the documents folder which is the only place we have write access to
	//thats why we check if the file exists in the documents folder.
	
	if( _XMLOne.loadFile(iOSDocumentsDirectory + _mathButton.XMLFileOne) ){
		messageOne = _mathButton.XMLFileOne + " loaded from documents folder!";
	}else if( _XMLOne.loadFile(_mathButton.XMLFileOne) ){
		messageOne = _mathButton.XMLFileOne + " loaded from data folder!";
	}else{
		messageOne = "unable to load" + _mathButton.XMLFileOne + " check data/ folder";
	}

    
    if( _XMLTwo.loadFile(iOSDocumentsDirectory + _mathButton.XMLFileTwo) ){
		messageTwo = _mathButton.XMLFileTwo + " loaded from documents folder!";
	}else if( _XMLTwo.loadFile(_mathButton.XMLFileTwo) ){
		messageTwo = _mathButton.XMLFileTwo + " loaded from data folder!";
	}else{
		messageTwo = "unable to load" + _mathButton.XMLFileTwo + " check data/ folder";
	}

//    printf("ran XMLSetupThang \n");
    
}


////////////////////////////////////////////////////////////////////
//      Get XML String                                            //
////////////////////////////////////////////////////////////////////

//from problemMath
//This grabs the text that should be displayed in the 
//------------------------------------------------------------------
string xmlParty::getXMLString(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton) {
    
    
    xmlSetupThang(iOSDocumentsDirectory, _XMLOne, _XMLTwo, _mathButton);
	//Where we grab the data
    
    string theText = _XMLOne.getValue("PROBLEM:STRING", "Nothing", 0);
//    printf("theText %s \n", theText.c_str());
    
    
    return theText;
    
}

//------------------------------------------------------------------
int xmlParty::getXMLStage(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton) {
    
    xmlSetupThang(iOSDocumentsDirectory, _XMLOne, _XMLTwo, _mathButton);
	//Where we grab the data
    
    int theStage = _XMLOne.getValue("STAGE", 0, 0);
    //    printf("theText %s \n", theText.c_str());
        
    return theStage;
    
}

////////////////////////////////////////////////////////////////////
//      Get XML                                                   //
////////////////////////////////////////////////////////////////////

//This takes the data from the XML file
//and loads it into local containers (ex. drawings and flagStates)
//This is currently used by saveMath.cpp
//------------------------------------------------------------------
void xmlParty::getXML(ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, vector <drawing>& _drawThese, vector<flagState>& _theFlagStates, vector <ofPoint>& _scrubFeedback, int& _startTime, int& _endTime, button& _scrubBox) {
    
    
    _drawThese.clear();
    _theFlagStates.clear();
    
    drawing _thisDrawing;
    
	//Where we grab the data
    int numDrawingTags = _XMLOne.getNumTags("DRAWING:TOUCHPOINT");
//    printf("numDrawingTags %d \n", numDrawingTags);

	//if there is at least one <STROKE> tag we can read the list of points
	//and then try and draw it as a line on the screen
	if(numDrawingTags > 0){
        
        for (int i = 0; i < numDrawingTags; i++) {

            _XMLOne.pushTag("DRAWING", i);

            //we see how many points we have stored in <TOUCHPOINT> tags
            int numTouchPointTags = _XMLOne.getNumTags("TOUCHPOINT");
//            printf("numTouchPointTags %d \n", numTouchPointTags);
            
            if(numTouchPointTags > 0){

                for (int h = 0; h < numTouchPointTags; h++) {

                    ofPoint     pos;
                    int         timeStamp;
                    bool        drawMe;
                    ofPoint     whereAreWe;
                    ofColor     color;
                    float       lineWidth;
                    
                    pos.x           = _XMLOne.getValue("TOUCHPOINT:POS:X", 0, h);
                    pos.y           = _XMLOne.getValue("TOUCHPOINT:POS:Y", 0, h);
                    timeStamp       = _XMLOne.getValue("TOUCHPOINT:TIMESTAMP:INT", 0, h);
                    drawMe          = _XMLOne.getValue("TOUCHPOINT:DRAWME:BOOL", 0, h);
                    whereAreWe.x    = _XMLOne.getValue("TOUCHPOINT:WHEREAREWE:X", 0, h);
                    whereAreWe.y    = _XMLOne.getValue("TOUCHPOINT:WHEREAREWE:Y", 0, h);
                    color.r         = _XMLOne.getValue("TOUCHPOINT:COLOR:RED", 0, h);
                    color.g         = _XMLOne.getValue("TOUCHPOINT:COLOR:GREEN", 0, h);
                    color.b         = _XMLOne.getValue("TOUCHPOINT:COLOR:BLUE", 0, h);
                    lineWidth       = _XMLOne.getValue("TOUCHPOINT:LINEWIDTH:FLOAT", 0, h);
                    

                    
//                    printf("drawing pos.x: %f \n", pos.x);
//                    printf("drawing pos.y: %f \n", pos.y);
                    
                    _thisDrawing.update(pos, timeStamp, color, lineWidth, drawMe, whereAreWe);
                }
                
            }
            
            _drawThese.push_back(_thisDrawing);
            _thisDrawing.reset();
            _XMLOne.popTag();
            
        }
    
//        printf("ran GETXML Drawing \n");

        
    }
 
        
    //Where we grab the data
    int numReflectionTags = _XMLTwo.getNumTags("REFLECTIONFLAG:STARTPOS");
//    printf("numReflectionTags %d \n", numReflectionTags);
    
	//if there is at least one <STROKE> tag we can read the list of points
	//and then try and draw it as a line on the screen
	if(numReflectionTags > 0){
        
        for (int i = 0; i < numReflectionTags; i++) {
                        
            flagState theFlagState;
            
            theFlagState.theReflectionFlag.startPos.x          = _XMLTwo.getValue("REFLECTIONFLAG:STARTPOS:X", 0, i);
            theFlagState.theReflectionFlag.startPos.y          = _XMLTwo.getValue("REFLECTIONFLAG:STARTPOS:Y", 0, i);
            theFlagState.theReflectionFlag.endPos.x            = _XMLTwo.getValue("REFLECTIONFLAG:ENDPOS:X", 0, i);
            theFlagState.theReflectionFlag.endPos.y            = _XMLTwo.getValue("REFLECTIONFLAG:ENDPOS:Y", 0, i);
            theFlagState.theReflectionFlag.size.x              = _XMLTwo.getValue("REFLECTIONFLAG:SIZE:X", 0, i);
            theFlagState.theReflectionFlag.size.y              = _XMLTwo.getValue("REFLECTIONFLAG:SIZE:Y", 0, i);
            theFlagState.theReflectionFlag.startTime           = _XMLTwo.getValue("REFLECTIONFLAG:STARTTIME:INT", 0, i);
            theFlagState.theReflectionFlag.endTime             = _XMLTwo.getValue("REFLECTIONFLAG:ENDTIME:INT", 0, i);
            theFlagState.theReflectionFlag.textPos.x           = _XMLTwo.getValue("REFLECTIONFLAG:TEXTPOS:X", 0, i);
            theFlagState.theReflectionFlag.textPos.y           = _XMLTwo.getValue("REFLECTIONFLAG:TEXTPOS:Y", 0, i);
            theFlagState.theReflectionFlag.tabPos.x            = _XMLTwo.getValue("REFLECTIONFLAG:TABPOS:X", 0, i);
            theFlagState.theReflectionFlag.tabPos.y            = _XMLTwo.getValue("REFLECTIONFLAG:TABPOS:Y", 0, i);
            theFlagState.theReflectionFlag.tabSize.x           = _XMLTwo.getValue("REFLECTIONFLAG:TABSIZE:X", 0, i);
            theFlagState.theReflectionFlag.tabSize.y           = _XMLTwo.getValue("REFLECTIONFLAG:TABSIZE:Y", 0, i);
            theFlagState.theReflectionFlag.tabPostPos.x        = _XMLTwo.getValue("REFLECTIONFLAG:TABPOSTPOS:X", 0, i);
            theFlagState.theReflectionFlag.tabPostPos.y        = _XMLTwo.getValue("REFLECTIONFLAG:TABPOSTPOS:Y", 0, i);
            theFlagState.theReflectionFlag.tabPostSize.x       = _XMLTwo.getValue("REFLECTIONFLAG:TABPOSTSIZE:X", 0, i);
            theFlagState.theReflectionFlag.tabPostSize.y       = _XMLTwo.getValue("REFLECTIONFLAG:TABPOSTSIZE:Y", 0, i);
            theFlagState.theReflectionFlag.color.r             = _XMLTwo.getValue("REFLECTIONFLAG:COLOR:RED", 0, i);
            theFlagState.theReflectionFlag.color.g             = _XMLTwo.getValue("REFLECTIONFLAG:COLOR:GREEN", 0, i);
            theFlagState.theReflectionFlag.color.b             = _XMLTwo.getValue("REFLECTIONFLAG:COLOR:BLUE", 0, i);
            theFlagState.theReflectionFlag.presentCheck.x      = _XMLTwo.getValue("REFLECTIONFLAG:PRESENTCHECK:X", 0, i);
            theFlagState.theReflectionFlag.presentCheck.y      = _XMLTwo.getValue("REFLECTIONFLAG:PRESENTCHECK:Y", 0, i);
            theFlagState.theReflectionFlag.presentCheck.width  = _XMLTwo.getValue("REFLECTIONFLAG:PRESENTCHECK:WIDTH", 0, i);
            theFlagState.theReflectionFlag.presentCheck.height = _XMLTwo.getValue("REFLECTIONFLAG:PRESENTCHECK:HEIGHT", 0, i);
            theFlagState.theReflectionFlag.floor               = _XMLTwo.getValue("REFLECTIONFLAG:FLOOR:INT", 0, i);
            theFlagState.theReflectionFlag.ended               = _XMLTwo.getValue("REFLECTIONFLAG:ENDED:BOOL", 0, i);
            theFlagState.theReflectionFlag.selected            = _XMLTwo.getValue("REFLECTIONFLAG:SELECTED:BOOL", 0, i);
            theFlagState.theReflectionFlag.state               = _XMLTwo.getValue("REFLECTIONFLAG:STATE:INT", 0, i);
            theFlagState.theReflectionFlag.stateMessage        = _XMLTwo.getValue("REFLECTIONFLAG:STATEMESSAGE:STRING", "Nothing", i);
            
//            printf("theFlagState startPos.x: %f \n", theFlagState.theReflectionFlag.startPos.x);
//            printf("theFlagState startPos.y: %f \n", theFlagState.theReflectionFlag.startPos.y);

            _theFlagStates.push_back(theFlagState);
            
        }
//        printf("ran GETXML ReflectionFlag \n");
    }


    //draw all the points, etc
    getPoints(_drawThese, _theFlagStates, _scrubFeedback, _startTime, _endTime, _scrubBox);
    
}


////////////////////////////////////////////////////////////////////
//      Get POINTS                                                //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void xmlParty::getPoints(vector <drawing> _drawThese, vector<flagState>& _theFlagStates, vector <ofPoint>& _scrubFeedback, int& _startTime, int& _endTime, button& _scrubBox) {
    
    _scrubFeedback.clear();
    _startTime = 0;
    _endTime = 0;
    
    //_endTime = _drawThese[0].thePoints[0].timeStamp;
    //final elapsed time of final point
    //this sets the scale
    _startTime = _drawThese[0].thePoints[0].timeStamp;
    int drawTheseAmount = _drawThese.size()-2;
    int thePointsAmount = _drawThese[drawTheseAmount].thePoints.size()-1;
    _endTime = _drawThese[drawTheseAmount].thePoints[thePointsAmount].timeStamp;
    
    
//    printf("get points -> state time = %d", _startTime);
//    printf("get points -> end time = %d", _endTime);
    
    
    //this draws the activity line
    ofPoint mapTempPos;
    mapTempPos.y = 10;
    for (int i = 0; i < _drawThese.size(); i++){
        for (int h = 0; h < _drawThese[i].thePoints.size(); h++){
            mapTempPos.x = ofMap(_drawThese[i].thePoints[h].timeStamp, _startTime, _endTime, _scrubBox.pos.x, _scrubBox.pos.x + _scrubBox.thisRectangle.getWidth());
            mapTempPos.y *= -1;
            
            _scrubFeedback.push_back(mapTempPos);
        }
    }
    
    for (int i = 0; i < _scrubFeedback.size(); i++){
        _scrubFeedback[i].y += ofGetHeight()-25;
    }
    
    //-----------------------------------------------
    //update reflection flags if they exist
    float endPosition;
    endPosition = _scrubBox.pos.x + _scrubBox.thisRectangle.getWidth();
    
//    printf("getPoints scrubBox.pos.x= %f \n", _scrubBox.pos.x);
//    printf("getPoints scrumbBox.thisRectengle.getWidth() = %f \n", _scrubBox.thisRectangle.getWidth());
//    printf("getPoints endPosition = %f \n", endPosition);
    
    if (_theFlagStates.size() > 0) {
        
        for (int i = 0; i < _theFlagStates.size(); i++){
            _theFlagStates[i].newStartEndTime(_startTime, _endTime, _scrubBox.pos.x, endPosition);
            _theFlagStates[i].makeMarker();
        }
        
        checkSavedFlags(_theFlagStates);
    }
    
}


////////////////////////////////////////////////////////////////////
//      SET POINTS                                                //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void xmlParty::setPoints(vector <drawing>& _drawTheseIn, vector <drawing>& _drawTheseOut, vector<flagState>& _theFlagStates, vector <ofPoint>& _scrubFeedback, int& _startTime, int& _endTime, button& _scrubBox) {
 
    
    _drawTheseOut.clear();
    _scrubFeedback.clear();
    
    for (int i=0; i < _drawTheseIn.size(); i++) {
        //this is the vector of drawing
        _drawTheseOut.push_back(_drawTheseIn[i]);
    }
    
    _endTime = 0;
//    _endTime = _drawTheseOut[0].thePoints[0].timeStamp;
    //final elapsed time of final point
    _startTime = _drawTheseOut[0].thePoints[0].timeStamp;
    int drawTheseAmount = _drawTheseOut.size()-2;
    int thePointsAmount = _drawTheseOut[drawTheseAmount].thePoints.size()-1;
    _endTime = _drawTheseOut[drawTheseAmount].thePoints[thePointsAmount].timeStamp;
    
    
    ofPoint mapTempPos;
    mapTempPos.y = 10;
    for (int i = 0; i < _drawTheseOut.size(); i++){
        for (int h = 0; h < _drawTheseOut[i].thePoints.size(); h++){
            mapTempPos.x = ofMap(_drawTheseOut[i].thePoints[h].timeStamp, _startTime, _endTime, _scrubBox.pos.x, _scrubBox.pos.x + _scrubBox.thisRectangle.getWidth());
            mapTempPos.y *= -1;
            
            _scrubFeedback.push_back(mapTempPos);
        }
    }
    
    for (int i = 0; i < _scrubFeedback.size(); i++){
        _scrubFeedback[i].y += ofGetHeight()-25;
    }
    
    //-----------------------------------------------
    //update reflection flags if they exist
    
    float endPosition;
    endPosition = _scrubBox.pos.x + _scrubBox.thisRectangle.getWidth();
    
//    printf("set points scrubBox.pos.x= %f \n", _scrubBox.pos.x);
//    printf("set points scrumbBox.thisRectengle.getWidth() = %f \n", _scrubBox.thisRectangle.getWidth());
//    printf("set points endPosition = %f \n", endPosition);


    if (_theFlagStates.size() > 0) {
        
        for (int i = 0; i < _theFlagStates.size(); i++){
            _theFlagStates[i].newStartEndTime(_startTime, _endTime, _scrubBox.pos.x, endPosition);
            _theFlagStates[i].makeMarker();
        }
        
        checkSavedFlags(_theFlagStates);
    }

}



////////////////////////////////////////////////////////////////////
//      Check Saved Flags                                         //
////////////////////////////////////////////////////////////////////

//Used to see if flags need to be repositiond based on updates to content
//when going back to Journey section from Breadcrumbs
//------------------------------------------------------------------
void xmlParty::checkSavedFlags(vector<flagState>& _theFlagStates) {
    
    //-----------------------------------------------
    //first get all the floors that are taken
    
    if (_theFlagStates.size() > 0) {
        
        int         flagCount = 0;
        
        for (int i = 0; i<_theFlagStates.size(); i++) {
            
            bool    floor [100];
            
            for (int j = 0; j<100; j++) {
                floor[j] = false;
            }
            
            bool    chosen = 0;
            int     counter = 0;
            
            
            for (int h = 0; h<flagCount; h++) {
                
                if (i != h) {
                    float dist = _theFlagStates[h].theReflectionFlag.startPos.x - _theFlagStates[i].theReflectionFlag.startPos.x;
                    
                    dist = abs(dist);
                    
                    if (dist < 140) {
                        floor[_theFlagStates[h].theReflectionFlag.floor] = true;
                    }
                }
                
            }
            
            while (chosen == false) {
                //check through each floor.
                //if true, go to next.
                //if false, assign the floor to current flag
                if (floor[counter]==true) {
                    counter++;
                } else {
                    _theFlagStates[i].adjustMarker(counter);
                    chosen = true;
                }
            }
            
            flagCount++;
            
        }
        
    }
}



////////////////////////////////////////////////////////////////////
//      SAVE XML                                                  //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void xmlParty::saveXML(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton, vector <drawing>& _drawThese, vector<flagState>& _theFlagStates, string& theText) {

    _XMLOne.clear();
    _XMLTwo.clear();
    
    ///PART ONE -- CREATE
 
    //adding text
    
    
    lastTagNumberFlagstate     = _XMLOne.addTag("PROBLEM");
    
    
    if( _XMLOne.pushTag("PROBLEM", lastTagNumberFlagstate) ){
        
        int tagNum = _XMLOne.addTag("STRING");
        _XMLOne.setValue("STRING", theText, tagNum);
        
        _XMLOne.popTag();

        tagNum = _XMLOne.addTag("STAGE");
        _XMLOne.setValue("STAGE", _mathButton.stage, tagNum);
        
        _XMLOne.popTag();

    }


    //drawing from create
    for (int i = 0; i < _drawThese.size(); i++) {
        
//        printf("drawThese.size(): %ld \n", drawThese.size());
        
        lastTagNumberDrawing	= _XMLOne.addTag("DRAWING");

        
        if( _XMLOne.pushTag("DRAWING", lastTagNumberDrawing) ){
            
            //now we will add a pt tag - with two
            //children - X and Y
            
            for (int h = 0; h < _drawThese[i].thePoints.size(); h++){

                lastTagNumberTouchPoint	= _XMLOne.addTag("TOUCHPOINT");

                if( _XMLOne.pushTag("TOUCHPOINT", lastTagNumberTouchPoint) ){
                    
                    int tagNum = _XMLOne.addTag("POS");
                    _XMLOne.setValue("POS:X", _drawThese[i].thePoints[h].pos.x, tagNum);
                    _XMLOne.setValue("POS:Y", _drawThese[i].thePoints[h].pos.y, tagNum);

                    tagNum = _XMLOne.addTag("TIMESTAMP");
                    _XMLOne.setValue("TIMESTAMP:INT", _drawThese[i].thePoints[h].timeStamp, tagNum);

                    tagNum = _XMLOne.addTag("DRAWME");
                    _XMLOne.setValue("DRAWME:BOOL", _drawThese[i].thePoints[h].drawMe, tagNum);

                    tagNum = _XMLOne.addTag("WHEREAREWE");
                    _XMLOne.setValue("WHEREAREWE:X", _drawThese[i].thePoints[h].whereAreWe.x, tagNum);
                    _XMLOne.setValue("WHEREAREWE:Y", _drawThese[i].thePoints[h].whereAreWe.y, tagNum);
                                        
                    tagNum = _XMLOne.addTag("COLOR");
                    _XMLOne.setValue("COLOR:RED", _drawThese[i].color.r, tagNum);
                    _XMLOne.setValue("COLOR:GREEN", _drawThese[i].color.g, tagNum);
                    _XMLOne.setValue("COLOR:BLUE", _drawThese[i].color.b, tagNum);
                    _XMLOne.setValue("COLOR:ALPHA", _drawThese[i].color.a, tagNum);

                    tagNum = _XMLOne.addTag("LINEWIDTH");
                    _XMLOne.setValue("LINEWIDTH:FLOAT", _drawThese[i].lineWidth, tagNum);

                    _XMLOne.popTag();

                }
            }
            
            _XMLOne.popTag();

        }
        
    }

    _XMLOne.saveFile( iOSDocumentsDirectory + _mathButton.XMLFileOne );
    _XMLOne.saveFile( iOSDocumentsDirectory + _mathButton.myCreateProbRefresh );
    //        printf(" saved to app documents folder \n ");

    
    for (int i = 0; i < _theFlagStates.size(); i++) {
           
        
        lastTagNumberFlagstate     = _XMLTwo.addTag("REFLECTIONFLAG");
           
           
        if(_XMLTwo.pushTag("REFLECTIONFLAG", lastTagNumberFlagstate) ){
            
            int tagNum = _XMLTwo.addTag("STARTPOS");
            _XMLTwo.setValue("STARTPOS:X", _theFlagStates[i].theReflectionFlag.startPos.x, tagNum);
            _XMLTwo.setValue("STARTPOS:Y", _theFlagStates[i].theReflectionFlag.startPos.y, tagNum);

            tagNum = _XMLTwo.addTag("ENDPOS");
            _XMLTwo.setValue("ENDPOS:X", _theFlagStates[i].theReflectionFlag.endPos.x, tagNum);
            _XMLTwo.setValue("ENDPOS:Y", _theFlagStates[i].theReflectionFlag.endPos.y, tagNum);

            tagNum = _XMLTwo.addTag("SIZE");
            _XMLTwo.setValue("SIZE:X", _theFlagStates[i].theReflectionFlag.size.x, tagNum);
            _XMLTwo.setValue("SIZE:Y", _theFlagStates[i].theReflectionFlag.size.y, tagNum);
            
            tagNum = _XMLTwo.addTag("STARTTIME");
            _XMLTwo.setValue("STARTTIME:INT", _theFlagStates[i].theReflectionFlag.startTime, tagNum);
            tagNum = _XMLTwo.addTag("ENDTIME");
            _XMLTwo.setValue("ENDTIME:INT", _theFlagStates[i].theReflectionFlag.endTime, tagNum);

            tagNum = _XMLTwo.addTag("TEXTPOS");
            _XMLTwo.setValue("TEXTPOS:X", _theFlagStates[i].theReflectionFlag.textPos.x, tagNum);
            _XMLTwo.setValue("TEXTPOS:Y", _theFlagStates[i].theReflectionFlag.textPos.y, tagNum);
            
            tagNum = _XMLTwo.addTag("TABPOS");
            _XMLTwo.setValue("TABPOS:X", _theFlagStates[i].theReflectionFlag.tabPos.x, tagNum);
            _XMLTwo.setValue("TABPOS:Y", _theFlagStates[i].theReflectionFlag.tabPos.y, tagNum);
            
            tagNum = _XMLTwo.addTag("TABSIZE");
            _XMLTwo.setValue("TABSIZE:X", _theFlagStates[i].theReflectionFlag.tabSize.x, tagNum);
            _XMLTwo.setValue("TABSIZE:Y", _theFlagStates[i].theReflectionFlag.tabSize.y, tagNum);
            
            tagNum = _XMLTwo.addTag("TABPOSTPOS");
            _XMLTwo.setValue("TABPOSTPOS:X", _theFlagStates[i].theReflectionFlag.tabPostPos.x, tagNum);
            _XMLTwo.setValue("TABPOSTPOS:Y", _theFlagStates[i].theReflectionFlag.tabPostPos.y, tagNum);
            
            tagNum = _XMLTwo.addTag("TABPOSTSIZE");
            _XMLTwo.setValue("TABPOSTSIZE:X", _theFlagStates[i].theReflectionFlag.tabPostSize.x, tagNum);
            _XMLTwo.setValue("TABPOSTSIZE:Y", _theFlagStates[i].theReflectionFlag.tabPostSize.y, tagNum);

            tagNum = _XMLTwo.addTag("TABPOSTSIZE");
            _XMLTwo.setValue("TABPOSTSIZE:X", _theFlagStates[i].theReflectionFlag.tabPostSize.x, tagNum);
            _XMLTwo.setValue("TABPOSTSIZE:Y", _theFlagStates[i].theReflectionFlag.tabPostSize.y, tagNum);
            
            tagNum = _XMLTwo.addTag("COLOR");
            _XMLTwo.setValue("COLOR:RED", _theFlagStates[i].theReflectionFlag.color.r, tagNum);
            _XMLTwo.setValue("COLOR:GREEN", _theFlagStates[i].theReflectionFlag.color.g, tagNum);
            _XMLTwo.setValue("COLOR:BLUE", _theFlagStates[i].theReflectionFlag.color.b, tagNum);
            _XMLTwo.setValue("COLOR:ALPHA", _theFlagStates[i].theReflectionFlag.color.a, tagNum);
            
            tagNum = _XMLTwo.addTag("PRESENTCHECK");
            _XMLTwo.setValue("PRESENTCHECK:X", _theFlagStates[i].theReflectionFlag.presentCheck.x, tagNum);
            _XMLTwo.setValue("PRESENTCHECK:Y", _theFlagStates[i].theReflectionFlag.presentCheck.y, tagNum);
            _XMLTwo.setValue("PRESENTCHECK:WIDTH", _theFlagStates[i].theReflectionFlag.presentCheck.width, tagNum);
            _XMLTwo.setValue("PRESENTCHECK:HEIGHT", _theFlagStates[i].theReflectionFlag.presentCheck.height, tagNum);

            tagNum = _XMLTwo.addTag("FLOOR");
            _XMLTwo.setValue("FLOOR:INT", _theFlagStates[i].theReflectionFlag.floor, tagNum);

            tagNum = _XMLTwo.addTag("ENDED");
            _XMLTwo.setValue("ENDED:BOOL", _theFlagStates[i].theReflectionFlag.ended, tagNum);

            tagNum = _XMLTwo.addTag("SELECTED");
            _XMLTwo.setValue("SELECTED:BOOL", _theFlagStates[i].theReflectionFlag.selected, tagNum);

            tagNum = _XMLTwo.addTag("STATE");
            _XMLTwo.setValue("STATE:INT", _theFlagStates[i].theReflectionFlag.state, tagNum);

            tagNum = _XMLTwo.addTag("STATEMESSAGE");
            _XMLTwo.setValue("STATEMESSAGE:STRING", _theFlagStates[i].theReflectionFlag.stateMessage, tagNum);

            _XMLTwo.popTag();

            }
           
        }
           
        _XMLTwo.saveFile( iOSDocumentsDirectory + _mathButton.XMLFileTwo );
        _XMLTwo.saveFile( iOSDocumentsDirectory + _mathButton.myReflectProbRefresh );
    //        printf(" saved to app documents folder \n ");
                  
}






////////////////////////////////////////////////////////////////////
//      SAVE XML TEXT                                             //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void xmlParty::saveXMLText(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton) {
    
    
    _XMLOne.clear();
    _XMLTwo.clear();
    
    
    int lastTag     = _XMLOne.addTag("PROBLEM");
    
    
    if( _XMLOne.pushTag("PROBLEM", lastTag) ){
        
        int tagNum = _XMLTwo.addTag("STRING");
        _XMLOne.setValue("STRING", _mathButton.problemText, tagNum);
        
        _XMLOne.popTag();
//        printf(" did it \n");
        
    } else {
//        printf(" didn't do it");
    }
    
    
//    int lastTagNumberDrawing	= _XMLOne.addTag("DRAWING");
//    
//    
//    if( _XMLOne.pushTag("DRAWING", lastTagNumberDrawing) ){
//        
//        int lastTagNumberTouchPoint	= _XMLOne.addTag("TOUCHPOINT");
//        
//        if( _XMLOne.pushTag("TOUCHPOINT", lastTagNumberTouchPoint) ){
//            
//            int tagNum = _XMLOne.addTag("POS");
//            _XMLOne.setValue("POS:X", 389, tagNum);
//            _XMLOne.setValue("POS:Y", 389, tagNum);
//            
//            tagNum = _XMLOne.addTag("TIMESTAMP");
//            _XMLOne.setValue("TIMESTAMP:INT", 389, tagNum);
//            
//            tagNum = _XMLOne.addTag("DRAWME");
//            _XMLOne.setValue("DRAWME:BOOL", true, tagNum);
//            
//            tagNum = _XMLOne.addTag("WHEREAREWE");
//            _XMLOne.setValue("WHEREAREWE:X", 389, tagNum);
//            _XMLOne.setValue("WHEREAREWE:Y", 389, tagNum);
//            
//            tagNum = _XMLOne.addTag("COLOR");
//            _XMLOne.setValue("COLOR:RED", 0.0, tagNum);
//            _XMLOne.setValue("COLOR:GREEN", 0.0, tagNum);
//            _XMLOne.setValue("COLOR:BLUE", 0.0, tagNum);
//            _XMLOne.setValue("COLOR:ALPHA", 0.0, tagNum);
//            
//            tagNum = _XMLOne.addTag("LINEWIDTH");
//            _XMLOne.setValue("LINEWIDTH:FLOAT", 1.0, tagNum);
//            
//            _XMLOne.popTag();
//            
//        }
//        
//        _XMLOne.popTag();
//        
//    }
    
    _XMLOne.saveFile( iOSDocumentsDirectory + _mathButton.XMLFileOne );
    _XMLOne.saveFile( iOSDocumentsDirectory + _mathButton.myCreateProbRefresh );
    //        printf(" saved to app documents folder \n ");
    
    
//    int lastTagNumberFlagstate     = _XMLTwo.addTag("REFLECTIONFLAG");
//    
//    
//    if( _XMLTwo.pushTag("REFLECTIONFLAG", lastTagNumberFlagstate) ){
//        
//        int tagNum = _XMLTwo.addTag("STARTPOS");
//        _XMLTwo.setValue("STARTPOS:X", 389, tagNum);
//        _XMLTwo.setValue("STARTPOS:Y", 389, tagNum);
//        
//        tagNum = _XMLTwo.addTag("ENDPOS");
//        _XMLTwo.setValue("ENDPOS:X", 389, tagNum);
//        _XMLTwo.setValue("ENDPOS:Y", 389, tagNum);
//        
//        tagNum = _XMLTwo.addTag("SIZE");
//        _XMLTwo.setValue("SIZE:X", 1.0, tagNum);
//        _XMLTwo.setValue("SIZE:Y", 1.0, tagNum);
//        
//        tagNum = _XMLTwo.addTag("STARTTIME");
//        _XMLTwo.setValue("STARTTIME:INT", 0, tagNum);
//        tagNum = _XMLTwo.addTag("ENDTIME");
//        _XMLTwo.setValue("ENDTIME:INT", 0, tagNum);
//        
//        tagNum = _XMLTwo.addTag("TEXTPOS");
//        _XMLTwo.setValue("TEXTPOS:X", 389, tagNum);
//        _XMLTwo.setValue("TEXTPOS:Y", 389, tagNum);
//        
//        tagNum = _XMLTwo.addTag("TABPOS");
//        _XMLTwo.setValue("TABPOS:X", 389, tagNum);
//        _XMLTwo.setValue("TABPOS:Y", 389, tagNum);
//        
//        tagNum = _XMLTwo.addTag("TABSIZE");
//        _XMLTwo.setValue("TABSIZE:X", 389, tagNum);
//        _XMLTwo.setValue("TABSIZE:Y", 389, tagNum);
//        
//        tagNum = _XMLTwo.addTag("TABPOSTPOS");
//        _XMLTwo.setValue("TABPOSTPOS:X", 389, tagNum);
//        _XMLTwo.setValue("TABPOSTPOS:Y", 389, tagNum);
//        
//        tagNum = _XMLTwo.addTag("TABPOSTSIZE");
//        _XMLTwo.setValue("TABPOSTSIZE:X", 389, tagNum);
//        _XMLTwo.setValue("TABPOSTSIZE:Y", 389, tagNum);
//        
//        tagNum = _XMLTwo.addTag("TABPOSTSIZE");
//        _XMLTwo.setValue("TABPOSTSIZE:X", 389, tagNum);
//        _XMLTwo.setValue("TABPOSTSIZE:Y", 389, tagNum);
//        
//        tagNum = _XMLTwo.addTag("COLOR");
//        _XMLTwo.setValue("COLOR:RED", 255, tagNum);
//        _XMLTwo.setValue("COLOR:GREEN", 255, tagNum);
//        _XMLTwo.setValue("COLOR:BLUE", 255, tagNum);
//        _XMLTwo.setValue("COLOR:ALPHA", 255, tagNum);
//        
//        tagNum = _XMLTwo.addTag("PRESENTCHECK");
//        _XMLTwo.setValue("PRESENTCHECK:X", 20.0, tagNum);
//        _XMLTwo.setValue("PRESENTCHECK:Y", 20.0, tagNum);
//        _XMLTwo.setValue("PRESENTCHECK:WIDTH", 20.0, tagNum);
//        _XMLTwo.setValue("PRESENTCHECK:HEIGHT", 20.0, tagNum);
//        
//        tagNum = _XMLTwo.addTag("FLOOR");
//        _XMLTwo.setValue("FLOOR:INT", 0, tagNum);
//        
//        tagNum = _XMLTwo.addTag("ENDED");
//        _XMLTwo.setValue("ENDED:BOOL", 0, tagNum);
//        
//        tagNum = _XMLTwo.addTag("SELECTED");
//        _XMLTwo.setValue("SELECTED:BOOL", 0, tagNum);
//        
//        tagNum = _XMLTwo.addTag("STATE");
//        _XMLTwo.setValue("STATE:INT", 0, tagNum);
//        
//        tagNum = _XMLTwo.addTag("STATEMESSAGE");
//        _XMLTwo.setValue("STATEMESSAGE:STRING", 0, tagNum);
//        
//        _XMLTwo.popTag();
//        
//    }

    
    _XMLTwo.saveFile( iOSDocumentsDirectory + _mathButton.XMLFileTwo );
    _XMLTwo.saveFile( iOSDocumentsDirectory + _mathButton.myReflectProbRefresh );
    
}



////////////////////////////////////////////////////////////////////
//      SET FILE NAME                                             //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void xmlParty::setFileNameSave(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton, vector <drawing>& _drawThese, vector<flagState>& _theFlagStates, string& theText) {
    
    
    //    welcomeButton.thisString = "welcome "+_setUserName+"!";
    //float stringSize = welcomeButton.thisString.size();
    
    //    welcomeButton.offSet.set(415, 35);
    
    
    //ASSIGN ALL THE BUTTON INFO HERE
    
    
    _mathButton.XMLFileOne = ofToString(ofGetSystemTime()) + "_" + _mathButton.myCreateProbRefresh;
    _mathButton.XMLFileTwo = ofToString(ofGetSystemTime()) + "_" + _mathButton.myReflectProbRefresh;
    xmlSetupThang(iOSDocumentsDirectory, _XMLOne, _XMLTwo, _mathButton);
    saveXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, _mathButton, _drawThese, _theFlagStates, theText);

//    mathTwoButton.XMLFileOne = ofToString(ofGetSystemTime()) + "_myCreateProbTwo.xml";
//    mathTwoButton.XMLFileTwo = ofToString(ofGetSystemTime()) + "_myReflectProbTwo.xml";
//    xmlSetupThang(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathTwoButton.XMLFileOne, mathTwoButton.XMLFileTwo);
//    saveXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathTwoButton.XMLFileOne, mathTwoButton.XMLFileTwo, mathTwoButton.problemText);
//    
//    mathThreeButton.XMLFileOne = ofToString(ofGetSystemTime()) + "_myCreateProbThree.xml";
//    mathThreeButton.XMLFileTwo = ofToString(ofGetSystemTime()) + "_myReflectProbThree.xml";
//    xmlSetupThang(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathThreeButton.XMLFileOne, mathThreeButton.XMLFileTwo);
//    saveXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathThreeButton.XMLFileOne, mathThreeButton.XMLFileTwo, mathThreeButton.problemText);
//    
//    mathFourButton.XMLFileOne = ofToString(ofGetSystemTime()) + "_myCreateProbFour.xml";
//    mathFourButton.XMLFileTwo = ofToString(ofGetSystemTime()) + "_myReflectProbFour.xml";
//    xmlSetupThang(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFourButton.XMLFileOne, mathFourButton.XMLFileTwo);
//    saveXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFourButton.XMLFileOne, mathFourButton.XMLFileTwo, mathFourButton.problemText);
//    
//    mathFiveButton.XMLFileOne = ofToString(ofGetSystemTime()) + "_myCreateProbFive.xml";
//    mathFiveButton.XMLFileTwo = ofToString(ofGetSystemTime()) + "_myReflectProbFive.xml";
//    xmlSetupThang(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFiveButton.XMLFileOne, mathFiveButton.XMLFileTwo);
//    saveXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFiveButton.XMLFileOne, mathFiveButton.XMLFileTwo, mathFiveButton.problemText);
//    
//    mathSixButton.XMLFileOne = ofToString(ofGetSystemTime()) + "_myCreateProbSix.xml";
//    mathSixButton.XMLFileTwo = ofToString(ofGetSystemTime()) + "_myReflectProbSix.xml";
//    xmlSetupThang(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathSixButton.XMLFileOne, mathSixButton.XMLFileTwo);
//    saveXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathSixButton.XMLFileOne, mathSixButton.XMLFileTwo, mathSixButton.problemText);
//    
    
    
}


////////////////////////////////////////////////////////////////////
//      REST XML                                                  //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void xmlParty::resetXML(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, button& _mathButton, button& resetMathButton) {
    
    xmlSetupThang(iOSDocumentsDirectory, _XMLOne, _XMLTwo, _mathButton);
    saveXMLText(iOSDocumentsDirectory, _XMLOne, _XMLTwo, _mathButton);
    
    _mathButton.stage = 0;
    resetMathButton.toggle = false;
    
}

