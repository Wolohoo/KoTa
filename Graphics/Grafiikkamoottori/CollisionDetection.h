#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H
#include "glm\glm.hpp"
#include "GLFW\glfw3.h"
#include "Matikka.h"
void getPolygonBoudningBox(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glVertex2f(x1, y2);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}
#endif