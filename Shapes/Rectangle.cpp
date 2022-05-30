//
// Created by ritwiz on 28/5/22.
//
#include "Rectangle.h"

float getRandomFloat(int num) {
    return (1.0 * rand() / RAND_MAX) * num;
}

Rectangle::Rectangle(float sh, float sw) {
    screen_height = sh;
    screen_width = sw;
}
void Rectangle::CreateRandDimensions() {
    x = getRandomFloat(screen_width);
    y = getRandomFloat(screen_height);
    w = getRandomFloat(screen_width);
    h = getRandomFloat(screen_height);
    sf::RectangleShape re(sf::Vector2f(w, h));
    sf::Uint8 r = getRandomFloat(255);
    sf::Uint8 g = getRandomFloat(255);
    sf::Uint8 b = getRandomFloat(255);
    sf::Uint8 a = getRandomFloat(255);
    color = sf::Color{r, g, b, a};
}

void Rectangle::FillWithColor(sf::Uint8 *buffer) {
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            if (i + y < screen_height and j + x < screen_width)
                SetPixel(buffer, j + x, i + y);
}

bool Rectangle::Inside(int i, int j) {
    return i >= x && i < std::min(screen_width, x + w) && j >= y && j < std::min(screen_height, y + h);
}