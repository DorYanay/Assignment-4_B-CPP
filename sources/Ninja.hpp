#pragma once
#include <iostream>
#include <string>
#include "Character.hpp"
using namespace std;
constexpr int YoungHP = 100;
constexpr int YoungSpeed = 14;
constexpr int TrainedHP = 120;
constexpr int TrainedSpeed = 12;
constexpr int OldHP = 150;
constexpr int OldSpeed = 8;

class Ninja : public Character
{
    int speed;

public:
    Ninja(string name, const Point &location, int hitpoints, int speed);
    void move(const Character *);
    void slash(Character *);
    string print() override;
    void attack(Character *enemy) override;
};
