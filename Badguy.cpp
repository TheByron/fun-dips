#include "Badguy.h"


Badguy::Badguy()
{
}

Badguy::~Badguy()
{
}

void Badguy::doDmg(float d){
	health -= d;
	r -= 0.1;
	if (health <= 0){
		dead = true;
	}
}

void Badguy::draw(){
	if (!dead){
		glColor3f(1, 1, 1);
		glutSolidCube(r);
	}
}

void Badguy::advance(){
	z += 0.5;
}

void Badguy::randomize(){
	double ex = (double)(rand() % 40)/10 - 3.8;
	x = ex;
}

double Badguy::getX(){
	return x;
}

double Badguy::getZ(){
	return z;
}

double Badguy::getR(){
	return r;
}

double Badguy::getHealth(){
	return health;
}