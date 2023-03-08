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
    sf::ConvexShape shape;
    //Bool for collision to enable reaction
    bool colliding = false;

    //Allow one object to be dragged
    bool beingDragged = false;
    // Forces acting on the object
    std::vector<sf::Vector2f> forces;

    // Updates the object's position, velocity, and acceleration based on the forces acting on it
    void update(float dt);
    void vectorUpdateDrag(float drag);


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

