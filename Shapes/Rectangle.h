//
// Created by ritwiz on 28/5/22.
//

#ifndef UNTITLED_RECTANGLE_H
#define UNTITLED_RECTANGLE_H

#endif //UNTITLED_RECTANGLE_H
//
// Created by ritwiz on 28/5/22.
//
#include "Shape.h"

float getRandomFloat(int num);

class Rectangle : public Shape {
    float w, h, x, y;
public:
    Rectangle(float sh, float sw);
    void CreateRandDimensions() override;
    bool Inside(int i, int j) override;
    void FillWithColor(sf::Image &img) override;
};