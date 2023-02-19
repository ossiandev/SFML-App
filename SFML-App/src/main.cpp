#include "PhysicsObject.h"


/*




*/

int main()
{


    // Create a window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fysik");
    std::cout << "New window opened\n";
    
    // Start clock
    sf::Clock clock;
    clock.restart();

    //Time to keep track of passed amount of time
    sf::Time time;
    

    // Specifies a specific value for the framerate
    window.setFramerateLimit(60);

    // Viewport
    sf::View view = window.getDefaultView();


    //List of objects on screen
    std::vector<PhysicsObject> objects;
    
    //Adding objects
    objects.push_back(PhysicsObject::PhysicsObject(sf::ConvexShape(4),1.f));
    objects.push_back(PhysicsObject::PhysicsObject(sf::ConvexShape(4),1.f));
    
    //moving the points in the first object
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
   
        
       
      


        time = clock.getElapsedTime();
        window.clear();
        window.draw(objects[0].shape);
        window.draw(objects[1].shape);
        
 
        window.display();
    }

    return 0;

}
