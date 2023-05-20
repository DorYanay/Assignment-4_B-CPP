#pragma once
#include <iostream>
#include <string>
#include "Character.hpp"

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
};

class YoungNinja : public Ninja
{

public:
    YoungNinja(string name, const Point &location)
        : Ninja(std::move(name), location, YoungHP, YoungSpeed) {}
};

class TrainedNinja : public Ninja
{

public:
    TrainedNinja(string name, const Point &location)
        : Ninja(std::move(name), location, TrainedHP, TrainedSpeed) {}
};

class OldNinja : public Ninja
{

public:
    OldNinja(string name, const Point &location)
        : Ninja(std::move(name), location, OldHP, OldSpeed) {}
};
