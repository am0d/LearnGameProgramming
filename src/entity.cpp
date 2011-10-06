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

#include "entity.hpp"

Entity::Entity () :
    _sprite () {
    x = y = 0;
    xspeed = yspeed = 0;
    width = height = 0;
}

Entity::~Entity () {

}

void Entity::SetTexture (sf::Texture& texture) {
    _sprite.SetTexture (texture);
}

void Entity::SetSubRect (sf::IntRect& rect) {
    _sprite.SetSubRect (rect);
}

void Entity::Draw (sf::RenderTarget& target) {
    _sprite.SetPosition (x, y);
    target.Draw (_sprite);
}

void Entity::Update (int delta) {
    x += (xspeed * delta) / 1000;
    y += (yspeed * delta) / 1000;
}

bool Entity::CheckCollision (Entity& other) {
    return ((x < other.x + other.width) &&
            (x + width > other.x) &&
            (y < other.y + other.height) &&
            (y + height > other.y));
}

void Entity::HandleCollision (Entity&) {

}
