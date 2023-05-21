#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"
#include "Team2.hpp"
class SmartTeam : public Team
{

public:
    SmartTeam(Character *leader);
    SmartTeam(const SmartTeam &);
    void attack(Team *);
    void print();
    Character *getFarthestMember(Character *member);
};
