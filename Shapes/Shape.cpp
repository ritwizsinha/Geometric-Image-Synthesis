//
// Created by ritwiz on 28/5/22.
//

#include "Shape.h"

void Shape::SetPixel(sf::Image &img, int x, int y) {
    sf::Color prevColor = img.getPixel(x, y);

    // Current pixel color = alpha * currentColor + (1 - alpha) * prevColor
    uint8_t r = ((1.0 * color.a) / 255) * color.r + (1 - (1.0*color.a)/255) * prevColor.r;
    uint8_t g = ((1.0 * color.a) / 255) * color.g + (1 - (1.0*color.a)/255) * prevColor.g;
    uint8_t b = ((1.0 * color.a) / 255) * color.b + (1 - (1.0*color.a)/255) * prevColor.b;;
    img.setPixel(x, y, sf::Color{
        r,
        g,
        b,
        255
    });
}

sf::Color Shape::GetPixel(sf::Image &img, int i, int j) {
    sf::Color prevColor = img.getPixel(i, j);

    // Current pixel color = alpha * currentColor + (1 - alpha) * prevColor
    uint8_t r = ((1.0 * color.a) / 255) * color.r + (1 - (1.0*color.a)/255) * prevColor.r;
    uint8_t g = ((1.0 * color.a) / 255) * color.g + (1 - (1.0*color.a)/255) * prevColor.g;
    uint8_t b = ((1.0 * color.a) / 255) * color.b + (1 - (1.0*color.a)/255) * prevColor.b;;

    return {
        r,
        g,
        b,
        255
    };
}