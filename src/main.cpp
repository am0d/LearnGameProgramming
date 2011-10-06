#include <SFML/Graphics.hpp>

int main () {
    sf::RenderWindow app (sf::VideoMode (640, 480, 32), "SFML Window");

    sf::Texture texture;
    if (!texture.LoadFromFile("resources/platform.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    bool running = true;
    while (running) {
        sf::Event event;
        while (app.PollEvent (event)) {
            switch (event.Type) {
                case sf::Event::Closed:
                    running = false;
                    break;
                case sf::Event::KeyPressed:
                    if (event.Key.Code == sf::Keyboard::Escape) {
                        running = false;
                    }
                    break;
                default:
                    break;
            }
        }

        app.Clear();
        app.Draw(sprite);
        app.Display ();
    }

    return EXIT_SUCCESS;
}
