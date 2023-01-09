#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "PhysicsObject.h"
#include "Object.h"




int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fysik");
    std::cout << "New window opened\n";



    Object object();


    //visual object
    sf::CircleShape circle(100.f, 600);
    circle.setFillColor(sf::Color::Blue);
    //set start pos for visual objectt
    circle.setPosition(1280 / 2, 720 / 2);

    //Logic object
    std::vector<PhysicsObject> objects;
    
    objects[0].mass = 1.f;
    objects[0].displacement = circle.getPosition();


    

    // Specifies a specific value for the framerate
    window.setFramerateLimit(60);

    // Viewport
    sf::View view = window.getDefaultView();

    // Timer
    sf::Clock clock;
    clock.restart();
    sf::Time time;

    //add gravity
    objects[0].forces.push_back(sf::Vector2f(0, 9.8f));

    
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

 
        objects[0].update(time.asSeconds());

        circle.setPosition(objects[0].position);


        window.clear();

        window.draw(circle);
        window.display();
    }

    return 0;

}
