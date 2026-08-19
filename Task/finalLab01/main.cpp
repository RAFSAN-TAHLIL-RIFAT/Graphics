#include <windows.h>
#include <GL/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1.1f, 1.1f, 1.1f, 1.1f);

  glBegin(GL_LINES);
  glColor3f(1,0,0);
  glVertex2d(-1,0);
  glVertex2d(1,0);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0,0,1);
  glVertex2d(0,1);
  glVertex2d(0,-1);
  glEnd();


  glBegin(GL_TRIANGLES);
  glColor3f(1,0,0);
  glVertex2f(-0.3f, -0.3f);
  glVertex2f( 0.3f, -0.3f);
  glVertex2f( 0.0f,  0.3f);
  glEnd();

  glTranslatef(0.2f, 0.1f, 0.0f);
  glBegin(GL_TRIANGLES);
  glColor3f(0,1,0);
  glVertex2f(-0.3f, -0.3f);
  glVertex2f( 0.3f, -0.3f);
  glVertex2f( 0.0f,  0.3f);
  glEnd();

  /*glScalef(1.5f, 1.5f, 1.0f);
  glBegin(GL_TRIANGLES);
  glColor3f(0,1,0);
  glVertex2f(-0.3f, -0.3f);
  glVertex2f( 0.3f, -0.3f);
  glVertex2f( 0.0f,  0.3f);
  glEnd();*/

  glFlush();

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(320,320);
    glutCreateWindow("Final Lab");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

