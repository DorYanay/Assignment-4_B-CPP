#pragma once
#include <iostream>
#include <string>

class Point
{

    double AxisX;
    double AxisY;

public:
    Point(double AxisX, double AxisY);
    double distance(const Point &);
    void print();
    static Point moveTowards(Point, Point, double);
};
