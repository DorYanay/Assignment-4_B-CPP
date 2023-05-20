#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"

class Team2
{
    Character *leader;
    vector<Character *> team;

public:
    Team2(Character *leader);
    Team2(const Team2 &);
    Team2 &operator=(const Team2 &);
    Team2(Team2 &&) noexcept;
    Team2 &operator=(Team2 &&) noexcept;
    void add(Character *);
    void attack(Team2 *);
    int stillAlive();
    void print();
    ~Team2();
};
