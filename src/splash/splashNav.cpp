/*
 *  splashNav.cpp
 *
 *  Created by Ryan Raffa on 6/3/13.
 *
 */

#include "splashNav.h"


//------------------------------------------------------------------
splashNav::~splashNav() {

    
    delete     storyAction;
    delete     storyZeroActive;
    delete     storyOneActive;
    delete     storyTwoActive;
    delete     storyThreeActive;
    delete     storyFourActive;
    delete     storyFiveActive;
    
    delete     layerOne;
    delete     layerTwoA;
    delete     layerTwoB;
    delete     layerTwoC;
    delete     layerTwoD;
    delete     layerTwoE;
    delete     layerTwoF;

    
    //    printf(" splashNav deconstructor \n");
//    printf(" splashNav deconstructor \n");    
    
}

//------------------------------------------------------------------
splashNav::splashNav() {

//    printf(" splashNav setup started \n");
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    
    section = 0;
    

    splashPageOne.pageStage0.set(0, 0);
    splashPageOne.pageStage1.set(-7, 0);
    splashPageOne.pageStage2.set(-14, 0);
    splashPageOne.pageStage3.set(-21, 0);
    splashPageOne.pageStage4.set(-28, 0);
    splashPageOne.pageStage5.set(-35, 0);

    
    splashPageTwo.pageStage0.set(0, 0);
    splashPageTwo.pageStage1.set(-1024, 0);
    splashPageTwo.pageStage2.set(-2048, 0);
    splashPageTwo.pageStage3.set(-3072, 0);
    splashPageTwo.pageStage4.set(-4096, 0);
    splashPageTwo.pageStage5.set(-5120, 0);

 
    storyAction = new ofPoint;
    storyZeroActive = new ofPoint;
    storyOneActive = new ofPoint;
    storyTwoActive = new ofPoint;
    storyThreeActive = new ofPoint;
    storyFourActive = new ofPoint;
    storyFiveActive = new ofPoint;
    
    storyAction->set(ofGetWidth()/2-65, ofGetHeight()-30);
    storyZeroActive->set(ofGetWidth()/2-65, ofGetHeight()-30);
    storyOneActive->set(ofGetWidth()/2-39, ofGetHeight()-30);
    storyTwoActive->set(ofGetWidth()/2-13, ofGetHeight()-30);
    storyThreeActive->set(ofGetWidth()/2+13, ofGetHeight()-30);
    storyFourActive->set(ofGetWidth()/2+39, ofGetHeight()-30);
    storyFiveActive->set(ofGetWidth()/2+65, ofGetHeight()-30);
    
    layerOne = new ofImage;
    layerTwoA = new ofImage;
    layerTwoB = new ofImage;
    layerTwoC = new ofImage;
    layerTwoD = new ofImage;
    layerTwoE = new ofImage;
    layerTwoF = new ofImage;
    
    layerOne->loadImage("images/splash/intro_forest.png");
    layerTwoA->loadImage("images/splash/intro_p1@Low.png");
    layerTwoB->loadImage("images/splash/intro_p2@Low.png");
    layerTwoC->loadImage("images/splash/intro_p3@Low.png");
    layerTwoD->loadImage("images/splash/intro_p4@Low.png");
    layerTwoE->loadImage("images/splash/intro_p5@Low.png");
    layerTwoF->loadImage("images/splash/intro_p6@Low.png");
    
    previousState = false;
    
    locationB.x    = splashPageTwo.pos.x + 1024;
    locationC.x    = splashPageTwo.pos.x + 2048;
    locationD.x    = splashPageTwo.pos.x + 3072;
    locationE.x    = splashPageTwo.pos.x + 4096;
    locationF.x    = splashPageTwo.pos.x + 5120;
    
//    printf(" splashNav setup ended \n");
    
}



//------------------------------------------------------------------
void splashNav::update(int _section, bool panning, ofPoint _currentLocation) {
        
    
    if (panning) {
        
        splashPageTwo.pos.x = newLocation.x;
        splashPageTwo.pos.x += _currentLocation.x;
        
        if (!previousState) {
            
            if (_currentLocation.x > 100) {
                if (section > 0) {
                    section--;
                }
                
                previousState = true;

            } else if (_currentLocation.x < -100) {
                if (section < 5) {
                    section++;
                }
            
                previousState = true;
            
            }
            
        }

        
    } else {
        
        if (this->section == 0) {
            getThere(*storyAction, *storyZeroActive);
            getThere(splashPageOne.pos, splashPageOne.pageStage0);
            getThere(splashPageTwo.pos, splashPageTwo.pageStage0);
        }
        if (this->section == 1) {
            getThere(*storyAction, *storyOneActive);
            getThere(splashPageOne.pos, splashPageOne.pageStage1);
            getThere(splashPageTwo.pos, splashPageTwo.pageStage1);
        }
        if (this->section == 2) {
            getThere(*storyAction, *storyTwoActive);
            getThere(splashPageOne.pos, splashPageOne.pageStage2);
            getThere(splashPageTwo.pos, splashPageTwo.pageStage2);
        }
        if (this->section == 3) {
            getThere(*storyAction, *storyThreeActive);
            getThere(splashPageOne.pos, splashPageOne.pageStage3);
            getThere(splashPageTwo.pos, splashPageTwo.pageStage3);
        }
        if (this->section == 4) {
            getThere(*storyAction, *storyFourActive);
            getThere(splashPageOne.pos, splashPageOne.pageStage4);
            getThere(splashPageTwo.pos, splashPageTwo.pageStage4);
        }
        if (this->section == 5) {
            getThere(*storyAction, *storyFiveActive);
            getThere(splashPageOne.pos, splashPageOne.pageStage5);
            getThere(splashPageTwo.pos, splashPageTwo.pageStage5);
        }
        
        previousState = false;
        newLocation.x = splashPageTwo.pos.x;

    }
    
    
    locationB.x    = splashPageTwo.pos.x + 1024;
    locationC.x    = splashPageTwo.pos.x + 2048;
    locationD.x    = splashPageTwo.pos.x + 3072;
    locationE.x    = splashPageTwo.pos.x + 4096;
    locationF.x    = splashPageTwo.pos.x + 5120;

    
//    printf("section: %d \n", section);
//    printf("splashPageOne.pos.x: %f \n", splashPageOne.pos.x);
//    printf("splashPageOne.pos.y: %f \n", splashPageOne.pos.y);
//    printf("splashPageTwo.pos.x: %f \n", splashPageTwo.pos.x);
//    printf("splashPageTwo.pos.y: %f \n", splashPageTwo.pos.y);
//    printf("panning: %d \n", panning);
//    printf("newLocation.x: %f \n", newLocation.x);
//    printf("splashPageTwo.pos.x: %f \n", splashPageTwo.pos.x);

//    printf("section value: %d \n", this->section);

}

//------------------------------------------------------------------
void splashNav::getThere(ofPoint& current, ofPoint& ideal) {

    ofPoint dist;
    
    dist.x = ideal.x - current.x;
	dist.y = ideal.y - current.y;
	
	current.x += dist.x/5.0;
	current.y += dist.y/5.0;
    
}

//------------------------------------------------------------------
void splashNav::draw() {
    
        ofBackground(0, 0, 0);
    
        ofEnableAlphaBlending();

        
        ofSetColor(190, 190, 190, 255);
    
        layerOne->draw(splashPageOne.pos.x, splashPageOne.pos.y);
        layerTwoA->draw(splashPageTwo.pos.x, splashPageTwo.pos.y);
        layerTwoB->draw(locationB.x, locationB.y);
        layerTwoC->draw(locationC.x, locationC.y);
        layerTwoD->draw(locationD.x, locationD.y);
        layerTwoE->draw(locationE.x, locationE.y);
        layerTwoF->draw(locationF.x, locationF.y);
    
        ofEnableSmoothing();
        ofNoFill();
        ofCircle(storyZeroActive->x, storyZeroActive->y, 8.0);
        ofCircle(storyOneActive->x, storyOneActive->y, 8.0);
        ofCircle(storyTwoActive->x, storyTwoActive->y, 8.0);
        ofCircle(storyThreeActive->x, storyThreeActive->y, 8.0);
        ofCircle(storyFourActive->x, storyFourActive->y, 8.0);
        ofCircle(storyFiveActive->x, storyFiveActive->y, 8.0);
        ofFill();
        ofCircle(storyAction->x, storyAction->y, 8.0);
        ofDisableSmoothing();
    
        
    
        ofDisableAlphaBlending();
}


//------------------------------------------------------------------
void splashNav::touchingDown(ofTouchEventArgs &touch) {
    
    
}

//------------------------------------------------------------------
void splashNav::touchingMove(ofTouchEventArgs &touch) {

    
    
    
}

//------------------------------------------------------------------
void splashNav::touchingUp(ofTouchEventArgs &touch) {

}

//------------------------------------------------------------------
void splashNav::doubleTap(ofTouchEventArgs &touch) {
    
}


