/*
 *  nav.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#include "nav.h"


//------------------------------------------------------------------
void nav::setup() {

    printf(" NAV setup started \n");
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    homeButton.loadImage("images/ui/glyphicons_020_home.png");
    
    pos.set(0, 0);
    size.set(homeButton.getWidth()+20, homeButton.getHeight()+20);
    offSet.set(25, 40);
    
    color.set(170, 170, 170, 120);
    homeButtonRect.setup(pos, size, color);

    raleigh.loadImage("images/raleigh.jpg");
    sanFran.loadImage("images/SanFran.jpg");
    gainesville.loadImage("images/gainesville.jpg");
    
    ofPoint posTwo;
    posTwo.set(50, 50);
    size.set(625, 75);
    mathButton.setup(posTwo, size, offSet, "Example #1", color);

    ofPoint posThree;
    posThree.set(50, 150);
    size.set(625, 75);
    scienceButton.setup(posThree, size, offSet, "Example #2", color);

    ofPoint posFour;
    posFour.set(50, 250);
    size.set(625, 75);
    historyButton.setup(posFour, size, offSet, "Example #3", color);

    ofPoint posFive;
    posFive.set(50, 350);
    size.set(625, 75);
    mathAgainButton.setup(posFive, size, offSet, "Example #4", color);

    
    navStateToc = true;
    navStateExerciseOne = false;
    navStateExerciseTwo = false;
    navStateExerciseThree = false;
    navStateExerciseFour = false;
    
    printf(" NAV setup ended \n");
    
}
		 
//------------------------------------------------------------------
void nav::update() {

    //depending on the selection made, a specific setup is run
    //when returning to TOC from monster, monster is reset

//    printf(" NAV update started \n");
    
    if (mathButton.selected) {
        mathExercisesOne = new problemMathOne();
        navStateToc = false;
        navStateExerciseOne = true;
        navStateExerciseTwo = false;
        navStateExerciseThree = false;
        navStateExerciseFour = false;
        mathButton.selected=false;
    }

    if (scienceButton.selected) {
        mathExercisesTwo = new problemMathTwo();
        navStateToc = false;
        navStateExerciseOne = false;
        navStateExerciseTwo = true;
        navStateExerciseThree = false;
        navStateExerciseFour = false;
        scienceButton.selected=false;
    }

    if (historyButton.selected) {
        mathExercisesThree = new problemMathThree();
        navStateToc = false;
        navStateExerciseOne = false;
        navStateExerciseTwo = false;
        navStateExerciseThree = true;
        navStateExerciseFour = false;
        historyButton.selected=false;
    }

    if (mathAgainButton.selected) {
        mathExercisesFour = new problemMathFour();
        navStateToc = false;
        navStateExerciseOne = false;
        navStateExerciseTwo = false;
        navStateExerciseThree = false;
        navStateExerciseFour = true;
        mathAgainButton.selected=false;
    }

    
    if (homeButtonRect.selected) {
        
        if (navStateExerciseOne) {
            navStateExerciseOne = false;
            navStateToc = true;
            delete mathExercisesOne;
            homeButtonRect.selected=false;
        }

        if (navStateExerciseTwo) {
            navStateExerciseTwo = false;
            navStateToc = true;
            delete mathExercisesTwo;
            homeButtonRect.selected=false;
        }

        if (navStateExerciseThree) {
            navStateExerciseThree = false;
            navStateToc = true;
            delete mathExercisesThree;
            homeButtonRect.selected=false;
        }

        if (navStateExerciseFour) {
            navStateExerciseFour = false;
            navStateToc = true;
            delete mathExercisesFour;
            homeButtonRect.selected=false;
        }

    
    }

    //based on what state is active, update information is passed
    if (navStateExerciseOne) mathExercisesOne->update();
    if (navStateExerciseTwo) mathExercisesTwo->update();
    if (navStateExerciseThree) mathExercisesThree->update();
    if (navStateExerciseFour) mathExercisesFour->update();
    
//    printf(" NAV udpate ended \n");
    
}


//------------------------------------------------------------------
void nav::draw(ofTrueTypeFont& basicFont) {

    if (navStateToc) {
        mathButton.draw(basicFont, raleigh);
        scienceButton.draw(basicFont, sanFran);
        historyButton.draw(basicFont, gainesville);
        mathAgainButton.draw(basicFont, raleigh);
    }

    if (navStateExerciseOne) {
        mathExercisesOne->draw(basicFont);
        homeButtonRect.draw(basicFont);
        
        ofEnableAlphaBlending();
            homeButton.draw(10, 10);
        ofDisableAlphaBlending();
    }

    if (navStateExerciseTwo) {
        mathExercisesTwo->draw(basicFont);
        homeButtonRect.draw(basicFont);
        
        ofEnableAlphaBlending();
        homeButton.draw(10, 10);
        ofDisableAlphaBlending();
    }

    if (navStateExerciseThree) {
        mathExercisesThree->draw(basicFont);
        homeButtonRect.draw(basicFont);
        
        ofEnableAlphaBlending();
        homeButton.draw(10, 10);
        ofDisableAlphaBlending();
    }

    if (navStateExerciseFour) {
        mathExercisesFour->draw(basicFont);
        homeButtonRect.draw(basicFont);
        
        ofEnableAlphaBlending();
        homeButton.draw(10, 10);
        ofDisableAlphaBlending();
    }

}

//------------------------------------------------------------------
void nav::touchingDown(ofTouchEventArgs &touch) {
    
    if (navStateToc) {
        mathButton.touchingDown(touch);
        scienceButton.touchingDown(touch);
        historyButton.touchingDown(touch);
        mathAgainButton.touchingDown(touch);
    }
    
    if (navStateExerciseOne) {
        mathExercisesOne->touchingDown(touch);
        homeButtonRect.touchingDown(touch);
    }

    if (navStateExerciseTwo) {
        mathExercisesTwo->touchingDown(touch);
        homeButtonRect.touchingDown(touch);
    }

    if (navStateExerciseThree) {
        mathExercisesThree->touchingDown(touch);
        homeButtonRect.touchingDown(touch);
    }

    if (navStateExerciseFour) {
        mathExercisesFour->touchingDown(touch);
        homeButtonRect.touchingDown(touch);
    }

}

//------------------------------------------------------------------
void nav::touchingMove(ofTouchEventArgs &touch) {
    if (navStateToc) {
        mathButton.touchingMove(touch);
        scienceButton.touchingMove(touch);
        historyButton.touchingMove(touch);
        mathAgainButton.touchingMove(touch);
    }
    
    if (navStateExerciseOne) {
        mathExercisesOne->touchingMove(touch);
        homeButtonRect.touchingMove(touch);
    }

    if (navStateExerciseTwo) {
        mathExercisesTwo->touchingMove(touch);
        homeButtonRect.touchingMove(touch);
    }

    if (navStateExerciseThree) {
        mathExercisesThree->touchingMove(touch);
        homeButtonRect.touchingMove(touch);
    }

    if (navStateExerciseFour) {
        mathExercisesFour->touchingMove(touch);
        homeButtonRect.touchingMove(touch);
    }

}

//------------------------------------------------------------------
void nav::touchingUp(ofTouchEventArgs &touch) {

    if (navStateToc) {
        mathButton.touchingUp(touch);
        scienceButton.touchingUp(touch);
        historyButton.touchingUp(touch);
        mathAgainButton.touchingUp(touch);
    }
    
    if (navStateExerciseOne) {
        mathExercisesOne->touchingUp(touch);
        homeButtonRect.touchingUp(touch);
    }

    if (navStateExerciseTwo) {
        mathExercisesTwo->touchingUp(touch);
        homeButtonRect.touchingUp(touch);
    }

    if (navStateExerciseThree) {
        mathExercisesThree->touchingUp(touch);
        homeButtonRect.touchingUp(touch);
    }

    if (navStateExerciseFour) {
        mathExercisesFour->touchingUp(touch);
        homeButtonRect.touchingUp(touch);
    }

}

//------------------------------------------------------------------
void nav::doubleTap(ofTouchEventArgs &touch) {
    
}


