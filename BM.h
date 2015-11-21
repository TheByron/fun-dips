#pragma once

#include <vector>
#include "Badguy.h"

class BM
{
public:
	BM();
	~BM();
	void update();
	void display();
	int checkCollision(double, double, float);
	void populate(int, int);

private:
	std::vector<Badguy> bay;
	int num_at_once = 0;
	int max_pop = 0;
};

