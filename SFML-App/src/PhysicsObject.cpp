#include "PhysicsObject.h"

void PhysicsObject::update(float dt)
{
    //if collision detected

    /*
    if(collision==true){
    forces.pushback(forces.sum())
    }
    */

    // Sum of the forces acting on the object
    sf::Vector2f totalForce = { 0.0f, 0.0f };
    PhysicsObject::vectorUpdateDrag(0.01);
    for (const auto& force : forces)
    {
        totalForce += force;
    }
    



    acceleration = totalForce / mass;
    velocity += acceleration * dt * 0.001f;
    displacement += velocity * dt;

}
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

void PhysicsObject::checkCollision(sf::ConvexShape other)
{

}