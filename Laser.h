#pragma once
#include <GL/glut.h>

class Laser
{
public:
	Laser();
	~Laser();
	void advance();
	void draw();
	double getZ();
	double getX();
	void set(double, double);

private:
	double x_loc = 0.0;
	double z_loc = 0.0;
	float dmg = 10.0f;
	float length = 0.5f;
};
