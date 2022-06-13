//
// Created by ritwiz on 28/5/22.
//

#ifndef UNTITLED_SHAPE_H
#define UNTITLED_SHAPE_H
#include <SFML/Graphics.hpp>
#include "../utility/Point.h"

class Shape {
public:
    float screen_width;
    float screen_height;
    Shape(float sw, float sh);
    sf::Color color;
    virtual void CreateRandDimensions() = 0;
    virtual void FillWithColor(sf::Uint8 *buffer) = 0;
    virtual bool Inside(const Point& p) = 0;
    void SetPixel(sf::Uint8 *buffer, int i, int j);
    sf::Color GetPixel(sf::Uint8 *buffer, int i, int j);
    static float getRandomFloat(int num);
};


#endif //UNTITLED_SHAPE_H
