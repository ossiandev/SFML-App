#include "PhysicsObject.h"

struct PhysicsObject
{
    // Position, velocity, acceleration vectors and mass
    sf::Vector2f displacement;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float mass = 1;





    // Forces acting on the object
    std::vector<sf::Vector2f> forces;

    // Updates the object's position, velocity, and acceleration based on the forces acting on it
    void update(float dt)
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
};