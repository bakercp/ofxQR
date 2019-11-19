#include "ofApp.h"


void ofApp::setup()
{
    // Create a QR Code.
    code = ofx::QRCode("https://github.com/bakercp/ofxQR");

    // This uses depth information for occlusion rather than always drawing
    // things on top of each other.
    ofEnableDepthTest();

    // ofBox uses texture coordinates from 0-1, so you can load whatever
    // sized images you want and still use them to texture your box
    // but we have to explicitly normalize our tex coords here
    ofEnableNormalizedTexCoords();
}


void ofApp::update()
{
    float t = ofGetElapsedTimef();

    rotation += glm::vec3(ofSignedNoise(t, 0, 0),
                          ofSignedNoise(0, t, 0),
                          ofSignedNoise(0, 0, t));
}

void ofApp::draw()
{
    cam.begin();

    code.getTexture().bind();
    ofFill();
    ofSetColor(255);

    ofPushMatrix();
    ofRotateXDeg(rotation.x);
    ofRotateYDeg(rotation.y);
    ofRotateZDeg(rotation.z);

    ofDrawBox(code.getWidth());
    ofPopMatrix();
    code.getTexture().unbind();

    cam.end();
}
