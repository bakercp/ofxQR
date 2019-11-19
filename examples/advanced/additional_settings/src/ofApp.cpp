#include "ofApp.h"


void ofApp::setup()
{
    std::string text = "https://github.com/bakercp/ofxQR";

    // Create the same QR Code at multiple error correction levels.
    codes.push_back(ofx::QRCode(text, ofx::QRCode::ECC::LOW));
    codes.push_back(ofx::QRCode(text, ofx::QRCode::ECC::MEDIUM));
    codes.push_back(ofx::QRCode(text, ofx::QRCode::ECC::QUARTILE));
    codes.push_back(ofx::QRCode(text, ofx::QRCode::ECC::HIGH));

    labels = {
        "   LOW  ",
        " MEDIUM ",
        "QUARTILE",
        "  HIGH  "
    };
}


void ofApp::draw()
{
    std::size_t i = 0;

    float xStep = ofGetWidth() / 4;
    float x = xStep / 2;
    float y = ofGetHeight() / 2;

    for (std::size_t i = 0; i < codes.size(); ++i)
    {
        codes[i].draw(x - codes[i].getWidth() / 2,
                      y - codes[i].getHeight() / 2);

        ofDrawBitmapString(labels[i], x - 30, ofGetHeight() - 30);

        x += xStep;
    }
}
