/*
 *  nav.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#include "nav.h"




////////////////////////////////////////////////////////////////////
//      SET UP                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void nav::setup(string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo) {

//    printf(" NAV setup started \n");
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    ofColor textColor;
    ofColor colorTwo;
    homeImageOne.loadImage("images/ui/Home_Low.png");
    homeImageTwo.loadImage("images/ui/Home_Low_bw.png");
    
    
    pos.set(0, 0);
    size.set(ofGetWidth(), 50);
    offSet.set(450, 35);
    color.set(124, 191, 85, 255);
    textColor.set(222, 220, 217, 255);
    welcomeButton.setup(pos, size, offSet, "welcome!", colorTwo, color, textColor, textColor);
    
    pos.set(15, 15);
    size.set(homeImageOne.getWidth(), homeImageOne.getHeight());
    offSet.set(0,0);
    color.set(255, 255, 255, 255);
    homeButton.setup(pos, size, color, homeImageOne, homeImageTwo, offSet);
    
    
    //skip intro button
    pos.set(831, 10);
    size.set(180, 40);
    color.set(255, 255, 255, 10);
    colorTwo.set(255, 0, 0,100);
    skipIntroButton.setup(pos, size, offSet, "", colorTwo, color, textColor, textColor);
    
    pos.set(293, 361);
    size.set(144, 44);
    color.set(255, 255, 255, 0);
    skipIntroTwoButton.setup(pos, size, offSet, "", colorTwo, color, textColor, textColor);
    
    
    textColor.set(86, 86, 86, 255);
    
    
    //-----------------------------------------------
    //for math button id's
    
    startColor.set(96, 200, 84, 255);
    startString = "start";
    startOffset.set(40, 35);
    
    continueColor.set(57, 140, 209, 255);
    continueString = "continue";
    continueOffset.set(10, 35);
    
    viewColor.set(255, 216, 64, 255);
    viewString = "view";
    viewOffset.set(44, 35);


    //-----------------------------------------------
    //submit user name
    
    ofImage saveItOne;
    ofImage saveItTwo;
    saveItOne.loadImage("images/ui/Save_Low.png");
    saveItTwo.loadImage("images/ui/Save_Low.png");
    
    pos.set(185, 683);
    size.set(saveItOne.getWidth(), saveItOne.getHeight());
    color.set(200, 200, 200);
    offSet.set(0, 0);
    
//    submitUserNameButton.setup(pos, size, color, saveItOne, saveItTwo, offSet);
    
    //view problem new
    pos.set(600, 100);
    size.set(150, 50);
    color.set(96, 200, 84, 255);
    colorTwo.set(255, 0, 0, 200);
//    startUserNameButton.setup(pos, size, offSet, "not you? set user name", colorTwo, color, textColor, textColor);

    
    
    ofPoint posOne;
    posOne.set(625, 130);
    offSet.set(40, 35);  //THIS OFFSETS THE TEXT!!!

    //view problem new
    size.set(150, 50);
    color.set(96, 200, 84, 255);
    colorTwo.set(255, 0, 0, 200);
    mathOneButton.setup(posOne, size, offSet, "start", colorTwo, color, textColor, textColor);
    mathOneButton.difficulty = 1;

    posOne.set(625, 230);
    mathTwoButton.setup(posOne, size, offSet, "start", colorTwo, color, textColor, textColor);
    mathTwoButton.difficulty = 2;
    
    posOne.set(625, 330);
    mathThreeButton.setup(posOne, size, offSet, "start", colorTwo, color, textColor, textColor);
    mathThreeButton.difficulty = 2;

    posOne.set(625, 430);
    mathFourButton.setup(posOne, size, offSet, "start", colorTwo, color, textColor, textColor);
    mathFourButton.difficulty = 3;

    posOne.set(625, 530);
    mathFiveButton.setup(posOne, size, offSet, "start", colorTwo, color, textColor, textColor);
    mathFiveButton.difficulty = 3;

    posOne.set(625, 630);
    mathSixButton.setup(posOne, size, offSet, "start", colorTwo, color, textColor, textColor);
    mathSixButton.difficulty = 0;
    
    color.set(159, 159, 159);
    greyStartButton.setup(posOne, size, offSet, "start", colorTwo, color, textColor, textColor);
    

    //setting XML data and stage values
    mathOneButton.XMLFileOne = "myCreateProbOne.xml";
    mathOneButton.XMLFileTwo = "myReflectProbOne.xml";
    mathOneButton.myCreateProbRefresh = "myCreateProbOne.xml";
    mathOneButton.myReflectProbRefresh = "myReflectProbOne.xml";
    mathOneButton.stage         = theXMLParty.getXMLStage(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathOneButton);
    mathOneButton.problemText   = theXMLParty.getXMLString(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathOneButton);
    
    //setting XML data and stage values
    mathTwoButton.XMLFileOne = "myCreateProbTwo.xml";
    mathTwoButton.XMLFileTwo = "myReflectProbTwo.xml";
    mathTwoButton.myCreateProbRefresh = "myCreateProbTwo.xml";
    mathTwoButton.myReflectProbRefresh = "myReflectProbTwo.xml";
    mathTwoButton.stage      = theXMLParty.getXMLStage(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathTwoButton);
    mathTwoButton.problemText   = theXMLParty.getXMLString(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathTwoButton);
    
    //setting XML data and stage values
    mathThreeButton.XMLFileOne = "myCreateProbThree.xml";
    mathThreeButton.XMLFileTwo = "myReflectProbThree.xml";
    mathThreeButton.myCreateProbRefresh = "myCreateProbThree.xml";
    mathThreeButton.myReflectProbRefresh = "myReflectProbThree.xml";
    mathThreeButton.stage      = theXMLParty.getXMLStage(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathThreeButton);
    mathThreeButton.problemText   = theXMLParty.getXMLString(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathThreeButton);

    //setting XML data and stage values
    mathFourButton.XMLFileOne = "myCreateProbFour.xml";
    mathFourButton.XMLFileTwo = "myReflectProbFour.xml";
    mathFourButton.myCreateProbRefresh = "myCreateProbFour.xml";
    mathFourButton.myReflectProbRefresh = "myReflectProbFour.xml";
    mathFourButton.stage      = theXMLParty.getXMLStage(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFourButton);
    mathFourButton.problemText   = theXMLParty.getXMLString(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFourButton);

    //setting XML data and stage values
    mathFiveButton.XMLFileOne = "myCreateProbFive.xml";
    mathFiveButton.XMLFileTwo = "myReflectProbFive.xml";
    mathFiveButton.myCreateProbRefresh = "myCreateProbFive.xml";
    mathFiveButton.myReflectProbRefresh = "myReflectProbFive.xml";
    mathFiveButton.stage      = theXMLParty.getXMLStage(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFiveButton);
    mathFiveButton.problemText   = theXMLParty.getXMLString(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFiveButton);

    //setting XML data and stage values
    mathSixButton.XMLFileOne = "myCreateProbSix.xml";
    mathSixButton.XMLFileTwo = "myReflectProbSix.xml";
    mathSixButton.myCreateProbRefresh = "myCreateProbSix.xml";
    mathSixButton.myReflectProbRefresh = "myReflectProbSix.xml";
    mathSixButton.stage      = theXMLParty.getXMLStage(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathSixButton);
    mathSixButton.problemText   = theXMLParty.getXMLString(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathSixButton);
    
    if (mathSixButton.stage == 2) greyStartButton.toggle = true;
    
    
//    printf("mathOneButton Stage = %d \n", mathOneButton.stage);
//    printf("mathTwoButton Stage = %d \n", mathTwoButton.stage);
//    printf("mathThreeButton Stage = %d \n", mathThreeButton.stage);
//    printf("mathFourButton Stage = %d \n", mathFourButton.stage);
//    printf("mathFiveButton Stage = %d \n", mathFiveButton.stage);
//    printf("mathSixButton Stage = %d \n", mathSixButton.stage);
    
    if (mathOneButton.stage == 0) mathOneButton.update(startColor, startString, startOffset);
    if (mathOneButton.stage == 1) mathOneButton.update(startColor, startString, startOffset);
    if (mathOneButton.stage == 2) mathOneButton.update(viewColor, viewString, viewOffset);
    
    if (mathTwoButton.stage == 0) mathTwoButton.update(startColor, startString, startOffset);
    if (mathTwoButton.stage == 1) mathTwoButton.update(startColor, startString, startOffset);
    if (mathTwoButton.stage == 2) mathTwoButton.update(viewColor, viewString, viewOffset);
    
    if (mathThreeButton.stage == 0) mathThreeButton.update(startColor, startString, startOffset);
    if (mathThreeButton.stage == 1) mathThreeButton.update(startColor, startString, startOffset);
    if (mathThreeButton.stage == 2) mathThreeButton.update(viewColor, viewString, viewOffset);
    
    if (mathFourButton.stage == 0) mathFourButton.update(startColor, startString, startOffset);
    if (mathFourButton.stage == 1) mathFourButton.update(startColor, startString, startOffset);
    if (mathFourButton.stage == 2) mathFourButton.update(viewColor, viewString, viewOffset);
    
    if (mathFiveButton.stage == 0) mathFiveButton.update(startColor, startString, startOffset);
    if (mathFiveButton.stage == 1) mathFiveButton.update(startColor, startString, startOffset);
    if (mathFiveButton.stage == 2) mathFiveButton.update(viewColor, viewString, viewOffset);
    
    if (mathSixButton.stage == 0) mathSixButton.update(startColor, startString, startOffset);
    if (mathSixButton.stage == 1) mathSixButton.update(startColor, startString, startOffset);
    if (mathSixButton.stage == 2) mathSixButton.update(viewColor, viewString, viewOffset);

    
    
    
//    mathOneButton.problemText = "Four birds live in different parts of the forest. Amelia does not live near the water. Wendy has fear of heights. Phylis likes to watch the sunrise across the lake. Amelia and Phylis always go to Ann's to watch TV. Determine which part of the forest each bird lives in.";
//    mathTwoButton.problemText = "Balloons are 1 each, but for every 3 you buy, 1 deflates upon leaving the store.  How many balloons do you need to buy to insure you have enough for each of your 100 guests?";
//    mathThreeButton.problemText = "I want to buy 10 items for 99 cents, but all I have are quarters.  How many quarters do I need to buy my items?  How much change do I receive?";
//    mathFourButton.problemText = "Make a row of squares with toothpicks. Count both the number of toothpicks and number of squares.  Describe the relationship. If someone asked for 35 squares, how many toothpicks do you need?";
//    mathFiveButton.problemText = "A new music service opens, and it costs a dollar for the first song and 25 cents for each song after.  The album you want has 13 songs. How much will it cost?";
//    mathSixButton.problemText = "You may input your custom problem here. Type or paste your question in the text field and click 'Return' to save.";
//    

    
    color.set(255, 255, 255, 120);


    splash = new splashNav;
//    theUserName = new userName;
    
    //to include splash, make navStateSplash true and navStateTOC false.
    navStateSplash = true;
//    navStateUserName = false;
    
    navStateToc = false;
    navStateMathOne = false;
    navStateMathTwo = false;
    navStateMathThree = false;
    navStateMathFour = false;
    navStateMathFive = false;
    navStateMathSix = false;
    navStateSavedMathOne = false;
    navStateSavedMathTwo = false;
    navStateSavedMathThree = false;
    navStateSavedMathFour = false;
    navStateSavedMathFive = false;
    navStateSavedMathSix = false;
    
    
    ofPoint posSix;
    size.set(200, 200);
    posSix.set(ofGetWidth()/2-(size.x/2), ofGetHeight()/2-(size.x/2));
    color.set(230, 230, 230, 245);
    offSet.set(58, 100);
    loadingFeedback.setup(posSix, size, offSet, "Loading...", colorTwo, color, textColor, textColor);
    loading = false;
    counter = 0;
    
    
    
    //Metics and FAQ Button
    
    editImage.loadImage("images/ui/edit@Low.png");
    FAQ.loadImage("images/faq/FAQ_home_Low.png");
    metrics.loadImage("images/faq/mockup_metrics_comingsoon.png");
    
    
    ofImage    questionImageOne;
    ofImage    questionImageTwo;
    ofImage    metricsImageOne;
    ofImage    metricsImageTwo;

    questionImageOne.loadImage("images/ui/FAQ_Low.png");
    questionImageTwo.loadImage("images/ui/FAQ_Low_bw.png");
    metricsImageOne.loadImage("images/ui/metrics@Low.png");
    metricsImageTwo.loadImage("images/ui/metrics_b&w@Low.png");

    
    //-----------------------------------------------
    //for question button
    size.set(questionImageOne.getWidth(), questionImageOne.getHeight());
    pos.set(ofGetWidth()-85, 15);
    offSet.set(0, 0);
    color.set(230, 230, 230, 245);
    questionButton.setup(pos, size, color, questionImageOne, questionImageTwo, offSet);

    
    //-----------------------------------------------
    //for metrics button
    size.set(metricsImageOne.getWidth(), metricsImageOne.getHeight());
    pos.set(ofGetWidth()-170, 15);
    offSet.set(0, 0);
    color.set(230, 230, 230, 245);
    metricsButton.setup(pos, size, color, metricsImageOne, metricsImageTwo, offSet);


    pos.set(15, 15);
    size.set(homeImageOne.getWidth(), homeImageOne.getHeight());
    offSet.set(0,0);
    color.set(255, 255, 255, 255);
    metricsButton2.setup(pos, size, color, homeImageOne, homeImageTwo, offSet);

    
    //-----------------------------------------------
    //Stars

    starNormal.loadImage("images/ui/Star_Low.png");
    starBlackWhite.loadImage("images/ui/Star_Low_bw.png");
    
    
    //-----------------------------------------------
    //for ftp buttons

//    ofImage    ftpImageOne;
//    ofImage    ftpImageTwo;
//    ftpImageOne.loadImage("images/ui/Share_Low.png");
//    ftpImageTwo.loadImage("images/ui/Share_Low_bw.png");
//    
//    size.set(ftpImageOne.getWidth(), ftpImageOne.getHeight());
//    pos.set(800, 133);
//    offSet.set(0, 0);
//    color.set(230, 230, 230, 245);
//    sendMathOneButton.setup(pos, size, color, ftpImageOne, ftpImageTwo, offSet);
//
//    pos.set(800, 233);
//    sendMathTwoButton.setup(pos, size, color, ftpImageOne, ftpImageTwo, offSet);
//
//    pos.set(800, 333);
//    sendMathThreeButton.setup(pos, size, color, ftpImageOne, ftpImageTwo, offSet);
//
//    pos.set(800, 433);
//    sendMathFourButton.setup(pos, size, color, ftpImageOne, ftpImageTwo, offSet);
//
//    pos.set(800, 533);
//    sendMathFiveButton.setup(pos, size, color, ftpImageOne, ftpImageTwo, offSet);
//
//    pos.set(800, 633);
//    sendMathSixButton.setup(pos, size, color, ftpImageOne, ftpImageTwo, offSet);

    
    //-----------------------------------------------
    //for reset buttons
    
    ofImage    resetImageOne;
    ofImage    resetImageTwo;
    resetImageOne.loadImage("images/ui/Reset_Low.png");
    resetImageTwo.loadImage("images/ui/Reset_Low.png");
    
    greyRefresh.loadImage("images/ui/Reset_Low_bw.png");
    
    size.set(resetImageOne.getWidth(), resetImageTwo.getHeight());
    pos.set(850, 133);
    offSet.set(0, 0);
    color.set(230, 230, 230, 245);
    resetMathOneButton.setup(pos, size, color, resetImageOne, resetImageTwo, offSet);

    pos.set(850, 233);
    resetMathTwoButton.setup(pos, size, color, resetImageOne, resetImageTwo, offSet);
    
    pos.set(850, 333);
    resetMathThreeButton.setup(pos, size, color, resetImageOne, resetImageTwo, offSet);
    
    pos.set(850, 433);
    resetMathFourButton.setup(pos, size, color, resetImageOne, resetImageTwo, offSet);
    
    pos.set(850, 533);
    resetMathFiveButton.setup(pos, size, color, resetImageOne, resetImageTwo, offSet);
    
    pos.set(850, 633);
    resetMathSixButton.setup(pos, size, color, resetImageOne, resetImageTwo, offSet);
    
    //    printf(" NAV setup ended \n");
    
    

//    theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathOneButton, resetMathOneButton);
//    mathOneButton.update(startColor, startString, startOffset);
//
//    theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathTwoButton, resetMathTwoButton);
//    mathTwoButton.update(startColor, startString, startOffset);
//    
//    theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathThreeButton, resetMathThreeButton);
//    mathThreeButton.update(startColor, startString, startOffset);
//
//    theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFourButton, resetMathFourButton);
//    mathFourButton.update(startColor, startString, startOffset);
//    
//    theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFiveButton, resetMathFiveButton);
//    mathFiveButton.update(startColor, startString, startOffset);
//    
//    theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathSixButton, resetMathSixButton);
//    mathSixButton.update(startColor, startString, startOffset);
    
}



////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void nav::update(int section, string iOSDocumentsDirectory, ofxXmlSettings& _XMLOne, ofxXmlSettings& _XMLTwo, ofPoint _currentLocation, ofPoint speed, bool panning, ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36) {

    //depending on the selection made, a specific setup is run
    //when returning to TOC from monster, monster is reset

//    printf(" NAV update started \n");

    if (skipIntroButton.selected) {
        navStateSplash          = false;
        navStateToc             = true;
        delete splash;
        skipIntroButton.selected=false;
    }

    if (skipIntroTwoButton.selected) {
        navStateSplash          = false;
        navStateToc             = true;
        delete splash;
        skipIntroTwoButton.selected=false;
    }
    
//    if (submitUserNameButton.selected) {
//        navStateUserName        = false;
//        navStateSplash          = false;
//        navStateToc             = true;
//        delete theUserName;
//        
//        submitUserNameButton.selected = false;
//    }
    
    if (mathOneButton.selected) {
        
        if (mathOneButton.stage < 2) {
            mathOne = new problemMath(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathOneButton, quicksandBold60, quicksandBold36, quicksandBook36);
            
            string grid = "images/grid.png";
            mathOne->loadImage(grid);
            
            navStateToc             = false;
            navStateMathOne         = true;
            navStateMathTwo         = false;
            navStateMathThree       = false;
            navStateMathFour        = false;
            navStateMathFive        = false;
            navStateMathSix         = false;
            navStateSavedMathOne    = false;
            navStateSavedMathTwo    = false;
            navStateSavedMathThree  = false;
            navStateSavedMathFour   = false;
            navStateSavedMathFive   = false;
            navStateSavedMathSix    = false;
            navStateNewTextMathSix  = false;
            mathOneButton.selected  = false;

        } else {
            
            loading = true;
            counter++;
            //        printf("counter: %d \n", counter);
            //        printf("saving: %d \n", loading);
            
            if (counter > 1) {
                
                savedMathOne = new saveMath(iOSDocumentsDirectory, mathOneButton, quicksandBold60, quicksandBold36, quicksandBook36);
                
                string grid = "images/grid.png";
                savedMathOne->loadImage(grid);
                
                navStateToc             = false;
                navStateMathOne         = false;
                navStateMathTwo         = false;
                navStateMathThree       = false;
                navStateMathFour        = false;
                navStateMathFive        = false;
                navStateMathSix         = false;
                navStateSavedMathOne    = true;
                navStateSavedMathTwo    = false;
                navStateSavedMathThree  = false;
                navStateSavedMathFour   = false;
                navStateSavedMathFive   = false;
                navStateSavedMathSix    = false;
                navStateNewTextMathSix  = false;
                mathOneButton.selected=false;
                
                loading = false;
                counter = 0;
            }
        }
    }

    
    if (mathTwoButton.selected) {

        if (mathTwoButton.stage < 2) {
        
            mathTwo = new problemMath(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathTwoButton, quicksandBold60, quicksandBold36, quicksandBook36);
            
            navStateToc             = false;
            navStateMathOne         = false;
            navStateMathTwo         = true;
            navStateMathThree       = false;
            navStateMathFour        = false;
            navStateMathFive        = false;
            navStateMathSix         = false;
            navStateSavedMathOne    = false;
            navStateSavedMathTwo    = false;
            navStateSavedMathThree  = false;
            navStateSavedMathFour   = false;
            navStateSavedMathFive   = false;
            navStateSavedMathSix    = false;
            navStateNewTextMathSix  = false;
            mathTwoButton.selected  = false;
        
        } else {
            
            loading = true;
            counter++;
            //        printf("counter: %d \n", counter);
            //        printf("saving: %d \n", loading);
            
            if (counter > 1) {
                
                savedMathTwo = new saveMath(iOSDocumentsDirectory, mathTwoButton, quicksandBold60, quicksandBold36, quicksandBook36);
                
                navStateToc             = false;
                navStateMathOne         = false;
                navStateMathTwo         = false;
                navStateMathThree       = false;
                navStateMathFour        = false;
                navStateMathFive        = false;
                navStateMathSix         = false;
                navStateSavedMathOne    = false;
                navStateSavedMathTwo    = true;
                navStateSavedMathThree  = false;
                navStateSavedMathFour   = false;
                navStateSavedMathFive   = false;
                navStateSavedMathSix    = false;
                navStateNewTextMathSix  = false;
                mathTwoButton.selected=false;
                
                loading = false;
                counter = 0;
                
            }
            
        }
        

    }

    if (mathThreeButton.selected) {
        
        if (mathThreeButton.stage < 2) {
            mathThree = new problemMath(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathThreeButton, quicksandBold60, quicksandBold36, quicksandBook36);

            navStateToc             = false;
            navStateMathOne         = false;
            navStateMathTwo         = false;
            navStateMathThree       = true;
            navStateMathFour        = false;
            navStateMathFive        = false;
            navStateMathSix         = false;
            navStateSavedMathOne    = false;
            navStateSavedMathTwo    = false;
            navStateSavedMathThree  = false;
            navStateSavedMathFour   = false;
            navStateSavedMathFive   = false;
            navStateSavedMathSix    = false;
            navStateNewTextMathSix  = false;
            mathThreeButton.selected= false;

        } else {
            loading = true;
            counter++;
            //        printf("counter: %d \n", counter);
            //        printf("saving: %d \n", loading);
            
            if (counter > 1) {
                
                savedMathThree = new saveMath(iOSDocumentsDirectory, mathThreeButton, quicksandBold60, quicksandBold36, quicksandBook36);
                
                navStateToc             = false;
                navStateMathOne         = false;
                navStateMathTwo         = false;
                navStateMathThree       = false;
                navStateMathFour        = false;
                navStateMathFive        = false;
                navStateMathSix         = false;
                navStateSavedMathOne    = false;
                navStateSavedMathTwo    = false;
                navStateSavedMathThree  = true;
                navStateSavedMathFour   = false;
                navStateSavedMathFive   = false;
                navStateSavedMathSix    = false;
                navStateNewTextMathSix  = false;
                mathThreeButton.selected = false;
                
                loading = false;
                counter = 0;
                
            }

        }
    }
    
    

    if (mathFourButton.selected) {
        
        if (mathFourButton.stage < 2) {
            mathFour = new problemMath(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFourButton, quicksandBold60, quicksandBold36, quicksandBook36);
            
            navStateToc             = false;
            navStateMathOne         = false;
            navStateMathTwo         = false;
            navStateMathThree       = false;
            navStateMathFour        = true;
            navStateMathFive        = false;
            navStateMathSix         = false;
            navStateSavedMathOne    = false;
            navStateSavedMathTwo    = false;
            navStateSavedMathThree  = false;
            navStateSavedMathFour   = false;
            navStateSavedMathFive   = false;
            navStateSavedMathSix    = false;
            navStateNewTextMathSix  = false;
            mathFourButton.selected = false;

        } else {
            
            loading = true;
            counter++;
            //        printf("counter: %d \n", counter);
            //        printf("saving: %d \n", loading);
            
            if (counter > 1) {
                
                savedMathFour = new saveMath(iOSDocumentsDirectory, mathFourButton, quicksandBold60, quicksandBold36, quicksandBook36);
                
                navStateToc             = false;
                navStateMathOne         = false;
                navStateMathTwo         = false;
                navStateMathThree       = false;
                navStateMathFour        = false;
                navStateMathFive        = false;
                navStateMathSix         = false;
                navStateSavedMathOne    = false;
                navStateSavedMathTwo    = false;
                navStateSavedMathThree  = false;
                navStateSavedMathFour   = true;
                navStateSavedMathFive   = false;
                navStateSavedMathSix    = false;
                navStateNewTextMathSix  = false;
                mathFourButton.selected = false;
                
                loading = false;
                counter = 0;
                
            }
            
        }
 
    }
    
    if (mathFiveButton.selected) {
        
        if (mathFiveButton.stage < 2) {
            mathFive = new problemMath(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFiveButton, quicksandBold60, quicksandBold36, quicksandBook36);
            
            navStateToc             = false;
            navStateMathOne         = false;
            navStateMathTwo         = false;
            navStateMathThree       = false;
            navStateMathFour        = false;
            navStateMathFive        = true;
            navStateMathSix         = false;
            navStateSavedMathOne    = false;
            navStateSavedMathTwo    = false;
            navStateSavedMathThree  = false;
            navStateSavedMathFour   = false;
            navStateSavedMathFive   = false;
            navStateSavedMathSix    = false;
            navStateNewTextMathSix  = false;
            mathFiveButton.selected = false;

        } else {
            
            loading = true;
            counter++;
            //        printf("counter: %d \n", counter);
            //        printf("saving: %d \n", loading);
            
            if (counter > 1) {
                
                savedMathFive = new saveMath(iOSDocumentsDirectory, mathFiveButton, quicksandBold60, quicksandBold36, quicksandBook36);
                
                navStateToc             = false;
                navStateMathOne         = false;
                navStateMathTwo         = false;
                navStateMathThree       = false;
                navStateMathFour        = false;
                navStateMathFive        = false;
                navStateMathSix         = false;
                navStateSavedMathOne    = false;
                navStateSavedMathTwo    = false;
                navStateSavedMathThree  = false;
                navStateSavedMathFour   = false;
                navStateSavedMathFive   = true;
                navStateSavedMathSix    = false;
                navStateNewTextMathSix  = false;
                mathFiveButton.selected  = false;
                
                loading = false;
                counter = 0;
                
            }
            
        }
    
    }
    
    
    
    if (mathSixButton.selected) {
        
        if (mathSixButton.stage < 2) {
            mathSix = new problemMath(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathSixButton, quicksandBold60, quicksandBold36, quicksandBook36);
            
            navStateToc             = false;
            navStateMathOne         = false;
            navStateMathTwo         = false;
            navStateMathThree       = false;
            navStateMathFour        = false;
            navStateMathFive        = false;
            navStateMathSix         = true;
            navStateSavedMathOne    = false;
            navStateSavedMathTwo    = false;
            navStateSavedMathThree  = false;
            navStateSavedMathFour   = false;
            navStateSavedMathFive   = false;
            navStateSavedMathSix    = false;
            navStateNewTextMathSix  = false;
            mathSixButton.selected  = false;

        } else {
            
            loading = true;
            counter++;
            //        printf("counter: %d \n", counter);
            //        printf("saving: %d \n", loading);
            
            greyStartButton.toggle = true;
            
            if (counter > 1) {
                
                savedMathSix = new saveMath(iOSDocumentsDirectory, mathSixButton, quicksandBold60, quicksandBold36, quicksandBook36);
                
                navStateToc             = false;
                navStateMathOne         = false;
                navStateMathTwo         = false;
                navStateMathThree       = false;
                navStateMathFour        = false;
                navStateMathFive        = false;
                navStateMathSix         = false;
                navStateSavedMathOne    = false;
                navStateSavedMathTwo    = false;
                navStateSavedMathThree  = false;
                navStateSavedMathFour   = false;
                navStateSavedMathFive   = false;
                navStateSavedMathSix    = true;
                navStateNewTextMathSix  = false;
                mathSixButton.selected   = false;
                
                loading = false;
                counter = 0;
                
            }
            
        }
    }

    
    //this is actually a home button that is used only when metrics is on
    if (metricsButton2.selected ) {
        metricsButton.toggle = false;
        metricsButton2.toggle = false;
        metricsButton2.selected = false;
        
    }

    
//    if (sendMathOneButton.selected) {
//        
//        printf("sending mathOne   ");
//        string theFile = mathOneButton.XMLFileOne;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//        theFile = mathOneButton.XMLFileTwo;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//        
//        printf("mathOne sent \n");
//        
//        sendMathOneButton.selected   = false;
//    }
//
//    if (sendMathTwoButton.selected) {
//        
//        printf("sending mathTwo   ");
//        string theFile = mathTwoButton.XMLFileOne;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//        theFile = mathTwoButton.XMLFileTwo;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//        
//        printf("mathTwo sent \n");
//
//        sendMathTwoButton.selected   = false;
//    }
//
//    if (sendMathThreeButton.selected) {
//        
//        printf("sending mathThree   ");
//        string theFile = mathThreeButton.XMLFileOne;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//        theFile = mathThreeButton.XMLFileTwo;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//        
//        printf("mathThree sent \n");
//
//        sendMathThreeButton.selected   = false;
//    }
//
//    if (sendMathFourButton.selected) {
//        
//        printf("sending mathFour   ");
//        string theFile = mathFourButton.XMLFileOne;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//        theFile = mathFourButton.XMLFileTwo;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//        
//        printf("mathFour sent \n");
//
//        sendMathFourButton.selected   = false;
//    }
//    
//    if (sendMathFiveButton.selected) {
//        
//        printf("sending mathFive   ");
//        string theFile = mathFiveButton.XMLFileOne;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//        theFile = mathFiveButton.XMLFileTwo;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//
//        printf("mathFive sent \n");
//
//        sendMathFiveButton.selected   = false;
//    }
//
//    if (sendMathSixButton.selected) {
//        
//        printf("sending mathSix   ");
//        string theFile = mathSixButton.XMLFileOne;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//        theFile = mathSixButton.XMLFileTwo;
//        ftpUpload.uploadFile(iOSDocumentsDirectory, theFile);
//        
//        printf("mathSix sent \n");
//
//        sendMathSixButton.selected   = false;
//    }
//    

    if (resetMathOneButton.selected) {
        
//        printf("resetting mathOne   ");
        
        theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathOneButton, resetMathOneButton);
        mathOneButton.update(startColor, startString, startOffset);
//        printf("reset mathOne done \n");
        
        resetMathOneButton.selected   = false;
    }
    
    if (resetMathTwoButton.selected) {
        
//        printf("resetting mathTwo   ");

        theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathTwoButton, resetMathTwoButton);
        mathTwoButton.update(startColor, startString, startOffset);

//        printf("reset mathTwo done \n");
        
        resetMathTwoButton.selected   = false;
    }
    
    if (resetMathThreeButton.selected) {
        
//        printf("resetting mathThree   ");

        theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathThreeButton, resetMathThreeButton);
        mathThreeButton.update(startColor, startString, startOffset);
        
//        printf("reset mathThree done \n");
        
        resetMathThreeButton.selected   = false;
    }
    
    if (resetMathFourButton.selected) {
        
//        printf("resetting mathFour   ");

        theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFourButton, resetMathFourButton);
        mathFourButton.update(startColor, startString, startOffset);

//        printf("reset mathFour done \n");
        
        resetMathFourButton.selected   = false;
    }
    
    if (resetMathFiveButton.selected) {
        
//        printf("resetting mathFive   ");

        theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFiveButton, resetMathFiveButton);
        mathFiveButton.update(startColor, startString, startOffset);

//        printf("reset mathFive done \n");
        
        resetMathFiveButton.selected   = false;
    }
    
    if (resetMathSixButton.selected) {
        
//        printf("resetting mathSix   ");

        theXMLParty.resetXML(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathSixButton, resetMathSixButton);
        mathSixButton.update(startColor, startString, startOffset);

        printf("reset mathSix done \n");
        
        resetMathSixButton.selected   = false;
    }
    
    if (homeButton.selected) {
        
        homeButton.toggle = false;        
        
        if (navStateMathOne) {
            navStateMathOne = false;
            navStateToc = true;
            delete mathOne;
            
            if (mathOneButton.stage == 0) mathOneButton.update(startColor, startString, startOffset);
            if (mathOneButton.stage == 1) mathOneButton.update(startColor, startString, startOffset);
            //if (mathOneButton.stage == 1) mathOneButton.update(continueColor, continueString, continueOffset);
            if (mathOneButton.stage == 2) mathOneButton.update(viewColor, viewString, viewOffset);
            
            homeButton.selected=false;
        }

        if (navStateMathTwo) {
            navStateMathTwo = false;
            navStateToc = true;
            delete mathTwo;

            if (mathTwoButton.stage == 0) mathTwoButton.update(startColor, startString, startOffset);
            if (mathTwoButton.stage == 1) mathTwoButton.update(startColor, startString, startOffset);
            //if (mathTwoButton.stage == 1) mathTwoButton.update(continueColor, continueString, continueOffset);
            if (mathTwoButton.stage == 2) mathTwoButton.update(viewColor, viewString, viewOffset);
            
            homeButton.selected=false;
        }

        if (navStateMathThree) {
            navStateMathThree = false;
            navStateToc = true;
            delete mathThree;
            
            if (mathThreeButton.stage == 0) mathThreeButton.update(startColor, startString, startOffset);
            if (mathThreeButton.stage == 1) mathThreeButton.update(startColor, startString, startOffset);
//            if (mathThreeButton.stage == 1) mathThreeButton.update(continueColor, continueString, continueOffset);
            if (mathThreeButton.stage == 2) mathThreeButton.update(viewColor, viewString, viewOffset);

            homeButton.selected=false;
        }

        if (navStateMathFour) {
            navStateMathFour = false;
            navStateToc = true;
            delete mathFour;
            
            if (mathFourButton.stage == 0) mathFourButton.update(startColor, startString, startOffset);
            if (mathFourButton.stage == 1) mathFourButton.update(startColor, startString, startOffset);
            //if (mathFourButton.stage == 1) mathFourButton.update(continueColor, continueString, continueOffset);
            if (mathFourButton.stage == 2) mathFourButton.update(viewColor, viewString, viewOffset);

            homeButton.selected=false;
        }

        if (navStateMathFive) {
            navStateMathFive = false;
            navStateToc = true;
            delete mathFive;
            
            if (mathFiveButton.stage == 0) mathFiveButton.update(startColor, startString, startOffset);
            if (mathFiveButton.stage == 1) mathFiveButton.update(startColor, startString, startOffset);
            //if (mathFiveButton.stage == 1) mathFiveButton.update(continueColor, continueString, continueOffset);
            if (mathFiveButton.stage == 2) mathFiveButton.update(viewColor, viewString, viewOffset);

            homeButton.selected=false;
        }

        if (navStateMathSix) {
            navStateMathSix = false;
            navStateToc = true;
            delete mathSix;
            
            if (mathSixButton.stage == 0) mathSixButton.update(startColor, startString, startOffset);
            if (mathSixButton.stage == 1) mathSixButton.update(startColor, startString, startOffset);
            //if (mathSixButton.stage == 1) mathSixButton.update(continueColor, continueString, continueOffset);
            if (mathSixButton.stage == 2) mathSixButton.update(viewColor, viewString, viewOffset);

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

        if (navStateSavedMathFour) {
            navStateSavedMathFour = false;
            navStateToc = true;
            delete savedMathFour;
            homeButton.selected=false;
        }

        if (navStateSavedMathFive) {
            navStateSavedMathFive = false;
            navStateToc = true;
            delete savedMathFive;
            homeButton.selected=false;
        }

        if (navStateSavedMathSix) {
            navStateSavedMathSix = false;
            navStateToc = true;
            delete savedMathSix;
            homeButton.selected=false;
        }
    }
    
    
    //based on what state is active, update information is passed
    if (navStateSplash) {
        splash->update(section, panning, _currentLocation);
        
        ofPoint newLocationOne;
        ofPoint newLocationTwo;
        newLocationOne.set(831, 10);
        newLocationTwo.set(293, 361);
        
        skipIntroButton.update(splash->splashPageTwo.pos+newLocationOne);
        skipIntroTwoButton.update(splash->locationF+newLocationTwo);
    }
    
    if (navStateMathOne) mathOne->update(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathOneButton, _currentLocation, speed, panning);
    if (navStateMathTwo) mathTwo->update(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathTwoButton, _currentLocation, speed, panning);
    if (navStateMathThree) mathThree->update(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathThreeButton, _currentLocation, speed, panning);
    if (navStateMathFour) mathFour->update(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFourButton, _currentLocation, speed, panning);
    if (navStateMathFive) mathFive->update(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathFiveButton, _currentLocation, speed, panning);
    if (navStateMathSix) mathSix->update(iOSDocumentsDirectory, _XMLOne, _XMLTwo, mathSixButton, _currentLocation, speed, panning);

    if (navStateSavedMathOne) savedMathOne->update();
    if (navStateSavedMathTwo) savedMathTwo->update();
    if (navStateSavedMathThree) savedMathThree->update();
    if (navStateSavedMathFour) savedMathFour->update();
    if (navStateSavedMathFive) savedMathFive->update();
    if (navStateSavedMathSix) savedMathSix->update();
    
//    printf(" NAV udpate ended \n");
    
}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void nav::draw(ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36) {
    
    if (navStateSplash) {
        splash->draw();
        skipIntroButton.drawTwoColorsRounded(quicksandBook36);
        skipIntroTwoButton.drawTwoColorsRounded(quicksandBold36);
    }
    
    
//    if (navStateUserName)   theUserName->draw();
    
    if (navStateToc) {

        //shaded background
        ofSetColor(86, 86, 86);
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
        ofSetColor(255,255,255);
        
        //-----------------------------------------------
        //Button UI

        welcomeButton.drawTwoColors(quicksandBold60);
        ofEnableAlphaBlending();
        homeImageOne.draw(15, 15);
        ofDisableAlphaBlending();
        
//        startUserNameButton.drawTwoColors(quicksandBold60);
        
        mathOneButton.drawTwoColorsRounded(quicksandBold60);
        mathTwoButton.drawTwoColorsRounded(quicksandBold60);
        mathThreeButton.drawTwoColorsRounded(quicksandBold60);
        mathFourButton.drawTwoColorsRounded(quicksandBold60);
        mathFiveButton.drawTwoColorsRounded(quicksandBold60);
        mathSixButton.drawTwoColorsRounded(quicksandBold60);
        
        if (greyStartButton.toggle == false) {
            greyStartButton.drawTwoColorsRounded(quicksandBold60);
        }
        
//        if (mathOneButton.stage == 2) sendMathOneButton.drawTwoImages();
//        if (mathTwoButton.stage == 2) sendMathTwoButton.drawTwoImages();
//        if (mathThreeButton.stage == 2) sendMathThreeButton.drawTwoImages();
//        if (mathFourButton.stage == 2) sendMathFourButton.drawTwoImages();
//        if (mathFiveButton.stage == 2) sendMathFiveButton.drawTwoImages();
//        if (mathSixButton.stage == 2) sendMathSixButton.drawTwoImages();

        ofEnableAlphaBlending();
        ofSetColor(255);
        if (mathOneButton.stage < 2) greyRefresh.draw(850, 133);
        if (mathTwoButton.stage < 2) greyRefresh.draw(850, 233);
        if (mathThreeButton.stage < 2) greyRefresh.draw(850, 333);
        if (mathFourButton.stage < 2) greyRefresh.draw(850, 433);
        if (mathFiveButton.stage < 2) greyRefresh.draw(850, 533);
        if (mathSixButton.stage < 2) greyRefresh.draw(850, 633);
        ofDisableAlphaBlending();
        
        if (mathOneButton.stage == 2) resetMathOneButton.drawTwoImages();
        if (mathTwoButton.stage == 2) resetMathTwoButton.drawTwoImages();
        if (mathThreeButton.stage == 2) resetMathThreeButton.drawTwoImages();
        if (mathFourButton.stage == 2) resetMathFourButton.drawTwoImages();
        if (mathFiveButton.stage == 2) resetMathFiveButton.drawTwoImages();
        if (mathSixButton.stage == 2) resetMathSixButton.drawTwoImages();

        
        ofSetColor(255, 255, 255);
        quicksandBold60.drawString("1. Birds", 100, 167);
        quicksandBold60.drawString("2. Balloons", 100, 267);
        quicksandBold60.drawString("3. 99 Cents", 100, 367);
        quicksandBold60.drawString("4. Toothpicks", 100, 467);
        quicksandBold60.drawString("5. Music", 100, 567);
        quicksandBold60.drawString("6. Custom", 100, 667);
        
        
        //-----------------------------------------------
        //Stars
        
        ofEnableAlphaBlending();
        starsDraw(415, 140, mathOneButton.difficulty);
        starsDraw(415, 240, mathTwoButton.difficulty);
        starsDraw(415, 340, mathThreeButton.difficulty);
        starsDraw(415, 440, mathFourButton.difficulty);
        starsDraw(415, 540, mathFiveButton.difficulty);
        starsDraw(415, 640, mathSixButton.difficulty);
        ofDisableAlphaBlending();
        
        //-----------------------------------------------
        //FAQ
        
        if (questionButton.toggle) {
            ofEnableAlphaBlending();
            editImage.draw(275, 633);
            ofSetColor(70, 70, 70, 180);
            ofRect(0, 0, ofGetWidth(), ofGetHeight());
            ofSetColor(255, 255, 255, 255);
            FAQ.draw(0,0);
            ofDisableAlphaBlending();
        }

        if (metricsButton.toggle) {
            ofEnableAlphaBlending();
            editImage.draw(275, 633);
            metrics.draw(0,0);
            //to make home button clickable from metrics screen
            metricsButton2.drawTwoImages();
            ofDisableAlphaBlending();
        }

        //question mark
        questionButton.drawTwoImages();
        metricsButton.drawTwoImages();
    }

    if (navStateMathOne) {
        mathOne->draw(quicksandBold60, quicksandBold36, quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }

    if (navStateMathTwo) {
        mathTwo->draw(quicksandBold60, quicksandBold36,quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }

    if (navStateMathThree) {
        mathThree->draw(quicksandBold60, quicksandBold36,quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }

    if (navStateMathFour) {
        mathFour->draw(quicksandBold60, quicksandBold36,quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }

    if (navStateMathFive) {
        mathFive->draw(quicksandBold60, quicksandBold36,quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }

    if (navStateMathSix) {
        mathSix->draw(quicksandBold60, quicksandBold36,quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }

    if (navStateSavedMathOne) {
        savedMathOne->draw(quicksandBold60, quicksandBold36,quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }
    
    if (navStateSavedMathTwo) {
        savedMathTwo->draw(quicksandBold60, quicksandBold36,quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }
    
    if (navStateSavedMathThree) {
        savedMathThree->draw(quicksandBold60, quicksandBold36,quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }

    if (navStateSavedMathFour) {
        savedMathFour->draw(quicksandBold60, quicksandBold36,quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }

    if (navStateSavedMathFive) {
        savedMathFive->draw(quicksandBold60, quicksandBold36,quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }

    if (navStateSavedMathSix) {
        savedMathSix->draw(quicksandBold60, quicksandBold36,quicksandBook36);
        ofSetColor(230, 230, 230, 245);
        ofRect(0, 0, 101, 50);
        homeButton.drawTwoImages();
    }

    
    if (loading) {
//        printf("loading in draw \n");
        loadingFeedback.drawTwoColorsRounded(quicksandBook36);
    }


    
}


////////////////////////////////////////////////////////////////////
//      STARS                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void nav::starsDraw(float x, float y, int difficulty) {

    int counter = 0;
    
    for (int i = 0; i < 3; i++) {
        
        if (difficulty > counter) {
            starNormal.draw(x+(50*i),y);
        } else {
            starBlackWhite.draw(x+(50*i), y);
        }
        
        counter++;
    }
    
}



////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void nav::touchingDown(ofTouchEventArgs &touch) {
    
    if (navStateSplash) {
        skipIntroButton.touchingDown(touch);
        skipIntroTwoButton.touchingDown(touch);
    }
    
//    if (navStateUserName) submitUserNameButton.touchingDown(touch);
    
    if (navStateToc) {
//        startUserNameButton.touchingDown(touch);
        questionButton.touchingDown(touch);
        metricsButton.touchingDown(touch);
        
        if (metricsButton.toggle) metricsButton2.touchingDown(touch);
        
        mathOneButton.touchingDown(touch);
        mathTwoButton.touchingDown(touch);
        mathThreeButton.touchingDown(touch);
        mathFourButton.touchingDown(touch);
        mathFiveButton.touchingDown(touch);
        
        if (greyStartButton.toggle) mathSixButton.touchingDown(touch);
        
//        if (mathOneButton.stage == 2) sendMathOneButton.touchingDown(touch);
//        if (mathTwoButton.stage == 2) sendMathTwoButton.touchingDown(touch);
//        if (mathThreeButton.stage == 2) sendMathThreeButton.touchingDown(touch);
//        if (mathFourButton.stage == 2) sendMathFourButton.touchingDown(touch);
//        if (mathFiveButton.stage == 2) sendMathFiveButton.touchingDown(touch);
//        if (mathSixButton.stage == 2) sendMathSixButton.touchingDown(touch);

        if (mathOneButton.stage == 2) resetMathOneButton.touchingDown(touch);
        if (mathTwoButton.stage == 2) resetMathTwoButton.touchingDown(touch);
        if (mathThreeButton.stage == 2) resetMathThreeButton.touchingDown(touch);
        if (mathFourButton.stage == 2) resetMathFourButton.touchingDown(touch);
        if (mathFiveButton.stage == 2) resetMathFiveButton.touchingDown(touch);
        if (mathSixButton.stage == 2) resetMathSixButton.touchingDown(touch);

    }
    
    if (navStateMathOne) {
        mathOne->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateMathTwo) {
        mathTwo->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateMathThree) {
        mathThree->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateMathFour) {
        mathFour->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateMathFive) {
        mathFive->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateMathSix) {
        mathSix->touchingDown(touch);
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

    if (navStateSavedMathFour) {
        savedMathFour->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateSavedMathFive) {
        savedMathFive->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

    if (navStateSavedMathSix) {
        savedMathSix->touchingDown(touch);
        homeButton.touchingDown(touch);
    }

}

//------------------------------------------------------------------
void nav::touchingMove(ofTouchEventArgs &touch) {
    
    if (navStateSplash) {
        skipIntroButton.touchingMove(touch);
        skipIntroTwoButton.touchingMove(touch);
    }
    
//    if (navStateUserName) submitUserNameButton.touchingMove(touch);
    
    if (navStateToc) {
//        startUserNameButton.touchingMove(touch);
        questionButton.touchingMove(touch);
        metricsButton.touchingMove(touch);
        if (metricsButton.toggle) metricsButton2.touchingMove(touch);

        mathOneButton.touchingMove(touch);
        mathTwoButton.touchingMove(touch);
        mathThreeButton.touchingMove(touch);
        mathFourButton.touchingMove(touch);
        mathFiveButton.touchingMove(touch);
        if (greyStartButton.toggle) mathSixButton.touchingMove(touch);
        
//        if (mathOneButton.stage == 2) sendMathOneButton.touchingMove(touch);
//        if (mathTwoButton.stage == 2) sendMathTwoButton.touchingMove(touch);
//        if (mathThreeButton.stage == 2) sendMathThreeButton.touchingMove(touch);
//        if (mathFourButton.stage == 2) sendMathFourButton.touchingMove(touch);
//        if (mathFiveButton.stage == 2) sendMathFiveButton.touchingMove(touch);
//        if (mathSixButton.stage == 2) sendMathSixButton.touchingMove(touch);

        if (mathOneButton.stage == 2) resetMathOneButton.touchingMove(touch);
        if (mathTwoButton.stage == 2) resetMathTwoButton.touchingMove(touch);
        if (mathThreeButton.stage == 2) resetMathThreeButton.touchingMove(touch);
        if (mathFourButton.stage == 2) resetMathFourButton.touchingMove(touch);
        if (mathFiveButton.stage == 2) resetMathFiveButton.touchingMove(touch);
        if (mathSixButton.stage == 2) resetMathSixButton.touchingMove(touch);

    }
    
    if (navStateMathOne) {
        mathOne->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateMathTwo) {
        mathTwo->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateMathThree) {
        mathThree->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateMathFour) {
        mathFour->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateMathFive) {
        mathFive->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateMathSix) {
        mathSix->touchingMove(touch);
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

    if (navStateSavedMathFour) {
        savedMathFour->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateSavedMathFive) {
        savedMathFive->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

    if (navStateSavedMathSix) {
        savedMathSix->touchingMove(touch);
        homeButton.touchingMove(touch);
    }

}

//------------------------------------------------------------------
void nav::touchingUp(ofTouchEventArgs &touch) {

    if (navStateSplash) {
        skipIntroButton.touchingUp(touch);
        skipIntroTwoButton.touchingUp(touch);
    }
    
//    if (navStateUserName) submitUserNameButton.touchingUp(touch);
    
    if (navStateToc) {
//        startUserNameButton.touchingUp(touch);
        questionButton.touchingUp(touch);
        metricsButton.touchingUp(touch);
        if (metricsButton.toggle) metricsButton2.touchingUp(touch);
        
        mathOneButton.touchingUp(touch);
        mathTwoButton.touchingUp(touch);
        mathThreeButton.touchingUp(touch);
        mathFourButton.touchingUp(touch);
        mathFiveButton.touchingUp(touch);
        if (greyStartButton.toggle) mathSixButton.touchingUp(touch);
        
//        if (mathOneButton.stage == 2) sendMathOneButton.touchingUp(touch);
//        if (mathTwoButton.stage == 2) sendMathTwoButton.touchingUp(touch);
//        if (mathThreeButton.stage == 2) sendMathThreeButton.touchingUp(touch);
//        if (mathFourButton.stage == 2) sendMathFourButton.touchingUp(touch);
//        if (mathFiveButton.stage == 2) sendMathFiveButton.touchingUp(touch);
//        if (mathSixButton.stage == 2) sendMathSixButton.touchingUp(touch);

        if (mathOneButton.stage == 2) resetMathOneButton.touchingUp(touch);
        if (mathTwoButton.stage == 2) resetMathTwoButton.touchingUp(touch);
        if (mathThreeButton.stage == 2) resetMathThreeButton.touchingUp(touch);
        if (mathFourButton.stage == 2) resetMathFourButton.touchingUp(touch);
        if (mathFiveButton.stage == 2) resetMathFiveButton.touchingUp(touch);
        if (mathSixButton.stage == 2) resetMathSixButton.touchingUp(touch);

    }
    
    if (navStateMathOne) {
        mathOne->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateMathTwo) {
        mathTwo->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateMathThree) {
        mathThree->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateMathFour) {
        mathFour->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateMathFive) {
        mathFive->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateMathSix) {
        mathSix->touchingUp(touch);
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

    if (navStateSavedMathFour) {
        savedMathFour->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateSavedMathFive) {
        savedMathFive->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

    if (navStateSavedMathSix) {
        savedMathSix->touchingUp(touch);
        homeButton.touchingUp(touch);
    }

}

//------------------------------------------------------------------
void nav::doubleTap(ofTouchEventArgs &touch) {
    
}


