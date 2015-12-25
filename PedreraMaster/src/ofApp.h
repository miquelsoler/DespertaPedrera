#pragma once

#include "ofMain.h"

#include "XBSceneManager.h"

class ofApp : public ofBaseApp
{
public:

    void setup();
    void update();
    void draw();

    void exit();

    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);

private:

    XBSceneManager sceneManager;
};
