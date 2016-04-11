//#include "GLFW\glfw3.h"
//#include <math.h>
//#include "glm\glm.hpp"
#ifndef CIRCLE_H
#define CIRCLE_H
#include "CollisionDetection.h"
void DrawCircle()
{
	float x1, y1, x2, y2;
	float angle;
	double radius = 0.5;
	x1 = 0.5, y1 = 0.6;
	GLfloat aabbX1 = x1 - radius;
	GLfloat aabbX2 = x1 + radius;
	GLfloat aabbY1 = y1 + radius;
	GLfloat aabbY2 = y1 - radius;
	glColor3f(1.0, 1.0, 0.6);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	getPolygonBoudningBox( aabbX1, aabbX2, aabbY1, aabbY2 );

	for (angle = 1.0f; angle<361.0f; angle += 0.2)
	{
		glColor3f(0.0, 1.0, 0.0);

		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}

	


	glEnd();
}
#endif