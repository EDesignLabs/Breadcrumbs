#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
    
	//If you want a landscape oreintation 
	iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_LEFT);
    ofTrueTypeFont::setGlobalDpi(72);
    ofRegisterTouchEvents(this);            //method that passes touch events

    EAGLView *view = ofxiPhoneGetGLView();
    recogSwipe = [[ofSwipeGestureRecognizer alloc] initWithView:view];
    section = 0;

    string fontName = "verdana.ttf";
    
    verdana12.loadFont(fontName, 12, true, true, true);
    verdana12.setLineHeight(24.0f);
    verdana12.setLetterSpacing(1.03);

    verdana16.loadFont(fontName, 16, true, true, true);
    verdana16.setLineHeight(24.0f);
    verdana16.setLetterSpacing(0.96);

    verdana22.loadFont(fontName, 22, true, true, true);
    verdana22.setLineHeight(24.0f);
    verdana22.setLetterSpacing(0.96);

    theNav.setup();

    iPhoneDocumentsDirectory = ofxiPhoneGetDocumentsDirectory();
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    section =     recogSwipe->section;
    theNav.update(section, iPhoneDocumentsDirectory);

    //    printf("swipping value: %d \n", section);

}

//--------------------------------------------------------------
void testApp::draw(){
	
    retina.setupScreenOrtho();
    
    ofBackground(255, 255, 255);

    theNav.draw(verdana16);

//    ofSetColor(0, 0, 0);
//    verdana12.drawString("testing the font12 to see if there are any\nissues similar", ofGetWidth()/2-100, 200);
//    verdana16.drawString("testing the font16 to see if there are any\nissues similar", ofGetWidth()/2-100, 300);
//    verdana22.drawString("testing the font22 to see if there are any\nissues similar", ofGetWidth()/2-100, 400);
    
    
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
    
    theNav.touchingDown(touch);
    
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    
    theNav.touchingMove(touch);
    
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){

    theNav.touchingUp(touch);
    
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){

    theNav.doubleTap(touch);
    
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
    sprintf(eventString, "alert - orientation change to %i", newOrientation);
}

