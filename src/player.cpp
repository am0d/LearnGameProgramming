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

#include "player.hpp"

Player::Player () :
    Entity () {
        xspeed = yspeed = 30.0f;
        width = 19;
        height = 26;
        _clippings[0] = sf::IntRect (485, 36, width, height);
        _clippings[1] = sf::IntRect (506, 36, width, height);
        _clippings[2] = sf::IntRect (485, 36, width, height);
        _clippings[3] = sf::IntRect (527, 36, width, height);
        _clippings[4] = sf::IntRect (485, 64, width, height);
        _clippings[5] = sf::IntRect (527, 64, width, height);
        _clippings[6] = sf::IntRect (506, 64, width, height);
        _clippings[7] = sf::IntRect (527, 64, width, height);

        _facing = RIGHT;
        _moving = false;

        _animTime = 0.0;
        _animSpeed = 5.0f;
}

Player::~Player () {

}

void Player::Update (int delta) {
    _moving = false;
    if (sf::Keyboard::IsKeyPressed  (sf::Keyboard::Left)) {
        x -= xspeed * delta / 1000.0f;
        _facing = LEFT;
        _moving = true;
    }
    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Right)) {
        x += xspeed * delta / 1000.0f;
        _facing = RIGHT;
        _moving = true;
    }
    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Up)) {
        y -= yspeed * delta / 1000.0f;
    }
    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Down)) {
        y += yspeed * delta / 1000.0f;
    }

    //update the animation if necessary
    if (_moving) {
        _animTime += _animSpeed * delta / 1000.0f;
        if (_animTime >= 4.0) _animTime = 0.0;
    }
    else {
        _animTime = 0;
    }
}

void Player::HandleCollision (Entity* ) {

}

void Player::Draw (sf::RenderTarget& target) {
    if (_facing == RIGHT) {
        if (_moving) {
            _sprite.SetSubRect (_clippings[(int)_animTime + 0]);
        }
        else {
            _sprite.SetSubRect (_clippings[0]);
        }
    }
    else {
        if (_moving) {
            _sprite.SetSubRect (_clippings[(int)_animTime + 4]);
        }
        else {
            _sprite.SetSubRect (_clippings[7]);
        }
    }
    Entity::Draw (target);
}
