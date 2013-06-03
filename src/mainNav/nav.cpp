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
    home.loadImage("images/ui/glyphicons_020_home.png");
    
    pos.set(0, 0);
    size.set(home.getWidth()+20, home.getHeight()+20);
    offSet.set(25, 40);
    
    color.set(170, 170, 170, 120);
    homeButton.setup(pos, size, color);

    raleigh.loadImage("images/raleigh.jpg");
    sanFran.loadImage("images/SanFran.jpg");
    gainesville.loadImage("images/gainesville.jpg");
    
    //skip intro button
    skipIntro.loadImage("images/ui/glyphicons_207_remove_2.png");
    pos.set(ofGetWidth()-(skipIntro.getWidth()+20), 0);
    skipIntroButton.setup(pos, size, color);    
    
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

    splash = new splashNav;
    
    navStateSplash = true;
    navStateToc = false;
    navStateExerciseOne = false;
    navStateExerciseTwo = false;
    navStateExerciseThree = false;
    navStateExerciseFour = false;
    
    printf(" NAV setup ended \n");
    
}
		 
//------------------------------------------------------------------
void nav::update(int section) {

    //depending on the selection made, a specific setup is run
    //when returning to TOC from monster, monster is reset

//    printf(" NAV update started \n");

    if (skipIntroButton.selected) {
        navStateSplash = false;
        navStateToc = true;
        delete splash;
        skipIntroButton.selected=false;
    }
    
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

        if (navStateExerciseFour) {
            navStateExerciseFour = false;
            navStateToc = true;
            delete mathExercisesFour;
            homeButton.selected=false;
        }

    
    }

    //based on what state is active, update information is passed
    if (navStateSplash) splash->update(section);
    if (navStateExerciseOne) mathExercisesOne->update();
    if (navStateExerciseTwo) mathExercisesTwo->update();
    if (navStateExerciseThree) mathExercisesThree->update();
    if (navStateExerciseFour) mathExercisesFour->update();
    
//    printf(" NAV udpate ended \n");
    
}


//------------------------------------------------------------------
void nav::draw(ofTrueTypeFont& basicFont) {

    if (navStateSplash) {
        splash->draw();
        skipIntroButton.draw(basicFont);
        
        ofEnableAlphaBlending();
        skipIntro.draw(ofGetWidth()-(skipIntro.getWidth()+10), 15);
        ofDisableAlphaBlending();

    }
    
    if (navStateToc) {
        mathButton.draw(basicFont, raleigh);
        scienceButton.draw(basicFont, sanFran);
        historyButton.draw(basicFont, gainesville);
        mathAgainButton.draw(basicFont, raleigh);
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

    if (navStateExerciseFour) {
        mathExercisesFour->draw(basicFont);
        homeButton.draw(basicFont);
        
        ofEnableAlphaBlending();
        home.draw(10, 10);
        ofDisableAlphaBlending();
    }

}

//------------------------------------------------------------------
void nav::touchingDown(ofTouchEventArgs &touch) {
    
    if (navStateSplash) skipIntroButton.touchingDown(touch);
    
    if (navStateToc) {
        mathButton.touchingDown(touch);
        scienceButton.touchingDown(touch);
        historyButton.touchingDown(touch);
        mathAgainButton.touchingDown(touch);
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

    if (navStateExerciseFour) {
        mathExercisesFour->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

}

//------------------------------------------------------------------
void nav::touchingMove(ofTouchEventArgs &touch) {
    
    if (navStateSplash) skipIntroButton.touchingMove(touch);
    
    if (navStateToc) {
        mathButton.touchingMove(touch);
        scienceButton.touchingMove(touch);
        historyButton.touchingMove(touch);
        mathAgainButton.touchingMove(touch);
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

    if (navStateExerciseFour) {
        mathExercisesFour->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

}

//------------------------------------------------------------------
void nav::touchingUp(ofTouchEventArgs &touch) {

    if (navStateSplash) skipIntroButton.touchingUp(touch);
    
    if (navStateToc) {
        mathButton.touchingUp(touch);
        scienceButton.touchingUp(touch);
        historyButton.touchingUp(touch);
        mathAgainButton.touchingUp(touch);
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

    if (navStateExerciseFour) {
        mathExercisesFour->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

}

//------------------------------------------------------------------
void nav::doubleTap(ofTouchEventArgs &touch) {
    
}


