#include "ofApp.h"


int main()
{
    ofSetupOpenGL(256, 256, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}
