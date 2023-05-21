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
    if (!member->isAlive())
    {
        throw runtime_error("DEAD MAN - ARE YOU A NECROMANCER?\n");
    }
    if (member->getTeam() || team.size() > MAX_CAPACITY)
    {
        throw runtime_error("either a member is a spy or you are trying to build an army.\n");
    }
    team.push_back(member);
    member->setTeam();
}
Character *Team::getClosestMember(Character *leader)
{
    Character *closestCharacter = nullptr;
    float minDistance = std::numeric_limits<float>::max();

    for (Character *member : this->team)
    {
        if (member != leader && member->isAlive())
        {
            float currentDistance = leader->distance(member);
            if (currentDistance < minDistance)
            {
                minDistance = currentDistance;
                closestCharacter = member;
            }
        }
    }

    return closestCharacter;
}
Character *Team::getFarthestMember(Character *teammate)
{
    Character *farthestCharacter = nullptr;
    float maxDistance = -std::numeric_limits<float>::max(); // initially set to the smallest possible value

    for (Character *member : *this->getTeam())
    {
        if (member->isAlive())
        {
            float currentDistance = teammate->distance(member);
            if (currentDistance > maxDistance)
            {
                maxDistance = currentDistance;
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
        return;
    }
    if (!this->leader->isAlive())
    {
        this->leader = getClosestMember(leader);
    }
    while (this->stillAlive() && enemyTeam->stillAlive())
    {
        Character *victim = enemyTeam->getClosestMember(this->leader);
        for (Character *member : team)
        {
            if (member->getRole())
            {
                if (member->isAlive())
                {
                    member->attack(enemyTeam->getClosestMember(this->leader));
                }
                if (!victim->isAlive())
                {
                    victim = enemyTeam->getClosestMember(this->leader);
                }
            }
        }
        for (Character *member : team)
        {
            if (!member->getRole())
            {
                if (member->isAlive())
                {
                    member->attack(enemyTeam->getClosestMember(this->leader));
                }
                if (!victim->isAlive())
                {
                    victim = enemyTeam->getClosestMember(this->leader);
                }
            }
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