#include "Character.hpp"
#include "SmartTeam.hpp"
#include <vector>

SmartTeam::SmartTeam(Character *leader) : Team(leader) {}
SmartTeam::SmartTeam(const SmartTeam &other) : Team(other) {}
void SmartTeam::attack(Team *enemyTeam)
{
    if (!enemyTeam)
    {
        throw invalid_argument("WHERE IS THE ENEMY TEAM?!\n");
    }
    if (!enemyTeam->stillAlive())
    {
        throw runtime_error("You are defiling corpses\n");
    }
    Character *leader = this->getLeader();
    if (!leader->isAlive())
    {
        leader = this->getClosestMember(this);
    }

    Character *victim = this->getClosestMember(enemyTeam);
    for (Character *member : *this->getTeam())
    {
        if (member->getRole())
        {
            Character *victim = this->getFarthestMember(member, enemyTeam);
            if (!victim->isAlive())
            {
                victim = this->getFarthestMember(member, enemyTeam);
                if (!victim)
                {
                    return;
                }
            }
            if (member->isAlive())
            {
                member->attack(victim);
            }
        }
        else if (!member->getRole())
        {
            Character *victim = this->getClosestMemberSmart(member, enemyTeam);
            if (!victim->isAlive())
            {
                victim = this->getClosestMemberSmart(member, enemyTeam);
                if (!victim)
                {
                    return;
                }
            }
            if (member->isAlive())
            {
                member->attack(victim);
            }
        }
    }
}
void SmartTeam::print()
{
    for (Character *member : *this->getTeam())
    {
        cout << member->print() << endl;
    }
}
