//
// Created by ritwiz on 10/6/22.
//

#ifndef UNTITLED_BOUNDINGBOX_H
#define UNTITLED_BOUNDINGBOX_H

#ifndef UNTITLED_POINT_H
#include "Point.h"
#endif

class BoundingBox {
public:
    Point l, h;
    BoundingBox(int x, int y);
    void evaluate(int x, int y);

};


#endif //UNTITLED_BOUNDINGBOX_H
