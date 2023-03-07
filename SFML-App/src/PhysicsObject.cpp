#include "PhysicsObject.h"

void PhysicsObject::updateBool()
{
    if (!colliding)
    {
        //std::cout << "COLLIDING ";
        colliding = true;
       // std::cout << colliding<<" ";
    }
    else
    {

    }
}

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

    //calculate speed
    acceleration = totalForce / mass;

    velocity += acceleration * dt * 0.1f; // added 0.001f because it will go too fast otherwise
    displacement += velocity * dt;
    //after calculating where velocity would have moved it with time change position
    shape.setPosition(displacement);
    if (colliding) {
        shape.setFillColor(sf::Color::Blue);
    }
    else 
    {
        shape.setFillColor(sf::Color::Red);
    }

    //collision reaction. does not work bool 204
    //change color
    if (colliding == true) {
        
        shape.setFillColor(sf::Color::Blue);
        
    }
    //change color
    else if (colliding == false)
    {

        shape.setFillColor(sf::Color::Red);

    }
 
    
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
PhysicsObject::PhysicsObject(sf::ConvexShape shape, float mass)

void PhysicsObject::updateBool() 
{

}
//thought constructor was a problem. so used initizalation list with a constructor to get rid of bool 204 bug. still doesnt work... 

//Constructor

/*
PhysicsObject::PhysicsObject(sf::ConvexShape shape, float mass) :
    shape(shape), mass(mass),
    displacement(sf::Vector2f()), velocity(sf::Vector2f()), acceleration(sf::Vector2f()), maxVelocity(sf::Vector2f()),
    colliding(false) {};

*/




