//
// Created by ritwiz on 28/5/22.
//

#ifndef UNTITLED_SHAPE_H
#define UNTITLED_SHAPE_H
#include <SFML/Graphics.hpp>

class Shape {
public:
    float screen_width;
    float screen_height;
    sf::Color color;
    virtual void CreateRandDimensions() = 0;
    virtual void FillWithColor(sf::Uint8 *buffer) = 0;
    virtual bool Inside(int i, int j) = 0;
    void SetPixel(sf::Uint8 *buffer, int i, int j);
    sf::Color GetPixel(sf::Uint8 *buffer, int i, int j);
};


#endif //UNTITLED_SHAPE_H
