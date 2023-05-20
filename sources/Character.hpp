#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"
using namespace std;

class Character
{
    Point location;
    int hitpoints;
    string name;

public:
    Character(string, const Point &, int);
    bool isAlive();
    double distance(const Character *);
    void hit(int dmg);
    string getName();
    Point getLocation();
    string print();
};
