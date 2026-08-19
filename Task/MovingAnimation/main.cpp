#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 0.05f;

void update(int value) {

    if(position1 > 1.0f)
        position1 = -1.0f;
    position1 += speed;


    if(position2 < -1.0f)
        position2 = 1.0f;
    position2 -= speed;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();


   glPushMatrix();
   glTranslatef(position1, 0.4f, 0.0f);
       glBegin(GL_QUADS);
          glColor3f(1.0f, 0.0f, 0.0f);
          glVertex2f(-0.2f, -0.2f);
          glVertex2f( 0.2f, -0.2f);
          glVertex2f( 0.2f,  0.2f);
          glVertex2f(-0.2f,  0.2f);
       glEnd();
       glBegin(GL_TRIANGLES);
          glColor3f(0.0f, 0.0f, 1.0f);
          glVertex2f(0.2f, -0.2f);
          glVertex2f(0.5f,  0.0f);
          glVertex2f(0.2f,  0.2f);
       glEnd();
   glPopMatrix();


   glPushMatrix();
   glTranslatef(position2, -0.4f, 0.0f);
       glBegin(GL_QUADS);
          glColor3f(0.0f, 1.0f, 0.0f);
          glVertex2f(-0.2f, -0.2f);
          glVertex2f( 0.2f, -0.2f);
          glVertex2f( 0.2f,  0.2f);
          glVertex2f(-0.2f,  0.2f);
       glEnd();
       glBegin(GL_TRIANGLES);
          glColor3f(1.0f, 1.0f, 0.0f);
          glVertex2f(-0.2f, -0.2f);
          glVertex2f(-0.5f,  0.0f);
          glVertex2f(-0.2f,  0.2f);
       glEnd();
   glPopMatrix();

   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Translation Animation");
   glutDisplayFunc(display);
   init();
   glutTimerFunc(100, update, 0);
   glutMainLoop();
   return 0;
}
