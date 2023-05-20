#pragma once
#include <iostream>
#include <string>
#include "Character.hpp"

class Cowboy : public Character
{
    int bullets;

public:
    Cowboy(string name, const Point &location);
    void shoot(Character *);
    bool hasboolets();
    void reload();
};
