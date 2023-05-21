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
        return;
    }
    Character *leader = this->getLeader();
    if (!leader->isAlive())
    {
        leader = this->getClosestMember(this);
    }
    while (this->stillAlive() && enemyTeam->stillAlive())
    {
        Character *victim = this->getClosestMember(enemyTeam);
        for (Character *member : *this->getTeam())
        {
            if (member->getRole())
            {
                if (member->isAlive())
                {
                    member->attack(this->getFarthestMember(member, enemyTeam));
                }
                if (!victim->isAlive())
                {
                    victim = this->getClosestMember(enemyTeam);
                }
            }
            if (!member->getRole())
            {
                if (member->isAlive())
                {
                    member->attack(this->getClosestMember(enemyTeam));
                }
                if (!victim->isAlive())
                {
                    victim = this->getClosestMember(enemyTeam);
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
