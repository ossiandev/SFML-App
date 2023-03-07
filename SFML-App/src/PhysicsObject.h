#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include "omath.h"

                         //KOLLA ASTROIDS! ! ! 
struct PhysicsObject
{
    
    // Position, velocity, acceleration vectors and mass
    sf::Vector2f displacement;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f maxVelocity;
    float mass;
    //Storing shape in physicsobject
    sf::ConvexShape shape;

    //Bool for collision to enable reaction
    bool colliding;

    // Forces acting on the object
    std::vector<sf::Vector2f> forces;

    // Updates the object's position, velocity, and acceleration based on the forces acting on it
    void update(float dt);
    void vectorUpdateDrag(float drag);

    //Constructor, order is as follows: shape and then mass
    //PhysicsObject(sf::ConvexShape shape, float mass);

};

