#include "PhysicsObject.h"




int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fysik");
    std::cout << "New window opened\n";

    //visual object
    sf::CircleShape circle(100.f, 600);
    circle.setFillColor(sf::Color::Blue);
    //set start pos for visual objectt
    circle.setPosition(1280 / 2, 720 / 2);

    //Logic object

    PhysicsObject logicObject;
    logicObject.mass = 1.f;
    logicObject.displacement = circle.getPosition();


    

    // Specifies a specific value for the framerate
    window.setFramerateLimit(60);

    // Viewport
    sf::View view = window.getDefaultView();

    // Timer
    sf::Clock clock;
    clock.restart();
    sf::Time time;

    //add gravity
    logicObject.forces.push_back(sf::Vector2f(0, 9.8f));

    
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
            if (event.type == sf::Event::KeyPressed)
            {
                window.close();
                return 0;
            }
        }

        time = clock.getElapsedTime();

 
        logicObject.update(time.asSeconds());

        circle.setPosition(logicObject.displacement);


        window.clear();

        window.draw(circle);
        window.display();
    }

    return 0;

}
