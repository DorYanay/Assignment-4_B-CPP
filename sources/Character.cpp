#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"

Character::Character(string name, const Point &location, int hitpoints, bool isCowboy)
    : name(name), location(location), hitpoints(hitpoints), isCowboy(isCowboy), Team(false) {}
bool Character::isAlive()
{
    return this->hitpoints > 0;
}
double Character::distance(Character *other)
{
    return this->getLocation().distance(other->getLocation());
}
bool Character::getTeam()
{
    return this->Team;
}
bool Character::setTeam()
{
    return this->Team = true;
}
bool Character::getRole()
{
    return isCowboy;
}
void Character::hit(int dmg)
{
    if (dmg < 0)
        throw invalid_argument("MISSED BROTHA\n");
    if (hitpoints - dmg < 0)
    {
        this->hitpoints = 0;
    }
    else
    {
        this->hitpoints = hitpoints - dmg;
    }
};
string Character::getName() { return this->name; }
Point Character::getLocation() const { return this->location; }
void Character::setLocation(Point newLoc)
{
    this->location = newLoc;
}
int Character::getHitpoints()
{
    return this->hitpoints;
}
