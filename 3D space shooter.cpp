#include <ctime>
#include <iostream>
#include <math.h>
#include <vector>
#include <gl/glut.h>
#include "laser.h"
#include "Badguy.h"
#include "BM.h"

using namespace std;

float p_x = 0.0f;
vector<Laser> lasers;
BM bmanager;	// class that manages all the bad guys

void drawLanes(){
	glLineWidth(1);
	glColor3f(0.0, 1.0, 0.0);

	for (int x = -4; x < 5; x++){
		glBegin(GL_LINES);
		glVertex3f(x, 0, -500);
		glVertex3f(x, 0, 10);
		glEnd();
	}
}

void drawShip(){
	// just using a wiresphere for quick testing
	glColor3f(0, 0, 0);
	glutWireSphere(0.5f, 20, 20);
}

void drawSightLine(){
	glColor3f(1, 0.7, 0);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex3f(p_x, 0.0f, -0.5);
	glVertex3f(p_x, 0.0f, -200);
	glEnd();
}

void drawLasers(){
	for (int i = 0; i < lasers.size(); i++){
		lasers[i].draw();
	}
}

void updateLasers(){
	for (int i = 0; i < lasers.size(); i++){
		lasers[i].advance();
	}

	for (int i = 0; i < lasers.size(); i++){
		if (lasers[i].getZ() >= 50){
			lasers.erase(lasers.begin() + i);
		}
	}
}

void drawEverything(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		0, 2, 8,
		0, 0, -5,
		0, 1, 0
	);

	// Draw the lane lines first
	drawLanes();

	// Then draw the player
	glPushMatrix();
	glTranslatef(p_x, 0.1f, 0);
	drawShip();
	glPopMatrix();

	bmanager.display();
	drawSightLine();		// draw the player's sight beam
	drawLasers();			// draw the laser beams
	

	glutSwapBuffers();
	glFlush();
}

void init(){
	glClearColor(0.3, 0.3, 0.3, 1.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0f, 1.0, 0.1f, 500.0f);
}

void displayCB(){
	drawEverything();
}

void specKeys(int key, int x, int y){
	
}

void normKeys(unsigned char key, int x, int y){
	if (key == 'a' && p_x > -3.8){
		p_x -= 0.1f;
	}
	if (key == 'd' && p_x < 3.8){
		p_x += 0.1f;
	}
	if (key == ' '){
		
	}

	glutPostRedisplay();
}

void mouseClick(int b, int s, int x, int y){
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN){
		Laser las;
		las.set(p_x, 0);
		lasers.push_back(las);
	}
}

void timer(int timer_id){
	// timer function callback
	if (timer_id == 1){		// updates laser beams
		updateLasers();
		glutTimerFunc(10, timer, 1);
	}

	if (timer_id == 2){		// updates enemies
		bmanager.update();
		glutTimerFunc(10, timer, 2);
	}

	glutPostRedisplay();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);

	// Window setup
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Space Shooter!");
	glutInitDisplayMode(GLUT_DOUBLE);
	init();

	// Register callbacks
	glutDisplayFunc(displayCB);
	glutSpecialFunc(specKeys);
	glutKeyboardFunc(normKeys);
	glutMouseFunc(mouseClick);
	glutTimerFunc(10, timer, 1);
	glutTimerFunc(10, timer, 2);

	// create bad guys
	bmanager.populate(2, 10);

	// Enter main loop
	glutMainLoop();
}