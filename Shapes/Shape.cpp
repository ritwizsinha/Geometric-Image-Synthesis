//
// Created by ritwiz on 28/5/22.
//

#include "Shape.h"

void Shape::SetPixel(sf::Uint8 *buffer, int i, int j) {
    int index = 4*(j * screen_width + i);
    sf::Uint8 r = buffer[index];
    sf::Uint8 g = buffer[index+1];
    sf::Uint8 b = buffer[index+2];

    // Current pixel color = alpha * currentColor + (1 - alpha) * prevColor
    r = ((1.0 * color.a) / 255) * color.r + (1 - (1.0*color.a)/255) * r;
    g = ((1.0 * color.a) / 255) * color.g + (1 - (1.0*color.a)/255) * g;
    b = ((1.0 * color.a) / 255) * color.b + (1 - (1.0*color.a)/255) * b;

    buffer[index] = r, buffer[index + 1] = g, buffer[index + 2] = b, buffer[index + 3] = 255;
}

sf::Color Shape::GetPixel(sf::Uint8 *buffer, int i, int j) {
    int index = 4*(j * screen_width + i);
    sf::Uint8 r = buffer[index];
    sf::Uint8 g = buffer[index+1];
    sf::Uint8 b = buffer[index+2];


    // Current pixel color = alpha * currentColor + (1 - alpha) * prevColor
    r = ((1.0 * color.a) / 255) * color.r + (1 - (1.0*color.a)/255) * r;
    g = ((1.0 * color.a) / 255) * color.g + (1 - (1.0*color.a)/255) * g;
    b = ((1.0 * color.a) / 255) * color.b + (1 - (1.0*color.a)/255) * b;;

    return {
        r,
        g,
        b,
        255
    };
}