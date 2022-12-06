#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fysik");
    std::cout << "New window opened\n";

    // Specifies a specific value for the framerate
    window.setFramerateLimit(60);


        
    // Circle1 shape
    sf::CircleShape circle1(100.0f);
    circle1.setFillColor(sf::Color::Blue);
    circle1.setPosition(500,500);

    // Circle2
    sf::CircleShape circle2(100.0f);
    circle2.setFillColor(sf::Color::Green);
    circle2.setPosition(800, 200);

    // Viewport
    sf::View view = window.getDefaultView();

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
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

        if (sf::Mouse::isButtonPressed) { 
        circle2.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y); 
        }

        float distX = circle1.getPosition().x - circle2.getPosition().x;
        float distY = circle1.getPosition().y - circle2.getPosition().y;
        float distance = sqrt((distX * distX) + (distY * distY));

        if (distance <= circle1.getRadius() + circle2.getRadius()) {
            circle1.setFillColor(sf::Color::Cyan);
        }
        else {
            circle1.setFillColor(sf::Color::Green);
        }

        window.clear();

        window.draw(circle1);
        window.draw(circle2);


        window.display();
    }

    return 0;
}