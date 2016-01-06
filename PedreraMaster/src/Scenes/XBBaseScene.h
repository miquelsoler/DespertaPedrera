//
// Created by Miquel Àngel Soler on 24/12/15.
//

#ifndef PEDRERAMASTER_XBBASESCENE_H
#define PEDRERAMASTER_XBBASESCENE_H

#include "ofMain.h"

class XBBaseScene
{
public:

    XBBaseScene(string name);

    virtual void setup();
    virtual void update();
    virtual void drawIntoFBO() = 0;

    const string &getName() const { return name; }
    const ofFbo &getMainFBO() const { return fbo; }

    void setFBOAlpha(float _fboAlpha) { fboAlpha = _fboAlpha; };
    float *getFBOAlpha() { return &fboAlpha; }

    virtual void onCelloStarted() {};
    virtual void onCelloStopped() {};
    virtual void onCelloPitchChanged(float &pitch) {};
    virtual void onCelloEnergyChanged(float &energy) {};
    virtual void onCelloSilenceChanged(bool &isSilent) {};
    virtual void onCelloPauseChanged(bool &isPaused) {};
    virtual void onCelloOnsetDetected() {};

    virtual void onViolinStarted() {};
    virtual void onViolinStopped() {};
    virtual void onViolinPitchChanged(float &pitch) {};
    virtual void onViolinEnergyChanged(float &energy) {};
    virtual void onViolinSilenceChanged(bool &isSilent) {};
    virtual void onViolinPauseChanged(bool &isPaused) {};
    virtual void onViolinOnsetDetected() {};

protected:

    void drawFadeRectangle();

    ofFbo fbo;
    float fboAlpha;

private:

    string name;
};


#endif //PEDRERAMASTER_XBBASESCENE_H
