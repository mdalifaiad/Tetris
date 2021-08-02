#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800.f, 600.f), "My window" /*, sf::Style::Titlebar | sf::Style::Close*/);

    sf::CircleShape circle;
    circle.setPosition(25.f, 25.f);
    circle.setOrigin(25.f, 25.f);
    circle.setRadius(50.f);
    circle.setFillColor(sf::Color(255, 255, 77));

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
            } // catch the resize events
            else if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            // key pressed
            else if (event.type == sf::Event::KeyPressed)
            { // move the entity relatively to its current position
                if (event.key.code == sf::Keyboard::Up)
                {
                    circle.move(0.f, -5.f);
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    circle.move(0.f, 5.f);
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    circle.move(-5.f, 0.f);
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    circle.move(5.f, 0.f);
                }
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