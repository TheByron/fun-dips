#include "BM.h"


BM::BM()
{
}


BM::~BM()
{
}

void BM::update(){
	for (int i = 0; i < bay.size(); i++){
		if (!bay[i].dead){	// only update living enemies
			bay[i].advance();
			if (bay[i].getZ() >= -5){
				bay[i].dead = true;
			}
		}
	}

	// go through and remove anything dead
	for (int i = 0; i < bay.size(); i++){
		if (bay[i].dead){
			bay.erase(bay.begin() + i);
		}
	}
}

void BM::display(){
	int num_to_show = num_at_once;
	unsigned int i = 0; 

	while (num_to_show > 0) {
		if (!bay[i].dead) {
			num_to_show -= 1;	// decrement remaining enemies to display

								// push a matrix on, translate to baddie's coords and draw
			glPushMatrix();
			glTranslatef(bay[i].getX(), 0, bay[i].getZ());
			bay[i].draw();
			glPopMatrix();
		}
		i++;
	}
	
}

int BM::checkCollision(double x, double z, float dam){
	for (int i = 0; i < bay.size(); i++){
		double radius = bay[i].getR();
		if (x >= (bay[i].getX() - radius) && x <= (bay[i].getX() + radius)){
			if (z >= (bay[i].getZ() - radius) && z <=(bay[i].getZ() + radius)){
				bay[i].doDmg(dam);
				return 0;
			}
		}
	}
	return -1;
}

void BM::populate(int wave_size, int total_population){
	num_at_once = wave_size;
	for (int i = 0; i < total_population; i++){
		Badguy temp;
		temp.randomize();
		bay.push_back(temp);
	}
}
