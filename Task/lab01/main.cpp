#include <windows.h>
#include <GL/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1.1f, 1.1f, 1.1f, 1.1f);

  glBegin(GL_TRIANGLES);
  glColor3f(1,0,0);
  glVertex2d(-0.5,0.7);
  glVertex2d(-0.7,0.3);
  glVertex2d(-0.4,0.3);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0,1,0);
  glVertex2d(0.2,0.2);
  glVertex2d(0.8,0.8);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3f(1,0,0);
  glVertex2d(0.4,-0.4);
  glVertex2d(0.49,-0.7);
  glVertex2d(0.8,-0.2);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0,0,1);
  glVertex2d(-0.7,-0.1);
  glVertex2d(-0.7,-0.6);
  glVertex2d(-0.1,-0.6);
  glVertex2d(-0.1,-0.1);
  glEnd();

  glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(320,320);
    glutCreateWindow("First lab Practice");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
