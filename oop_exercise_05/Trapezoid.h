#ifndef OOP_EXERCISE_05_TRAPEZOID_H
#define OOP_EXERCISE_05_TRAPEZOID_H

#include "Point.h"
#include "Figure.h"
#include <vector>

using namespace std;

class Trapezoid : Figure {
public:
    Point A, B, C, D;
public:
    Trapezoid(vector<Point> v);
    //Trapezoid(Vector<Point> v);
    Trapezoid(std::istream& in);
    size_t get_Vertex();
    double get_Area();
    Trapezoid();
    Trapezoid(Trapezoid& s);
    Trapezoid(Point a, Point b, Point c, Point d);
    Point get_center();
    friend std::istream& operator>>(std::istream& in, const Trapezoid& S);
    friend std::ostream& operator<<(std::ostream& out, Trapezoid& S);
    friend std::ostream& operator<<(std::ostream& out, vector<Point> v);

    
    Trapezoid& operator= (const Trapezoid& S);
    bool operator== (const Trapezoid& S);
};
#endif 
