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
    
    color.set(170, 170, 170);
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
    posThree.set(50, 250);
    size.set(625, 75);
    historyButton.setup(posThree, size, offSet, "Example #3", color);
    
    navStateToc = true;
    navStateExercises = false;

    printf(" NAV setup ended \n");
    
}
		 
//------------------------------------------------------------------
void nav::update() {

    //depending on the selection made, a specific setup is run
    //when returning to TOC from monster, monster is reset

//    printf(" NAV update started \n");
    
    if (mathButton.selected) {
        mathExercises = new exercisesMath();
        navStateToc = false;
        navStateExercises = true;
        mathButton.selected=false;
    }

    if (scienceButton.selected) {
        mathExercises = new exercisesMath();
        navStateToc = false;
        navStateExercises = true;
        scienceButton.selected=false;
    }

    if (historyButton.selected) {
        mathExercises = new exercisesMath();
        navStateToc = false;
        navStateExercises = true;
        historyButton.selected=false;
    }

    
    if (homeButtonRect.selected) {
        
        if (navStateExercises) {
            navStateExercises = false;
            navStateToc = true;
            delete mathExercises;
            homeButtonRect.selected=false;
        }
    }

    //based on what state is active, update information is passed
    if (navStateExercises) {
        mathExercises->update();
    }
    
//    printf(" NAV udpate ended \n");
    
}


//------------------------------------------------------------------
void nav::draw(ofTrueTypeFont& basicFont) {

    if (navStateToc) {
        mathButton.draw(basicFont, raleigh);
        scienceButton.draw(basicFont, sanFran);
        historyButton.draw(basicFont, gainesville);
    }

    if (navStateExercises) {
        mathExercises->draw(basicFont);
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
    }
    
    if (navStateExercises) {
        mathExercises->touchingDown(touch);
        homeButtonRect.touchingDown(touch);
    }
    
}

//------------------------------------------------------------------
void nav::touchingMove(ofTouchEventArgs &touch) {
    if (navStateToc) {
        mathButton.touchingMove(touch);
        scienceButton.touchingMove(touch);
        historyButton.touchingMove(touch);
    }
    
    if (navStateExercises) {
        mathExercises->touchingMove(touch);
        homeButtonRect.touchingMove(touch);
    }

}

//------------------------------------------------------------------
void nav::touchingUp(ofTouchEventArgs &touch) {

    if (navStateToc) {
        mathButton.touchingUp(touch);
        scienceButton.touchingUp(touch);
        historyButton.touchingUp(touch);
    }
    
    if (navStateExercises) {
        mathExercises->touchingUp(touch);
        homeButtonRect.touchingUp(touch);
    }
    
}

//------------------------------------------------------------------
void nav::doubleTap(ofTouchEventArgs &touch) {
    
}


