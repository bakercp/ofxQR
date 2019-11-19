#pragma once


#include "ofMain.h"
#include "ofxQR.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    std::vector<ofx::QRCode> codes;

    std::vector<std::string> labels;
};
