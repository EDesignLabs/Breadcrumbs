#include "testApp.h"
#include "ofAppiOSWindow.h"

////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------
void testApp::setup(){
    
    //-----------------------------------------------
	// initialize the accelerometer

	ofxAccelerometer.setup();
	
    
    //    enum ofOrientation{
    //        OF_ORIENTATION_DEFAULT = 1,
    //        OF_ORIENTATION_180 = 2,
    //        OF_ORIENTATION_90_LEFT = 3,
    //        OF_ORIENTATION_90_RIGHT = 4,
    //        OF_ORIENTATION_UNKNOWN = 5
    //    };
    
    
    //-----------------------------------------------
    //Make it landscape
 
    ofSetOrientation(OF_ORIENTATION_90_RIGHT);
//    iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);
//    ofTrueTypeFont::setGlobalDpi(72);

//    printf("getWidth: %d \n", ofGetWidth());
//    printf("getHeight: %d \n", ofGetHeight());
    
    //-----------------------------------------------
    //Touch events
    
    ofRegisterTouchEvents(this);            //method that passes touch events


    //-----------------------------------------------
    //views for recognizing pan
    
    EAGLView *view = ofxiPhoneGetGLView();
    
    //for swipe
    section = 0;
    direction = "original text";
    
    recogPan = [[ofPanGestureRecognizer alloc] initWithView:view];
    
    //for pan
    pos.set(0.0, 0.0);
    speed.set(0.0, 0.0);
    angle = 0.0;
    velocity.set(0.0, 0.0);
    startLocation.set(0.0, 0.0);
    endLocation.set(0.0, 0.0);
    panning = false;
    
    
    //-----------------------------------------------
    //get the directory
    
    iOSDocumentsDirectory = ofxiOSGetDocumentsDirectory();

    
    //-----------------------------------------------
    //load fonts

    string fontName = "quicksandregular.ttf";
    
    quicksandBook36.loadFont(fontName, 14, true, true, true);
    quicksandBook36.setLineHeight(24.0f);
    quicksandBook36.setLetterSpacing(0.96);
    
    fontName = "quicksandbold.ttf";
    
    quicksandBold36.loadFont(fontName, 14, true, true, true);
    quicksandBold36.setLineHeight(22.0f);
    quicksandBold36.setLetterSpacing(0.97);
    
    quicksandBold60.loadFont(fontName, 22, true, true, true);
    quicksandBold60.setLineHeight(32.0f);
    quicksandBold60.setLetterSpacing(0.94);

    theNav.setup(iOSDocumentsDirectory, XMLOne, XMLTwo);
    
    
    //-----------------------------------------------
    //keyboard

    keyboard = new ofxiPhoneKeyboard(740,220,32,420);
	keyboard->setVisible(false);
	keyboard->setBgColor(255, 255, 255, 255);
	keyboard->setFontColor(0,0,0, 255);
	keyboard->setFontSize(26);
    
//    keyboardTwo = new ofxiPhoneKeyboard(620,285,32,415);
//	keyboardTwo->setVisible(false);
//	keyboardTwo->setBgColor(255, 255, 255, 255);
//	keyboardTwo->setFontColor(0,0,0, 255);
//	keyboardTwo->setFontSize(26);

    //-----------------------------------------------
    //wrap text

    theTextWrap.init(quicksandBook36);
    theTextWrap.setText( "Please press 'Return' to submit text" );
    theTextWrap.setColor(255, 255, 255, 255);
    //    theTextWrap.setLineHeight(32.0f);
    //    theTextWrap.setLetterSpacing(0.90);
    theTextWrap.wrapTextX(565);

    
    //-----------------------------------------------
    //change text button

    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    ofColor textColor;
    ofColor colorTwo;
    
    //Got to URL button
    pos.set(10, 10);
    size.set(408, 36);
    color.set(255, 255, 255, 10);
    colorTwo.set(255, 0, 0,100);
    goToURL.setup(pos, size, offSet, "", colorTwo, color, textColor, textColor);
    
    //view problem new
    pos.set(435, 500);
    size.set(150, 50);
    color.set(96, 200, 84, 255);
    colorTwo.set(255, 0, 0, 200);
    textColor.set(86, 86, 86, 255);
    offSet.set(44, 35);  //THIS OFFSETS THE TEXT!!!

    saveNewText.setup(pos, size, offSet, "save", colorTwo, color, textColor, textColor);
    
    navStateNewTextWindow = false;
    navStateNewTextSaved = false;
    
    
    //for submitting user name
    
    ofImage saveItOne;
    ofImage saveItTwo;
    saveItOne.loadImage("images/ui/Save_Low.png");
    saveItTwo.loadImage("images/ui/Save_Low.png");
    
    pos.set(710, 365);
    size.set(saveItOne.getWidth(), saveItOne.getHeight());
    color.set(200, 200, 200);
    offSet.set(0, 0);
    
    submitUserNameButton.setup(pos, size, color, saveItOne, saveItTwo, offSet);
    
    
    //-----------------------------------------------
    //for edit text button
    ofImage    editImageOne;
    ofImage    editImageTwo;
    
    editImageOne.loadImage("images/ui/edit@Low.png");
    editImageTwo.loadImage("images/ui/edit@Low.png");
    
    
    size.set(editImageOne.getWidth(), editImageOne.getHeight());
    pos.set(275, 633);
    offSet.set(0, 0);
    color.set(230, 230, 230, 245);
    editTextMathButton.setup(pos, size, color, editImageOne, editImageTwo, offSet);
    
    
    
}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------
void testApp::update(){
    
    
    //-----------------------------------------------
    //panning

    //divide by the amount you like to get the speed your looking for
    pos.x = pos.x + speed.x/40.0;
    pos.y = pos.y + speed.y/40.0;
    panning =     recogPan->panning;

    
    
    //-----------------------------------------------
    //bring keyboard visible
    
    if (editTextMathButton.selected) {
        keyboard->setVisible(true);
        navStateNewTextWindow = true;
        navStateNewTextSaved = false;
        
        //-----------------------------------------------
        //load the XML once
        
//        string XMLFileOne = "myCreateProbSix.xml";
//        string XMLFileTwo = "myReflectProbSix.xml";
        
        theXMLParty.xmlSetupThang(iOSDocumentsDirectory, XMLOne, XMLTwo, theNav.mathSixButton);
        
        editTextMathButton.selected = false;
        
    }
    
    if (navStateNewTextWindow && keyboard->getText() != "") {
        theTextWrap.setText( keyboard->getText() );
        theTextWrap.wrapTextX(565);
    }
    
    
    if (theNav.navStateSplash) {
        
        ofPoint newLocationOne;
        newLocationOne.set(308, 620);
        
        goToURL.update(theNav.splash->locationF+newLocationOne);

        if (goToURL.selected) {

            goToURL.selected=false;

            string url = "http://breadcrumbstheapp.net";
            
            [[UIApplication sharedApplication] openURL:[NSURL URLWithString: [[[[NSString alloc] initWithCString: url.c_str()]stringByAddingPercentEscapesUsingEncoding: NSASCIIStringEncoding] autorelease]   ]];

        }
    }
    
    if (saveNewText.selected) {
        navStateNewTextSaved = true;
        theNav.mathSixButton.problemText = keyboard->getText();
        
        theXMLParty.saveXMLText(iOSDocumentsDirectory, XMLOne, XMLTwo, theNav.mathSixButton);
        
        keyboard->setVisible(false);
        keyboard->setText("");
        navStateNewTextWindow = false;
        theNav.greyStartButton.toggle = true;  //this is for the grey start
        saveNewText.selected = false;
        

    }
    
    
    
//    if (theNav.navStateUserName) {
//        keyboardTwo->setVisible(true);
//    }
    
//    if (submitUserNameButton.selected) {
//
//        userName = keyboardTwo->getText();
//        printf("userName is... %s \n", userName.c_str());
//        
//        keyboardTwo->setVisible(false);
//        keyboardTwo->setText("");
    
        //send the user name to nav
//        theNav.setUserName(iOSDocumentsDirectory, XMLOne, XMLTwo, userName);
//        theNav.submitUserNameButton.selected = true;
//        submitUserNameButton.selected = false;
//    }
    
    //-----------------------------------------------
    //NAV update
    
    theNav.update(section, iOSDocumentsDirectory, XMLOne, XMLTwo, currentLocation, speed, panning, quicksandBold60, quicksandBold36, quicksandBook36);

    
    
    //    printf("swipping value: %d \n", section);

}



////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------
void testApp::draw(){
	

    //-----------------------------------------------
    //background

    ofBackground(255, 255, 255);

    
    //-----------------------------------------------
    //retina screen

    retina.setupScreenOrtho();
    

    //-----------------------------------------------
    //nav draw

    theNav.draw(quicksandBold60, quicksandBold36, quicksandBook36);

    
    //-----------------------------------------------
    //keyboard
    
    if (theNav.navStateToc && theNav.questionButton.toggle == false && theNav.metricsButton.toggle == false) {
        editTextMathButton.drawTwoImages();
        
        if (navStateNewTextWindow) {
            ofSetColor(200, 200, 200, 120);
            ofRect(0, 0, ofGetWidth(), ofGetHeight());
            drawNewText();
        }
        
    }
    
//    if (theNav.navStateUserName) {
//        submitUserNameButton.drawTwoImages();
//    }

    
    if (theNav.navStateSplash) {
        goToURL.drawTwoColorsRounded(quicksandBook36);
    }
    
    
    //-----------------------------------------------
    //frame rate
    
//    ofSetColor(0, 0, 0);
//    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 270, 743);
    
}


////////////////////////////////////////////////////////////////////
//      DRAW NEW TEXT                                             //
////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------
void testApp::drawNewText(){
        
    ofSetColor(122, 122, 122);
    ofRectRounded(200, 200, 600, 400, 5);

    ofSetColor(255,255, 255);
    quicksandBook36.drawString("You may input your custom problem here: ", 220, 234);
    theTextWrap.draw(220,320);
    
    saveNewText.drawTwoColorsRounded(quicksandBold60);
    
}

//--------------------------------------------------------------
void testApp::exit(){

}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
    
    if (theNav.navStateSplash) goToURL.touchingDown(touch);
    
    if (!navStateNewTextWindow && theNav.metricsButton.toggle == false) editTextMathButton.touchingDown(touch);
    if (navStateNewTextWindow) saveNewText.touchingDown(touch);

//    if (theNav.navStateUserName) submitUserNameButton.touchingDown(touch);
    
    if (!navStateNewTextWindow) theNav.touchingDown(touch);
    
    
    speed.set(0.0, 0.0);
    
    pos.x = touch.x;
    pos.y = touch.y;
    
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    

    if (theNav.navStateSplash) goToURL.touchingMove(touch);

    if (!navStateNewTextWindow && theNav.metricsButton.toggle == false) editTextMathButton.touchingMove(touch);
    if (navStateNewTextWindow) saveNewText.touchingMove(touch);
    
//    if (theNav.navStateUserName) submitUserNameButton.touchingMove(touch);
    
    if (!navStateNewTextWindow) theNav.touchingMove(touch);
    
    
    pos.x = touch.x;
    pos.y = touch.y;
    
    //gets official start of swipe and adjusts original swipe beginning
    if (panning) {
        startLocation.x =     recogPan->startLocation.x;
        startLocation.y =     recogPan->startLocation.y;
    }
    
    currentLocation.x =   recogPan->currentLocation.x;
    currentLocation.y =   recogPan->currentLocation.y;
    
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){

    if (theNav.navStateSplash) goToURL.touchingUp(touch);

    if (!navStateNewTextWindow && theNav.metricsButton.toggle == false) editTextMathButton.touchingUp(touch);
    if (navStateNewTextWindow) saveNewText.touchingUp(touch);
//    if (theNav.navStateUserName) submitUserNameButton.touchingUp(touch);
    
    if (!navStateNewTextWindow) theNav.touchingUp(touch);
    
    //gathers velocity info
    //******FLIPPED X AND Y VELOCITY BECAUSE OF FORCED ORIENTATION********
    speed.x =     recogPan->velocity.x;
    speed.y =     recogPan->velocity.y;
    
    pos.x = touch.x;
    pos.y = touch.y;
    
    currentLocation.x =   recogPan->currentLocation.x;
    currentLocation.y =   recogPan->currentLocation.y;

    //grabs actual end position which is based off of real origin
    endLocation.x =     recogPan->endLocation.x;
    endLocation.y =     recogPan->endLocation.y;
    
    newLocation.x = startLocation.x + endLocation.x;
    newLocation.y = startLocation.y + endLocation.y;
    
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){


}


//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){
    
    if ((ofOrientation)newOrientation == OF_ORIENTATION_90_RIGHT) {
        ofSetOrientation(OF_ORIENTATION_90_RIGHT);
    } else if ((ofOrientation)newOrientation == OF_ORIENTATION_90_LEFT) {
        ofSetOrientation(OF_ORIENTATION_90_LEFT);
    }

}

