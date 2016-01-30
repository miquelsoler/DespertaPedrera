//
// Created by Miquel Àngel Soler on 24/12/15.
//

#ifndef PEDRERAMASTER_XBSCENE2_H
#define PEDRERAMASTER_XBSCENE2_H

#include "XBBaseScene.h"
#include "ofxTraerPhysics.h"
#include "Wave.h"
#include "BlurEffect.h"

using namespace  traer::physics ;

class XBScene2 : public XBBaseScene
{
public:

    XBScene2(const string &name) : XBBaseScene(name) {}

    virtual void setup(XBBaseGUI *gui);
    virtual void update();
    virtual void drawIntoFBO();
    void keyReleased(int key);
    void keyPressed(int key);
    void onViolinPitchChanged(float &pitch);
    void onViolinEnergyChanged(float &energy);
    void onCelloPitchChanged(float &pitch);
    void onCelloEnergyChanged(float &energy);
    void onPianoNoteOn(XBOSCManager::PianoNoteOnArgs &noteOn);
    void onPianoNoteOff(int &noteOff);
    void onKinectStateChanged(string &kState) {};
    void onKinectLPositionChanged(XBOSCManager::KinectPosVelArgs &lPos) ;
    void onKinectLVelocityChanged(XBOSCManager::KinectPosVelArgs &lVel);
    void onKinectRPositionChanged(XBOSCManager::KinectPosVelArgs &rPos);
    void onKinectRVelocityChanged(XBOSCManager::KinectPosVelArgs &rVel);

private:

    void initWaves();
    void initWindows(string name,  vector<ofRectangle>& vectorWindows, vector<Wave>& vectorWaves,int starIndex, int floor);
    void arrangeWindows(int index, vector<ofRectangle>& elements);
    void initWindowsOutlines(string name, vector<expandingPolyLine> &vectorWindows);

    
    int drawWindow(float note, vector<ofRectangle>& windows, vector<Wave> &waves);
    
    ofFbo auxFbo;
    ofxSVG svg;
    vector<ofRectangle> celloWindows;
    vector<ofRectangle> violinWindows;
    vector<ofRectangle> pianoWindows;
    
    vector<Wave> celloWaves;
    vector<Wave> violinWaves;
    vector<Wave> pianoWaves;
    
    vector<expandingPolyLine> celloOutlines;
    vector<expandingPolyLine> celloOutlinesToDraw;
    vector<expandingPolyLine> pianoOutlines;
    vector<expandingPolyLine> pianoOutlinesToDraw;
    
    ofImage windowMask;
    ofImage rectMask;
    
    vector<Wave> waves;
    
    ofColor directorColor;
    
    BlurEffect blur;
    
    bool fakeCelloEvent = false;
    float celloNote;
    float celloEnergy = 0;
    bool fakePianoEvent = false;
    float pianoNote;
    float pianoEnergy = 0;
    bool fakeViolinEvent = false;
    float violinNote;
    float violinEnergy = 0;
    float energyThreshold = 0.01;
    kinectHand leftHand;
    kinectHand rightHand;
};


#endif //PEDRERAMASTER_XBSCENE2_H
