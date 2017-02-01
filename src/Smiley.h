//
// Created by Taehyung Kim on 1/30/17.
//

#ifndef SNIPPETS_CPP_SMILEY_H
#define SNIPPETS_CPP_SMILEY_H

#include <vector>
#include "Circle.h"
#include "Smiley.h"

class Smiley: public Circle {
public:
    Smiley(Point p, int r): Circle{p,r}, mouth{nullptr}
    {
        std::cout << "Smiley class: Smiley()." << std::endl;
    }

    ~Smiley()
    {
        std::cout << "Smiley class: ~Smiley()." << std::endl;
        delete mouth;
        for (auto p: eyes)
            delete p;
    }

    void move(Point to) { std::cout << "Smiley class: move()." << std::endl; }

    void draw() const;
    void rotate(int);

    void add_eye(Shape* s) { eyes.push_back(s); }
    void set_mouth(Shape* s) { mouth=s; }
    virtual void wink(int i) { std::cout << "Smiley class: wink()." << std::endl; }

private:
    std::vector<Shape*> eyes;
    Shape* mouth;
};

void Smiley::draw() const
{
    Circle::draw();
    for (auto p: eyes)
        p->draw();
    mouth->draw();
}

void Smiley::rotate(int angle)
{
    Circle::rotate(angle);
    for (auto p: eyes)
        p->rotate(angle);
    mouth->rotate(angle);
}

#endif //SNIPPETS_CPP_SMILEY_H
