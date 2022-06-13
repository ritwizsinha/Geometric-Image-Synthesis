//
// Created by ritwiz on 10/6/22.
//

#include "BoundingBox.h"

void BoundingBox::evaluate(int x, int y) {
    if (x < l.x) l.x = x;
    if (x > h.x) h.x = x;
    if (y < l.y) l.y = y;
    if (y > h.y) h.y = y;
}

BoundingBox::BoundingBox(int x, int y) {
    l.x = 0;
    l.y = 0;
    h.x = x;
    h.y = y;
}
