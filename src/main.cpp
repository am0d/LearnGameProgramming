#include <SFML/Graphics.hpp>

int main () {
    sf::RenderWindow app (sf::VideoMode (640, 480, 32), "SFML Window");

    sf::Texture texture;
    if (!texture.LoadFromFile("resources/platform.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    sprite.SetSubRect(sf::IntRect(485, 36, 19, 26));

    int left = 0, top = 0;

    bool running = true;
    while (running) {
        sf::Event event;
        while (app.PollEvent (event)) {
            switch (event.Type) {
                case sf::Event::Closed:
                    running = false;
                    break;
                case sf::Event::KeyPressed:
                    switch (event.Key.Code) {
                        case sf::Keyboard::Escape:
                            running = false;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        if (sf::Keyboard::IsKeyPressed  (sf::Keyboard::Left)) {
                            left--;
        }
        if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Right)) {
                            left++;
        }
        if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Up)) {
        top--;
        }
        if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Down)) {
                            top++;
        }


        // move the sprite
        sprite.SetPosition (left, top);

        app.Clear ();
        app.Draw (sprite);
        app.Display ();
    }

    return EXIT_SUCCESS;
}
