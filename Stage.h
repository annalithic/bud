#pragma once
class Stage {
public:
	static Stage* activeStage;

	float width;
	float height;

	Stage(float w, float h) {
		width = w;
		height = h;
		activeStage = this;
	}
};

