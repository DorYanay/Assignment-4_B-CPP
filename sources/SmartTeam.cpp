#include "Character.hpp"
#include "SmartTeam.hpp"
#include <vector>

SmartTeam::SmartTeam(Character *leader) : leader(leader) {}
SmartTeam::SmartTeam(const SmartTeam &other) : leader(other.leader) {}
SmartTeam::SmartTeam(SmartTeam &&other) noexcept
{
    leader = other.leader;
    team = other.team;
}

SmartTeam &SmartTeam::operator=(const SmartTeam &other)
{
    leader = other.leader;
    team = other.team;
    return *this;
}

SmartTeam &SmartTeam::operator=(SmartTeam &&other) noexcept
{
    leader = other.leader;
    team = other.team;
    return *this;
}
void SmartTeam::add(Character *member) {}
void SmartTeam::attack(SmartTeam *other) {}
int SmartTeam::stillAlive() { return 0; }
void SmartTeam::print() {}
SmartTeam::~SmartTeam() {}
