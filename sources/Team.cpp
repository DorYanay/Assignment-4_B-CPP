#include "Character.hpp"
#include "Team.hpp"
#include <vector>
using namespace std;
Team::Team(Character *leader) : leader(leader)
{
    if (!leader->isAlive())
    {
        throw runtime_error("HOW A DEAD MAN CAN LEAD?\n");
    }
    if (leader->getTeam())
    {
        throw runtime_error("Going behind the enemy rank? not on my watch.\n");
    }
    team.push_back(leader);
    leader->setTeam();
}
Team::Team(const Team &other) : leader(other.leader) {}
Team::Team(Team &&other) noexcept
{
    leader = other.leader;
    team = other.team;
}

Team &Team::operator=(const Team &other)
{
    leader = other.leader;
    team = other.team;
    return *this;
}

Team &Team::operator=(Team &&other) noexcept
{
    leader = other.leader;
    team = other.team;
    return *this;
}
void Team::add(Character *member)
{

    if (team.size() == 10 || member->getTeam())
    {
        throw runtime_error("there are maximum 10 members that are not already in other teams");
    }

    if (!member->isAlive())
    {
        throw runtime_error("DEAD MAN - ARE YOU A NECROMANCER?\n");
    }
    team.push_back(member);
    member->setTeam();
}

Character *Team::getClosestMember(Team *other)
{
    Character *closestCharacter = nullptr;
    double minDistance = __DBL_MAX__;

    for (Character *member : other->team)
    {
        if (member->isAlive())
        {
            if (member->distance(this->leader) < minDistance)
            {
                minDistance = member->distance(this->leader);
                closestCharacter = member;
            }
        }
    }

    return closestCharacter;
}
Character *Team::getClosestMemberSmart(Character *teammate, Team *other)
{
    Character *closestCharacter = nullptr;
    double minDistance = __DBL_MAX__;

    for (Character *member : other->team)
    {
        if (member->isAlive())
        {
            if (member->distance(teammate) < minDistance)
            {
                minDistance = member->distance(teammate);
                closestCharacter = member;
            }
        }
    }

    return closestCharacter;
}
Character *Team::getFarthestMember(Character *teammate, Team *other)
{
    Character *farthestCharacter = nullptr;
    double maxDistance = __DBL_MIN__;

    for (Character *member : other->team)
    {
        if (member->isAlive())
        {
            if (member->distance(teammate) > maxDistance)
            {
                maxDistance = member->distance(teammate);
                farthestCharacter = member;
            }
        }
    }

    return farthestCharacter;
}
void Team::attack(Team *enemyTeam)
{
    if (!enemyTeam)
    {
        throw invalid_argument("WHERE IS THE ENEMY TEAM?!\n");
    }
    if (!enemyTeam->stillAlive())
    {
        throw runtime_error("You are defiling corpses\n");
    }
    if (!this->leader->isAlive())
    {
        this->leader = this->getClosestMember(this);
    }

    Character *victim = this->getClosestMember(enemyTeam);
    for (Character *member : team)
    {
        if (member->getRole())
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
        else
        {
            continue;
        }
    }
    for (Character *member : team)
    {
        if (!member->getRole())
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
        else
        {
            continue;
        }
    }
}
int Team::stillAlive()
{
    int alive = 0;
    for (Character *member : team)
    {
        if (member->isAlive())
        {
            alive++;
        }
    }
    return alive;
}
void Team::print()
{
    for (Character *member : team)
    {
        if (member->getRole())
        {
            cout << member->print() << endl;
        }
    }
    for (Character *member : team)
    {
        if (!member->getRole())
        {
            cout << member->print() << endl;
        }
    }
}
Team::~Team()
{
    for (Character *member : team)
    {
        team.pop_back();
    }
}
Character *Team::getLeader()
{
    return this->leader;
}
vector<Character *> *Team::getTeam()
{
    return &this->team;
}