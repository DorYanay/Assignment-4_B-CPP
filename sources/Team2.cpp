#include "Character.hpp"
#include "Team2.hpp"

Team2::Team2(Character *leader) : Team(leader) {}
Team2::Team2(const Team2 &other) : Team(other) {}
void Team2::attack(Team *enemyTeam)
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
        leader = getClosestMember(leader);
    }
    while (this->stillAlive() && enemyTeam->stillAlive())
    {
        Character *victim = enemyTeam->getClosestMember(leader);
        for (Character *member : *this->getTeam())
        {
            if (member->isAlive())
            {
                member->attack(enemyTeam->getClosestMember(leader));
            }
            if (!victim->isAlive())
            {
                victim = enemyTeam->getClosestMember(leader);
            }
        }
    }
}
void Team2::print()
{
    for (Character *member : *this->getTeam())
    {
        cout << member->print() << endl;
    }
}
