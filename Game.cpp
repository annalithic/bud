#include <raylib.h>
#include <raymath.h>
#include <string>

#include "Ship.h"
#include "Bullet.h"

#define PLAYER_SPEED 300
#define PLAYER_SPEED_FOCUS 120

#define STAGE_WIDTH 1024
#define STAGE_HIGHT 1024

Vector2 playerPosition;
float playerSpeed;

Bullet testBullet;
float testSpawnTimer;
#define TEST_SPAWN_TIME 0.3;

//input
bool lastPressedLeft;
bool lastPressedUp;

void GameInit() {

    //todo
    new Stage(STAGE_WIDTH, STAGE_HIGHT);

    playerPosition = Vector2{ 512, 512 };

    lastPressedLeft = false;
    lastPressedUp = false;

    testBullet = Bullet(5, RED);
    testSpawnTimer = TEST_SPAWN_TIME;

    testBullet.Spawn(Vector2{ 50, 250 }, Vector2{ 0, 0 });
    testBullet.Spawn(Vector2{ 50, 350 }, Vector2{ 200, 0 });
}


void GameLoop() {

    float deltaTime = GetFrameTime();

    testSpawnTimer -= deltaTime;
    if (testSpawnTimer < 0) {
        testSpawnTimer = TEST_SPAWN_TIME;
        testBullet.Spawn(Vector2{ 50, 350 }, Vector2{ 200, 0 });
    }
    
    float moveAmount = IsKeyDown(KEY_LEFT_SHIFT) ? PLAYER_SPEED_FOCUS : PLAYER_SPEED;
    playerPosition += Ship::GetPlayerMoveDirection() * moveAmount * deltaTime;

    testBullet.Update(deltaTime);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangle(0, 0, Stage::activeStage->width, Stage::activeStage->height, DARKBLUE);

    //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    DrawText(std::to_string(testBullet.instances.size()).c_str(), 8, 8, 20, GRAY);
    DrawText(std::to_string(testBullet.GetCount()).c_str(), 8, 30, 20, GRAY);

    DrawCircle(playerPosition.x, playerPosition.y, 8, GREEN);

    for (int i = 0; i < testBullet.instances.size(); i++) {
        auto instance = testBullet.instances[i];
        //if(!instance.free)
        DrawCircle(instance.position.x, instance.position.y, testBullet.radius, instance.free ? YELLOW : testBullet.color);
    }

    EndDrawing();
}

int main(void) {
	InitWindow(1600, 1280, "game");
	SetTargetFPS(144);

    GameInit();

    while (!WindowShouldClose()) {
        GameLoop();
    }

    CloseWindow();

	return 0;
}

