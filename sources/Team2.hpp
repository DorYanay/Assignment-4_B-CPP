#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Team.hpp"

class Team2 : public Team
{
public:
    Team2(Character *leader);
    Team2(const Team2 &);
    void attack(Team *);
    void print();
};
