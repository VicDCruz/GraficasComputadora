#include "GL/glut.h"
#include <math.h>

void init(void) {
	glClearColor(140 / 225.0, 94 / 255.0, 60 / 255.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 225.0, 0.0, 225.0);
}

void drawRectangle(int width, int heigth, int x, int y) {
	// glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(x, y, -1);
	glVertex3f(x + width, y, -1);
	glVertex3f(x + width, y + heigth, -1);
	glVertex3f(x, y + heigth, -1);
	glEnd();
}

void drawCuadr(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	// glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(x1, y1, -1);
	glVertex3f(x2, y2, -1);
	glVertex3f(x3, y3, -1);
	glVertex3f(x4, y4, -1);
	glEnd();
}

void drawTri(int x1, int y1, int x2, int y2, int x3, int y3) {
	// glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(x1, y1, -1);
	glVertex3f(x2, y2, -1);
	glVertex3f(x3, y3, -1);
	glEnd();
}

void drawCircle(float x, float y, float radius) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, 0.0f);
	static const int circle_points = 100;
	static const float angle = 2.0f * 3.1416f / circle_points;

	// this code (mostly) copied from question:
	glBegin(GL_POLYGON);
	double angle1 = 0.0;
	glVertex2d(radius * cos(0.0), radius * sin(0.0));
	int i;
	for (i = 0; i < circle_points; i++)
	{
		glVertex2d(radius * cos(angle1), radius * sin(angle1));
		angle1 += angle;
	}
	glEnd();
	glPopMatrix();
}

void lineSegment(void) {
	/*glBegin(GL_LINES);
	glVertex3f(180, 15, -1);
	glVertex3f(10, 145, -1);
	glEnd();
	glFlush();*/
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(124/255.0, 23/255.0, 31/255.0);
	drawCuadr(70, 0, 197, 0, 197, 130, 70, 225 - 186);
	glColor3f(82 / 255.0, 46 / 255.0, 34 / 255.0);
	drawRectangle(58, 106, 0, 0);
	glColor3f(118 / 255.0, 137 / 255.0, 152 / 255.0);
	drawRectangle(41, 87, 0, 106);
	glColor3f(107 / 255.0, 71 / 255.0, 35 / 255.0);
	drawRectangle(70, 35, 0, 193);
	glColor3f(190 / 255.0, 191 / 255.0, 193 / 255.0);
	drawRectangle(35, 144, 41, 49);
	glColor3f(190 / 255.0, 191 / 255.0, 193 / 255.0);
	drawRectangle(104, 27, 13, 22);
	glColor3f(111 / 255.0, 103 / 255.0, 114 / 255.0);
	drawRectangle(97, 17, 0, 0);
	glColor3f(175 / 255.0, 163 / 255.0, 0 / 255.0);
	drawRectangle(49, 72, 76, 225 - 71);
	glColor3f(53 / 255.0, 45 / 255.0, 43 / 255.0);
	drawRectangle(56, 30, 169, 225 - 30);
	glColor3f(217 / 255.0, 220 / 255.0, 225 / 255.0);
	drawRectangle(98, 25, 135, 200);
	glColor3f(17 / 255.0, 13 / 255.0, 27 / 255.0);
	drawRectangle(79, 53, 45 + 72, 0);
	glColor3f(150 / 255.0, 141 / 255.0, 0 / 255.0);
	drawRectangle(82, 31, 117, 43);
	glColor3f(27 / 255.0, 44 / 255.0, 54 / 255.0);
	drawRectangle(31, 53, 194, 0);
	glColor3f(150 / 255.0, 138 / 255.0, 86 / 255.0);
	drawRectangle(55, 55, 115, 0);
	glColor3f(177 / 255.0, 185 / 255.0, 198 / 255.0);
	drawCuadr(197, 53, 225, 53, 225, 150, 197, 130);
	glColor3f(179 / 255.0, 67 / 255.0, 21 / 255.0);
	drawTri(76, 225 - 71, 117, 225 - 71, 117, 225 - 156);
	glColor3f(35 / 255.0, 77 / 255.0, 89 / 255.0);
	drawCircle(164, 225 - 72, 38);
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Constructivismo");
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
