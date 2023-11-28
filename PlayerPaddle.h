#pragma once
class PlayerPaddle
{


public:
	PlayerPaddle();
	~PlayerPaddle();

	void Update();
	void Draw();

	float x;
	float y;
	float width;
	float height;
	float speed;

};

