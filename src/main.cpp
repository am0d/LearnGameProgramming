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

#include <list>
#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "item.hpp"

int main () {
    sf::RenderWindow app (sf::VideoMode (640, 480, 32), "SFML Window");

    sf::Texture texture;
    if (!texture.LoadFromFile("resources/platform.png")) {
        return EXIT_FAILURE;
    }

    // list of all game items
    std::list<Entity*> items;
    
    // Player entity
    Player* player = new Player ();
    player->SetTexture (texture);

    for (int i=0; i < 5; i++) {
        Item* item = new Item();
        item->SetTexture (texture);
        item->x = i*10;
        item->y = i*10;
        items.push_back (item);
    }

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

        // update all the items
        player->Update (elapsedTime);
        for (std::list<Entity*>::iterator i = items.begin ();
                i != items.end ();
                i++) {
            // update the entity
            (*i)->Update (elapsedTime);

            // check for any collisions
            if (player->CheckCollision (*i)) {
                        player->HandleCollision (*i);
                        (*i)->HandleCollision (player);
            }
        }

        std::list<Entity*>::iterator i = items.begin ();
        while (i != items.end ()) {
            if ((*i)->isDead) {
                delete *i;
                items.erase (i++);
            }
            else {
                i++;
            }
        }

        app.Clear ();
        player->Draw (app);
        for (std::list<Entity*>::iterator i = items.begin ();
                i != items.end ();
                i++) {
            (*i)->Draw (app);
        }
        app.Display ();
    }

    // clean up
    delete player;
    while (!items.empty()) {
        delete items.front ();
        items.pop_front ();
    }

    return EXIT_SUCCESS;
}
