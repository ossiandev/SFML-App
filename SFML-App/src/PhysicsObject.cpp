#include "PhysicsObject.h"


//Updates positional oriented values according to time and reaction
void PhysicsObject::update(float dt)
{
    //set where its going to where it is
    displacement = shape.getPosition();

    // Sum of the forces acting on the object
    sf::Vector2f totalForce = { 0.0f, 0.0f };
    
    for (const auto& force : forces)
    {
        totalForce += force;
    }

    //calculate velocity
    acceleration = totalForce / mass;
    velocity += acceleration * dt; 
   
    //check if it's colliding
    if (colliding) {

        shape.setFillColor(sf::Color::Blue);
        velocity = velocity * -1.f;

        for (int i = 0; i < forces.size(); i++)
        {
            forces[i] *= -1.f;
        }

    }
    // if it's not we change it back
    else if (!colliding)
    {

        shape.setFillColor(sf::Color::Red);

    }
    
    displacement += velocity * dt;
    shape.setPosition(displacement);
}

//very bad code, gonna rework
void PhysicsObject::vectorUpdateDrag(float drag)
{
    for (auto& i : forces) {
       
        // if x positive, drag negative
        
        if (i.x > 0)
        {
            i.x -= drag;
        }
        // if y positive, drag negative
        if (i.y > 0)
        {
            i.y -= drag;
        }
        // if y negative, drag positive
        if (i.y < 0)
        {
            i.y += drag;
        }
        // if x negative, drag positive
        if (i.x < 0)
        {
            i.x += drag;
        }
        //
        if (i.y <= 0.01f && i.y >= -0.01f) {
            i.y = 0;
        }       
        if (-0.01f >= i.x && i.x <= 0.01f  ) {
            i.x = 0;
        }

    }
    
}

//Constructor

/*
PhysicsObject::PhysicsObject(sf::ConvexShape shape, float mass) :
    shape(shape),
    mass(mass),
    displacement(sf::Vector2f()), 
    velocity(sf::Vector2f()),
    acceleration(sf::Vector2f()),
    maxVelocity(sf::Vector2f()),
    colliding(false) {};

*/




