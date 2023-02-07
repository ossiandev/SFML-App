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
    

    sf::ConvexShape shape;
    shape.setPointCount(4);
    shape.setPoint(0,sf::Vector2f(0, 0));
    shape.setPoint(1,sf::Vector2f(250,0));
    shape.setPoint(2,sf::Vector2f(150,200));
    shape.setPoint(3,sf::Vector2f(0, 120));
    shape.setFillColor(sf::Color::White);
    shape.setPosition(1280 / 3, 720 / 3);

    PhysicsObject polygon;
    polygon.mass = 1.f;
    polygon.displacement = shape.getPosition();
    polygon.shape = shape;

    

    

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
    polygon.forces.push_back(sf::Vector2f(0, 9.8f));

    
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
        std::cout << "Force " << polygon.forces[0].y << " Position: " << polygon.shape.getPosition().x << " " << polygon.shape.getPosition().y << "\n";
        std::cout << "Acceleration: " << polygon.acceleration.x << " " <<polygon.acceleration.y << " Velocity: " << polygon.velocity.x << " " << polygon.velocity.y << "\n";

        polygon.update(time.asSeconds());
        logicObject.update(time.asSeconds());
        circle.setPosition(logicObject.displacement);

        if (polygon.shape.getPosition().y <= 1030.f) { polygon.velocity.y * -1; polygon.forces[0].y * -1; }

        shape.setPosition(polygon.displacement);

        window.clear();

        window.draw(circle);
        window.draw(polygon.shape);
 
        window.display();
    }

    return 0;

}
