#include "Cowboy.hpp"
#include "Character.hpp"

Cowboy::Cowboy(string name, const Point &location) : Character(name, location, 100, true), bullets(6) {}
void Cowboy::shoot(Character *enemy)
{
    if (!this->isAlive())
    {
        throw runtime_error("the dead is not a zombie. he is dead.\n");
    }
    if (this == enemy)
    {
        throw runtime_error("I SHALL NOT SELF HARM!\n");
    }
    if (!enemy->isAlive())
    {
        throw runtime_error("ATTACK A DEADMAN? you must be sick\n");
    }
    if (this->hasboolets() == false)
    {
        this->reload();
    }
    else
    {
        enemy->hit(10);
        this->bullets -= 1;
    }
}
bool Cowboy::hasboolets() { return 0 < bullets; }
void Cowboy::reload()
{
    if (!this->isAlive())
    {
        throw runtime_error("DEADMAN can`t reload\n");
    }
    else
    {
        bullets = 6;
    }
}
string Cowboy::print()
{
    if (isAlive())
    {
        return "name: (C)" + this->getName() + ", hit points: " + to_string(this->getHitpoints()) + ", location: " + this->getLocation().print();
    }
    return "name: (C)" + this->getName() + ", location: " + this->getLocation().print();
}