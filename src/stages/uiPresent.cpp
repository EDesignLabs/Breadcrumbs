/*
 *  uiPresent.cpp
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#include "uiPresent.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiPresent::~uiPresent() {
    
    //uiPresent elements
    delete scrubBox;
    delete scrubLocation;
    delete currentPos;
    
    delete markerButtonSelected;
    delete playPauseButton;
    delete markerButton;
    
}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiPresent::uiPresent() {
    
    //set initial values for state
    
    scrubBox = new button;
    currentPos = new button;
    
    //set initial values for state
    markerButtonSelected = new bool;
    *markerButtonSelected = false;

    
    ofPoint pos;
    ofPoint size;
    ofColor color;
    
    float scrubHeight;
    scrubHeight = 50;
    
    
    //main scrub box
    pos.set(100, ofGetHeight()-scrubHeight);
    size.set(ofGetWidth()-pos.x, scrubHeight);
    color.set(170, 170, 170);
    scrubBox->setup(pos, size, color);
    
    
    //position indicator
    size.set(10, scrubHeight);
    color.set(0, 0, 170);
    currentPos->setup(pos, size, color);
    
    scrubLocation = new ofPoint;
    scrubLocation->set(pos);
    scrubPos.set(0, 0);
    
    
    //playback and flag
    playPauseButton = new button;
    markerButton = new button;
    
    color.set(170, 170, 170);
    
    ofPoint offSet;
    offSet.set(17, 15);
    ofImage play;
    play.loadImage("images/ui/glyphicons_173_play.png");
    ofImage pause;
    pause.loadImage("images/ui/glyphicons_174_pause.png");
    ofImage marker;
    marker.loadImage("images/ui/glyphicons_234_brush.png");
    
    pos.set(0, ofGetHeight()-scrubHeight);
    size.set(50, 50);
    playPauseButton->setup(pos, size, color, pause, play, offSet);
    
    offSet.set(16, 12);
    pos.set(50, ofGetHeight()-scrubHeight);
    markerButton->setup(pos, size, color, marker, offSet);
    
}


////////////////////////////////////////////////////////////////////
//      SET POINTS                                                //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::setPoints(vector <drawing> theDrawings, vector<flagState> theFlagStates) {

    this->theFlagStates = theFlagStates;

    drawThese.clear();
    scrubFeedback.clear();
    
    for (int i=0; i < theDrawings.size(); i++) {
        //this is the vector of drawing
        drawThese.push_back(theDrawings[i]);
    }
    
    endTime = 0;
    endTime = drawThese[0].thePoints[0].timeStamp;
    //final elapsed time of final point
    startTime = drawThese[0].thePoints[0].timeStamp;
    int drawTheseAmount = drawThese.size()-1;
    int thePointsAmount = drawThese[drawTheseAmount].thePoints.size()-1;
    endTime = drawThese[drawTheseAmount].thePoints[thePointsAmount].timeStamp;
    
    
    ofPoint mapTempPos;
    mapTempPos.y = 10;
    for (int i = 0; i < theDrawings.size(); i++){
        for (int h = 0; h < drawThese[i].thePoints.size(); h++){
            mapTempPos.x = ofMap(drawThese[i].thePoints[h].timeStamp, startTime, endTime, 100, ofGetWidth());
            mapTempPos.y *= -1;
            
            scrubFeedback.push_back(mapTempPos);
        }
    }
    
    for (int i = 0; i < scrubFeedback.size(); i++){
        scrubFeedback[i].y += ofGetHeight()-25;
    }
    
//    printf(" endTime is: %d \n", endTime);
//    printf(" scrubfeedback[0].x is: %f \n", scrubFeedback[0].x);
//    printf(" scrubfeedback[0].y is: %f \n", scrubFeedback[0].y);

}


////////////////////////////////////////////////////////////////////
//      PLAY DATA                                                 //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::playData() {
    
    if (playPauseButton->toggle && drawThese.size() > 0) {
        
        int diff;
        currentTime = ofGetElapsedTimeMillis();
        diff =  currentTime - previousTime;
        
        //        printf(" diff is: %d \n", diff);
        
        //this advances the drawing
        if (scrubPos.x <= endTime) {
            scrubPos.x += diff;
        } else {
            scrubPos.x = startTime;
        }
        
        //        printf(" scrubPos is: %f \n", scrubPos.x);
        
        //this advances the currentPos scrubBox indicator
        scrubLocation->x = ofMap(scrubPos.x, startTime, endTime, 100, ofGetWidth());
        
        //        printf(" scrubLocation.x is: %f \n", scrubLocation->x);
        
        currentPos->update(scrubLocation->x);
        
        previousTime = ofGetElapsedTimeMillis();
        
    } else {
        
        currentTime = previousTime = ofGetElapsedTimeMillis();
        scrubPos.x = ofMap(scrubLocation->x, 100, ofGetWidth(), startTime, endTime);
        
    }
    
}


////////////////////////////////////////////////////////////////////
//      XML Setup Thang                                           //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::xmlSetupThang(string iPhoneDocumentsDirectory, string xmlFileOne, string xmlFileTwo) {
    
    
    //-----------
	//the string is printed at the top of the app
	//to give the user some feedback
	messageOne = "loading mySettings.xml";
    
	//we load our settings file
	//initially we do this from the data/ folder
	//but when we save we are saving to the documents folder which is the only place we have write access to
	//thats why we check if the file exists in the documents folder.
	
	if( XMLOne.loadFile(iPhoneDocumentsDirectory + xmlFileOne) ){
		messageOne = xmlFileOne + " loaded from documents folder!";
	}else if( XMLOne.loadFile(xmlFileOne) ){
		messageOne = xmlFileOne + " loaded from data folder!";
	}else{
		messageOne = "unable to load" + xmlFileOne + " check data/ folder";
	}

    
    if( XMLTwo.loadFile(iPhoneDocumentsDirectory + xmlFileTwo) ){
		messageTwo = xmlFileTwo + " loaded from documents folder!";
	}else if( XMLTwo.loadFile(xmlFileTwo) ){
		messageTwo = xmlFileTwo + " loaded from data folder!";
	}else{
		messageTwo = "unable to load" + xmlFileTwo + " check data/ folder";
	}

    
    //read the colors from XML
	//if the settings file doesn't exist we assigns default values (170, 190, 240)
	int red		= XMLOne.getValue("DRAWING:TOUCHPOINT:COLOR:RED", 255);
	int green	= XMLOne.getValue("DRAWING:TOUCHPOINT:COLOR:GREEN", 255);
	int blue	= XMLOne.getValue("DRAWING:TOUCHPOINT:COLOR:BLUE", 255);

//    printf("XMLOne Red: %d \n", red);
//    printf("XMLOne Green: %d \n", green);
//    printf("XMLOne Blue: %d \n", blue);

    red		= XMLTwo.getValue("REFLECTIONFLAG:COLOR:RED", 20);
	green	= XMLTwo.getValue("REFLECTIONFLAG:COLOR:GREEN", 20);
	blue	= XMLTwo.getValue("REFLECTIONFLAG:COLOR:BLUE", 20);
    
//    printf("XMLTwo Red: %d \n", red);
//    printf("XMLTwo Green: %d \n", green);
//    printf("XMLTwo Blue: %d \n", blue);

//    printf("ran XMLSetupThang \n");
    
}

////////////////////////////////////////////////////////////////////
//      Grab XML                                                  //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::getXML(string XMLFileOne, string XMLFileTwo) {
    
	//Where we grab the data
    int numDrawingTags = XMLOne.getNumTags("DRAWING:TOUCHPOINT");
    printf("numDrawingTags %d \n", numDrawingTags);

	//if there is at least one <STROKE> tag we can read the list of points
	//and then try and draw it as a line on the screen
	if(numDrawingTags > 0){
        
        for (int i = 0; i < numDrawingTags; i++) {

            XMLOne.pushTag("DRAWING", i);

            //we see how many points we have stored in <TOUCHPOINT> tags
            int numTouchPointTags = XMLOne.getNumTags("TOUCHPOINT");
//            printf("numTouchPointTags %d \n", numTouchPointTags);
            
            if(numTouchPointTags > 0){

                for (int h = 0; h < numTouchPointTags; h++) {

                    ofPoint     pos;
                    int         timeStamp;
                    ofColor     color;
                    float       lineWidth;
                    
                    pos.x       = XMLOne.getValue("TOUCHPOINT:POS:X", 0, h);
                    pos.y       = XMLOne.getValue("TOUCHPOINT:POS:Y", 0, h);
                    timeStamp   = XMLOne.getValue("TOUCHPOINT:TIMESTAMP:INT", 0, h);
                    color.r     = XMLOne.getValue("TOUCHPOINT:COLOR:RED", 0, h);
                    color.g     = XMLOne.getValue("TOUCHPOINT:COLOR:GREEN", 0, h);
                    color.b     = XMLOne.getValue("TOUCHPOINT:COLOR:BLUE", 0, h);
                    lineWidth   = XMLOne.getValue("TOUCHPOINT:LINEWIDTH:FLOAT", 0, h);
                    
//                    printf("drawing pos.x: %f \n", pos.x);
//                    printf("drawing pos.y: %f \n", pos.y);
                    
                    thisDrawing.update(pos, timeStamp, color, lineWidth);

                }
                
            }
            
            drawThese.push_back(thisDrawing);
            thisDrawing.reset();
            XMLOne.popTag();
            
        }
    
//        printf("ran GETXML Drawing \n");

        
    }
 
        
    //Where we grab the data
    int numReflectionTags = XMLTwo.getNumTags("REFLECTIONFLAG:STARTPOS");
//    printf("numReflectionTags %d \n", numReflectionTags);
    
	//if there is at least one <STROKE> tag we can read the list of points
	//and then try and draw it as a line on the screen
	if(numReflectionTags > 0){
        
        for (int i = 0; i < numReflectionTags; i++) {
                        
            flagState theFlagState;
            
            theFlagState.theReflectionFlag.startPos.x          = XMLTwo.getValue("REFLECTIONFLAG:STARTPOS:X", 0, i);
            theFlagState.theReflectionFlag.startPos.y          = XMLTwo.getValue("REFLECTIONFLAG:STARTPOS:Y", 0, i);
            theFlagState.theReflectionFlag.endPos.x            = XMLTwo.getValue("REFLECTIONFLAG:ENDPOS:X", 0, i);
            theFlagState.theReflectionFlag.endPos.y            = XMLTwo.getValue("REFLECTIONFLAG:ENDPOS:Y", 0, i);
            theFlagState.theReflectionFlag.size.x              = XMLTwo.getValue("REFLECTIONFLAG:SIZE:X", 0, i);
            theFlagState.theReflectionFlag.size.y              = XMLTwo.getValue("REFLECTIONFLAG:SIZE:Y", 0, i);
            theFlagState.theReflectionFlag.textPos.x           = XMLTwo.getValue("REFLECTIONFLAG:TEXTPOS:X", 0, i);
            theFlagState.theReflectionFlag.textPos.y           = XMLTwo.getValue("REFLECTIONFLAG:TEXTPOS:Y", 0, i);
            theFlagState.theReflectionFlag.tabPos.x            = XMLTwo.getValue("REFLECTIONFLAG:TABPOS:X", 0, i);
            theFlagState.theReflectionFlag.tabPos.y            = XMLTwo.getValue("REFLECTIONFLAG:TABPOS:Y", 0, i);
            theFlagState.theReflectionFlag.tabSize.x           = XMLTwo.getValue("REFLECTIONFLAG:TABSIZE:X", 0, i);
            theFlagState.theReflectionFlag.tabSize.y           = XMLTwo.getValue("REFLECTIONFLAG:TABSIZE:Y", 0, i);
            theFlagState.theReflectionFlag.tabPostPos.x        = XMLTwo.getValue("REFLECTIONFLAG:TABPOSTPOS:X", 0, i);
            theFlagState.theReflectionFlag.tabPostPos.y        = XMLTwo.getValue("REFLECTIONFLAG:TABPOSTPOS:Y", 0, i);
            theFlagState.theReflectionFlag.tabPostSize.x       = XMLTwo.getValue("REFLECTIONFLAG:TABPOSTSIZE:X", 0, i);
            theFlagState.theReflectionFlag.tabPostSize.y       = XMLTwo.getValue("REFLECTIONFLAG:TABPOSTSIZE:Y", 0, i);
            theFlagState.theReflectionFlag.color.r             = XMLTwo.getValue("REFLECTIONFLAG:COLOR:RED", 0, i);
            theFlagState.theReflectionFlag.color.g             = XMLTwo.getValue("REFLECTIONFLAG:COLOR:GREEN", 0, i);
            theFlagState.theReflectionFlag.color.b             = XMLTwo.getValue("REFLECTIONFLAG:COLOR:BLUE", 0, i);
            theFlagState.theReflectionFlag.presentCheck.x      = XMLTwo.getValue("REFLECTIONFLAG:PRESENTCHECK:X", 0, i);
            theFlagState.theReflectionFlag.presentCheck.y      = XMLTwo.getValue("REFLECTIONFLAG:PRESENTCHECK:Y", 0, i);
            theFlagState.theReflectionFlag.presentCheck.width  = XMLTwo.getValue("REFLECTIONFLAG:PRESENTCHECK:WIDTH", 0, i);
            theFlagState.theReflectionFlag.presentCheck.height = XMLTwo.getValue("REFLECTIONFLAG:PRESENTCHECK:HEIGHT", 0, i);
            theFlagState.theReflectionFlag.floor               = XMLTwo.getValue("REFLECTIONFLAG:FLOOR:INT", 0, i);
            theFlagState.theReflectionFlag.ended               = XMLTwo.getValue("REFLECTIONFLAG:ENDED:BOOL", 0, i);
            theFlagState.theReflectionFlag.selected            = XMLTwo.getValue("REFLECTIONFLAG:SELECTED:BOOL", 0, i);
            theFlagState.theReflectionFlag.state               = XMLTwo.getValue("REFLECTIONFLAG:STATE:INT", 0, i);
            theFlagState.theReflectionFlag.stateMessage        = XMLTwo.getValue("REFLECTIONFLAG:STATEMESSAGE:STRING", "Nothing", i);
            
//            printf("theFlagState startPos.x: %f \n", theFlagState.theReflectionFlag.startPos.x);
//            printf("theFlagState startPos.y: %f \n", theFlagState.theReflectionFlag.startPos.y);

            theFlagStates.push_back(theFlagState);
            
        }
//        printf("ran GETXML ReflectionFlag \n");
    }


    //draw all the points, etc
    setPoints(drawThese, theFlagStates);
    
}

////////////////////////////////////////////////////////////////////
//      SAVE XML                                                  //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::saveXML(string iPhoneDocumentsDirectory, string xmlFileOne, string xmlFileTwo) {

    XMLOne.clear();
    XMLTwo.clear();
    
    ///PART ONE -- CREATE
 
    //drawing from create
    for (int i = 0; i < drawThese.size(); i++) {
        
        lastTagNumberDrawing	= XMLOne.addTag("DRAWING");

        
        if( XMLOne.pushTag("DRAWING", lastTagNumberDrawing) ){
            
            //now we will add a pt tag - with two
            //children - X and Y
            
            for (int h = 0; h < drawThese[i].thePoints.size(); h++){

                lastTagNumberTouchPoint	= XMLOne.addTag("TOUCHPOINT");

                if( XMLOne.pushTag("TOUCHPOINT", lastTagNumberTouchPoint) ){
                    
                    int tagNum = XMLOne.addTag("POS");
                    XMLOne.setValue("POS:X", drawThese[i].thePoints[h].pos.x, tagNum);
                    XMLOne.setValue("POS:Y", drawThese[i].thePoints[h].pos.y, tagNum);

                    tagNum = XMLOne.addTag("TIMESTAMP");
                    XMLOne.setValue("TIMESTAMP:INT", drawThese[i].thePoints[h].timeStamp, tagNum);

                    tagNum = XMLOne.addTag("COLOR");
                    XMLOne.setValue("COLOR:RED", drawThese[i].color.r, tagNum);
                    XMLOne.setValue("COLOR:GREEN", drawThese[i].color.g, tagNum);
                    XMLOne.setValue("COLOR:BLUE", drawThese[i].color.b, tagNum);
                    XMLOne.setValue("COLOR:ALPHA", drawThese[i].color.a, tagNum);

                    tagNum = XMLOne.addTag("LINEWIDTH");
                    XMLOne.setValue("LINEWIDTH:FLOAT", drawThese[i].lineWidth, tagNum);

                    XMLOne.popTag();

                }
            }
            
            XMLOne.popTag();

        }

        XMLOne.saveFile( iPhoneDocumentsDirectory + xmlFileOne );
//        printf(" saved to app documents folder \n ");
        
    }

    
    for (int i = 0; i < theFlagStates.size(); i++) {
           
           
        lastTagNumberFlagstate     = XMLTwo.addTag("REFLECTIONFLAG");
           
           
        if( XMLTwo.pushTag("REFLECTIONFLAG", lastTagNumberFlagstate) ){
               
            int tagNum = XMLTwo.addTag("STARTPOS");
            XMLTwo.setValue("STARTPOS:X", theFlagStates[i].theReflectionFlag.startPos.x, tagNum);
            XMLTwo.setValue("STARTPOS:Y", theFlagStates[i].theReflectionFlag.startPos.y, tagNum);

            tagNum = XMLTwo.addTag("ENDPOS");
            XMLTwo.setValue("ENDPOS:X", theFlagStates[i].theReflectionFlag.endPos.x, tagNum);
            XMLTwo.setValue("ENDPOS:Y", theFlagStates[i].theReflectionFlag.endPos.y, tagNum);

            tagNum = XMLTwo.addTag("SIZE");
            XMLTwo.setValue("SIZE:X", theFlagStates[i].theReflectionFlag.size.x, tagNum);
            XMLTwo.setValue("SIZE:Y", theFlagStates[i].theReflectionFlag.size.y, tagNum);

            tagNum = XMLTwo.addTag("TEXTPOS");
            XMLTwo.setValue("TEXTPOS:X", theFlagStates[i].theReflectionFlag.textPos.x, tagNum);
            XMLTwo.setValue("TEXTPOS:Y", theFlagStates[i].theReflectionFlag.textPos.y, tagNum);
            
            tagNum = XMLTwo.addTag("TABPOS");
            XMLTwo.setValue("TABPOS:X", theFlagStates[i].theReflectionFlag.tabPos.x, tagNum);
            XMLTwo.setValue("TABPOS:Y", theFlagStates[i].theReflectionFlag.tabPos.y, tagNum);
            
            tagNum = XMLTwo.addTag("TABSIZE");
            XMLTwo.setValue("TABSIZE:X", theFlagStates[i].theReflectionFlag.tabSize.x, tagNum);
            XMLTwo.setValue("TABSIZE:Y", theFlagStates[i].theReflectionFlag.tabSize.y, tagNum);
            
            tagNum = XMLTwo.addTag("TABPOSTPOS");
            XMLTwo.setValue("TABPOSTPOS:X", theFlagStates[i].theReflectionFlag.tabPostPos.x, tagNum);
            XMLTwo.setValue("TABPOSTPOS:Y", theFlagStates[i].theReflectionFlag.tabPostPos.y, tagNum);
            
            tagNum = XMLTwo.addTag("TABPOSTSIZE");
            XMLTwo.setValue("TABPOSTSIZE:X", theFlagStates[i].theReflectionFlag.tabPostSize.x, tagNum);
            XMLTwo.setValue("TABPOSTSIZE:Y", theFlagStates[i].theReflectionFlag.tabPostSize.y, tagNum);

            tagNum = XMLTwo.addTag("TABPOSTSIZE");
            XMLTwo.setValue("TABPOSTSIZE:X", theFlagStates[i].theReflectionFlag.tabPostSize.x, tagNum);
            XMLTwo.setValue("TABPOSTSIZE:Y", theFlagStates[i].theReflectionFlag.tabPostSize.y, tagNum);
            
            tagNum = XMLTwo.addTag("COLOR");
            XMLTwo.setValue("COLOR:RED", theFlagStates[i].theReflectionFlag.color.r, tagNum);
            XMLTwo.setValue("COLOR:GREEN", theFlagStates[i].theReflectionFlag.color.g, tagNum);
            XMLTwo.setValue("COLOR:BLUE", theFlagStates[i].theReflectionFlag.color.b, tagNum);
            XMLTwo.setValue("COLOR:ALPHA", theFlagStates[i].theReflectionFlag.color.a, tagNum);
            
            tagNum = XMLTwo.addTag("PRESENTCHECK");
            XMLTwo.setValue("PRESENTCHECK:X", theFlagStates[i].theReflectionFlag.presentCheck.x, tagNum);
            XMLTwo.setValue("PRESENTCHECK:Y", theFlagStates[i].theReflectionFlag.presentCheck.y, tagNum);
            XMLTwo.setValue("PRESENTCHECK:WIDTH", theFlagStates[i].theReflectionFlag.presentCheck.width, tagNum);
            XMLTwo.setValue("PRESENTCHECK:HEIGHT", theFlagStates[i].theReflectionFlag.presentCheck.height, tagNum);

            tagNum = XMLTwo.addTag("FLOOR");
            XMLTwo.setValue("FLOOR:INT", theFlagStates[i].theReflectionFlag.floor, tagNum);

            tagNum = XMLTwo.addTag("ENDED");
            XMLTwo.setValue("ENDED:BOOL", theFlagStates[i].theReflectionFlag.ended, tagNum);

            tagNum = XMLTwo.addTag("SELECTED");
            XMLTwo.setValue("SELECTED:BOOL", theFlagStates[i].theReflectionFlag.selected, tagNum);

            tagNum = XMLTwo.addTag("STATE");
            XMLTwo.setValue("STATE:INT", theFlagStates[i].theReflectionFlag.state, tagNum);

            tagNum = XMLTwo.addTag("STATEMESSAGE");
            XMLTwo.setValue("STATEMESSAGE:STRING", theFlagStates[i].theReflectionFlag.stateMessage, tagNum);

            XMLTwo.popTag();

            }
           
        }
           
        XMLTwo.saveFile( iPhoneDocumentsDirectory + xmlFileTwo );
        printf(" saved to app documents folder \n ");
                  
    }



////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::update() {
    
    playData();
    
    if (scrubBox->touching) {
        playPauseButton->toggle = false;
        scrubPos.x = ofMap(scrubLocation->x, 100, ofGetWidth(), startTime, endTime);
        currentPos->update(scrubLocation->x);
    }
 
    if (markerButton->selected) {
        *markerButtonSelected = !*markerButtonSelected;
        markerButton->selected=false;
    }

    
}



////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::draw(ofTrueTypeFont& basicFont) {
    
//    basicFont.drawString(messageOne, ofGetWidth()/2, 250);
//    basicFont.drawString(messageTwo, ofGetWidth()/2, 280);
    
    playPauseButton->drawNoColorWithImageToggle();
    markerButton->drawNoColorWithImage();
    scrubBox->drawNoColor();
    currentPos->draw();
    
//    ofSetLineWidth(2.0);
//    ofSetColor(0, 0, 0);

    //drawing from create
    for (int i = 0; i < drawThese.size(); i++) {
        ofSetColor(drawThese[i].color);
        ofSetLineWidth(drawThese[i].lineWidth);
        drawThese[i].draw(scrubPos.x);
    }
    
    ofSetColor(0, 0, 0);
    ofSetLineWidth(1.0);
    if (scrubFeedback.size() > 0) {
        for (int i = 1; i < scrubFeedback.size(); i++) {
            ofLine(scrubFeedback[i-1].x, scrubFeedback[i-1].y, scrubFeedback[i].x, scrubFeedback[i].y);
        }
    }
    
    for (int i = 0; i < theFlagStates.size(); i++) {
        theFlagStates[i].draw(basicFont);
    }

    
    //-----------------------------------------------
    //What is from marker

    for (int i = 0; i < markerThese.size(); i++) {
        ofSetColor(markerThese[i].color);
        ofSetLineWidth(markerThese[i].lineWidth);
        markerThese[i].draw();
    }

    //-----------------------------------------------
    //Marker feedback
    ofSetColor(255, 220, 0);
    
    if (*markerButtonSelected) {

        ofSetLineWidth(6.0);
        if (currentDrawing.size()>0) {
            for (int i = 1; i < currentDrawing.size(); i++) {
                ofLine(currentDrawing[i-1].x, currentDrawing[i-1].y, currentDrawing[i].x, currentDrawing[i].y);
            }
        }

    }
    
    ofSetLineWidth(1.0);
    //    printf("theFlagStates.size(): %lu \n", theFlagStates.size());
}

//------------------------------------------------------------------
void uiPresent::draw(ofTrueTypeFont& basicFont, ofImage& questionImage) {
    
//    basicFont.drawString(messageOne, ofGetWidth()/2, 250);
//    basicFont.drawString(messageTwo, ofGetWidth()/2, 280);
    
    playPauseButton->drawNoColorWithImageToggle();
    markerButton->drawNoColorWithImage();
    scrubBox->drawNoColor();
    currentPos->draw();
    
    //    ofSetLineWidth(2.0);
    
    //drawing from create
    for (int i = 0; i < drawThese.size(); i++) {
        ofSetColor(drawThese[i].color);
        ofSetLineWidth(drawThese[i].lineWidth);
        drawThese[i].draw(scrubPos.x);
    }

    ofSetColor(0, 0, 0);
    ofSetLineWidth(1.0);
    if (scrubFeedback.size() > 0) {
        for (int i = 1; i < scrubFeedback.size(); i++) {
            ofLine(scrubFeedback[i-1].x, scrubFeedback[i-1].y, scrubFeedback[i].x, scrubFeedback[i].y);
        }
    }
    
    for (int i = 0; i < theFlagStates.size(); i++) {
        theFlagStates[i].draw(basicFont);
    }
    
    
    //-----------------------------------------------
    //What is from marker
    
    for (int i = 0; i < markerThese.size(); i++) {
        ofSetColor(markerThese[i].color);
        ofSetLineWidth(markerThese[i].lineWidth);
        markerThese[i].draw();
    }
    
    //-----------------------------------------------
    //Marker feedback
    ofSetColor(255, 220, 0);
    
    if (*markerButtonSelected) {
        
        ofSetLineWidth(6.0);
        if (currentDrawing.size()>0) {
            for (int i = 1; i < currentDrawing.size(); i++) {
                ofLine(currentDrawing[i-1].x, currentDrawing[i-1].y, currentDrawing[i].x, currentDrawing[i].y);
            }
        }
        
    }
    
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255);
    questionImage.draw(175, ofGetHeight()/3+50);
    ofDisableAlphaBlending();
    
    ofSetLineWidth(1.0);
    //    printf("theFlagStates.size(): %lu \n", theFlagStates.size());
}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiPresent::touchingDown(ofTouchEventArgs &touch) {
    
    playPauseButton->touchingDown(touch);
    markerButton->touchingDown(touch);
    scrubBox->touchingDown(touch);
    
    if (scrubBox->touching) {
        scrubLocation->set(touch.x, touch.y);
    }
    
    if (*markerButtonSelected) {
        
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;
        
        currentDrawing.push_back(currentPos);
        
        //checks to see what flag we're in
        for (int i = 0; i < theFlagStates.size(); i++) {
        
            if (theFlagStates[i].theReflectionFlag.presentCheck.inside(scrubLocation->x, scrubLocation->y)){
        
                markerColor.set(theFlagStates[i].theReflectionFlag.color);
//                printf(" found a color that matches! \n ");
                break;
            } else {
                markerColor.set(0,255,0);
            }
        }
        
        float lineWidth;
        lineWidth = 6.0;
        thisDrawing.update(touch, markerColor, lineWidth);
    }

    
}

//------------------------------------------------------------------
void uiPresent::touchingMove(ofTouchEventArgs &touch) {
    
    playPauseButton->touchingMove(touch);
    markerButton->touchingMove(touch);
    scrubBox->touchingMove(touch);
    
    if (scrubBox->touching && touch.x >= scrubBox->pos.x) {
        scrubLocation->set(touch.x, touch.y);
    }
    
    
    if (*markerButtonSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;
        
        currentDrawing.push_back(currentPos);
        
        ofColor thisColor;
        thisColor.set(255, 220, 0);
        float lineWidth;
        lineWidth = 6.0;
        
        for (int i = 0; i < theFlagStates.size(); i++) {
            
            if (theFlagStates[i].theReflectionFlag.presentCheck.inside(scrubLocation->x, scrubLocation->y)){
                
                markerColor.set(theFlagStates[i].theReflectionFlag.color);
                printf(" found a color that matches! \n ");
                break;
            } else {
                markerColor.set(0,255,0);
            }
        }

        
        thisDrawing.update(touch, markerColor, lineWidth);
    }

    
}

//------------------------------------------------------------------
void uiPresent::touchingUp(ofTouchEventArgs &touch) {
    
    playPauseButton->touchingUp(touch);
    markerButton->touchingUp(touch);
    scrubBox->touchingUp(touch);
    
    if (scrubBox->thisRectangle.inside(touch.x, touch.y)) {
        scrubLocation->set(touch.x, touch.y);
    }
    
    if (*markerButtonSelected) {
        currentDrawing.clear();
        markerThese.push_back(thisDrawing);
        thisDrawing.reset();
    }

}


//------------------------------------------------------------------
void uiPresent::doubleTap(ofTouchEventArgs &touch) {
    
    
}

//--------------------------------------------------------------
void uiPresent::exit() {
    
    
}
