#include "ofApp.h"


void ofApp::setup()
{
    // Advanced examples from the underlying library can be used. For more
    // information see:
    //
    // https://www.nayuki.io/page/qr-code-generator-library

    // Illustration "golden"
    const char* golden0 = "Golden ratio \xCF\x86 = 1.";
    const char* golden1 = "6180339887498948482045868343656381177203091798057628621354486227052604628189024497072072041893911374";
    const char* golden2 = "......";

    // Create the raw bytes for the first string.
    std::vector<uint8_t> bytes(golden0, golden0 + std::strlen(golden0));

    // Create the segments.
    const std::vector<qrcodegen::QrSegment> segments = {
        qrcodegen::QrSegment::makeBytes(bytes),
        qrcodegen::QrSegment::makeNumeric(golden1),
        qrcodegen::QrSegment::makeAlphanumeric(golden2)
    };

    // Create the QR Code.
    const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeSegments(segments, qrcodegen::QrCode::Ecc::LOW);

    // Create a QR Code.
    code = ofx::QRCode(qr);
}


void ofApp::draw()
{
    // Draw it centered in the middle of the screen.
    code.draw(ofGetWidth() / 2 - code.getWidth() / 2,
              ofGetHeight() / 2 - code.getHeight() / 2);
}
