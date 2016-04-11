//#include "GLFW\glfw3.h"
//#include "Shader.h"
//
//void Triforce(int n)
//{
//	//if (n == 0)
//	//{
//	//	glBegin(GL_TRIANGLES);
//	//	glColor3f(1.0f, 0.0f, 0.0f);
//	//	glVertex3f(0.0f, 0.5f, 0.0f);
//	//	glColor3f(0.0f, 1.0f, 0.0f);
//	//	glVertex3f(-0.5f, -0.5f, 0.0f);
//	//	glColor3f(0.0f, 0.0f, 1.0f);
//	//	glVertex3f(0.5f, -0.5f, 0.0f);
//	//	glEnd();
//	//}
//
//	//if (n == 1)
//	//{
//	//	//1.1
//	//	glBegin(GL_TRIANGLES);
//	//	glColor3f(1.0f, 0.0f, 0.0f);
//	//	glVertex3f(-1.0f, -1.0f, 0.0f);
//	//	glColor3f(0.0f, 1.0f, 0.0f);
//	//	glVertex3f(0.0f, -1.0f, 0.0f);
//	//	glColor3f(0.0f, 0.0f, 1.0f);
//	//	glVertex3f(-0.5f, 0.0f, 0.0f);
//	//	glEnd();
//
//	//	//2.1
//	//	glBegin(GL_TRIANGLES);
//	//	glColor3f(1.0f, 0.0f, 0.0f);
//	//	glVertex3f(0.0f, -1.0f, 0.0f);
//	//	glColor3f(0.0f, 1.0f, 0.0f);
//	//	glVertex3f(1.0f, -1.0f, 0.0f);
//	//	glColor3f(0.0f, 0.0f, 1.0f);
//	//	glVertex3f(0.5f, 0.0f, 0.0f);
//	//	glEnd();
//
//	//	//3.1
//	//	glBegin(GL_TRIANGLES);
//	//	glColor3f(1.0f, 0.0f, 0.0f);
//	//	glVertex3f(-0.5f, 0.0f, 0.0f);
//	//	glColor3f(0.0f, 1.0f, 0.0f);
//	//	glVertex3f(0.5f, 0.0f, 0.0f);
//	//	glColor3f(0.0f, 0.0f, 1.0f);
//	//	glVertex3f(0.0f, 1.0f, 0.0f);
//	//	glEnd();
//	//}
//
//	//if (n == 2)
//	//{
//	//	//1.2
//	//	glBegin(GL_TRIANGLES);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(-1.0f, -1.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(0.0f, -1.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(-0.5f, 0.0f, 0.0f);
//	//	glEnd();
//
//	//	//2.2
//	//	glBegin(GL_TRIANGLES);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(0.0f, -1.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(1.0f, -1.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(0.5f, 0.0f, 0.0f);
//	//	glEnd();
//
//	//	//3.2
//	//	glBegin(GL_TRIANGLES);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(-0.5f, 0.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(0.5f, 0.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(0.0f, 1.0f, 0.0f);
//	//	glEnd();
//	//}
//
//	//if (n == 3)
//	//{
//	//	//1.2
//	//	glBegin(GL_TRIANGLES);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(-1.0f, -1.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(0.0f, -1.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(-0.5f, 0.0f, 0.0f);
//	//	glEnd();
//
//	//	//2.2
//	//	glBegin(GL_TRIANGLES);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(0.0f, -1.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(1.0f, -1.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(0.5f, 0.0f, 0.0f);
//	//	glEnd();
//
//	//	//3.3
//	//	glBegin(GL_TRIANGLES);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(0.0f, 0.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(-1.0f, 0.0f, 0.0f);
//	//	glColor3f(1.0f, 1.0f, 0.0f);
//	//	glVertex3f(-0.5f, 1.0f, 0.0f);
//	//	glEnd();
//
//		glGenVertexArrays(1, &VertexArrayID);
//		glBindVertexArray(VertexArrayID);
//
//		programID = LoadShaders("VertexShader.vertexshader", "FragmentShader.fragmentshader");
//		MVP_MatrixID = glGetUniformLocation(programID, "MVP");
//
//		static GLfloat g_vertex_buffer_data[] = 
//		{
//			0.0f, 0.5f, 0.0f,
//			-0.5f, -0.5f, 0.0f,
//			0.5f, -0.5f, 0.0f,
//		};
//		glGenBuffers(1, &vertexbuffer);
//		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//
//
//		static GLuint g_indices[] = {
//			0, 1, 2, //1
//
//		};
//		glGenBuffers(1, &indexbuffer);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexbuffer);
//		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_indices), g_indices, GL_STATIC_DRAW);
//
//
//
//		static const GLfloat g_color_buffer_data[] = {
//			1.0f, 0.0f, 0.0f,
//			0.0f, 1.0f, 0.0f,
//			0.0f, 0.0f, 1.0f,
//		};
//
//		glGenBuffers(1, &colorbuffer);
//		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
//
//
//
//		N_vertex = sizeof(g_indices) / sizeof(*g_indices);
//	
//
//		glEnable(GL_BLEND);
//
//
//		RotateMath(-alpha, 0.1, 0.25);
//		glUseProgram(programID);
//
//
//		glUniformMatrix4fv(MVP_MatrixID, 1, GL_FALSE, &MVP[0][0]);
//		glUniform2fv(wh_VectorID, 1, &wh[0]);
//
//		glEnableVertexAttribArray(0);
//		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//		glVertexAttribPointer(
//			VERTEX_POSITION,
//			3,
//			GL_FLOAT,
//			GL_FALSE,
//			0,
//			(void*)0
//			);
//
//		glEnableVertexAttribArray(1);
//		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
//		glVertexAttribPointer(
//			VERTEX_COLOR,
//			4,
//			GL_FLOAT,
//			GL_FALSE,
//			0,
//			(void*)0
//			);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexbuffer);
//		//glDrawElements(GL_LINE_LOOP, N_vertex, GL_UNSIGNED_BYTE, (GLvoid*)0);
//		glDrawElements(GL_TRIANGLES, N_vertex, GL_UNSIGNED_INT, (GLvoid*)0);
//		alpha += 0.015;
//		glDisableVertexAttribArray(0);
//		glDisableVertexAttribArray(1);
//}