#include "ofApp.h"


int main()
{
    ofSetupOpenGL(768, 256, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}
