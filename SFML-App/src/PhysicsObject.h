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
private:
    sf::Vector2f acceleration;
    sf::Vector2f displacement;
public:   
    // Position, velocity, acceleration vectors and mass
    sf::Vector2f velocity;
    sf::Vector2f maxVelocity;
    float mass;
    //Storing shape in physicsobject
    void updateBool();
    sf::ConvexShape shape;
    //Bool for collision to enable reaction
    bool colliding = false;

    // Forces acting on the object
    std::vector<sf::Vector2f> forces;

    // Updates the object's position, velocity, and acceleration based on the forces acting on it
    void update(float dt);
    void vectorUpdateDrag(float drag);

    //Constructor, order is as follows: shape nd then mass
    PhysicsObject(sf::ConvexShape shape, float mass);
    //Conclusion: All other things being equal, your code will run faster if you use initialization lists rather than assignment. -https://isocpp.org/wiki/faq/ctors#init-lists
// 
//Constructor with initialization list, syntax: sf::ConvexShape shape, float mass
/*
 PhysicsObject(sf::ConvexShape shape, float mass) :
     shape(shape), mass(mass),
     displacement(sf::Vector2f()), velocity(sf::Vector2f()), acceleration(sf::Vector2f()), maxVelocity(sf::Vector2f()),
     colliding(false){};
*/

};

