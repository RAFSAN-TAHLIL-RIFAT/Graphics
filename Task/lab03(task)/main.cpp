#include <windows.h>
#include <GL/glut.h>
#include <math.h>


void drawSun(float cx, float cy, float r, int num_segments) {
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++) {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.8f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(-1.0f, -0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.7f, 0.2f);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    drawSun(0.6f, 0.7f, 0.15f, 30);

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.6f, 0.4f);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(-0.1f, -0.4f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.6f, 0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.1f, 0.1f);
    glVertex2f(-0.65f, 0.1f);
    glVertex2f(-0.05f, 0.1f);
    glVertex2f(-0.35f, 0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(-0.3f, -0.4f);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(-0.4f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.9f, 0.9f);
    glVertex2f(-0.22f, -0.15f);
    glVertex2f(-0.15f, -0.15f);
    glVertex2f(-0.15f, -0.02f);
    glVertex2f(-0.22f, -0.02f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.35f, 0.0f);
    glVertex2f(0.25f, -0.4f);
    glVertex2f(0.35f, -0.4f);
    glVertex2f(0.35f, 0.0f);
    glVertex2f(0.25f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 0.1f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.3f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.15f);
    glVertex2f(0.15f, 0.2f);
    glVertex2f(0.45f, 0.2f);
    glVertex2f(0.3f, 0.5f);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simple OpenGL Scenario");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
