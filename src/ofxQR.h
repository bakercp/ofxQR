#pragma once


#include "BitBuffer.hpp"
#include "QrCode.hpp"
#include "QrSegment.hpp"


#include "ofGLBaseTypes.h"
#include "ofPixels.h"
#include "ofTexture.h"


namespace ofx {


class QRCode: public ofBaseImage
{
public:
    enum class ECC
    {
        LOW,
        MEDIUM,
        QUARTILE,
        HIGH
    };

    QRCode();
    
    QRCode(const std::string& text, ECC ecc = ECC::HIGH);
    QRCode(const qrcodegen::QrCode& code);

    /// \brief Destroy the QR Code.
    virtual ~QRCode();

    ofPixels& getPixels() override;
    const ofPixels& getPixels() const override;

    ofTexture& getTexture() override;
    const ofTexture& getTexture() const override;
    void setUseTexture(bool useTexture) override;
    bool isUsingTexture() const override;

    using ofBaseDraws::draw;

    void draw(float x, float y, float w, float h) const override;
    float getHeight() const override;
    float getWidth() const override;

    void setText(const std::string& text, ECC ecc = ECC::HIGH);
    void setCode(const qrcodegen::QrCode& code);

    void setNumPixelsPerModule(std::size_t numPixelsPerModule);
    std::size_t getNumPixelsPerModule() const;

    void setNumBorderModules(std::size_t numBorderModules);
    std::size_t getNumBorderModules() const;

    /// \brief The number number of pixels (width / height) used to represent a single QR code module.
    static const std::size_t DEFAULT_NUM_PIXELS_PER_MODULE = 3;

    /// \brief The number of border modules used to outline the QR code.
    static const std::size_t DEFAULT_NUM_BORDER_MODULES = 1;

    static std::string to_string(ECC ecc);
private:
    void renderToPixels();

    const qrcodegen::QrCode::Ecc toEcc(QRCode::ECC ecc) const;

    std::shared_ptr<const qrcodegen::QrCode> _code;

    bool _useTexture = true;
    ofPixels _pixels;
    ofTexture _texture;

    bool _needsRender = true;

    std::size_t _numPixelsPerModule = DEFAULT_NUM_PIXELS_PER_MODULE;
    std::size_t _numBorderModules = DEFAULT_NUM_BORDER_MODULES;

};


} // namespace ofx
