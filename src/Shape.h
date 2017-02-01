//
// Created by Taehyung Kim on 1/30/17.
//

#ifndef SNIPPETS_CPP_SHAPE_H
#define SNIPPETS_CPP_SHAPE_H

#include "Point.h"

class Shape {
public:
    virtual Point center() const=0;
    virtual void move(Point to)=0;

    virtual void draw() const=0;
    virtual void rotate(int angle)=0;

    virtual ~Shape() { std::cout << "Shape class: virtual ~Shape()." << std::endl; }
};

#endif //SNIPPETS_CPP_SHAPE_H
