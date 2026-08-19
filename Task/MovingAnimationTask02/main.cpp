#include <cstdio>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>


GLfloat position1 = -1.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 0.02f;

void update(int value) {
    position1 += speed;
    if (position1 > 0.0f) {
        position1 = -1.2f;
    }
    position2 += speed;
    if (position2 > 1.2f) {
        position2 = 0.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void drawEnvironment() {
    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.6f, 0.9f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f( 1.0f, 1.0f);

        glColor3f(0.7f, 0.9f, 1.0f);
        glVertex2f( 1.0f, -0.3f);
        glVertex2f(-1.0f, -0.3f);
    glEnd();

    glColor3f(1.0f, 0.8f, 0.0f);
    drawCircle(0.7f, 0.7f, 0.12f, 30);

    glBegin(GL_TRIANGLES);
        glColor3f(0.4f, 0.3f, 0.2f);
        glVertex2f(-1.0f, -0.3f);
        glVertex2f(-0.5f, 0.2f);
        glVertex2f(0.0f, -0.3f);

        glColor3f(0.35f, 0.25f, 0.15f);
        glVertex2f(-0.2f, -0.3f);
        glVertex2f(0.4f, 0.3f);
        glVertex2f(1.0f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.2f, 0.7f, 0.2f);
        glVertex2f(-1.0f, -0.3f);
        glVertex2f( 1.0f, -0.3f);

        glColor3f(0.1f, 0.5f, 0.1f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.4f, 0.2f, 0.1f);
        glVertex2f(-0.75f, -0.5f);
        glVertex2f(-0.65f, -0.5f);
        glVertex2f(-0.65f, -0.2f);
        glVertex2f(-0.75f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.4f, 0.1f);
        glVertex2f(-0.85f, -0.2f);
        glVertex2f(-0.55f, -0.2f);
        glVertex2f(-0.70f,  0.0f);

        glColor3f(0.0f, 0.5f, 0.1f);
        glVertex2f(-0.82f, -0.08f);
        glVertex2f(-0.58f, -0.08f);
        glVertex2f(-0.70f,  0.10f);

        glColor3f(0.0f, 0.6f, 0.15f);
        glVertex2f(-0.78f,  0.02f);
        glVertex2f(-0.62f,  0.02f);
        glVertex2f(-0.70f,  0.20f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.35f, 0.18f, 0.08f);
        glVertex2f(0.68f, -0.55f);
        glVertex2f(0.72f, -0.55f);
        glVertex2f(0.72f, -0.30f);
        glVertex2f(0.68f, -0.30f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.1f, 0.5f, 0.15f);
        glVertex2f(0.60f, -0.30f);
        glVertex2f(0.80f, -0.30f);
        glVertex2f(0.70f, -0.10f);

        glColor3f(0.15f, 0.6f, 0.2f);
        glVertex2f(0.62f, -0.20f);
        glVertex2f(0.78f, -0.20f);
        glVertex2f(0.70f, -0.02f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.15f, 0.05f);
        glVertex2f(0.88f, -0.60f);
        glVertex2f(0.94f, -0.60f);
        glVertex2f(0.94f, -0.20f);
        glVertex2f(0.88f, -0.20f);

        glVertex2f(0.88f, -0.30f);
        glVertex2f(0.82f, -0.20f);
        glVertex2f(0.84f, -0.18f);
        glVertex2f(0.89f, -0.25f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.45f, 0.1f);
        glVertex2f(0.78f, -0.20f);
        glVertex2f(0.92f, -0.20f);
        glVertex2f(0.85f, -0.05f);

        glColor3f(0.0f, 0.55f, 0.15f);
        glVertex2f(0.88f, -0.20f);
        glVertex2f(1.02f, -0.20f);
        glVertex2f(0.95f, -0.05f);

        glColor3f(0.1f, 0.6f, 0.2f);
        glVertex2f(0.83f, -0.10f);
        glVertex2f(0.97f, -0.10f);
        glVertex2f(0.90f,  0.08f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.9f, 0.8f, 0.7f);
        glVertex2f(0.1f, -0.6f);
        glVertex2f(0.5f, -0.6f);
        glVertex2f(0.5f, -0.35f);
        glVertex2f(0.1f, -0.35f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.8f, 0.1f, 0.1f);
        glVertex2f(0.05f, -0.35f);
        glVertex2f(0.55f, -0.35f);
        glVertex2f(0.30f, -0.15f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.4f, 0.2f, 0.0f);
        glVertex2f(0.26f, -0.6f);
        glVertex2f(0.34f, -0.6f);
        glVertex2f(0.34f, -0.42f);
        glVertex2f(0.26f, -0.42f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.2f, 0.5f, 0.8f);
        glVertex2f(0.14f, -0.5f);
        glVertex2f(0.22f, -0.5f);
        glVertex2f(0.22f, -0.42f);
        glVertex2f(0.14f, -0.42f);

        glVertex2f(0.38f, -0.5f);
        glVertex2f(0.46f, -0.5f);
        glVertex2f(0.46f, -0.42f);
        glVertex2f(0.38f, -0.42f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.95f, 0.85f, 0.70f);
        glVertex2f(-0.35f, -0.60f);
        glVertex2f( 0.05f, -0.60f);
        glVertex2f( 0.05f, -0.35f);
        glVertex2f(-0.35f, -0.35f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.85f, 0.15f, 0.1f);
        glVertex2f(-0.40f, -0.35f);
        glVertex2f( 0.10f, -0.35f);
        glVertex2f(-0.15f, -0.15f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.4f, 0.2f, 0.05f);
        glVertex2f(-0.20f, -0.60f);
        glVertex2f(-0.10f, -0.60f);
        glVertex2f(-0.10f, -0.42f);
        glVertex2f(-0.20f, -0.42f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.2f, 0.6f, 0.9f);
        glVertex2f(-0.31f, -0.50f);
        glVertex2f(-0.24f, -0.50f);
        glVertex2f(-0.24f, -0.42f);
        glVertex2f(-0.31f, -0.42f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.2f, 0.6f, 0.9f);
        glVertex2f(-0.06f, -0.50f);
        glVertex2f( 0.01f, -0.50f);
        glVertex2f( 0.01f, -0.42f);
        glVertex2f(-0.06f, -0.42f);
    glEnd();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawEnvironment();

    glPushMatrix();
    glTranslatef(position1, -position1, 0.0f);

        glBegin(GL_TRIANGLES);
           glColor3f(1.0f, 0.2f, 0.2f);
           glVertex2f(0.0f, 0.0f);
           glVertex2f(-0.12f, 0.12f);
           glVertex2f(-0.04f, 0.0f);

           glColor3f(0.8f, 0.0f, 0.0f);
           glVertex2f(0.0f, 0.0f);
           glVertex2f(0.12f, 0.12f);
           glVertex2f(0.04f, 0.0f);

           glColor3f(1.0f, 0.5f, 0.0f);
           glVertex2f(0.0f, 0.04f);
           glVertex2f(-0.04f, -0.08f);
           glVertex2f(0.04f, -0.08f);
        glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(position2, position2, 0.0f);

        glBegin(GL_TRIANGLES);
           glColor3f(0.0f, 0.7f, 1.0f);
           glVertex2f(0.0f, 0.0f);
           glVertex2f(-0.12f, 0.12f);
           glVertex2f(-0.04f, 0.0f);

           glColor3f(0.0f, 0.4f, 0.9f);
           glVertex2f(0.0f, 0.0f);
           glVertex2f(0.12f, 0.12f);
           glVertex2f(0.04f, 0.0f);

           glColor3f(1.0f, 0.9f, 0.0f);
           glVertex2f(0.0f, 0.04f);
           glVertex2f(-0.04f, -0.08f);
           glVertex2f(0.04f, -0.08f);
        glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Moving Animation with Birds");
    glutDisplayFunc(display);
    init();
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}
