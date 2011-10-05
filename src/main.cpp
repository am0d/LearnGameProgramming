#include <SFML/Window.hpp>

int main () {
    sf::Window app (sf::VideoMode (640, 480, 32), "SFML Window");

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

        app.Display ();
    }

    return EXIT_SUCCESS;
}
