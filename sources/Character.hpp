#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "Point.hpp"
using namespace std;

class Character
{
    Point location;
    int hitpoints;
    string name;
    int isCowboy;
    bool Team;

public:
    bool getRole();
    bool getTeam();
    bool setTeam();
    Character(string, const Point &, int hp, int isCowboy);
    void setLocation(Point);
    bool isAlive();
    int getHitpoints();
    virtual void attack(Character *enemy) = 0;
    double distance(Character *);
    void hit(int dmg);
    string getName();
    Point getLocation() const;
    virtual string print() = 0;
};
