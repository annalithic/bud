#include <raylib.h>
#include <raymath.h>
#include <string>

#include "Ship.h"

#define PLAYER_SPEED 300
#define PLAYER_SPEED_FOCUS 120

Vector2 playerPosition;
float playerSpeed;

//input
bool lastPressedLeft;
bool lastPressedUp;

void GameInit() {
    playerPosition = Vector2{ 512, 512 };

    lastPressedLeft = false;
    lastPressedUp = false;
}


void GameLoop() {

    float deltaTime = GetFrameTime();
    
    float moveAmount = IsKeyDown(KEY_LEFT_SHIFT) ? PLAYER_SPEED_FOCUS : PLAYER_SPEED;
    playerPosition += Ship::GetPlayerMoveDirection() * moveAmount * deltaTime;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    DrawText(std::to_string(1 / deltaTime).c_str(), 8, 8, 20, GRAY);
    DrawCircle(playerPosition.x, playerPosition.y, 8, GREEN);
    EndDrawing();
}

int main(void) {
	InitWindow(900, 900, "game");
	SetTargetFPS(144);

    GameInit();

    while (!WindowShouldClose()) {
        GameLoop();
    }

    CloseWindow();

	return 0;
}

