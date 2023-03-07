#include "collision.h"


/*

Current Error: 
    collision.cpp code returns bools as 204 
    example

    Collision collision

    collision.AABBCollision(object1, object2)

    cout << objects[i].colliding 

    output: 
    204



*/

int main()
{
    Collision collision;
   
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fysik");
    std::cout << "New window opened\n";
    
    // Start clock
    sf::Clock clock;

    //Time to keep track of passed amount of time
    sf::Time time;
    sf::Time oldTime;

    

    // Specifies a specific value for the framerate
    window.setFramerateLimit(60);
    

    // Viewport
    sf::View view = window.getDefaultView();

    

    //List of objects on screen
    std::vector<PhysicsObject> objects;
    PhysicsObject object;
    object.shape = sf::ConvexShape(4);
    object.mass = 1;
    //Adding objects

    objects.push_back(object);
    objects.push_back(object);


    PhysicsObject sampleObject;

    objects.push_back(sampleObject);
    objects.push_back(sampleObject);
    objects[0].shape.setPointCount(4);
    objects[1].shape.setPointCount(4);

    

    
    //moving the points in the first object
    std::cout << "";
    objects[0].shape.setPosition(sf::Vector2f(500,500));
    objects[0].shape.setPoint(1, sf::Vector2f(100,0));
    objects[0].shape.setPoint(2, sf::Vector2f(100,100));
    objects[0].shape.setPoint(3, sf::Vector2f(0,100));  
    
    objects[1].shape.setPosition(sf::Vector2f(100,100));
    objects[1].shape.setPoint(1, sf::Vector2f(100,0));
    objects[1].shape.setPoint(2, sf::Vector2f(100,100));
    objects[1].shape.setPoint(3, sf::Vector2f(0,100));

    //fill with color
    objects[0].shape.setFillColor(sf::Color(255,0,0));
    objects[1].shape.setFillColor(sf::Color(255,0,0));

    objects[1].velocity = sf::Vector2f(0,2.f);

    objects[1].forces.push_back(sf::Vector2f(0, 10.f));
    objects[1].mass = 2;

    /*
    to make objects or move in a direction.
    you can change the following vectors in objects[i]

    objects[i].forces.push_back(sf::Vector2f(x,y))  adds forces in one direction. There is no limit to the max velocity it can gain.
    objects[i].velocity(sf::Vector2f(x,y)) gives object speed 
    objects[i].maxVelocity(sf::Vector2f(x,y)) set max speed. (not working because i havent coded it yet.)
    */


   
    while (window.isOpen()) {

        sf::Event event;
        //Window Updates
        while (window.pollEvent(event)) {
            // Close Event
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Window closed\n";
                window.close();
            }
       
        }
        

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            sqrt(pow((sf::Mouse::getPosition(window).x - (objects[0].shape.getPosition().x+50)), 2) +
                pow((sf::Mouse::getPosition(window).y - (objects[0].shape.getPosition().y+50)), 2)) < 100)
        {
            objects[0].shape.setPosition((float)sf::Mouse::getPosition(window).x-50, (float)sf::Mouse::getPosition(window).y-50);
        }
       
        /*
        collision.AABBCollision(objects[0], objects[1]);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            
            std::cout << objects[0].colliding << "\n";
        }
        */
       
      


        time = clock.getElapsedTime();

        //Update every objects position.
        for (int i = 0; i < objects.size(); i++)
        {
            objects[i].update(time.asSeconds()-oldTime.asSeconds());
        }
        //Time oldTime
        oldTime = time;
        
        //drag objects with mouse
        for (int i = 0; i < objects.size(); i++)
        {
            //distance formula
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                sqrt(pow((sf::Mouse::getPosition(window).x - (objects[i].shape.getPosition().x + 50)), 2) +
                    pow((sf::Mouse::getPosition(window).y - (objects[i].shape.getPosition().y + 50)), 2)) < 100)
            {
               
                objects[i].shape.setPosition((float)sf::Mouse::getPosition(window).x - 50, (float)sf::Mouse::getPosition(window).y - 50);
            }
        }
        
        //debugging tool. used to check values on console.
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            collision.AABBCollision(objects[0], objects[1]);
           // objects[0].updateBool();
           // objects[1].updateBool();
            //objects[1].colliding = Collision::AABBCollision(objects[0], objects[1]);
            std::cout << objects[0].colliding << " Object BOOL\n";
           // std::cout << objects[1].velocity.x << " " << objects[1].velocity.y << "\n";

        }
        else
        {
            for (int i = 0; i < objects.size(); i++) {
                objects[i].colliding = false;
            }
        }
        

        //Draw objects.

        window.clear();
        window.draw(objects[0].shape);
        window.draw(objects[1].shape);
        
 
        window.display();
    }

    return 0;

}




//Result'

// 