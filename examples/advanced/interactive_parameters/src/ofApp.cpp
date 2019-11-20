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


    std::stringstream ss;

    ss << "KEYBOARD INPUT" << std::endl << std::endl;
    ss << "-/= to set the number of pixels per module: " << numPixelsPerModule << std::endl;
    ss << "[/] to set the number of border modules: " << numBorderModules << std::endl;
    ss << "Right arrow to change the ECC: " << ofx::QRCode::to_string(ecc) << std::endl;

    ss << std::endl;
    ss << "Update the text buffer by typing: " << std::endl << std::endl << text << std::endl;;


    ofDrawBitmapStringHighlight(ss.str(), glm::vec3(10, 16, 0));
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
    else if (key == OF_KEY_RIGHT)
    {
        switch (ecc)
        {
            case ofx::QRCode::ECC::LOW:
                ecc = ofx::QRCode::ECC::MEDIUM;
                break;
            case ofx::QRCode::ECC::MEDIUM:
                ecc = ofx::QRCode::ECC::QUARTILE;
                break;
            case ofx::QRCode::ECC::QUARTILE:
                ecc = ofx::QRCode::ECC::HIGH;
                break;
            case ofx::QRCode::ECC::HIGH:
                ecc = ofx::QRCode::ECC::LOW;
                break;
        }
    }
    else if (key == OF_KEY_RETURN)
    {
        text += '\n';
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
