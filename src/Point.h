//
// Created by Taehyung Kim on 1/30/17.
//

#ifndef SNIPPETS_CPP_POINT_H
#define SNIPPETS_CPP_POINT_H
#include <iostream>

class Point
{
public:
    Point(int x, int y): _x{x}, _y{y} {}
    Point(): _x(0), _y(0) {}
    friend std::ostream& operator<< (std::ostream &out, const Point &point);

    int _x, _y;
};

std::ostream& operator<< (std::ostream &out, const Point &point)
{
    out << "Point(" << point._x << ", " << point._y << ")";
    return out;
}
#endif //SNIPPETS_CPP_POINT_H

