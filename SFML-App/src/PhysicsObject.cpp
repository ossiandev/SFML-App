#include "PhysicsObject.h"

//Updates positional oriented values according to time and reaction
void PhysicsObject::update(float dt)
{
    displacement = shape.getPosition();

    // Sum of the forces acting on the object
    sf::Vector2f totalForce = { 0.0f, 0.0f };
    
    for (const auto& force : forces)
    {
        totalForce += force;
    }


    acceleration = totalForce / mass;
    velocity += acceleration * dt * 0.001f;
    displacement += velocity * dt;
    shape.setPosition(displacement);
  
    if (colliding) {
        shape.setFillColor(sf::Color::Blue);
        colliding = false;
    }
    else 
    {
        shape.setFillColor(sf::Color::Red);
    }

    
}

//
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
PhysicsObject::PhysicsObject(sf::ConvexShape shape, float mass)
{
    this->shape = shape;
    this->mass = mass;
}

