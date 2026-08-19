#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat position1 = -1.0f;
GLfloat position2 = 1.0f;
GLfloat speed = 0.03f;

void update(int value) {
    if(position1 > 1.2f)
        position1 = -1.2f;
    position1 += speed;


    if(position2 < -1.2f)
        position2 = 1.2f;
    position2 -= speed;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

void init() {
   glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();

   glBegin(GL_QUADS);
      glColor3f(0.2f, 0.7f, 0.2f);
      glVertex2f(-1.0f, -1.0f);
      glVertex2f( 1.0f, -1.0f);
      glVertex2f( 1.0f,  0.1f);
      glVertex2f(-1.0f,  0.1f);
   glEnd();

   glBegin(GL_QUADS);
      glColor3f(0.3f, 0.3f, 0.3f);
      glVertex2f(-1.0f, -0.8f);
      glVertex2f( 1.0f, -0.8f);
      glVertex2f( 1.0f, -0.1f);
      glVertex2f(-1.0f, -0.1f);
   glEnd();


   glBegin(GL_LINES);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-1.0f, -0.45f);
      glVertex2f( 1.0f, -0.45f);
   glEnd();


   glBegin(GL_QUADS);
      glColor3f(0.9f, 0.8f, 0.4f);
      glVertex2f(-0.3f,  0.1f);
      glVertex2f( 0.3f,  0.1f);
      glVertex2f( 0.3f,  0.5f);
      glVertex2f(-0.3f,  0.5f);
   glEnd();


   glBegin(GL_TRIANGLES);
      glColor3f(0.8f, 0.2f, 0.1f);
      glVertex2f(-0.35f, 0.5f);
      glVertex2f( 0.35f, 0.5f);
      glVertex2f( 0.0f,  0.8f);
   glEnd();


   glBegin(GL_QUADS);
      glColor3f(0.4f, 0.2f, 0.1f);
      glVertex2f(-0.08f, 0.1f);
      glVertex2f( 0.08f, 0.1f);
      glVertex2f( 0.08f, 0.35f);
      glVertex2f(-0.08f, 0.35f);
   glEnd();

   glBegin(GL_QUADS);
      glColor3f(0.4f, 0.26f, 0.13f);
      glVertex2f(0.55f, 0.1f);
      glVertex2f(0.65f, 0.1f);
      glVertex2f(0.65f, 0.4f);
      glVertex2f(0.55f, 0.4f);
   glEnd();

   glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 0.5f, 0.1f);
      glVertex2f(0.45f, 0.4f);
      glVertex2f(0.75f, 0.4f);
      glVertex2f(0.60f, 0.75f);
   glEnd();


   glPushMatrix();
   glTranslatef(position1, -0.3f, 0.0f);

       glBegin(GL_QUADS);
          glColor3f(0.9f, 0.1f, 0.1f);
          glVertex2f(-0.25f,  0.0f);
          glVertex2f( 0.25f,  0.0f);
          glVertex2f( 0.25f,  0.18f);
          glVertex2f(-0.25f,  0.18f);
       glEnd();

       glBegin(GL_QUADS);
          glColor3f(0.8f, 0.9f, 1.0f);
          glVertex2f( 0.15f,  0.08f);
          glVertex2f( 0.23f,  0.08f);
          glVertex2f( 0.23f,  0.15f);
          glVertex2f( 0.15f,  0.15f);
       glEnd();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(position2, -0.65f, 0.0f);

       glBegin(GL_QUADS);
          glColor3f(0.1f, 0.3f, 0.9f);
          glVertex2f(-0.25f,  0.0f);
          glVertex2f( 0.25f,  0.0f);
          glVertex2f( 0.25f,  0.18f);
          glVertex2f(-0.25f,  0.18f);
       glEnd();

       glBegin(GL_QUADS);
          glColor3f(0.8f, 0.9f, 1.0f);
          glVertex2f(-0.23f,  0.08f);
          glVertex2f(-0.15f,  0.08f);
          glVertex2f(-0.15f,  0.15f);
          glVertex2f(-0.23f,  0.15f);
       glEnd();
   glPopMatrix();

   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Moving Animation Task");
   glutDisplayFunc(display);
   init();
   glutTimerFunc(100, update, 0);
   glutMainLoop();
   return 0;
}
