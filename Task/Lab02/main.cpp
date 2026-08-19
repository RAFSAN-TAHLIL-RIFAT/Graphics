#include <windows.h>
#include <GL/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1.1f, 1.1f, 1.1f, 1.1f);

  glBegin(GL_LINES);
  glColor3f(1,0,0);
  glVertex2d(1.0,0.0);
  glVertex2d(-1.0,0.0);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0,0,1);
  glVertex2d(0.0,1.0);
  glVertex2d(0.0,-1.0);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3f(0.78,0.098,0.325);
  glVertex2d(0.4,0.8);
  glVertex2d(0.6,0.3);
  glVertex2d(0.8,0.8);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3f(0.098,0.702,0.78);
  glVertex2d(0.4,-0.4);
  glVertex2d(0.4,-0.8);
  glVertex2d(0.8,-0.6);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(0.941,0.831,0.153);
  glVertex2d(-0.5,-0.2);
  glVertex2d(-0.7,-0.5);
  glVertex2d(-0.7,-0.7);
  glVertex2d(-0.5,-0.9);
  glVertex2d(-0.3,-0.7);
  glVertex2d(-0.3,-0.5);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1,0,0);
  glVertex2d(-0.8,0.8);
  glVertex2d(-0.3,0.8);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0,1,0);
  glVertex2d(-0.8,0.8);
  glVertex2d(-0.8,0.3);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0,0,1);
  glVertex2d(-0.8,0.3);
  glVertex2d(-0.3,0.3);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0.941,0.831,0.153);
  glVertex2d(-0.3,0.3);
  glVertex2d(-0.3,0.8);
  glEnd();

  glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(320,320);
    glutCreateWindow("Lab 02");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
