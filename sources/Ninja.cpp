#include "Ninja.hpp"
#include "Character.hpp"

Ninja::Ninja(string name, const Point &location, int hitpoints, int speed)
    : Character(name, location, hitpoints), speed(speed) {}

void Ninja::move(const Character *enemy) {}
void Ninja::slash(Character *enemy) {}