#pragma once
#include "Force.hpp"
#include "Program.hpp"
#include "Component.hpp"
#include <vector>

class Machine {
    int perspective_point[3];
    std::vector<Component::Instance> components;
public:
    void draw();
    void iterate();
    void pan(int [3]);
    void bind(Component::Instance);
    Machine(int [3]);
}