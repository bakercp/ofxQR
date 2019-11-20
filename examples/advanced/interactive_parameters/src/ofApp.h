#pragma once


#include "ofMain.h"
#include "ofxQR.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;
    void keyPressed(int key) override;

    void generate();

    ofx::QRCode code;

    std::string text;

    std::size_t numPixelsPerModule = ofx::QRCode::DEFAULT_NUM_PIXELS_PER_MODULE;
    std::size_t numBorderModules = ofx::QRCode::DEFAULT_NUM_BORDER_MODULES;

    ofx::QRCode::ECC ecc = ofx::QRCode::ECC::LOW;

};
