// Victor Daniel Cruz González - 157948
// REFERENCIAS
// - https://www.glprogramming.com/red/chapter12.html
// - https://raksy.dyndns.org/bezier.html
// - https://stackoverflow.com/a/5443920

#include "GL/glut.h"
#include <math.h>
#define PI 3.14159265

float scale = 1;
float pos = 10;
float countPos = 0;
float rot = 10;
float coords[4][2] = { {0, 0}, {200, 0}, {200, 300}, {0, 300} };
const float MINX = -700.0, MAXX = 700.0, MINY = -700.0, MAXY = 700.0;

void init(void) {
	glMatrixMode(GL_MODELVIEW);
	glClearColor(22 / 225.0, 33 / 255.0, 51 / 255.0, 0.0);
	gluOrtho2D(MINX, MAXX, MINY, MAXY);
}

void drawCuadr(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	glBegin(GL_POLYGON);
	glVertex3f(x1, y1, -1);
	glVertex3f(x2, y2, -1);
	glVertex3f(x3, y3, -1);
	glVertex3f(x4, y4, -1);
	glEnd();
}

void drawRectangle(int x, int y, int width, int height) {
	drawCuadr(x, y, x + width, y, x + width, y + height, x, y + height);
}

void drawTri(int x1, int y1, int x2, int y2, int x3, int y3) {
	glBegin(GL_POLYGON);
	glVertex3f(x1, y1, -1);
	glVertex3f(x2, y2, -1);
	glVertex3f(x3, y3, -1);
	glEnd();
}

void drawCircle(float x, float y, float radius) {
	static const int circle_points = 100;
	static const float angle = 2.0f * 3.1416f / circle_points;

	glBegin(GL_POLYGON);
	double angle1 = 0.0;
	glVertex3f(x + radius * cos(0.0), y + radius * sin(0.0), -1);
	int i;
	for (i = 0; i < circle_points; i++)
	{
		glVertex3d(x + radius * cos(angle1), y + radius * sin(angle1), -1);
		angle1 += angle;
	}
	glEnd();
}

void drawSpline(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	GLfloat ctrlpoints[4][3] = {
		{ x1, y1, 0.0}, { x2, y2, 0.0},
		{x3, y3, 0.0}, {x4, y4, 0.0} };

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 30; i++)
		glEvalCoord1f((GLfloat)i / 30.0);
	glEnd();
}

void paint(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	// 4.1 - Morado oscuro
	glColor3f(73 / 255.0, 50 / 255.0, 120 / 255.0);
	drawCuadr(52, 250 - 76, 150, 250 - 76, 120, 250 - 0, 58, 250 - 0);
	// Spline 9 - Morado oscuro
	glColor3f(73 / 255.0, 50 / 255.0, 120 / 255.0);
	glLineWidth(5.7);
	drawSpline(67, 250 - 0, 41, 250 - 46, 58, 250 - 142, 57, 250 - 132);
	// 1 - Morado
	glColor3f(132 / 255.0, 115 / 255.0, 193 / 255.0);
	drawCuadr(70, 250 - 207, 130, 250 - 190, 116, 250 - 122, 62, 250 - 156);
	// 2 - Naranja
	glColor3f(225 / 255.0, 127 / 255.0, 39 / 255.0);
	drawCuadr(74, 250 - 234, 110, 250 - 227, 104, 250 - 195, 70, 250 - 207);
	// 3 - Fondo
	glColor3f(22 / 225.0, 33 / 255.0, 51 / 255.0);
	drawCuadr(115, 250 - 250, 201, 250 - 226, 201, 250 - 142, 98, 250 - 164);
	// 4 - Amarillo
	glColor3f(249 / 225.0, 202 / 255.0, 8 / 255.0);
	drawCuadr(135, 250 - 155, 161, 250 - 150, 148, 250 - 95, 126, 250 - 114);
	// 5 - Naranja
	glColor3f(225 / 255.0, 127 / 255.0, 39 / 255.0);
	drawCuadr(62, 250 - 156, 116, 250 - 122, 111, 250 - 98, 59, 250 - 137);
	// 5.1 - Naranja
	glColor3f(225 / 255.0, 127 / 255.0, 39 / 255.0);
	drawCuadr(126, 250 - 114, 148, 250 - 95, 143, 250 - 67, 121, 250 - 87);
	// 10 - Rojo
	glColor3f(255 / 255.0, 0 / 255.0, 0 / 255.0);
	drawCuadr(182, 250 - 57, 211, 250 - 0, 170, 250 - 0, 140, 250 - 70);
	// 6 - Azul oscuro
	glColor3f(34 / 225.0, 40 / 255.0, 125 / 255.0);
	drawTri(148, 250 - 95, 186, 250 - 51, 143, 250 - 71);
	drawTri(148, 250 - 95, 186, 250 - 51, 168, 250 - 75);
	// 16 - Amarillo
	glColor3f(254 / 255.0, 243 / 255.0, 115 / 255.0);
	drawCuadr(27, 250 - 114, 116, 250 - 82, 131, 250 - 28, 52, 250 - 83);
	drawCuadr(116, 250 - 82, 140, 250 - 57, 131, 250 - 24, 60, 250 - 90);
	// 7 - Gris
	glColor3f(161 / 225.0, 167 / 255.0, 183 / 255.0);
	drawCircle(112, 250 - 63, 16);
	// 9 - Rojo
	glColor3f(255 / 255.0, 0 / 255.0, 0 / 255.0);
	drawCuadr(0, 250 - 187, 62, 250 - 156, 59, 250 - 137, 0, 250 - 170);
	// 12 - Gris
	glColor3f(161 / 225.0, 167 / 255.0, 183 / 255.0);
	drawCuadr(141, 250 - 62, 178, 250 - 0, 145, 250 - 0, 131, 250 - 26);
	// 11 - Blanco
	glColor3f(255 / 255.0, 255 / 255.0, 255 / 255.0);
	drawCuadr(142, 250 - 66, 193, 250 - 0, 178, 250 - 0, 138, 250 - 61);
	// 8 - Azul oscuro
	glColor3f(34 / 225.0, 40 / 255.0, 125 / 255.0);
	drawTri(120, 250 - 79, 140, 250 - 57, 143, 250 - 71);
	// 18 - Blanco
	glColor3f(255 / 255.0, 255 / 255.0, 255 / 255.0);
	glLineWidth(5.7);
	drawCuadr(0, 250 - 170, 58, 250 - 137, 57, 250 - 131, 0, 250 - 164);
	// 13 - MoraAzul
	glColor3f(93 / 255.0, 97 / 255.0, 135 / 255.0);
	drawCuadr(0, 250 - 167, 57, 250 - 133, 52, 250 - 83, 0, 250 - 110);
	// 14 - Gris
	glColor3f(161 / 225.0, 167 / 255.0, 183 / 255.0);
	drawCuadr(0, 250 - 110, 54, 250 - 105, 52, 250 - 83, 0, 250 - 98);
	drawTri(0, 250 - 110, 54, 250 - 105, 24, 250 - 111);
	// 19 - Gris
	glColor3f(161 / 225.0, 167 / 255.0, 183 / 255.0);
	drawCuadr(110, 250 - 87, 118, 250 - 80, 115, 250 - 63, 102, 250 - 63);
	// 15 - Morado oscuro
	glColor3f(73 / 255.0, 50 / 255.0, 120 / 255.0);
	drawCuadr(57, 250 - 132, 114, 250 - 86, 118, 250 - 81, 54, 250 - 105);
	// 17 - Blanco
	glColor3f(255 / 255.0, 255 / 255.0, 255 / 255.0);
	glLineWidth(7.0);
	for (int i = 0; i < 5; i++)
		drawSpline(0, 250 - 97 + (i * 2), 60, 250 - 90, 117, 250 - 38, 160, 250 - 0);
	// 20 - Blanco
	glLineWidth(1);
	glColor3f(255 / 255.0, 255 / 255.0, 255 / 255.0);
	drawCuadr(111, 250 - 97, 120, 250 - 88, 118, 250 - 80, 110, 250 - 89);
	// Spline 1 - Negro
	glColor3f(0, 0, 0);
	glLineWidth(9.0);
	drawSpline(0, 0, 17, 250 - 246, 27, 250 - 238, 33, 250 - 226);
	// Spline 2 - Azul oscuro
	glColor3f(34 / 225.0, 40 / 255.0, 125 / 255.0);
	glLineWidth(7.0);
	drawSpline(0, 250 - 220, 134, 250 - 212, 163, 250 - 138, 250, 250 - 76);
	// Spline 3 - Azul oscuro
	glColor3f(34 / 225.0, 40 / 255.0, 125 / 255.0);
	glLineWidth(5.7);
	drawSpline(0, 250 - 187, 83, 250 - 146, 188, 250 - 93, 205, 250 - 0);
	// Spline 4 - Azul oscuro
	glColor3f(34 / 225.0, 40 / 255.0, 125 / 255.0);
	glLineWidth(6.4);
	drawSpline(0, 250 - 170, 75, 250 - 132, 139, 250 - 86, 190, 250 - 0);
	// Spline 5 - Rojo
	glColor3f(225 / 225.0, 0 / 255.0, 0 / 255.0);
	glLineWidth(6.8);
	drawSpline(0, 250 - 167, 68, 250 - 131, 155, 250 - 65, 170, 250 - 0);
	// Spline 6 - Rojo
	glColor3f(225 / 225.0, 0 / 255.0, 0 / 255.0);
	glLineWidth(5.7);
	drawSpline(0, 250 - 110, 45, 250 - 118, 124, 250 - 80, 250, 250 - 20);
	// Spline 8 - Azul oscuro
	glColor3f(34 / 225.0, 40 / 255.0, 125 / 255.0);
	glLineWidth(5.0);
	drawSpline(0, 250 - 88, 60, 250 - 90, 117, 250 - 38, 160, 250 - 0);
	// Spline 7 - Rojo
	glColor3f(225 / 225.0, 0 / 255.0, 0 / 255.0);
	glLineWidth(5.7);
	drawSpline(0, 250 - 98, 60, 250 - 95, 117, 250 - 37, 160, 250 - 0);
	glutSwapBuffers();
}

void rotate(float rotation) {
	int len = sizeof(coords) / sizeof(coords[0]);
	for (int i = 0; i < len; i++) {
		float x = coords[i][0];
		float y = coords[i][1];
		coords[i][0] = x * cos(10 * PI / 180.0) - y * sin(10 * PI / 180.0);
		coords[i][1] = x * sin(10 * PI / 180.0) + y * cos(10 * PI / 180.0);
	}
	countPos++;
}

void scalate(float factor) {
	int len = sizeof(coords) / sizeof(coords[0]);
	for (int i = 0; i < len; i++) {
		float x = coords[i][0];
		float y = coords[i][1];
		coords[i][0] = x * factor;
		coords[i][1] = y * factor;
	}
}

void translate(float pos) {
	int len = sizeof(coords) / sizeof(coords[0]);
	for (int i = 0; i < len; i++) {
		float x = coords[i][0];
		float y = coords[i][1];
		float tmp = countPos * pos + 45;
		if (scale >= 1) {
			coords[i][0] = x + pos * cos(tmp * PI / 180.0);
			coords[i][1] = y + pos * sin(tmp * PI / 180.0);
		}
		else {
			coords[i][0] = x + pos * cos(tmp * PI / 180.0) * (scale + 0.10);
			coords[i][1] = y + pos * sin(tmp * PI / 180.0) * (scale + 0.10);
		}
	}
}

bool touchedEdge() {
	bool output = false;
	int len = sizeof(coords) / sizeof(coords[0]);
	for (int i = 0; i < len; i++) {
		float x = coords[i][0];
		float y = coords[i][1];
		output = output || !(MINX <= x && x <= MAXX && MINY <= y && y <= MAXY);
	}
	return output;
}

void transform(unsigned char key, int xmouse, int ymouse)
{
	switch (key) {
	case 'R': {
		glRotatef(rot, 0, 0, 1);
		rotate(rot);
		break;
	}
	case 'e': {
		scale /= 2;
		glScalef(scale, scale, 1);
		scalate(scale);
		break;
	}
	case 'E': {
		scale *= 2;
		glScalef(scale, scale, 1);
		scalate(scale);
		break;
	}
	case 'T': {
		glTranslatef(pos, pos, 0);
		translate(pos);
		break;
	}
	case 'F': {
		exit(0);
		break;
	}
	default:
		break;
	}
	glutPostRedisplay();
	if (touchedEdge()) exit(0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(606, 750);
	glutCreateWindow("Pintura 3");
	init();
	glutKeyboardFunc(transform);
	glutDisplayFunc(paint);
	glutMainLoop();
	return 0;
}
