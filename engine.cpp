#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "libs/color.h"

using namespace std;

#include "libs/base.h"
#include "libs/GLbase.h"

char *easel;
int width, height, viewing_distance = 50;

void Point::drawPoint(int r = 255,int g = 255,int b = 255){
	double x,y;
	x = (width/2) + this->tuple[0] * viewing_distance / this->tuple[2]; 
	y = (height/2) + this->tuple[1] * viewing_distance / this->tuple[2]; 
	setpixel(easel, x, y, r, g, b);
	cout<<"Point drawn at ( "<<this->tuple[0]<<", "<<this->tuple[1]<<", "<<this->tuple[2]<<" )."<< endl;
}

int main(int argc, char **argv) {

	cout<<"Welcome to Test nGIN"<<endl;
	width = 640;
	height = 480;
	easel = new char[width*height*3];

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

	Point point1(1,2,1);
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
	point2.drawPoint(YEL);

	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, easel);
	glutSwapBuffers();
	glutPostRedisplay();
}

void setpixel(char *buf, int x, int y, int r=255, int g=255, int b=255) {
	buf[(y*width+x)*3+0] = r;
	buf[(y*width+x)*3+1] = g;
	buf[(y*width+x)*3+2] = b;
}
