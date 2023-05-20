#include "Character.hpp"

Character::Character(string name, const Point &location, int hitpoints) : name(name), location(location), hitpoints(hitpoints) {}
bool Character::isAlive() { return false; }
double Character::distance(const Character *other) { return 0; }
void Character::hit(int dmg){};
string Character::getName() { return ""; }
Point Character::getLocation() { return Point(0, 0); }
string Character::print() { return ""; }