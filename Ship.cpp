#include "Ship.h"

bool Ship::lastPressedLeft = false;
bool Ship::lastPressedUp = false;

Vector2 Ship::GetPlayerMoveDirection() {
    float x = 0;
    float y = 0;

    if (IsKeyPressed(KEY_LEFT)) Ship::lastPressedLeft = true;
    if (IsKeyPressed(KEY_RIGHT)) Ship::lastPressedLeft = false;
    if (IsKeyPressed(KEY_UP)) Ship::lastPressedUp = true;
    if (IsKeyPressed(KEY_DOWN)) Ship::lastPressedUp = false;

    if (IsKeyDown(KEY_LEFT) && (Ship::lastPressedLeft || !IsKeyDown(KEY_RIGHT))) {
        x = -1;
    } else if (IsKeyDown(KEY_RIGHT)) {
        x = 1;
    }

    if (IsKeyDown(KEY_UP) && (Ship::lastPressedUp || !IsKeyDown(KEY_DOWN))) {
        y = -1;
    } else if (IsKeyDown(KEY_DOWN)) {
        y = 1;
    }

    return Vector2Normalize(Vector2{ x,y });

}
