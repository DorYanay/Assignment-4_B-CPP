#include "Ninja.hpp"
#include "Character.hpp"

Ninja::Ninja(string name, const Point &location, int hitpoints, int speed)
    : Character(name, location, hitpoints, 0), speed(speed) {}

void Ninja::move(const Character *enemy)
{
    if (!this->isAlive())
    {
        throw runtime_error("the dead is not a zombie. he is dead.\n");
    }
    if (this == enemy)
    {
        throw runtime_error("I SHALL NOT SELF MOVE!\n");
    }
    this->setLocation(Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed));
}
void Ninja::slash(Character *enemy)
{
    if (!this->isAlive())
    {
        throw runtime_error("the dead is not a zombie. he is dead.\n");
    }
    if (this == enemy)
    {
        throw runtime_error("I SHALL NOT SELF HARM!\n");
    }

    if (this->distance(enemy) < 1)
    {
        enemy->hit(40);
    }
    else
    {
        this->move(enemy);
    }
}
string Ninja::print()
{
    if (isAlive())
    {
        return "name: N" + this->getName() + ", hit points: " + to_string(this->getHitpoints()) + ", location: " + this->getLocation().print();
    }
    return "name: (N" + this->getName() + "), location: " + this->getLocation().print();
}