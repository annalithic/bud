#include "Bullet.h"

void Bullet::RemoveInstance(int i) {
	instances[i].free = true;
	freeInstanceQueue.push(i);
}

Bullet::Bullet() {
	radius = 2;
	color = PINK;
	instances = std::vector<Instance>();
}

Bullet::Bullet(float radius, Color color) {
	stageRef = Stage::activeStage;
	this->radius = radius;
	this->color = color;
	this->instances = std::vector<Instance>();
}

void Bullet::Spawn(Vector2 position, Vector2 velocity) {
	if (freeInstanceQueue.empty())
		instances.push_back(Instance(position, velocity));
	else {
		int i = freeInstanceQueue.front(); freeInstanceQueue.pop();
		instances[i] = Instance(position, velocity);
	}
}

void Bullet::Update(float deltaTime) {
	for (int i = instances.size() - 1; i >= 0; i--) {
		if (instances[i].free) continue;
		Vector2 newPos = instances[i].position + instances[i].velocity * deltaTime;
		if (newPos.x < 0 || newPos.x > stageRef->width || newPos.y < 0 || newPos.y > stageRef->height) {
			RemoveInstance(i);
		} else {
			instances[i].position = newPos;
		}
	}
}
