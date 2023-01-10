#include "PhysicsObject.h"

void PhysicsObject::update(float dt)
{
    //if collision detected

    /*
    if(collision==true){
    forces.pushback(forces.sum())
    }
    */

    // Sum the forces acting on the object
    sf::Vector2f totalForce = { 0.0f, 0.0f };
    for (const auto& force : forces) {
        totalForce += force;
    }




    acceleration = totalForce / mass;
    velocity += acceleration * dt * 0.2f;
    displacement += velocity * dt;

}