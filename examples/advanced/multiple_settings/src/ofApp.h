#pragma once


#include "ofMain.h"
#include "ofxQR.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    ofx::QRCode code;

};
