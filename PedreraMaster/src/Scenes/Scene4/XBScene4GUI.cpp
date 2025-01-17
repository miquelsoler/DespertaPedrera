//
// Created by Miquel Àngel Soler on 12/1/16.
//

#include "XBScene4GUI.h"

XBScene4GUI::XBScene4GUI() : XBBaseGUI()
{
    sceneSettingsFilename = "scene4.xml";
    colorSettingsFilename = "colors4.xml";
}

void XBScene4GUI::setup()
{
    XBBaseGUI::setup();

    violinGroup.setup("Violin and Cello");
    violinGroup.add(linkAudio.setup("Alpha audio", false));
    violinGroup.add(minViolinSpeed.setup("Min v speed", 2, 0, 10));
    violinGroup.add(maxViolinSpeed.setup("Max v speed", 6, 0, 30));
    violinGroup.add(minCelloSpeed.setup("Min c speed", 2, 0, 10));
    violinGroup.add(maxCelloSpeed.setup("Max c speed", 6, 0, 30));
    violinGroup.add(violinK.setup("K", 0.057, 0.005, 0.095));
    violinGroup.add(violinF.setup("F", 0.028, 0.010, 0.065));
    violinGroup.add(presetIndex.setup("Presets", 0, 0, 13));
    presetIndex.addListener(this, &XBScene4GUI::onPresetChange);
    violinGroup.add(scaleFactor.setup("Scale factor", 0.7, 0.5, 1.));
    sceneGui.add(&violinGroup);
    
    windowGroup.setup("Window");
    windowGroup.add(barHeight.setup("Audio bar height", 30., 20., 120.));
    windowGroup.add(alphaStart.setup("Alpha attack", 0.8, 0.0f, 1.0f));
    windowGroup.add(alphaFactor.setup("Alpha decay", 18.0f, 0.0f, 30.0f));
    windowGroup.add(growFactor.setup("Speed", .05f, 0.0f, .5f));
    windowGroup.add(windowFrequency.setup("Frequency", 20, 2, 60));
    sceneGui.add(&windowGroup);
    
    pianoGroup.setup("Piano");
    pianoGroup.add(stoneGrowFactor.setup("Amplitude", 0.8, 0.000, 1.));
    pianoGroup.add(stoneDamping.setup("Damping", 0.98, 0.4, 1.00));
    pianoGroup.add(stoneAlphaDecrease.setup("Alpha speed", 2.3, 1, 20));
    pianoGroup.add(stoneTime.setup("Duration", 2, 0.0, 5.0));
    pianoGroup.add(stoneFrequency.setup("Pulsation freq", .05, 0.0, .5));
    pianoGroup.add(stonePhase.setup("Initial phase", 3, 0, 3));
    sceneGui.add(&pianoGroup);
    
    directorGroup.setup("Director");
    directorGroup.add(lineWidth.setup("Line width", 1.0f, 1.0f, 5.0f));
    directorGroup.add(minPeriod.setup("Min wave period", 800.0f, 200.0f, 2000.0f));
    directorGroup.add(maxPeriod.setup("Max wave period",  1600, 200.0, 3000.0));
    directorGroup.add(dampingWaves.setup("Damping",  0.80, 0.00, 1.00));
    directorGroup.add(minAttractorStrength.setup("Min strength",  0.5, 0.0, 10.0));
    directorGroup.add(attractorStrength.setup("Max strength",  4, 0.0, 10.0));
    directorGroup.add(attractorRadius.setup("attractorRadius", 10.0f, 0.00, 14.00));
    sceneGui.add(&directorGroup);
    
    sceneGui.add(blurAmount.setup("Blur amount", 0, 0, 8));
    
    loadSettings();
}

void XBScene4GUI::onPresetChange(int &index)
{
    violinK = presets.get(presetIndex).kill;
    violinF = presets.get(presetIndex).feed;
}
