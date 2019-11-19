#include "ofxQR.h"


namespace ofx {


QRCode::QRCode()
{
}


QRCode::QRCode(const std::string& text, ECC ecc):
    QRCode(qrcodegen::QrCode::encodeText(text.data(), toEcc(ecc)))
{
}


QRCode::QRCode(const qrcodegen::QrCode& code)
{
    setCode(code);
}


QRCode::~QRCode()
{
}


ofPixels& QRCode::getPixels()
{
    return _pixels;
}


const ofPixels& QRCode::getPixels() const
{
    return _pixels;
}


ofTexture& QRCode::getTexture()
{
    return _texture;
}


const ofTexture& QRCode::getTexture() const
{
    return _texture;
}


void QRCode::setUseTexture(bool useTexture)
{
    if (useTexture != _useTexture)
        _needsRender = true;

    _useTexture = useTexture;

    if (_needsRender)
        renderToPixels();
}


bool QRCode::isUsingTexture() const
{
    return _useTexture;
}


void QRCode::draw(float x, float y, float w, float h) const
{
    if (_texture.isAllocated())
        _texture.draw(x, y, w, h);
}


float QRCode::getHeight() const
{
    if (_pixels.isAllocated())
        return _pixels.getHeight();
    return 0;
}


float QRCode::getWidth() const
{
    if (_pixels.isAllocated())
        return _pixels.getWidth();
    return 0;
}


void QRCode::setText(const std::string& text, ECC ecc)
{
    setCode(qrcodegen::QrCode::encodeText(text.data(), toEcc(ecc)));
}


void QRCode::setCode(const qrcodegen::QrCode& code)
{
    _needsRender = true;
    _code = std::make_shared<const qrcodegen::QrCode>(code);
    renderToPixels();
}


void QRCode::setNumPixelsPerModule(std::size_t numPixelsPerModule)
{
    if (numPixelsPerModule != _numPixelsPerModule)
        _needsRender = true;

    _numPixelsPerModule = numPixelsPerModule;
}


std::size_t QRCode::getNumPixelsPerModule() const
{
    return _numPixelsPerModule;
}


void QRCode::setNumBorderModules(std::size_t numBorderModules)
{
    if (numBorderModules != _numBorderModules)
        _needsRender = true;

    _numBorderModules = numBorderModules;
}


std::size_t QRCode::getNumBorderModules() const
{
    return _numBorderModules;
}


void QRCode::renderToPixels()
{
    if (_needsRender && _code)
    {
        // The total number of pixels we need ot allocate given the QR size and settings.
        std::size_t size = (_code->size + 2 * _numBorderModules) * _numPixelsPerModule;

        // Allocate the required pixels using only one channel per pixel.
        _pixels.allocate(size, size, 1);

        // Set all pixels to white.
        _pixels.set(255);

        // Iterate through the QR code data.
        for (std::size_t y = 0; y < _code->size; y++)
        {
            for (std::size_t x = 0; x < _code->size; x++)
            {
                ofColor color = _code->getModule(x, y) > 0 ? ofColor::black : ofColor::white;

                // Determine the offset and the pixels to be filled.
                std::size_t sx = (x + _numBorderModules) * _numPixelsPerModule;
                std::size_t sy = (y + _numBorderModules) * _numPixelsPerModule;

                for (std::size_t yy = sy; yy < sy + _numPixelsPerModule; ++yy)
                {
                    for (std::size_t xx = sx; xx < sx + _numPixelsPerModule; ++xx)
                    {
                        _pixels.setColor(xx, yy, color);
                    }
                }
            }
        }

        if (_useTexture)
        {
            _texture.clear();
            _texture.loadData(_pixels);
            // No anti-aliasing.
            _texture.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
        }

        _needsRender = false;
    }
}


const qrcodegen::QrCode::Ecc QRCode::toEcc(QRCode::ECC ecc) const
{
    switch (ecc)
    {
        case QRCode::ECC::LOW:
            return qrcodegen::QrCode::Ecc::LOW;
        case QRCode::ECC::MEDIUM:
            return qrcodegen::QrCode::Ecc::MEDIUM;
        case QRCode::ECC::QUARTILE:
            return qrcodegen::QrCode::Ecc::QUARTILE;
        case QRCode::ECC::HIGH:
            return qrcodegen::QrCode::Ecc::HIGH;
    }

    return qrcodegen::QrCode::Ecc::LOW;
}


} // namespace ofx
