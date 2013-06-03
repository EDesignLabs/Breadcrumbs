/*
 *  splashNav.cpp
 *
 *  Created by Ryan Raffa on 6/3/13.
 *
 */

#include "splashNav.h"


//------------------------------------------------------------------
splashNav::~splashNav() {

    
    delete splashSix;
    
    printf(" splashNav deconstructor \n");
    
    
}

//------------------------------------------------------------------
splashNav::splashNav() {

    printf(" splashNav setup started \n");
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    
    section = 0;
    
    makeSectionZero();
    
    printf(" splashNav setup ended \n");
    
}
		 
//------------------------------------------------------------------
void splashNav::update(int section) {
    
    if (this->section != section) {

        if (section < 7) {
         
            this->section = section;
            
            if (this->section == 1) {
                makeSectionOne();
            }
            
            if (this->section == 2) {
                makeSectionTwo();
            }
            
            if (this->section == 3) {
                makeSectionThree();
            }
            
            if (this->section == 4) {
                makeSectionFour();
            }
            
            if (this->section == 5) {
                makeSectionFive();
            }
            
            if (this->section == 6) {
                makeSectionSix();
            }

        }
    }
    
    if (this->section == 0) splashZero->update();
    if (this->section == 1) splashOne->update();
    if (this->section == 2) splashTwo->update();
    if (this->section == 3) splashThree->update();
    if (this->section == 4) splashFour->update();
    if (this->section == 5) splashFive->update();
    if (this->section == 6) splashSix->update();
    
    printf("section value: %d \n", this->section);

}


//------------------------------------------------------------------
void splashNav::draw() {
    
    ofEnableAlphaBlending();
        if (this->section == 0) splashZero->draw();
        if (this->section == 1) splashOne->draw();
        if (this->section == 2) splashTwo->draw();
        if (this->section == 3) splashThree->draw();
        if (this->section == 4) splashFour->draw();
        if (this->section == 5) splashFive->draw();
        if (this->section == 6) splashSix->draw();
    ofDisableAlphaBlending();
}


//------------------------------------------------------------------
void splashNav::makeSectionZero() {

    ofImage theImage;
    splashZero = new splashSection;
    
    theImage.loadImage("images/splash/0-0.png");
    splashZero->setup(theImage, 0, 4000, false, false, 255);
    
    theImage.loadImage("images/splash/0-1.png");
    splashZero->setup(theImage, 1000, 4000, true, false, 0);
    
    
}

//------------------------------------------------------------------
void splashNav::makeSectionOne() {
    
    ofImage theImage;
    splashOne = new splashSection;
    
    theImage.loadImage("images/splash/1-0.png");
    splashOne->setup(theImage, 0, 4500, false, false, 255);
    
    theImage.loadImage("images/splash/1-1.png");
    splashOne->setup(theImage, 500, 4500, true, false, 0);
    
    theImage.loadImage("images/splash/1-2.png");
    splashOne->setup(theImage, 2000, 4500, true, false, 0);
    
    theImage.loadImage("images/splash/1-3.png");
    splashOne->setup(theImage, 3000, 4500, true, false, 0);
    
    theImage.loadImage("images/splash/1-4.png");
    splashOne->setup(theImage, 4000, 5500, true, false, 0);
    
    delete splashZero;
    
}

//------------------------------------------------------------------
void splashNav::makeSectionTwo() {
    
    ofImage theImage;
    splashTwo = new splashSection;

    theImage.loadImage("images/splash/2-0.png");
    splashTwo->setup(theImage, 0, 10000, false, false, 255);
    
    theImage.loadImage("images/splash/2-1.png");
    splashTwo->setup(theImage, 1000, 4000, true, true, 0);
    
    theImage.loadImage("images/splash/2-2.png");
    splashTwo->setup(theImage, 3000, 12000, true, false, 0);
    
    theImage.loadImage("images/splash/2-3.png");
    splashTwo->setup(theImage, 6000, 10000, true, true, 0);
    
    theImage.loadImage("images/splash/2-4.png");
    splashTwo->setup(theImage, 8500, 14000, true, true, 0);
    
    theImage.loadImage("images/splash/2-5.png");
    splashTwo->setup(theImage, 11000, 15200, true, true, 0);
    
    theImage.loadImage("images/splash/2-6.png");
    splashTwo->setup(theImage, 12000, 18000, true, false, 0);
    
    theImage.loadImage("images/splash/2-7.png");
    splashTwo->setup(theImage, 15000, 18000, true, false, 0);
    
    theImage.loadImage("images/splash/2-8.png");
    splashTwo->setup(theImage, 18000, 22000, true, false, 0);
 
    delete splashOne;
    
}

//------------------------------------------------------------------
void splashNav::makeSectionThree() {
    
    ofImage theImage;
    splashThree = new splashSection;
    
    theImage.loadImage("images/splash/3-0.png");
    splashThree->setup(theImage, 0, 10000, false, false, 255);
    
    theImage.loadImage("images/splash/3-1.png");
    splashThree->setup(theImage, 1000, 10000, true, false, 0);
    
    theImage.loadImage("images/splash/3-2.png");
    splashThree->setup(theImage, 2000, 10000, true, false, 0);
    
    theImage.loadImage("images/splash/3-3.png");
    splashThree->setup(theImage, 3000, 10000, true, false, 0);
    
    theImage.loadImage("images/splash/3-4.png");
    splashThree->setup(theImage, 4000, 10000, true, false, 0);
 
    delete splashTwo;
    
}

//------------------------------------------------------------------
void splashNav::makeSectionFour() {
   
    ofImage theImage;
    splashFour = new splashSection;

    theImage.loadImage("images/splash/4-0.png");
    splashFour->setup(theImage, 0, 10000, false, false, 255);
    
    theImage.loadImage("images/splash/4-1.png");
    splashFour->setup(theImage, 0, 2000, false, true, 255);
    
    theImage.loadImage("images/splash/4-2.png");
    splashFour->setup(theImage, 1000, 10000, true, false, 0);
    
    theImage.loadImage("images/splash/4-3.png");
    splashFour->setup(theImage, 2000, 10000, true, false, 0);
 
    delete splashThree;
    
}

//------------------------------------------------------------------
void splashNav::makeSectionFive() {
    
    ofImage theImage;
    splashFive = new splashSection;

    theImage.loadImage("images/splash/5-0.png");
    splashFive->setup(theImage, 0, 10000, false, false, 255);

    theImage.loadImage("images/splash/5-1.png");
    splashFive->setup(theImage, 1000, 4000, true, true, 0);

    theImage.loadImage("images/splash/5-2.png");
    splashFive->setup(theImage, 2000, 4000, true, true, 0);

    theImage.loadImage("images/splash/5-3.png");
    splashFive->setup(theImage, 3000, 4000, true, true, 0);

    theImage.loadImage("images/splash/5-4.png");
    splashFive->setup(theImage, 4000, 10000, true, false, 0);
    
    theImage.loadImage("images/splash/5-5.png");
    splashFive->setup(theImage, 5000, 10000, true, false, 0);

    theImage.loadImage("images/splash/5-6.png");
    splashFive->setup(theImage, 6000, 10000, true, false, 0);
    
    delete splashFour;
    
}

//------------------------------------------------------------------
void splashNav::makeSectionSix() {
    
    ofImage theImage;
    splashSix = new splashSection;
    
    theImage.loadImage("images/splash/6-0.png");
    splashSix->setup(theImage, 0, 20000, false, false, 255);

    theImage.loadImage("images/splash/6-1.png");
    splashSix->setup(theImage, 1000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-2.png");
    splashSix->setup(theImage, 2000, 8000, true, true, 0);

    theImage.loadImage("images/splash/6-3.png");
    splashSix->setup(theImage, 2000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-4.png");
    splashSix->setup(theImage, 4000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-5.png");
    splashSix->setup(theImage, 5000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-6.png");
    splashSix->setup(theImage, 6000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-7.png");
    splashSix->setup(theImage, 7000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-8.png");
    splashSix->setup(theImage, 8000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-9.png");
    splashSix->setup(theImage, 9000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-10.png");
    splashSix->setup(theImage, 10000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-11.png");
    splashSix->setup(theImage, 11000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-12.png");
    splashSix->setup(theImage, 12000, 13000, true, true, 0);

    theImage.loadImage("images/splash/6-13.png");
    splashSix->setup(theImage, 13000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-14.png");
    splashSix->setup(theImage, 13000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-15.png");
    splashSix->setup(theImage, 15000, 20000, true, false, 0);

    theImage.loadImage("images/splash/6-16.png");
    splashSix->setup(theImage, 16000, 20000, true, false, 0);

    delete splashFive;
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


