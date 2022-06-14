//
// Created by ritwiz on 13/6/22.
//

#include "PointInPolygonStrategy.h"

bool PointInPolygonStrategy::cn_PnPoly(const Point &p, Point *points, int sides) {
    int cn = 0;
    for(int i = 0; i < sides; i++) {
        int next = (i + 1) % sides;
        if ((points[i].y <= p.y and points[next].y > p.y) or (points[i].y > p.y and points[next].y <= p.y)) {
            float vt = (float)(p.y - points[i].y) / (points[next].y - points[i].y);
            float x_intersect = points[i].x + vt * (points[next].x - points[i].x);
            if (p.x < x_intersect) cn++;
        }
     }

    return cn&1;
}