//
// Created by ritwiz on 10/6/22.
//

#include "BoundingBox.h"
#include "iostream"

void BoundingBox::evaluate(const Point &p) {
    const auto &[x, y] = p;
    if (x < l.x) l.x = x;
    if (x > h.x) h.x = x;
    if (y < l.y) l.y = y;
    if (y > h.y) h.y = y;
}

BoundingBox::BoundingBox(int max_x, int max_y) {
    l.x = max_x;
    l.y = max_y;
    h.x = 0;
    h.y = 0;
}
