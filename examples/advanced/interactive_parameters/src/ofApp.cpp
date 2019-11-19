#include "ofApp.h"


void ofApp::setup()
{
    text = "https://github.com/bakercp/ofxQR";

    generate();
//    labels = {
//        "   LOW  ",
//        " MEDIUM ",
//        "QUARTILE",
//        "  HIGH  "
//    };
}


void ofApp::draw()
{
    // Draw it centered in the middle of the screen.
    code.draw(ofGetWidth() / 2 - code.getWidth() / 2,
              ofGetHeight() / 2 - code.getHeight() / 2);
}


void ofApp::keyPressed(int key)
{
    bool regenerate = true;

    if (key == '-')
    {
        numPixelsPerModule = std::max(numPixelsPerModule - 1, std::size_t(1));
    }
    else if (key == '=')
    {
        numPixelsPerModule = std::min(numPixelsPerModule + 1, std::numeric_limits<std::size_t>::max());
    }
    else if (key == '[')
    {
        numBorderModules = std::max(numBorderModules - 1, std::size_t(1));
    }
    else if (key == ']')
    {
        numBorderModules = std::min(numBorderModules + 1, std::numeric_limits<std::size_t>::max());
    }
    else if (key == OF_KEY_UP)
    {

    }
    else if (key == OF_KEY_DOWN)
    {

    }
    else if (key == OF_KEY_BACKSPACE || key == OF_KEY_BACKSPACE)
    {
        if (!text.empty())
            text.erase(text.end() - 1);
    }
    else if (key > 0 && key < 255)
    {
        text += char(key);
    }
    else regenerate = false;

    if (regenerate)
    {
        generate();
    }
}


void ofApp::generate()
{
    code.setText(text, ecc);
    code.setNumBorderModules(numBorderModules);
    code.setNumPixelsPerModule(numPixelsPerModule);
}
