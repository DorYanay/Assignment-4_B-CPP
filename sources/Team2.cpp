#include "Character.hpp"
#include "Team2.hpp"
#include <vector>

Team2::Team2(Character *leader) : leader(leader) {}
Team2::Team2(const Team2 &other) : leader(other.leader) {}
Team2::Team2(Team2 &&other) noexcept
{
    leader = other.leader;
    team = other.team;
}

Team2 &Team2::operator=(const Team2 &other)
{
    leader = other.leader;
    team = other.team;
    return *this;
}

Team2 &Team2::operator=(Team2 &&other) noexcept
{
    leader = other.leader;
    team = other.team;
    return *this;
}
void Team2::add(Character *member) {}
void Team2::attack(Team2 *other) {}
int Team2::stillAlive() { return 0; }
void Team2::print() {}
Team2::~Team2() {}