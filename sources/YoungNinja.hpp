#pragma once
#include "Ninja.hpp"

class YoungNinja : public Ninja
{

public:
    YoungNinja(string name, const Point &location)
        : Ninja(std::move(name), location, YoungHP, YoungSpeed) {}
};
