// Victor Daniel Cruz González - 157948
// REFERENCIAS
// - https://www.glprogramming.com/red/chapter12.html
// - https://raksy.dyndns.org/bezier.html
// - https://stackoverflow.com/a/5443920
// - https://www3.ntu.edu.sg/home/ehchua/programming/opengl/CG_Introduction.html

#include "windows.h"
#include "GL/glut.h"
#include <math.h>
#define PI 3.14159265

const int SLOW = 100; // lento
const int MEDIUM = 50;// normal
const int FAST = 20; // rápido
int speed = FAST;
int countRectangle1 = 0;
int countRectangle2 = 0;
int countRectangle3 = 0;
int countRectangle4 = 0;
int countRectangle5 = 0;
int countRectangle7 = 0;
int countRectangle9 = 0;
int countRectangle10 = 0;
int countRectangle11 = 0;
int countRectangle13 = 0;
int countRectangle15 = 0;
int countRectangle16 = 0;
int countRectangle17 = 0;
int countRectangle19 = 0;
int countOval6 = 0;
int countOval8 = 0;
int countYellowRectangle12 = 0;
int countPurpleRectangle14 = 0;
int countCircle18 = 0;
int cont = 0;
float angleRectangle = 0.0f;
float angleRectangleYellow = 0.0f;
float angleRectanglePurple = 0.0f;
float angleOval = 0.0f;
float sizeRectangle = 1.0f;
float sizeCircle = 0.07f;
float coordsRectangle = 1.0f;
float coordsRectangle1 = 1.0f;
bool changeDirectionRectangle = false;
bool changeDirectionRectangleYellow = false;
bool changeDirectionRectanglePurple = false;
bool changeDirectionOval = false;
bool changeSizeRectangle = false;
bool changeCoordsRectangle = false;
bool changeSizeCircle = false;
bool start = false;
float coords[4][2] = { {0, 0}, {200, 0}, {200, 300}, {0, 300} };
const float MINX = 0.0, MAXX = 225.0, MINY = 0.0, MAXY = 225.0;
float x = 500, y = 500, width = 606, heigth = 750;
const float XVMIN = 0, YVMIN = 0, VPWIDTH = 606, VPHEIGTH = 750;

void init(void) {
	glClearColor(22 / 225.0, 33 / 255.0, 51 / 255.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(MINX, MAXX, MINY, MAXY);
}

void idle() {
	// 100 - lento
	// 50 - normal
	// 20 - rápido
	Sleep(speed);
	glutPostRedisplay();   // Post a re-paint request to activate display()
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

void move(void (*func)(), void (*moves)(), int selectSpeed) {
	// 1 - lento
	// 2 - normal
	// 3 - rapido
	switch (selectSpeed)
	{
	case 1:
		speed = SLOW;
		break;
	case 2:
		speed = MEDIUM;
		break;
	case 3:
		speed = FAST;
		break;
	default:
		break;
	}

	glPushMatrix();
	moves();
	func();
	glPopMatrix();
}

void grayRectangle() {
	float baseX = 110, baseY = 250 - 87;
	glColor3f(161 / 225.0, 167 / 255.0, 183 / 255.0);
	drawCuadr(110 - baseX, 250 - 87 - baseY, 118 - baseX, 250 - 80 - baseY, 115 - baseX, 250 - 63 - baseY, 102 - baseX, 250 - 63 - baseY);
}

void yellowRectangle() {
	float baseX = 135, baseY = 250 - 155;
	glColor3f(249 / 225.0, 202 / 255.0, 8 / 255.0);
	drawCuadr(135 - baseX, 250 - 155 - baseY, 161 - baseX, 250 - 150 - baseY, 148 - baseX, 250 - 95 - baseY, 126 - baseX, 250 - 114 - baseY);
}

void purpleRectangle() {
	float baseX = 70, baseY = 250 - 207;
	glColor3f(132 / 255.0, 115 / 255.0, 193 / 255.0);
	drawCuadr(70 - baseX, 250 - 207 - baseY, 130 - baseX, 250 - 190 - baseY, 116 - baseX, 250 - 122 - baseY, 62 - baseX, 250 - 156 - baseY);
}

void moveGR1() {
	float baseX = 110, baseY = 250 - 87;
	glTranslatef(baseX, baseY, 0);
	if (!changeDirectionRectangle) {
		glRotatef(angleRectangle, 0.0f, 0.0f, 1.0f);
		angleRectangle += 5;
	}
	else {
		glRotatef(angleRectangle, 0.0f, 0.0f, 1.0f);
		angleRectangle -= 5;
	}
}

void moveGR2() {
	float baseX = 110, baseY = 250 - 87;
	glTranslatef(baseX, baseY, 0);
	if (!changeSizeRectangle) {
		glViewport(x, y, width, heigth);
		heigth -= 2;
		glScalef(sizeRectangle, sizeRectangle, 1);
		sizeRectangle += 0.05;
	}
	else {
		glViewport(x, y, width, heigth);
		heigth += 2;
		glScalef(sizeRectangle, sizeRectangle, 1);
		sizeRectangle -= 0.05;
	}
}

void moveGR3() {
	float baseX = 110, baseY = 250 - 87;
	glTranslatef(baseX, baseY, 0);
	if (!changeCoordsRectangle) {
		Sleep(35);
		glViewport(x, y, width, heigth); y--;
		glTranslatef(0, coordsRectangle, 0);
		coordsRectangle++;
	}
}

void moveGR4() {
	float baseX = 110, baseY = 250 - 87 + 30;
	glTranslatef(baseX, baseY, 0);
	if (!changeDirectionRectangle) {
		glRotatef(angleRectangle, 0.0f, 0.0f, 1.0f);
		angleRectangle += 5;
	}
	else {
		glRotatef(angleRectangle, 0.0f, 0.0f, 1.0f);
		angleRectangle -= 5;
	}
}

void moveGR5() {
	float baseX = 110, baseY = 250 - 87 + 30;
	glTranslatef(baseX, baseY, 0);
	if (!changeCoordsRectangle) {
		Sleep(35);
		glViewport(x, y, width, heigth);
		x++; // IZQ
		y -= 4; // ARR
		width += 2; heigth += 2; // ZOOM-IN
		if (coordsRectangle1 >= 0) coordsRectangle1--;
		else coordsRectangle1 = 0;
		glTranslatef(coordsRectangle, coordsRectangle1, 0);
		coordsRectangle--;
	}
}

void moveGR7() {
	float baseX = 110 - 85, baseY = 250 - 87 + 30;
	glTranslatef(baseX, baseY, 0);
	if (!changeCoordsRectangle) {
		Sleep(20);
		glViewport(x, y, width, heigth); x -= 3.5;
		if (coordsRectangle1 >= 0) coordsRectangle1--;
		else coordsRectangle1 = 0;
		glTranslatef(coordsRectangle, coordsRectangle1, 0);
		coordsRectangle += 2;
	}
}

void moveGR9() {
	float baseX = 110 + 105, baseY = 250 - 87 + 30;
	glTranslatef(baseX, baseY, 0);
	if (!changeCoordsRectangle) {
		Sleep(20);
		glViewport(x, y, width, heigth); x += 3;
		if (coordsRectangle1 >= 0) coordsRectangle1--;
		else coordsRectangle1 = 0;
		glTranslatef(coordsRectangle, coordsRectangle1, 0);
		coordsRectangle -= 2;
	}
}

void moveGR10() {
	float baseX = 110, baseY = 250 - 87 + 30;
	glTranslatef(baseX, baseY, 0);
	if (!changeCoordsRectangle) {
		glViewport(x, y, width, heigth); y += 2;
		glTranslatef(0, coordsRectangle, 0);
		coordsRectangle--;
	}
}

void moveGR11() {
	float baseX = 110, baseY = 250 - 87 - 75;
	glTranslatef(baseX, baseY, 0);
	if (!changeCoordsRectangle) {
		glViewport(x, y, width, heigth); x -= 2;
		if (coordsRectangle1 >= 0) coordsRectangle1--;
		else coordsRectangle1 = 0;
		glTranslatef(coordsRectangle, coordsRectangle1, 0);
		coordsRectangle++;
	}
}

void moveYR12() {
	float baseX = 135, baseY = 250 - 155;
	glTranslatef(baseX, baseY, 0);
	if (!changeDirectionRectangleYellow) {
		glRotatef(angleRectangleYellow, 0.0f, 0.0f, 1.0f);
		angleRectangleYellow += 0.8;
	}
	else {
		glRotatef(angleRectangleYellow, 0.0f, 0.0f, 1.0f);
		angleRectangleYellow -= 0.8;
	}
}

void moveGR13() {
	float baseX = 110 + 70, baseY = 250 - 87 - 75;
	glTranslatef(baseX, baseY, 0);
	if (!changeCoordsRectangle) {
		if (coordsRectangle1 >= -35) coordsRectangle1--; // INTERESANTE COMO SE MUEVE!!!!!!
		else coordsRectangle1 = -35;
		glViewport(x, y, width, heigth); x += 2;
		glTranslatef(coordsRectangle, coordsRectangle1, 0);
		coordsRectangle--;
	}
}

void movePR14() {
	float baseX = 70, baseY = 250 - 207;
	glTranslatef(baseX, baseY, 0);
	if (!changeDirectionRectanglePurple) {
		glRotatef(angleRectanglePurple, 0.0f, 0.0f, 1.0f);
		angleRectanglePurple += 0.8;
	}
	else {
		glRotatef(angleRectanglePurple, 0.0f, 0.0f, 1.0f);
		angleRectanglePurple -= 0.8;
	}
}

void moveGR15() {
	float baseX = 110 - 70, baseY = 250 - 87 - 75 - 35;
	glTranslatef(baseX, baseY, 0);
	if (!changeCoordsRectangle) {
		if (coordsRectangle1 <= 10) coordsRectangle1 += 4; // INTERESANTE COMO SE MUEVE!!!!!!
		else coordsRectangle1 = 10;
		glViewport(x, y, width, heigth); x -= 2;
		glTranslatef(coordsRectangle, coordsRectangle1, 0);
		coordsRectangle++;
	}
}

void moveGR16() {
	float baseX = 110, baseY = 250 - 87 - 75 - 35;
	glTranslatef(baseX, baseY, 0);
	if (!changeCoordsRectangle) {
		glViewport(x, y, width, heigth); y -= 2;
		glTranslatef(0, coordsRectangle, 0);
		coordsRectangle++;
	}
}

void moveGR17() {
	float baseX = 110, baseY = 250 - 87;
	glTranslatef(baseX, baseY, 0);
	if (!changeSizeRectangle) {
		glScalef(sizeRectangle, sizeRectangle, 1);
		sizeRectangle -= 0.05;
	}
}

void moveGR20() {
	float baseX = 110, baseY = 250 - 87;
	glTranslatef(baseX, baseY, 0);
	if (!changeSizeRectangle) glScalef(0.20, 0.20, 1);
	else glScalef(0.5, 0.5, 1);
}

void moveGR19() {
	float baseX = 110, baseY = 250 - 87;
	glTranslatef(baseX, baseY, 0);
	if (!changeSizeRectangle) {
		glScalef(sizeRectangle, sizeRectangle, 1);
		sizeRectangle += 0.05;
	}
}

void moveGR21() {
	float baseX = 110, baseY = 250 - 87;
	glTranslatef(baseX, baseY, 0);
	glScalef(1, 1, 1);
}

void grayCircle() {
	glColor3f(161 / 225.0, 167 / 255.0, 183 / 255.0);
	float baseX = 112, baseY = 250 - 63;
	drawCircle(112 - baseX, 250 - 63 - baseY, 16);
}

void moveGC1() {
	float baseX = 112, baseY = 250 - 63;
	glTranslatef(baseX, baseY, 0);
	glScalef(0.07, 0.07, 1);
}

void moveGC18() {
	float baseX = 112, baseY = 250 - 63;
	glTranslatef(baseX, baseY, 0);
	glViewport(x, y, width, heigth);
	if (x < XVMIN) x++;
	if (x > XVMIN) x--;
	if (y < YVMIN) y++;
	if (y > YVMIN) y--;
	if (width < VPWIDTH) width++;
	if (width > VPWIDTH) width--;
	if (heigth < VPHEIGTH) heigth++;
	if (heigth > VPHEIGTH) heigth--;
	if (!changeSizeCircle) {
		glScalef(sizeCircle, sizeCircle, 1);
		sizeCircle -= 0.01;
	}
	else {
		glScalef(sizeCircle, sizeCircle, 1);
		sizeCircle += 0.01;
	}
}

void moveGC20() {
	float baseX = 112, baseY = 250 - 63;
	glTranslatef(baseX, baseY, 0);
	glScalef(1, 1, 1);
}

void moveGC21() {
	float baseX = 112, baseY = 250 - 63;
	glTranslatef(baseX, baseY, 0);
	glScalef(1, 1, 1);
}

void purpleOval() {
	float baseX = 52, baseY = 250 - 76;
	glColor3f(73 / 255.0, 50 / 255.0, 120 / 255.0);
	drawCuadr(52 - baseX, 250 - 76 - baseY, 150 - baseX, 250 - 76 - baseY, 120 - baseX, 250 - 0 - baseY, 58 - baseX, 250 - 0 - baseY);
}

void redOval() {
	float baseX = 182, baseY = 250 - 57;
	glColor3f(255 / 255.0, 0 / 255.0, 0 / 255.0);
	drawCuadr(182 - baseX, 250 - 57 - baseY, 211 - baseX, 250 - 0 - baseY, 170 - baseX, 250 - 0 - baseY, 140 - baseX, 250 - 70 - baseY);
}

void movePO6() {
	float baseX = 52, baseY = 250 - 76;
	glTranslatef(baseX, baseY, 0);
	if (!changeDirectionOval) {
		Sleep(100);
		glRotatef(angleOval, 0.0f, 0.0f, 1.0f);
		angleOval += 8;
	}
	else {
		Sleep(100);
		glRotatef(angleOval, 0.0f, 0.0f, 1.0f);
		angleOval -= 8;
	}
}

void moveRO8() {
	float baseX = 182, baseY = 250 - 57;
	glTranslatef(baseX, baseY, 0);
	if (!changeDirectionOval) {
		glRotatef(angleOval, 0.0f, 0.0f, 1.0f);
		angleOval += 0.8;
	}
	else {
		glRotatef(angleOval, 0.0f, 0.0f, 1.0f);
		angleOval -= 0.8;
	}
}

void paint(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	if (!start && countRectangle1 == 0) {
		glViewport(x, y, width, heigth);
		if (x == 0 && y == 0) {
			x = XVMIN + 1; y = YVMIN + 1;
			width = VPWIDTH; heigth = VPHEIGTH;
			glViewport(x, y, width, heigth);
			glPopMatrix();
			Sleep(1500);
			start = true;
		}
		else if (x == 500 && y == 500) {
			glPushMatrix();
			glScalef(0.05, 0.05, 1);
		}
		else if (x == 1 && y == 1 && cont < 7) {
			glRotatef(5, 0, 0, 1);
			width--; heigth--;
			x++; y++; cont++;
		}
		else {
			glRotatef(5, 0, 0, 1);
			glScalef(1.007, 1.007, 1);
		}
		x--; y--;
	}

	// 4.1 - Morado oscuro
	if (countRectangle5 >= 0 || countOval6 < 0) {
		glColor3f(73 / 255.0, 50 / 255.0, 120 / 255.0);
		drawCuadr(52, 250 - 76, 150, 250 - 76, 120, 250 - 0, 58, 250 - 0);
	}
	if (countRectangle5 < 0) {
		if (0 <= countOval6 && countOval6 < 4) {
			changeCoordsRectangle = true;
			move(grayRectangle, moveGR7, 1);
			move(purpleOval, movePO6, 1);
			if (!changeDirectionOval && angleOval >= 50) {
				changeDirectionOval = true;
				countOval6++;
			}
			if (changeDirectionOval && angleOval < 0) {
				changeDirectionOval = false;
				countOval6++;
			}
		}
		else if (countOval6 == 4) {
			countOval6 = -1;
			changeDirectionOval = false;
			changeCoordsRectangle = false;
			angleOval = 0;
		}
	}
	// Spline 9 - Morado oscuro
	glColor3f(73 / 255.0, 50 / 255.0, 120 / 255.0);
	glLineWidth(5.7);
	drawSpline(67, 250 - 0, 41, 250 - 46, 58, 250 - 142, 57, 250 - 132);
	// 1 - Morado
	if (countRectangle13 >= 0 || countPurpleRectangle14 < 0) {
		glColor3f(132 / 255.0, 115 / 255.0, 193 / 255.0);
		drawCuadr(70, 250 - 207, 130, 250 - 190, 116, 250 - 122, 62, 250 - 156);
	}
	if (countRectangle13 < 0) {
		if (0 <= countPurpleRectangle14 && countPurpleRectangle14 < 3) {
			changeCoordsRectangle = true;
			move(grayRectangle, moveGR15, 1);
			move(purpleRectangle, movePR14, 1);
			if (!changeDirectionRectanglePurple && angleRectanglePurple >= 45) {
				changeDirectionRectanglePurple = true;
				countPurpleRectangle14++;
			}
			if (changeDirectionRectanglePurple && angleRectanglePurple < -30) {
				changeDirectionRectanglePurple = false;
				countPurpleRectangle14++;
			}
		}
		else if (countPurpleRectangle14 == 3) {
			changeCoordsRectangle = true;
			move(grayRectangle, moveGR15, 1);
			move(purpleRectangle, movePR14, 1);
			if (changeDirectionRectanglePurple && angleRectanglePurple < 0) {
				changeDirectionRectanglePurple = false;
				countPurpleRectangle14++;
			}
		}
		else if (countPurpleRectangle14 == 4) {
			countPurpleRectangle14 = -1;
			changeDirectionRectanglePurple = false;
			changeCoordsRectangle = false;
			angleRectanglePurple = 0;
		}
	}
	// 2 - Naranja
	glColor3f(225 / 255.0, 127 / 255.0, 39 / 255.0);
	drawCuadr(74, 250 - 234, 110, 250 - 227, 104, 250 - 195, 70, 250 - 207);
	// 3 - Fondo
	glColor3f(22 / 225.0, 33 / 255.0, 51 / 255.0);
	drawCuadr(115, 250 - 250, 201, 250 - 226, 201, 250 - 142, 98, 250 - 164);
	// 4 - Amarillo
	if (countRectangle11 >= 0 || countYellowRectangle12 < 0) {
		glColor3f(249 / 225.0, 202 / 255.0, 8 / 255.0);
		drawCuadr(135, 250 - 155, 161, 250 - 150, 148, 250 - 95, 126, 250 - 114);
	}
	if (countRectangle11 < 0) {
		if (0 <= countYellowRectangle12 && countYellowRectangle12 < 3) {
			changeCoordsRectangle = true;
			move(grayRectangle, moveGR13, 1);
			move(yellowRectangle, moveYR12, 1);
			if (!changeDirectionRectangleYellow && angleRectangleYellow >= 45) {
				changeDirectionRectangleYellow = true;
				countYellowRectangle12++;
			}
			if (changeDirectionRectangleYellow && angleRectangleYellow < -30) {
				changeDirectionRectangleYellow = false;
				countYellowRectangle12++;
			}
		}
		else if (countYellowRectangle12 == 3) {
			changeCoordsRectangle = true;
			move(grayRectangle, moveGR13, 1);
			move(yellowRectangle, moveYR12, 1);
			if (changeDirectionRectangleYellow && angleRectangleYellow < 0) {
				changeDirectionRectangleYellow = false;
				countYellowRectangle12++;
			}
		}
		else if (countYellowRectangle12 == 4) {
			countYellowRectangle12 = -1;
			changeDirectionRectangleYellow = false;
			changeCoordsRectangle = false;
			angleRectangleYellow = 0;
		}
	}
	// 5 - Naranja
	glColor3f(225 / 255.0, 127 / 255.0, 39 / 255.0);
	drawCuadr(62, 250 - 156, 116, 250 - 122, 111, 250 - 98, 59, 250 - 137);
	// 5.1 - Naranja
	glColor3f(225 / 255.0, 127 / 255.0, 39 / 255.0);
	drawCuadr(126, 250 - 114, 148, 250 - 95, 143, 250 - 67, 121, 250 - 87);
	// 10 - Rojo
	if (countRectangle7 >= 0 || countOval8 < 0) {
		glColor3f(255 / 255.0, 0 / 255.0, 0 / 255.0);
		drawCuadr(182, 250 - 57, 211, 250 - 0, 170, 250 - 0, 140, 250 - 70);
	}
	if (countRectangle7 < 0) {
		if (0 <= countOval8 && countOval8 < 5) {
			changeCoordsRectangle = true;
			move(grayRectangle, moveGR9, 1);
			move(redOval, moveRO8, 1);
			if (!changeDirectionOval && angleOval >= 0) {
				changeDirectionOval = true;
				countOval8++;
			}
			if (changeDirectionOval && angleOval < -50) {
				changeDirectionOval = false;
				countOval8++;
			}
		}
		else if (countOval8 == 5) {
			countOval8 = -1;
			changeDirectionOval = false;
			changeCoordsRectangle = false;
			angleOval = 0;
		}
	}
	// 6 - Azul oscuro
	glColor3f(34 / 225.0, 40 / 255.0, 125 / 255.0);
	drawTri(148, 250 - 95, 186, 250 - 51, 143, 250 - 71);
	drawTri(148, 250 - 95, 186, 250 - 51, 168, 250 - 75);
	// 16 - Amarillo
	glColor3f(254 / 255.0, 243 / 255.0, 115 / 255.0);
	drawCuadr(27, 250 - 114, 116, 250 - 82, 131, 250 - 28, 52, 250 - 83);
	drawCuadr(116, 250 - 82, 140, 250 - 57, 131, 250 - 24, 60, 250 - 90);
	// 7 - Gris
	if (countRectangle17 >= 0) move(grayCircle, moveGC1, 3);
	if (countRectangle17 < 0) {
		if (0 <= countCircle18 && countCircle18 < 6) {
			changeSizeRectangle = !changeSizeRectangle;
			move(grayRectangle, moveGR20, 1);
			move(grayCircle, moveGC18, 1);
			if (!changeSizeCircle && sizeCircle < 0) {
				changeSizeCircle = true;
				countCircle18++;
			}
			if (changeSizeCircle && sizeCircle > 1) {
				changeSizeCircle = false;
				countCircle18++;
			}
		}
		else if (countCircle18 == 6) {
			countCircle18 = -1;
			changeSizeCircle = false;
			changeSizeRectangle = false;
			changeCoordsRectangle = false;
			sizeCircle = 1;
			sizeRectangle = 0.2;
		}
	}
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

	// 19 - Gris
	if (start) {
		if (0 <= countRectangle1 && countRectangle1 < 3) {
			move(grayRectangle, moveGR1, 1);
			if (!changeDirectionRectangle && angleRectangle >= 45) {
				changeDirectionRectangle = true;
				countRectangle1++;
			}
			if (changeDirectionRectangle && angleRectangle < -45) {
				changeDirectionRectangle = false;
				countRectangle1++;
			}
		}
		else {
			countRectangle1 = -1;
			changeDirectionRectangle = false;
			angleRectangle = 0;
			start = false;
		}
	}
	if (countRectangle1 < 0) {
		if (0 <= countRectangle2 && countRectangle2 < 2) {
			move(grayRectangle, moveGR2, 1);
			if (!changeSizeRectangle && sizeRectangle >= 3) {
				changeSizeRectangle = true;
				countRectangle2++;
			}
			if (changeSizeRectangle && sizeRectangle < -3) {
				changeSizeRectangle = false;
				countRectangle2++;
			}
		}
		else if (countRectangle2 == 2) {
			move(grayRectangle, moveGR2, 1);
			if (!changeSizeRectangle && sizeRectangle >= 1) {
				changeSizeRectangle = true;
				countRectangle2++;
			}
		}
		else if (countRectangle2 == 3) {
			Sleep(4000);
			countRectangle2 = -1;
			changeSizeRectangle = false;
			sizeRectangle = 1;
		}
	}
	if (countRectangle2 < 0) {
		if (0 <= countRectangle3 && countRectangle3 < 1) {
			move(grayRectangle, moveGR3, 1);
			if (!changeCoordsRectangle && coordsRectangle >= 30) {
				changeCoordsRectangle = true;
				countRectangle3++;
			}
		}
		else if (countRectangle3 == 1) {
			countRectangle3 = -1;
			changeCoordsRectangle = false;
			coordsRectangle = 0;
		}
	}
	if (countRectangle3 < 0) {
		if (0 <= countRectangle4 && countRectangle4 < 2) {
			move(grayRectangle, moveGR4, 1);
			if (!changeDirectionRectangle && angleRectangle >= 30) {
				changeDirectionRectangle = true;
				countRectangle4++;
			}
			if (changeDirectionRectangle && angleRectangle < -30) {
				changeDirectionRectangle = false;
				countRectangle4++;
			}
		}
		else if (countRectangle4 == 2) {
			move(grayRectangle, moveGR4, 1);
			if (!changeDirectionRectangle && angleRectangle >= 0) {
				changeDirectionRectangle = true;
				countRectangle4++;
			}
		}
		else if (countRectangle4 == 3) {
			countRectangle4 = -1;
			changeDirectionRectangle = false;
			angleRectangle = 0;
		}
	}
	if (countRectangle4 < 0) {
		if (0 <= countRectangle5 && countRectangle5 < 1) {
			move(grayRectangle, moveGR5, 1);
			if (!changeCoordsRectangle && coordsRectangle < -85) {
				changeCoordsRectangle = true;
				countRectangle5++;
			}
		}
		else if (countRectangle5 == 1) {
			countRectangle5 = -1;
			changeCoordsRectangle = false;
			coordsRectangle = 0;
			coordsRectangle1 = 0;
		}
	}
	if (countOval6 < 0) {
		if (0 <= countRectangle7 && countRectangle7 < 1) {
			move(grayRectangle, moveGR7, 1);
			if (!changeCoordsRectangle && coordsRectangle >= 190) {
				changeCoordsRectangle = true;
				countRectangle7++;
			}
		}
		else if (countRectangle7 == 1) {
			countRectangle7 = -1;
			changeCoordsRectangle = false;
			coordsRectangle = 0;
			coordsRectangle1 = 0;
		}
	}
	if (countOval8 < 0) {
		if (0 <= countRectangle9 && countRectangle9 < 1) {
			move(grayRectangle, moveGR9, 1);
			if (!changeCoordsRectangle && coordsRectangle < -105) {
				changeCoordsRectangle = true;
				countRectangle9++;
			}
		}
		else if (countRectangle9 == 1) {
			countRectangle9 = -1;
			changeCoordsRectangle = false;
			coordsRectangle = 0;
			coordsRectangle1 = 0;
		}
	}
	if (countRectangle9 < 0) {
		if (0 <= countRectangle10 && countRectangle10 < 1) {
			move(grayRectangle, moveGR10, 1);
			if (!changeCoordsRectangle && coordsRectangle < -105) {
				changeCoordsRectangle = true;
				countRectangle10++;
			}
		}
		else if (countRectangle10 == 1) {
			countRectangle10 = -1;
			changeCoordsRectangle = false;
			coordsRectangle = 0;
		}
	}
	if (countRectangle10 < 0) {
		if (0 <= countRectangle11 && countRectangle11 < 1) {
			move(grayRectangle, moveGR11, 1);
			if (!changeCoordsRectangle && coordsRectangle >= 70) {
				changeCoordsRectangle = true;
				countRectangle11++;
			}
		}
		else if (countRectangle11 == 1) {
			countRectangle11 = -1;
			changeCoordsRectangle = false;
			coordsRectangle = 0;
			coordsRectangle1 = 0;
		}
	}
	if (countYellowRectangle12 < 0) {
		if (0 <= countRectangle13 && countRectangle13 < 1) {
			move(grayRectangle, moveGR13, 1);
			if (!changeCoordsRectangle && coordsRectangle < -140) {
				changeCoordsRectangle = true;
				countRectangle13++;
			}
		}
		else if (countRectangle13 == 1) {
			countRectangle13 = -1;
			changeCoordsRectangle = false;
			coordsRectangle = 0;
			coordsRectangle1 = 0;
		}
	}
	if (countPurpleRectangle14 < 0) {
		if (0 <= countRectangle15 && countRectangle15 < 1) {
			move(grayRectangle, moveGR15, 1);
			if (!changeCoordsRectangle && coordsRectangle >= 70) {
				changeCoordsRectangle = true;
				countRectangle15++;
			}
		}
		else if (countRectangle15 == 1) {
			countRectangle15 = -1;
			changeCoordsRectangle = false;
			coordsRectangle = 0;
			coordsRectangle1 = 0;
		}
	}
	if (countRectangle15 < 0) {
		if (0 <= countRectangle16 && countRectangle16 < 1) {
			move(grayRectangle, moveGR16, 1);
			if (!changeCoordsRectangle && coordsRectangle >= 110) {
				changeCoordsRectangle = true;
				countRectangle16++;
			}
		}
		else if (countRectangle16 == 1) {
			countRectangle16 = -1;
			changeCoordsRectangle = false;
			changeSizeRectangle = false;
			coordsRectangle = 0;
			coordsRectangle1 = 0;
		}
	}
	if (countRectangle16 < 0) {
		if (0 <= countRectangle17 && countRectangle17 < 1) {
			move(grayRectangle, moveGR17, 1);
			if (!changeSizeRectangle && sizeRectangle < 1 / 8) {
				changeSizeRectangle = true;
				countRectangle17++;
			}
		}
		else if (countRectangle17 == 1) {
			Sleep(4000);
			countRectangle17 = -1;
			changeSizeRectangle = false;
			sizeRectangle = 1;
		}
	}
	if (countCircle18 < 0) {
		if (0 <= countRectangle19 && countRectangle19 < 1) {
			move(grayCircle, moveGC20, 1);
			move(grayRectangle, moveGR19, 1);
			if (!changeSizeRectangle && sizeRectangle > 1) {
				changeSizeRectangle = true;
				countRectangle19++;
			}
		}
		else if (countRectangle19 == 1) {
			countRectangle19 = -1;
			changeSizeRectangle = false;
			sizeRectangle = 1;
			Sleep(1500);
		}
	}

	if (countRectangle19 < 0) {
		move(grayCircle, moveGC21, 1);
		move(grayRectangle, moveGR21, 1);
		glViewport(x, y, width, heigth);
		x += 2; y += 2; width -= 3; heigth -= 3;
		if (x > 430) exit(0);
	}

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(606, 750);
	glutCreateWindow("Pintura 4");
	init();
	glutDisplayFunc(paint);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}
