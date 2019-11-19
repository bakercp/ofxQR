#pragma once


#include "ofMain.h"
#include "ofxQR.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    ofx::QRCode code;

    glm::vec3 rotation;
    
    ofEasyCam cam;
};
