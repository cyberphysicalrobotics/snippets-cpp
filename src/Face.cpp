//
// Created by Taehyung Kim on 1/30/17.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Circle.h"
#include "Point.h"
#include "Shape.h"
#include "Smiley.h"
#include "Triangle.h"

enum class Kind { circle, triangle, smiley };

inline std::istream& operator>>(std::istream& str, Kind& k)
{
    unsigned int kind=0;
    if (str >> kind)
        k=static_cast<Kind>(kind);

    return str;
}

Shape* read_shape(std::istream& is)
{
    Kind k;
    int x1,y1,r1;
    int x2,y2,r2;
    int x3,y3,r3;
    int x4,y4,r4;

    is>>k;

    switch (k) {
        case Kind::circle:
            is>>x1>>y1>>r1;
            return new Circle{{x1,y1},r1};
        case Kind::triangle:
            is>>x1>>y1>>x2>>y2>>x3>>y3;
            return new Triangle{{x1,y1},{x2,y2},{x3,y3}};
        case Kind::smiley:
            is>>x1>>y1>>r1;
            is>>x2>>y2>>r2;
            is>>x3>>y3>>r3;
            is>>x4>>y4>>r4;
            Smiley* ps = new Smiley{{x1,y1},r1};
            Circle* e1 = new Circle{{x2,y2},r2};
            Circle* e2 = new Circle{{x3,y3},r3};
            Circle* m = new Circle{{x4,y4},r4};
            ps->add_eye(e1);
            ps->add_eye(e2);
            ps->set_mouth(m);
            return ps;
    }
}

void rotate_all(vector<Shape*>& v, int angle)
{
    std::cout << "rotate_all" << endl;
    for (auto p: v)
        p->rotate(angle);
}

void draw_all(vector<Shape*>& v)
{
    std::cout << "draw_all" << endl;
    for (auto p: v)
        p->draw();
}

void user()
{
    std::vector<Shape*> v;

    ifstream infile("afile.dat");

    while (!infile.eof())
        v.push_back(read_shape(infile));

    rotate_all(v,45);
    draw_all(v);

    infile.close();
}

int main()
{
    user();
}

//#include <iostream>
//#include <fstream>
//using namespace std;
//int main ()
//{
//ifstream input_file("afile.dat");
//if (!input_file.is_open()) {  // check for successful opening
//cout << "Input file could not be opened! Terminating!" << endl;
//return 1;   }
//ofstream output_file("data.output");  // open the output file
//if (!output_file.is_open()) { // check for successful opening
//cout << "Output file could not be opened! Terminating!" << endl;
//return 1;   }
//// read as long as the stream is good - any problem, just quit.
//// output is each number times two on a line by itself
//int datum;
//while (input_file >> datum) {
//    cout<<datum;
//output_file << datum * 2 << endl;
//}
//input_file.close();
//output_file.close();
//cout << "Done!" << endl;
//return 0;
//}