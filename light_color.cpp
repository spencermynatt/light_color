//this code is heavily based on a example i folloed through
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
void handleKeyPress(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
	{
		exit(0);
	}
	}
}
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE); //normalizes normal vectors that calculate lighting
};
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
float angle = 30.0f;
float camera_angle = 0.0f;
void draw_scene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 2.0f, -5.0f);


	GLfloat ambient_color[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_color);

	//positioned light
	 
	GLfloat lightColor0[] = {
		0.5f, 0.5f, 0.5f, 1.0f //light color
	};
	GLfloat lightPos0[] = {
		4.0f, 0.0f, 8.0f, 1.0f //light position
	};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);


	//add directed light
	GLfloat lightColor1[] = {
		0.50f, 0.2f, 0.2f, 1.0f
	};
	GLfloat lightPos1[] = {
		-1.0f, 0.5f, 0.5f, 0.0f,
	};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	

	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, 1.5f);

	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glVertex3f(1.5f, -1.0f, 1.5f);

	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, -1.0f, -1.5f);

	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, -1.5f);

	glEnd();
	glutSwapBuffers();
}


void update(int value) {
	angle = angle + 2.0;
	if (angle > 360) {
		angle = angle - 360;
	}
	glutPostRedisplay(); //display changed
	glutTimerFunc(25, update, 0); //put update again in 25 miliseconds
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("hi");
	initRendering();
	glutDisplayFunc(draw_scene);
	glutKeyboardFunc(handleKeyPress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0;

}
