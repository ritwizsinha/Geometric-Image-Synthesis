//
// Created by ritwiz on 10/6/22.
//

#include "BoundingBox.h"
#include "iostream"

void BoundingBox::evaluate(const Point &p) {
    const auto &[x, y] = p;
    if (x < l.x) l.x = std::max(0, x);
    if (x > h.x) h.x = std::min(screen_width-1, x);
    if (y < l.y) l.y = std::max(y, 0);
    if (y > h.y) h.y = std::min(y, screen_height-1);
}

BoundingBox::BoundingBox(int max_x, int max_y) {
    screen_width = max_x;
    screen_height = max_y;
    l.x = max_x;
    l.y = max_y;
    h.x = 0;
    h.y = 0;
}
