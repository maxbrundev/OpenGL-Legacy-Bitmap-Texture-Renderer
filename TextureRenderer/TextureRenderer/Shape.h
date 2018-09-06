#pragma once

class Shape
{
private:
	GLfloat m_angle {0.0f};

	bool isAxis{ false };
	bool isLine{ false };
public:
	Shape() = default;
	~Shape() = default;

	void Draw();
	void Update();
	void HandleEvent(unsigned char p_key);

	void Axis();
	void Cube();
};

