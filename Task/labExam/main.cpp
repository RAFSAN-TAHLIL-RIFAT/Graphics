#include <windows.h>
#include <GL/glut.h>

void display()
{
    glClearColor(0.55f, 0.64f, 0.79f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
        glVertex2f(-0.15f, 0.85f);
        glVertex2f( 0.10f, 0.85f);
        glVertex2f( 0.10f, 0.73f);
        glVertex2f(-0.15f, 0.73f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.15f, 0.73f);
        glVertex2f( 0.25f, 0.73f);
        glVertex2f( 0.25f, 0.55f);
        glVertex2f(-0.15f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.15f, 0.55f);
        glVertex2f( 0.10f, 0.55f);
        glVertex2f( 0.10f, 0.49f);
        glVertex2f(-0.15f, 0.49f);
    glEnd();

    glColor3f(0.98f, 0.83f, 0.71f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.05f, 0.55f);
        glVertex2f( 0.20f, 0.55f);
        glVertex2f( 0.20f, 0.37f);
        glVertex2f(-0.05f, 0.37f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f( 0.05f, 0.37f);
        glVertex2f( 0.20f, 0.37f);
        glVertex2f( 0.20f, 0.29f);
        glVertex2f( 0.05f, 0.29f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f( 0.00f, 0.29f);
        glVertex2f( 0.20f, 0.29f);
        glVertex2f( 0.20f, 0.14f);
        glVertex2f( 0.00f, 0.14f);
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.10f, 0.33f);
        glVertex2f( 0.00f, 0.33f);
        glVertex2f( 0.00f, -0.15f);
        glVertex2f(-0.10f, -0.15f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f( 0.20f, 0.33f);
        glVertex2f( 0.30f, 0.33f);
        glVertex2f( 0.30f, -0.15f);
        glVertex2f( 0.20f, -0.15f);
    glEnd();

    glColor3f(0.98f, 0.83f, 0.71f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.10f, -0.15f);
        glVertex2f( 0.00f, -0.15f);
        glVertex2f( 0.00f, -0.23f);
        glVertex2f(-0.10f, -0.23f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f( 0.20f, -0.15f);
        glVertex2f( 0.30f, -0.15f);
        glVertex2f( 0.30f, -0.23f);
        glVertex2f( 0.20f, -0.23f);
    glEnd();

    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.02f, -0.05f);
        glVertex2f( 0.22f, -0.05f);
        glVertex2f( 0.22f, -0.08f);
        glVertex2f(-0.02f, -0.08f);
    glEnd();

    glColor3f(0.0f, 0.33f, 0.64f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.02f, -0.08f);
        glVertex2f( 0.08f, -0.08f);
        glVertex2f( 0.08f, -0.60f);
        glVertex2f(-0.02f, -0.60f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f( 0.12f, -0.08f);
        glVertex2f( 0.22f, -0.08f);
        glVertex2f( 0.22f, -0.60f);
        glVertex2f( 0.12f, -0.60f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.02f, -0.60f);
        glVertex2f( 0.08f, -0.60f);
        glVertex2f( 0.08f, -0.66f);
        glVertex2f(-0.02f, -0.66f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f( 0.12f, -0.60f);
        glVertex2f( 0.22f, -0.60f);
        glVertex2f( 0.22f, -0.66f);
        glVertex2f( 0.12f, -0.66f);
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.12f, -0.66f);
        glVertex2f( 0.08f, -0.66f);
        glVertex2f( 0.08f, -0.78f);
        glVertex2f(-0.12f, -0.78f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f( 0.12f, -0.66f);
        glVertex2f( 0.32f, -0.66f);
        glVertex2f( 0.32f, -0.78f);
        glVertex2f( 0.12f, -0.78f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab-Exam");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
