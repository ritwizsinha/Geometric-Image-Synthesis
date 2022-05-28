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
    virtual void FillWithColor(sf::Image &img) = 0;
    virtual bool Inside(int i, int j) = 0;
    void SetPixel(sf::Image &img, int x, int y);
    sf::Color GetPixel(sf::Image &img, int i, int j);
};


#endif //UNTITLED_SHAPE_H
