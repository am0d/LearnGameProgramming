/* Copyright (c) 2011 by Damien Schoof
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *       
 * 3. This notice may not be removed or altered from any source
 *    distribution.
 */

#include <SFML/Graphics.hpp>

#include "player.hpp"

int main () {
    sf::RenderWindow app (sf::VideoMode (640, 480, 32), "SFML Window");

    sf::Texture texture;
    if (!texture.LoadFromFile("resources/platform.png")) {
        return EXIT_FAILURE;
    }
    Player ent;
    ent.SetTexture (texture);

    bool running = true;
    sf::Clock clock;
    int elapsedTime;

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
        elapsedTime = clock.GetElapsedTime ();
        clock.Reset ();

        ent.Update (elapsedTime);
        // move the sprite
        //sprite.SetPosition (left, top);

        app.Clear ();
        ent.Draw (app);
        app.Display ();
    }

    return EXIT_SUCCESS;
}
