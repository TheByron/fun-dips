#pragma once

#include <stdlib.h>
#include <gl/glut.h>

class Badguy
{
public:
	Badguy();
	~Badguy();
	void destroy();
	void doDmg(float);
	void draw();
	void advance();
	void randomize();
	double getX();
	double getZ();
	double getR();
	double getHealth();
	bool dead = false;

private:
	double health = 40.0;
	double x = 0.0;
	double z = -300.0;
	double r = 0.6;
	
};

