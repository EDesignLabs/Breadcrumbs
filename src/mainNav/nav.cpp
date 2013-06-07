/*
 *  nav.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#include "nav.h"


//------------------------------------------------------------------
void nav::setup() {

//    printf(" NAV setup started \n");
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    home.loadImage("images/ui/glyphicons_020_home.png");
    
    pos.set(0, 0);
    size.set(home.getWidth()+20, home.getHeight()+20);
    offSet.set(25, 40);
    
    color.set(170, 170, 170, 120);
    homeButton.setup(pos, size, color);

    birds.loadImage("images/problemNav/birds.png");
    breadcrumbs.loadImage("images/problemNav/breadcrumbs.png");
    candy.loadImage("images/problemNav/candy.png");
    myWork.loadImage("images/problemNav/myWork.png");
    
    //skip intro button
    skipIntro.loadImage("images/ui/glyphicons_207_remove_2.png");
    pos.set(ofGetWidth()-(skipIntro.getWidth()+20), 0);
    skipIntroButton.setup(pos, size, color);
    
    pos.set(338, 510);
    size.set(336, 174);
    color.set(255, 255, 255, 255);
    skipIntroTwoButton.setup(pos, size, color);
    
    ofPoint posTwo;
    posTwo.set(0, 0);
    size.set(256, 768);
    birdsButton.setup(posTwo, size, offSet, "BIRDS!", color);

    ofPoint posThree;
    posThree.set(256, 0);
    breadcrumbsButton.setup(posThree, size, offSet, "Find the path", color);

    ofPoint posFour;
    posFour.set(512, 0);
    candyButton.setup(posFour, size, offSet, "Candy", color);

    color.set(255, 255, 255, 120);

    ofPoint posFive;
    posFive.set(768, 0);
    myWorkButton.setup(posFive, size, offSet, "Recent Work", color);
    
    posFive.set(796, 80);
    size.set(200, 200);
    color.set(255, 200, 200, 120);
    myWorkBirds.setup(posFive, size, offSet, "BIRDS!", color);

    posFive.set(796, 308);
    myWorkBreadcrumb.setup(posFive, size, offSet, "Find the path", color);

    posFive.set(796, 536);
    myWorkCandy.setup(posFive, size, offSet, "Candy", color);

    splash = new splashNav;
    
    navStateSplash = true;
    navStateToc = false;
    navStateExerciseOne = false;
    navStateExerciseTwo = false;
    navStateExerciseThree = false;
    navStateSavedMathOne = false;
    navStateSavedMathTwo = false;
    navStateSavedMathThree = false;
    
//    printf(" NAV setup ended \n");
    
}
		 
//------------------------------------------------------------------
void nav::update(int section, string iPhoneDocumentsDirectory) {

    //depending on the selection made, a specific setup is run
    //when returning to TOC from monster, monster is reset

//    printf(" NAV update started \n");

    if (skipIntroButton.selected) {
        navStateSplash = false;
        navStateToc = true;
        delete splash;
        skipIntroButton.selected=false;
    }

    if (skipIntroTwoButton.selected) {
        navStateSplash = false;
        navStateToc = true;
        delete splash;
        skipIntroTwoButton.selected=false;
    }

    if (birdsButton.selected) {
        mathExercisesOne = new problemMathOne();
        navStateToc = false;
        navStateExerciseOne = true;
        navStateExerciseTwo = false;
        navStateExerciseThree = false;
        navStateSavedMathOne = false;
        navStateSavedMathTwo = false;
        navStateSavedMathThree = false;
        birdsButton.selected=false;
    }

    if (breadcrumbsButton.selected) {
        mathExercisesTwo = new problemMathTwo();
        navStateToc = false;
        navStateExerciseOne = false;
        navStateExerciseTwo = true;
        navStateExerciseThree = false;
        navStateSavedMathOne = false;
        navStateSavedMathTwo = false;
        navStateSavedMathThree = false;
        breadcrumbsButton.selected=false;
    }

    if (candyButton.selected) {
        mathExercisesThree = new problemMathThree();
        navStateToc = false;
        navStateExerciseOne = false;
        navStateExerciseTwo = false;
        navStateExerciseThree = true;
        navStateSavedMathOne = false;
        navStateSavedMathTwo = false;
        navStateSavedMathThree = false;
        candyButton.selected=false;
    }

    if (myWorkBirds.selected) {
        savedMathOne = new saveMathOne(iPhoneDocumentsDirectory);
        navStateToc = false;
        navStateExerciseOne = false;
        navStateExerciseTwo = false;
        navStateExerciseThree = false;
        navStateSavedMathOne = true;
        navStateSavedMathTwo = false;
        navStateSavedMathThree = false;
        myWorkBirds.selected=false;
    }

    if (myWorkBreadcrumb.selected) {
        savedMathTwo = new saveMathTwo(iPhoneDocumentsDirectory);
        navStateToc = false;
        navStateExerciseOne = false;
        navStateExerciseTwo = false;
        navStateExerciseThree = false;
        navStateSavedMathOne = false;
        navStateSavedMathTwo = true;
        navStateSavedMathThree = false;
        myWorkBreadcrumb.selected=false;
    }

    if (myWorkCandy.selected) {
        savedMathThree = new saveMathThree(iPhoneDocumentsDirectory);
        navStateToc = false;
        navStateExerciseOne = false;
        navStateExerciseTwo = false;
        navStateExerciseThree = false;
        navStateSavedMathOne = false;
        navStateSavedMathTwo = false;
        navStateSavedMathThree = true;
        myWorkCandy.selected=false;
    }

    if (homeButton.selected) {
        
        if (navStateExerciseOne) {
            navStateExerciseOne = false;
            navStateToc = true;
            delete mathExercisesOne;
            homeButton.selected=false;
        }

        if (navStateExerciseTwo) {
            navStateExerciseTwo = false;
            navStateToc = true;
            delete mathExercisesTwo;
            homeButton.selected=false;
        }

        if (navStateExerciseThree) {
            navStateExerciseThree = false;
            navStateToc = true;
            delete mathExercisesThree;
            homeButton.selected=false;
        }

        if (navStateSavedMathOne) {
            navStateSavedMathOne = false;
            navStateToc = true;
            delete savedMathOne;
            homeButton.selected=false;
        }

        if (navStateSavedMathTwo) {
            navStateSavedMathTwo = false;
            navStateToc = true;
            delete savedMathTwo;
            homeButton.selected=false;
        }

        if (navStateSavedMathThree) {
            navStateSavedMathThree = false;
            navStateToc = true;
            delete savedMathThree;
            homeButton.selected=false;
        }

    
    }

    //based on what state is active, update information is passed
    if (navStateSplash) splash->update(section);
    if (navStateExerciseOne) mathExercisesOne->update(iPhoneDocumentsDirectory);
    if (navStateExerciseTwo) mathExercisesTwo->update(iPhoneDocumentsDirectory);
    if (navStateExerciseThree) mathExercisesThree->update(iPhoneDocumentsDirectory);
    if (navStateSavedMathOne) savedMathOne->update();
    if (navStateSavedMathTwo) savedMathTwo->update();
    if (navStateSavedMathThree) savedMathThree->update();
    
//    printf(" NAV udpate ended \n");
    
}


//------------------------------------------------------------------
void nav::draw(ofTrueTypeFont& basicFont) {

    if (navStateSplash) {
        splash->draw();
        skipIntroButton.draw(basicFont);

//        if (splash->section ==7) skipIntroTwoButton.drawOnTop();

        ofEnableAlphaBlending();
        skipIntro.draw(ofGetWidth()-(skipIntro.getWidth()+10), 15);
        ofDisableAlphaBlending();

    }
    
    if (navStateToc) {
        ofColor textColor;
        textColor.set(255, 255, 255);
        birdsButton.drawTextColor(basicFont, birds, textColor);
        breadcrumbsButton.drawTextColor(basicFont, breadcrumbs, textColor);
        candyButton.drawTextColor(basicFont, candy, textColor);
        myWorkButton.draw(basicFont, myWork);
        myWorkBirds.draw(basicFont);
        myWorkBreadcrumb.draw(basicFont);
        myWorkCandy.draw(basicFont);
    }

    if (navStateExerciseOne) {
        mathExercisesOne->draw(basicFont);
        homeButton.draw(basicFont);
        
        ofEnableAlphaBlending();
            home.draw(10, 10);
        ofDisableAlphaBlending();
    }

    if (navStateExerciseTwo) {
        mathExercisesTwo->draw(basicFont);
        homeButton.draw(basicFont);
        
        ofEnableAlphaBlending();
        home.draw(10, 10);
        ofDisableAlphaBlending();
    }

    if (navStateExerciseThree) {
        mathExercisesThree->draw(basicFont);
        homeButton.draw(basicFont);
        
        ofEnableAlphaBlending();
        home.draw(10, 10);
        ofDisableAlphaBlending();
    }

    if (navStateSavedMathOne) {
        savedMathOne->draw(basicFont);
        homeButton.draw(basicFont);
        
        ofEnableAlphaBlending();
        home.draw(10, 10);
        ofDisableAlphaBlending();
    }
    
    if (navStateSavedMathTwo) {
        savedMathTwo->draw(basicFont);
        homeButton.draw(basicFont);
        
        ofEnableAlphaBlending();
        home.draw(10, 10);
        ofDisableAlphaBlending();
    }
    
    if (navStateSavedMathThree) {
        savedMathThree->draw(basicFont);
        homeButton.draw(basicFont);
        
        ofEnableAlphaBlending();
        home.draw(10, 10);
        ofDisableAlphaBlending();
    }
}

//------------------------------------------------------------------
void nav::touchingDown(ofTouchEventArgs &touch) {
    
    if (navStateSplash) skipIntroButton.touchingDown(touch);
    if (navStateSplash && splash->section==7) skipIntroTwoButton.touchingDown(touch);
    
    if (navStateToc) {
        birdsButton.touchingDown(touch);
        breadcrumbsButton.touchingDown(touch);
        candyButton.touchingDown(touch);
        myWorkBirds.touchingDown(touch);
        myWorkBreadcrumb.touchingDown(touch);
        myWorkCandy.touchingDown(touch);
    }
    
    if (navStateExerciseOne) {
        mathExercisesOne->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateExerciseTwo) {
        mathExercisesTwo->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateExerciseThree) {
        mathExercisesThree->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateSavedMathOne) {
        savedMathOne->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateSavedMathTwo) {
        savedMathTwo->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateSavedMathThree) {
        savedMathThree->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

}

//------------------------------------------------------------------
void nav::touchingMove(ofTouchEventArgs &touch) {
    
    if (navStateSplash) skipIntroButton.touchingMove(touch);
    if (navStateSplash && splash->section==7) skipIntroTwoButton.touchingMove(touch);
    
    if (navStateToc) {
        birdsButton.touchingMove(touch);
        breadcrumbsButton.touchingMove(touch);
        candyButton.touchingMove(touch);
        myWorkBirds.touchingMove(touch);
        myWorkBreadcrumb.touchingMove(touch);
        myWorkCandy.touchingMove(touch);
    }
    
    if (navStateExerciseOne) {
        mathExercisesOne->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateExerciseTwo) {
        mathExercisesTwo->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateExerciseThree) {
        mathExercisesThree->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateSavedMathOne) {
        savedMathOne->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateSavedMathTwo) {
        savedMathTwo->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateSavedMathThree) {
        savedMathThree->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

}

//------------------------------------------------------------------
void nav::touchingUp(ofTouchEventArgs &touch) {

    if (navStateSplash) skipIntroButton.touchingUp(touch);
    if (navStateSplash && splash->section==7) skipIntroTwoButton.touchingUp(touch);
    
    if (navStateToc) {
        birdsButton.touchingUp(touch);
        breadcrumbsButton.touchingUp(touch);
        candyButton.touchingUp(touch);
        myWorkBirds.touchingUp(touch);
        myWorkBreadcrumb.touchingUp(touch);
        myWorkCandy.touchingUp(touch);
    }
    
    if (navStateExerciseOne) {
        mathExercisesOne->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateExerciseTwo) {
        mathExercisesTwo->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateExerciseThree) {
        mathExercisesThree->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateSavedMathOne) {
        savedMathOne->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateSavedMathTwo) {
        savedMathTwo->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateSavedMathThree) {
        savedMathThree->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

}

//------------------------------------------------------------------
void nav::doubleTap(ofTouchEventArgs &touch) {
    
}


