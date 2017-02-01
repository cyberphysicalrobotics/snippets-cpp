//
// Created by Taehyung Kim on 1/30/17.
//

#ifndef SNIPPETS_CPP_TRIANGLE_H
#define SNIPPETS_CPP_TRIANGLE_H

#include <iostream>
#include "Shape.h"

using namespace std;

class Triangle: public Shape {
public:
    Triangle(Point p1, Point p2, Point p3): _p1{p1},_p2{p2}, _p3{p3} { cout << "Triangle class: Triangle()" << endl; }

    Point center() const {
        cout << "Triangle class: center()" << endl;
        return _p1;     // fake point.
    }
    void move(Point to) { cout << "Triangle class: move()" << endl; }
    void draw() const { cout << "Triangle class: draw()" << endl; }
    void rotate(int) { cout << "Triangle class: rotate()" << endl; }
    ~Triangle() = default;
private:
    Point _p1,_p2,_p3;
};
#endif //SNIPPETS_CPP_TRIANGLE_H
