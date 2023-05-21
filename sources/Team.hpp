#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Character.hpp"
#include <climits>
using namespace std;
const int MAX_CAPACITY = 10;
namespace ariel
{
};
class Team
{
    Character *leader;
    vector<Character *> team;
    int current;

public:
    Character *getFarthestMember(Character *member, Team *team);
    Character *getClosestMemberSmart(Character *member, Team *team);
    Character *getLeader();
    vector<Character *> *getTeam();
    Team(Character *leader);
    Team(const Team &);
    Team &operator=(const Team &);
    Team(Team &&) noexcept;
    Team &operator=(Team &&) noexcept;
    virtual void add(Character *);
    virtual void attack(Team *);
    int stillAlive();
    void print();
    Character *getClosestMember(Team *team);
    ~Team();
};
