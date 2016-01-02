#pragma once

#include "ofMain.h"
#include "ofxGUI.h"
#include "PMAudioAnalyzer.hpp"
#include "XBDeviceParams.h"

class ofApp : public ofBaseApp
{

public:

    void setup();
    void update();
    void draw();

    void exit();

    void keyReleased(int key);

private:

    // GUI

    // Audio device selector
    ofxPanel                guiDevices;
    vector<XBDeviceParams>  deviceParams;
    ofxButton               btnStartAnalysis;
    ofxButton               btnStopAnalysis;
    ofxLabel                lblStatus;

    // Audio analysis (cello)
    ofxPanel                guiAnalysis;
    ofParameterGroup        paramsPitch;
    ofParameter<float>      pitchMidiNote;
    ofParameterGroup        paramsEnergy;
    ofParameter<float>      energyEnergy;
    ofParameter<float>      energyGain;
    ofParameterGroup        paramsSilence;
    ofParameter<float>      silenceThreshold;
    ofParameter<float>      silenceLength;
    ofParameter<bool>       silenceOn;
    ofParameterGroup        paramsPause;
    ofParameter<float>      pauseLength;
    ofParameter<bool>       pauseOn;
    ofParameterGroup        paramsOnsets;
    ofParameter<float>      onsetsThreshold;
    ofParameter<bool>       onsetsOn;

    void buildDevicesPanel();
    void buildCelloAnalysisPanel();

    // GUI EVENTS

    void startButtonPressed();
    void stopButtonPressed();

    void guiSilenceThresholdChanged(float &threshold);
    void guiSilenceLengthChanged(float &length);
    void guiPauseLengthChanged(float &length);
    void guiOnsetsThresholdChanged(float &threshold);

    // AUDIO ANALYZER

    vector<PMDeviceAudioAnalyzer *> *audioAnalyzers;

    void analyzerPitchChanged(pitchParams &pitchParams);
    void analyzerEnergyChanged(energyParams &energyParams);
    void analyzerSilenceStateChanged(silenceParams &silenceParams);
    void analyzerPauseStateChanged(pauseParams &pauseParams);
    void analyzerOnsetDetected(onsetParams &onsetParams);
};