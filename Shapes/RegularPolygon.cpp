//
// Created by ritwiz on 10/6/22.
//

#include "RegularPolygon.h"
#include "math.h"
#include <iostream>

void RegularPolygon::CreateRandDimensions() {
    double radius = rand() % (int)std::min(screen_height / 2, screen_width / 2);
    double x_center = radius + rand() % (int)(screen_width - 2  * radius + 1);
    double y_center = radius + rand() % (int)(screen_height - 2 * radius + 1);
    int offset_angle = rand() % 90;
    // The sides can be from 3 to 10
    sides = 3 + (rand() % 8);
    points = new Point[sides];
    for(int i = 0, angle = offset_angle; i < sides; i++) {
        points[i].x = x_center + radius * cos(angle * 3.14 / 180);
        points[i].y = y_center + radius * sin(angle * 3.14 / 180);
        b->evaluate(points[i]);
        angle += 360.0 / sides;
    }

    sf::Uint8 r = getRandomFloat(255);
    sf::Uint8 g = getRandomFloat(255);
    sf::Uint8 b = getRandomFloat(255);
    sf::Uint8 a = getRandomFloat(255);

    color = sf::Color{r, g, b, a};
}

RegularPolygon::RegularPolygon(double sw, double sh) : Shape(sw, sh) {
    b = new BoundingBox(sw, sh);
    pips = new PointInPolygonStrategy();
}

bool RegularPolygon::Inside(const Point &p) {
    return pips->cn_PnPoly(p, points, sides);
}

bool RegularPolygon::doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

bool RegularPolygon::onSegment(Point p, Point q, Point r) {
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
        return true;
    return false;
}

int RegularPolygon::orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

void RegularPolygon::FillWithColor(sf::Uint8 *buffer) {
    Point p = {0, 0};
    for(int i = b->l.x; i <= b->h.x; i++) {
        for(int j = b->l.y; j <= b->h.y; j++){
            p.x = i, p.y = j;
            if (Inside(p)) {
                SetPixel(buffer, p);
            }
            }
        }
}