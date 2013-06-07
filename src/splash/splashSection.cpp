/*
 *  splashSection.cpp
 *
 *  Created by Ryan Raffa on 6/3/13.
 *
 */

#include "splashSection.h"


//------------------------------------------------------------------
splashSection::~splashSection() {

//    printf(" splashSection deconstructor \n");
    
}

//------------------------------------------------------------------
splashSection::splashSection() {
    
    currentTime = 0;
    
}

//------------------------------------------------------------------
void splashSection::setup(ofImage stage, int pageStart, int pageEnd, bool turnOn, bool turnOff, int currentAlpha) {

//    printf(" splashSection setup started \n");

    splashPage theSplashPage;
    
    theSplashPage.stage         = stage;
    theSplashPage.pageStart     = pageStart;
    theSplashPage.pageEnd       = pageEnd;
    theSplashPage.turnOn        = turnOn;
    theSplashPage.turnOff       = turnOff;
    theSplashPage.alphaValue    = currentAlpha;
    
    section.push_back(theSplashPage);
    
    updated = false;
    switcher = false;
//    printf(" splashSection setup ended \n");

}


//------------------------------------------------------------------
void splashSection::update() {
    
    slideTimer();
    
    for (int i = 0; i < section.size(); i++) {
        updatePage(section[i]);
    }
    
}

//------------------------------------------------------------------
void splashSection::updateWithDimmer(int newSize, int whichOne) {
    
    slideTimer();
    
    for (int i = 0; i < newSize; i++) {
        updatePage(section[i]);
    }
    
    dimmer(section[whichOne]);
    
    
}

//------------------------------------------------------------------
void splashSection::slideTimer() {
    
    currentTime = ofGetElapsedTimeMillis();

    if (!updated) {
        
        for (int i = 0; i < section.size(); i++) {
            section[i].pageStart += currentTime;
            section[i].pageEnd   += currentTime;
//            printf("section[i] pageStart, %d \n", section[i].pageStart);
//            printf("section[i] pageEnd, %d \n", section[i].pageEnd);

        }
        
        updated = true;
    }
    
}


//------------------------------------------------------------------
void splashSection::updatePage(splashPage &thePage) {
    
    if (thePage.turnOn == true) {
        if (currentTime >= thePage.pageStart  && currentTime < thePage.pageEnd) {
            if(thePage.alphaValue < 255 && thePage.turnOn == true) {
                thePage.alphaValue += 5;
//                printf("current time >= thepage.pagestart \n");
            }
        }
    }
    
    if (thePage.turnOff == true) {
        if (currentTime > thePage.pageEnd) {
            if (thePage.alphaValue > 0) {
                thePage.alphaValue -= 5;
//                printf("current time > thepage.pageEnd \n");
            }
        }
    }

}

//------------------------------------------------------------------
void splashSection::dimmer(splashPage &thePage) {
    
    
    if (currentTime > thePage.pageStart) {
        if (!switcher) {
            if ( thePage.alphaValue > 150 ) {
                thePage.alphaValue-=5;
            } else {
                switcher = true;
            }
        }
        
        if (switcher) {
            if ( thePage.alphaValue < 250 ) {
                thePage.alphaValue+=5;
            } else {
                switcher = false;
            }
        }
    }
}


//------------------------------------------------------------------
void splashSection::draw() {

    for (int i = 0; i < section.size(); i++) {
//        printf("section[i] alpha value, %d \n", section[i].alphaValue);
        ofSetColor(255, 255, 255, section[i].alphaValue);
        section[i].stage.draw(pos);
    }
}

//------------------------------------------------------------------
void splashSection::draw(int whichOne, ofColor whichColor) {
    
    for (int i = 0; i < section.size(); i++) {
        //        printf("section[i] alpha value, %d \n", section[i].alphaValue);
        ofSetColor(whichColor, section[whichOne].alphaValue);
        section[whichOne].stage.draw(pos);
    }
}



//------------------------------------------------------------------
void splashSection::touchingDown(ofTouchEventArgs &touch) {
    
}

//------------------------------------------------------------------
void splashSection::touchingMove(ofTouchEventArgs &touch) {

}

//------------------------------------------------------------------
void splashSection::touchingUp(ofTouchEventArgs &touch) {

}

//------------------------------------------------------------------
void splashSection::doubleTap(ofTouchEventArgs &touch) {
    
}


