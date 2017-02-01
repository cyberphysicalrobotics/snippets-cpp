//
// Created by Taehyung Kim on 1/30/17.
//

#ifndef SNIPPETS_CPP_POINT_H
#define SNIPPETS_CPP_POINT_H

class Point
{
public:
    Point(int x, int y): _x{x}, _y{y} {}
    Point(): _x(0), _y(0) {}

    int _x, _y;
};
#endif //SNIPPETS_CPP_POINT_H
