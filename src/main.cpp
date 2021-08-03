#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    unsigned WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window" /*, sf::Style::Titlebar | sf::Style::Close*/);
    window.setFramerateLimit(144);

    sf::Clock clock;
    float dt, multiplier = 60.f;
    // sf::Vector2f velocity, v;
    // v.x = 8.f;
    // v.y = 8.f;

    const float gridSize = 50.f;

    // player
    sf::RectangleShape player;
    player.setPosition(gridSize / 2, gridSize / 2);
    player.setOrigin(gridSize / 2, gridSize / 2);
    // player.setRadius(50.f);
    // player.setFillColor(sf::Color(255, 255, 77));
    player.setSize(sf::Vector2f(gridSize, gridSize));

    // player texture
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/images/soilTexture.jpg");
    player.setTexture(&playerTexture);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window OR Esc window close
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                // window closed
                window.close();
            }

            // catch the resize events
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                WINDOW_WIDTH = event.size.width;
                WINDOW_HEIGHT = event.size.height;
                window.setView(sf::View(visibleArea));
            }
        }

        // frame update time
        dt = clock.restart().asSeconds();

        // Update

        // velocity
        // key pressed
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        // {
        //     v.x = 0.f;
        //     v.y = -5.f;
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        // {
        //     v.x = -5.f;
        //     v.y = 0.f;
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        // {
        //     v.x = 0.f;
        //     v.y = 5.f;
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        // {
        //     v.x = 5.f;
        //     v.y = 0.f;
        // }

        // velocity.x = v.x * dt * multiplier;
        // velocity.y = v.y * dt * multiplier;

        // // auto update
        // player.move(velocity.x, velocity.y);

        // if (player.getPosition().x < 0)
        // {
        //     player.setPosition(0, player.getPosition().y);
        //     v.x *= -1;
        // }
        // if (player.getPosition().y < 0)
        // {
        //     player.setPosition(player.getPosition().x, 0);
        //     v.y *= -1;
        // }
        // if (player.getPosition().x + gridSize > WINDOW_WIDTH)
        // {
        //     player.setPosition(WINDOW_WIDTH - gridSize, player.getPosition().y);
        //     v.x *= -1;
        // }
        // if (player.getPosition().y + gridSize > WINDOW_HEIGHT)
        // {
        //     player.setPosition(player.getPosition().x, WINDOW_HEIGHT - gridSize);
        //     v.y *= -1;
        // }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(player);

        // end the current frame
        window.display();
    }

    return 0;
}