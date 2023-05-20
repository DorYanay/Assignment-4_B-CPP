#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
namespace ariel
{
};
class Team
{
    Character *leader;
    vector<Character *> team;

public:
    Team(Character *leader);
    Team(const Team &);
    Team &operator=(const Team &);
    Team(Team &&) noexcept;
    Team &operator=(Team &&) noexcept;
    void add(Character *);
    void attack(Team *);
    int stillAlive();
    void print();
    ~Team();
};
