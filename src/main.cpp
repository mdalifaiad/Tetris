#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Titlebar | sf::Style::Close);

    sf::CircleShape circle;
    circle.setPosition(25, 25);
    circle.setOrigin(25, 25);
    circle.setRadius(50);

    circle.setFillColor(sf::Color(255, 255, 77));
    // set a 10-pixel wide orange outline
    // circle.setOutlineThickness(10.f);
    // circle.setOutlineColor(sf::Color(250, 150, 100));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                // window closed
                window.close();
            }
            // key pressed
            else if (event.type == sf::Event::KeyPressed)
            { // move the entity relatively to its current position
                circle.move(1.f, 5.f);
            }
            // we don't process other types of events
            else
            {

                break;
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);

        // end the current frame
        window.display();
    }

    return 0;
}