
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

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

typedef enum FacingDirection {
    LEFT,
    RIGHT
} FacingDirection;

class Player : public Entity {
    public:
        Player ();
        ~Player ();

        void HandleCollision (Entity* other);
        
        void Update (int delta);
        void Draw (sf::RenderTarget& target);

    private:
        sf::IntRect _clippings[8];   // the clipping rectangles for the different frames
        FacingDirection _facing;    // direction the player is facing
        bool _moving;               // is the player moving
};

#endif
