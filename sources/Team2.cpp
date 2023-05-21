#include "Character.hpp"
#include "Team2.hpp"

Team2::Team2(Character *leader) : Team(leader) {}
Team2::Team2(const Team2 &other) : Team(other) {}
void Team2::attack(Team *enemyTeam)
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
        if (!victim->isAlive())
        {
            victim = this->getClosestMember(enemyTeam);
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
void Team2::print()
{
    for (Character *member : *this->getTeam())
    {
        cout << member->print() << endl;
    }
}
