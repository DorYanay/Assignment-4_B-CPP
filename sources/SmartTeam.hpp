#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"
#include "Team2.hpp"
class SmartTeam
{
    Character *leader;
    vector<Character *> team;

public:
    SmartTeam(Character *leader);
    SmartTeam(const SmartTeam &);
    SmartTeam &operator=(const SmartTeam &);
    SmartTeam(SmartTeam &&) noexcept;
    SmartTeam &operator=(SmartTeam &&) noexcept;
    void add(Character *);
    void attack(SmartTeam *);
    int stillAlive();
    void print();
    ~SmartTeam();
};
