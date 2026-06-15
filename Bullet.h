#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "Stage.h"
#include <queue>

class Instance {

public:
	Vector2 position;
	Vector2 velocity;
	bool free;

	Instance(Vector2 pos, Vector2 vel) {
		position = pos;
		velocity = vel;
		free = false;
	}
};

class Bullet {

private:
	Stage* stageRef;

	void RemoveInstance(int i);


public:
	float radius;
	Color color;

	std::queue<int> freeInstanceQueue;
	std::vector<Instance> instances;

	Bullet();

	Bullet(float radius, Color color);

	void Spawn(Vector2 position, Vector2 velocity);

	void Update(float deltaTime);

	int GetCount() {
		return instances.size() - freeInstanceQueue.size();
	}
};

