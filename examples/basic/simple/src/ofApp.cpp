#include "ofApp.h"


void ofApp::setup()
{
    // Create a QR Code.
    code = ofx::QRCode("https://github.com/bakercp/ofxQR");
}


void ofApp::draw()
{
    // Draw it centered in the middle of the screen.
    code.draw(ofGetWidth() / 2 - code.getWidth() / 2,
              ofGetHeight() / 2 - code.getHeight() / 2);
}
