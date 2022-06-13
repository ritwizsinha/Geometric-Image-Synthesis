//
// Created by ritwiz on 13/6/22.
//

#ifndef UNTITLED_POINTINPOLYGONSTRATEGY_H
#define UNTITLED_POINTINPOLYGONSTRATEGY_H

#ifndef  UNTITLED_POINT_H
#include "../utility/Point.h"
#endif

#ifndef UNTITLED_BOUNDINGBOX_H
#include "../utility/BoundingBox.h"
#endif

class PointInPolygonStrategy {
public:
//    static bool naive(Point &p, BoundingBox *b, int screen_width, Point *points)  {
//        if (p.x < b->l.x or p.x > b->h.x or p.y < b->l.y or p.y > b->h.y) return false;
//        Point extreme = {(int)screen_width + 1, p.y};
//        int count = 0;
//        for(int i = 0; i < sides; i++) {
//            int next = (i + 1) % sides;
//            if (doIntersect(points[i], points[next], p, extreme)) {
//                if (orientation(points[i],p, points[next]) == 0)
//                    return onSegment(points[i], p, points[next]);
//                if (p.y != points[i].y)
//                    count++;
//            }
//        }
//
//        return count&1;
//    }
    bool cn_PnPoly(const Point &p, Point *points, int sides);
};


#endif //UNTITLED_POINTINPOLYGONSTRATEGY_H
