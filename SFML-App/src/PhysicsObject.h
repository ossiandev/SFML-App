#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "omath.h"
//KOLLA ASTROIDS! ! ! 
struct PhysicsObject
{
    // Position, velocity, acceleration vectors and mass
    sf::ConvexShape shape;
    sf::Vector2f displacement;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f maxVelocity;
    //gravity
    sf::Vector2f gravity = sf::Vector2f(0,9.8f);
   
    float mass;

    // Forces acting on the object
    std::vector<sf::Vector2f> forces;



    // Updates the object's position, velocity, and acceleration based on the forces acting on it
    void update(float dt);

    void addGravity();

    void vectorUpdateDrag(float drag);

    //Check if colliding with other PhysicsObject
    void checkCollision(sf::ConvexShape other);
};
