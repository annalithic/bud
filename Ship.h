#pragma once

#include <raylib.h>
#include <raymath.h>

class Ship {

private:
	static bool lastPressedLeft;
	static bool lastPressedUp;

public:
	static Vector2 GetPlayerMoveDirection();
};