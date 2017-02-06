//
// Created by Taehyung Kim on 1/30/17.
//

#ifndef SNIPPETS_CPP_CIRCLE_H
#define SNIPPETS_CPP_CIRCLE_H

#include <iostream>
#include "Shape.h"

class Circle: public Shape {
public:
    Circle(Point p, int rr): x{p}, r{rr}
    {
        std::cout << "Circle class: Circle()." << std::endl;
    }

    Point center() const { return x; }
    void move(Point to) { x=to; }
    void draw() const { std::cout << "Circle class: draw()." << std::endl; }
    void rotate(int) { std::cout << "Circle class: rotate()." << std::endl; }
    ~Circle() = default;
    friend std::ostream& operator<< (std::ostream& out, const Circle& circle);
private:
    Point x;
    int r;
};

std::ostream& operator<< (std::ostream& out, const Circle& circle)
{
    out << "Circle: " << circle.x << ", r=" << circle.r << std::endl;
    return out;
}

#endif //SNIPPETS_CPP_CIRCLE_H
