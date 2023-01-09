#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
struct PhysicsObject
{
    // Position, velocity, acceleration vectors and mass
    sf::Vector2f displacement;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float mass;

    //Constructor




    // Forces acting on the object
    std::vector<sf::Vector2f> forces;

    // Updates the object's position, velocity, and acceleration based on the forces acting on it
    void update(float dt);
};
