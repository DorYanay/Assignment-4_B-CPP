#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"
#include "Team2.hpp"
using namespace std;
class SmartTeam : public Team
{

public:
    SmartTeam(Character *leader);
    SmartTeam(const SmartTeam &);
    void attack(Team *);
    void print();
};
