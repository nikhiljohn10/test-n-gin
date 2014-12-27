#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "libs/color.h"

using namespace std;

#include "libs/base.h"
#include "libs/GLbase.h"

char *easel;
int width, height, viewing_distance = 10;

void Point::drawPoint(int r = 255,int g = 255,int b = 255){
	int x,y;
	x = (width/2) + this->tuple[0] * viewing_distance / this->tuple[2]; 
	y = (height/2) + this->tuple[1] * viewing_distance / this->tuple[2]; 
	setpixel(easel, x, y, r, g, b);
	// setpixel2(x, y);
	cout<<"Point drawn at ( "<<this->tuple[0]<<", "<<this->tuple[1]<<", "<<this->tuple[2]<<" )."<< endl;
}


int main(int argc, char **argv) {

	cout<<"Welcome to Test nGIN"<<endl;
	width = 640;
	height = 480;
	easel = new char[width*height*3];

/*	for (int i = 0; i < 100; ++i){
		pointArray[i].tuple[0] = rand() % width + 1;
		pointArray[i].tuple[1] = rand() % height + 1;
		pointArray[i].tuple[2] = rand() % 40;
	}
*/
	glutInitWindowSize(width, height);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Test nGIN");

	myglinit();

	glutDisplayFunc(drawfunc);
	glutKeyboardFunc(keyfunc);

	glutMainLoop();
}

void drawfunc(void) {

	cout << "in drawfunc" << endl;

/*	Point point1(1,2,1);
	Point point2(0,4,4);
	Vector vector1(2,0,0);
	Vector vector2;

	point1.drawPoint(RED);
	point2.drawPoint(CYA);

	vector2 = point1.subtractPointFromPoint(point2);
	vector1 = vector1.addVectorToVector(vector2);

	point1 = point1.addVectorToPoint(vector1);
	point1.drawPoint(MAG);

	point2 = point2.subtractVectorFromPoint(vector2);
	point2.drawPoint(YEL);*/

// END OF TEST 1

/*	for (int j = 0; j < 100; ++j){
		pointArray[j].tuple[0] = rand() % width + 1;
		pointArray[j].tuple[1] = rand() % height + 1;
		pointArray[j].tuple[2] = rand() % 40;
		pointArray[j].drawPoint(RED);
	}*/

	Point pointArray(rand() % 40,1,1);
/*	pointArray.tuple[0] = rand() % width + 1;
	pointArray.tuple[1] = rand() % height + 1;
	pointArray.tuple[2] = rand() % 40;*/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	pointArray.drawPoint(RED);
	Sleep(100);
/*
	pointArray[1].tuple[0] = rand() % width + 1;
	pointArray[1].tuple[1] = rand() % height + 1;
	pointArray[1].tuple[2] = rand() % 40;
	pointArray[1].drawPoint(YEL);
*/
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, easel);
	glutSwapBuffers();
	glutPostRedisplay();
}

void setpixel(char *buf, int x, int y, int r=255, int g=255, int b=255) {
	buf[(y*width+x)*3+0] = r;
	buf[(y*width+x)*3+1] = g;
	buf[(y*width+x)*3+2] = b;
}

void putDot(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}