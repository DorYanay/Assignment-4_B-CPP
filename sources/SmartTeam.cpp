#include "Character.hpp"
#include "SmartTeam.hpp"
#include <vector>

SmartTeam::SmartTeam(Character *leader) : Team(leader) {}
SmartTeam::SmartTeam(const SmartTeam &other) : Team(other) {}
void SmartTeam::attack(Team *enemyTeam)
{
    if (!enemyTeam)
    {
        throw runtime_error("WHERE IS THE ENEMY TEAM?!\n");
    }
    if (!enemyTeam->stillAlive())
    {
        return;
    }
    Character *leader = this->getLeader();
    if (!leader->isAlive())
    {
        leader = this->getClosestMember(leader);
    }
    while (this->stillAlive() && enemyTeam->stillAlive())
    {
        Character *victim = enemyTeam->getClosestMember(leader);
        for (Character *member : *this->getTeam())
        {
            if (member->getRole())
            {
                if (member->isAlive())
                {
                    member->attack(enemyTeam->getFarthestMember(member));
                }
                if (!victim->isAlive())
                {
                    victim = enemyTeam->getClosestMember(leader);
                }
            }
            if (!member->getRole())
            {
                if (member->isAlive())
                {
                    member->attack(enemyTeam->getClosestMember(member));
                }
                if (!victim->isAlive())
                {
                    victim = enemyTeam->getClosestMember(leader);
                }
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
