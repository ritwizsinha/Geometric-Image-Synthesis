//
// Created by ritwiz on 10/6/22.
//

#ifndef UNTITLED_REGULARPOLYGON_H
#define UNTITLED_REGULARPOLYGON_H

#include "Shape.h"
#include "../utility/BoundingBox.h"
#include "../Strategies/PointInPolygonStrategy.h"

class RegularPolygon: public Shape {
public:
    RegularPolygon(double sw, double sh);
    void CreateRandDimensions() override;
    bool Inside(const Point &p) override;
    void FillWithColor(sf::Uint8 *buffer) override;
    BoundingBox *b;
    Point *points;
    int sides;
    PointInPolygonStrategy *pips;
private:
    // Given three collinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
    static bool onSegment(Point p, Point q, Point r);

    // To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
    static int orientation(Point p, Point q, Point r);

    // The function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
    bool doIntersect(Point p1, Point q1, Point p2, Point q2);
};


#endif //UNTITLED_REGULARPOLYGON_H
