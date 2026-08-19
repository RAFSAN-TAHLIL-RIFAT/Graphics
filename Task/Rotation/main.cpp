#include <windows.h>
#include <GL/glut.h>

GLfloat i = 0.0f;

void initGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Idle()
{
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_LINES);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2d(-1.0, 0.0);
        glVertex2d(1.0, 0.0);
    glEnd();


    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2d(0.0, 1.0);
        glVertex2d(0.0, -1.0);
    glEnd();

    glPushMatrix();

        glRotatef(i, 0.0f, 0.0f, -1.0f);

        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(0.34f, 0.15f);
            glVertex2f(0.3f, 0.2f);
        glEnd();

    glPopMatrix();

    i += 0.2f;

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(320, 320);
    glutCreateWindow("Triangle Rotation");

    glutDisplayFunc(display);
    initGL();
    glutIdleFunc(Idle);
    glutMainLoop();

    return 0;
}
