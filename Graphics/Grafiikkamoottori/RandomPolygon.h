#include "GLFW\glfw3.h"
#include "glm\glm.hpp"


void RandomPolygon(unsigned int sides)
{
    
	if (sides < 3) return;

	const float PI = 3.14159f;
	const float step = (2 * PI) / static_cast< float >(sides);

	glBegin(GL_LINES);
	for (unsigned int i = 0; i < sides; ++i)
	{
		unsigned int cur = (i + 0) % sides;
		unsigned int nxt = (i + 1) % sides;
		glVertex2f(cos(cur * step), sin(cur * step));
		glVertex2f(cos(nxt * step), sin(nxt * step));
	}
	glEnd();


}




