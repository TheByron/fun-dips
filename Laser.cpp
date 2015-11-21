#include "Laser.h"

Laser::Laser()
{
}

Laser::~Laser()
{
}

void Laser::advance(){
	// Advances the laser beam a little bit down the field
	z_loc -= 0.1;
}

void Laser::draw(){
	// x and z are for the front end of the laser
	glLineWidth(2);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(x_loc, 0.0, z_loc);
	glVertex3f(x_loc, 0.0, z_loc + length);
	glEnd();
}

double Laser::getZ(){
	return z_loc;
}

double Laser::getX(){
	return z_loc;
}

void Laser::set(double X, double Z){
	x_loc = X;
	z_loc = Z;
}
