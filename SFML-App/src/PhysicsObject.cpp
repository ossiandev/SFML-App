#include "PhysicsObject.h"


//Updates positional oriented values according to time 
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






