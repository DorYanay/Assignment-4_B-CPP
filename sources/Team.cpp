#include "Character.hpp"
#include "Team.hpp"
#include <vector>

Team::Team(Character *leader) : leader(leader) {}
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
void Team::add(Character *member) {}
void Team::attack(Team *other) {}
int Team::stillAlive() { return 0; }
void Team::print() {}
Team::~Team() {}