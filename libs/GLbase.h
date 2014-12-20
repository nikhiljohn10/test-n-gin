void drawfunc(void);
void setpixel(char*, int, int, int, int, int);

void keyfunc(unsigned char k, int x, int y) {
	cout << "in keyfunc" << endl;
	switch (k) {
		case 27:
			// escape key
			exit(0);
			break;
		case GLUT_KEY_UP:
			// up arrow
			break;
		case 'a':
			// 'a' key
			break;
	}
}

void myglinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}
