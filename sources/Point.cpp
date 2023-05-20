#include "Point.hpp"
using namespace std;

Point::Point(double AxisX, double AxisY) : AxisX(AxisX), AxisY(AxisY) {}
double Point::distance(const Point &other) { return 0; }
void Point::print() {}
Point Point::moveTowards(Point src, Point dst, double distance) { return Point(0, 0); }
