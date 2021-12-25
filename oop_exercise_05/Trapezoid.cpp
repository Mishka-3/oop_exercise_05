#include "Figure.h"
#include "Trapezoid.h"
#include "Point.h"
#include "cmath"
#include <iostream>
#include <vector>

Trapezoid::Trapezoid() : A(Point()), B(Point()), C(Point()), D(Point()) {
}

Trapezoid::Trapezoid(Point a, Point b, Point c, Point d) : A(a), B(b), C(c), D(d) {
}

Trapezoid::Trapezoid(Trapezoid& s)
{
    this->A = s.A;
    this->A = s.B;
    this->A = s.C;
    this->A = s.D;
}



Trapezoid::Trapezoid(std::istream& in) {
    in >> A >> B >> C >> D;
}

Trapezoid::Trapezoid(vector<Point> v) : A(v[0]), B(v[1]), C(v[2]), D(v[3]) {

    cout << "Trapezoid " << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << " was created" << endl;
}


double Trapezoid::get_Area() {
    double Area;
    Area = 0.5 * (A.get_X() * B.get_Y() + B.get_X() * C.get_Y() + C.get_X() * D.get_Y()
        - B.get_X() * A.get_Y() - C.get_X() * B.get_Y() - D.get_X() * C.get_Y());
    return std::abs(Area);
}

Point Trapezoid::get_center() {
    double x, y;
    x = (A.get_X() + B.get_X() + C.get_X() + D.get_X()) / 4.0;
    y = (A.get_Y() + B.get_Y() + C.get_Y() + D.get_X()) / 4.0;
    Point center(x, y);
    return center;
}
size_t Trapezoid::get_Vertex() {
    return (size_t)(4);
}

std::ostream& operator<<(std::ostream& out, Trapezoid& S) {
    out << S.A << ' ' << S.B << ' ' << S.C << ' ' << S.D << "\n";
    return out;
}
std::ostream& operator<<(std::ostream& out, vector<Point> v) {
    out << " Trapezoid" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << " was created" << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Trapezoid& S) {
    in >> S.A >> S.B >> S.C >> S.D;
    return in;
}

bool Trapezoid::operator==(const Trapezoid& S) {
    return ((A == S.A) && (B == S.B) && (C == S.C) && (D == S.D));
}

Trapezoid& Trapezoid::operator=(const Trapezoid& S) {
    if (this == &S) {
        return *this;
    }
    A = S.A;
    B = S.B;
    C = S.C;
    D = S.D;
    return *this;
}
