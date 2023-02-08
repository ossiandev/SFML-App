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
    
    for (const auto& force : forces)
    {
        totalForce += force;
    }

    //calculate drag
    sf::Vector2f drag; 

    if(abs(velocity.x) < 0.01f)
    {
        drag.x = (velocity.x * -0.2f) / mass;
    }
    if(abs(velocity.y) < 0.01f)
    {
        drag.y = (velocity.y * -0.2f) / mass;
    }
    

    acceleration = totalForce / mass;
    
    velocity += acceleration * dt * 0.001f;
    displacement += velocity * dt;
    shape.setPosition(displacement);
  
    if (abs(velocity.x) >= 0.02f || abs(velocity.y) >= 0.02f)
    {
        velocity += drag;
    }

    //collision with ground.
    
    if (shape.getPosition().y >= 600)
    {
        //adds bounce
        velocity.y *=  -1.0f;
        velocity.x *=  -1.0f;
        
    }
    

    
}
void PhysicsObject::addGravity()
{
    forces.push_back(gravity);
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
    
   /*
   search x shadows along screen axis
   findlargestxcorner
   findsmallestxcorner for shape
   then
   findlargestxcorner
   findsmallestxcorner for other
   if(shape largest x is bigger than smaller other smallest x or other way around then collision between shadows is true) 

   search y shadows along screen axis
   repeat same steps for x axis but instead y

   
   
   */
    OMath::FindLargestXSide(shape);
    OMath::FindSmallestXSide(shape);
    OMath::FindLargestXSide(other);
    OMath::FindSmallestXSide(other);







}