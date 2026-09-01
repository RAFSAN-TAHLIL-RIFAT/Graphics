#include <cstdio>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

GLfloat position1 = -0.50f;
GLfloat position2 = 0.00f;
GLfloat birdPosition = 1.0f;
GLfloat speed = 0.012f;
GLfloat birdSpeed = 0.03f;

int isDay = 1;

GLfloat waveOffset = 0.0f;
GLfloat wingOffset = 0.0f;
GLfloat armOffset = 0.0f;


void update(int value)
{
    position1 += speed;
    if (position1 > 1.40f)
        position1 = -1.40f;

    position2 += speed;
    if (position2 > 1.40f)
        position2 = -1.40f;

    if (birdPosition < -1.40f)
        birdPosition = 1.40f;
    birdPosition -= birdSpeed;

    waveOffset += 0.15f;
    wingOffset += 0.25f;
    armOffset  += 0.12f;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}


void handleMouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        if (button == GLUT_RIGHT_BUTTON)
        {
            birdSpeed += 0.01f;
        }
        if (button == GLUT_LEFT_BUTTON)
        {
            if (birdSpeed > 0.005f)
                birdSpeed -= 0.01f;
            else
                birdSpeed = 0.0f;
        }
    }
    glutPostRedisplay();
}


void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'd':
    case 'D':
        isDay = 1;
        break;
    case 'n':
    case 'N':
        isDay = 0;
        break;
    case 'x':
    case 'X':
        speed += 0.005f;
        break;
    case 'y':
    case 'Y':
        if (speed > 0.002f)
            speed -= 0.005f;
        else
            speed = 0.0f;
        break;
    }
    glutPostRedisplay();
}


void init()
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_LIGHT0);
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    glEnable(GL_LIGHTING);

    if (isDay == 1)
    {
        GLfloat day_ambient[]  = { 0.80f, 0.80f, 0.80f, 1.0f };
        GLfloat day_diffuse[]  = { 1.00f, 0.95f, 0.80f, 1.0f };
        GLfloat day_position[] = { 0.72f, 0.72f, 1.00f, 0.0f };

        glLightfv(GL_LIGHT0, GL_AMBIENT, day_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, day_diffuse);
        glLightfv(GL_LIGHT0, GL_POSITION, day_position);

        GLfloat global_ambient[] = { 0.30f, 0.30f, 0.30f, 1.0f };
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    }
    else
    {
        GLfloat night_ambient[]  = { 0.15f, 0.15f, 0.30f, 1.0f };
        GLfloat night_diffuse[]  = { 0.20f, 0.25f, 0.50f, 1.0f };
        GLfloat night_position[] = { 0.72f, 0.72f, 1.00f, 0.0f };

        glLightfv(GL_LIGHT0, GL_AMBIENT, night_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, night_diffuse);
        glLightfv(GL_LIGHT0, GL_POSITION, night_position);

        GLfloat global_ambient[] = { 0.10f, 0.10f, 0.20f, 1.0f };
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    }

    GLfloat x;
    GLfloat y;
    GLfloat radius;

    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;

    if (isDay == 1)
    {
        for (float sx = -1.10f; sx <= 1.10f; sx += 0.20f)
        {
            glColor3f(0.30f, 0.65f, 0.95f);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(sx, 0.90f);
            for (i = 0; i <= triangleAmount; i++)
                glVertex2f(sx + 0.35f * cos(i * twicePi / triangleAmount), 0.90f + 0.35f * sin(i * twicePi / triangleAmount));
            glEnd();
        }

        for (float sx = -1.10f; sx <= 1.10f; sx += 0.18f)
        {
            glColor3f(0.48f, 0.76f, 0.98f);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(sx, 0.60f);
            for (i = 0; i <= triangleAmount; i++)
                glVertex2f(sx + 0.32f * cos(i * twicePi / triangleAmount), 0.60f + 0.32f * sin(i * twicePi / triangleAmount));
            glEnd();
        }

        for (float sx = -1.10f; sx <= 1.10f; sx += 0.16f)
        {
            glColor3f(0.72f, 0.88f, 1.00f);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(sx, 0.32f);
            for (i = 0; i <= triangleAmount; i++)
                glVertex2f(sx + 0.28f * cos(i * twicePi / triangleAmount), 0.32f + 0.28f * sin(i * twicePi / triangleAmount));
            glEnd();
        }

        GLfloat cloud1X[] = { -0.70f, -0.62f, -0.54f, -0.62f };
        GLfloat cloud1Y[] = {  0.72f,  0.76f,  0.72f,  0.70f };
        GLfloat cloud1R[] = {  0.07f,  0.09f,  0.07f,  0.06f };
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int c = 0; c < 4; c++)
        {
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(cloud1X[c], cloud1Y[c]);
            for (i = 0; i <= triangleAmount; i++)
                glVertex2f(cloud1X[c] + cloud1R[c] * cos(i * twicePi / triangleAmount), cloud1Y[c] + cloud1R[c] * sin(i * twicePi / triangleAmount));
            glEnd();
        }

        GLfloat cloud2X[] = { 0.05f, 0.14f, 0.23f, 0.14f };
        GLfloat cloud2Y[] = { 0.78f, 0.83f, 0.78f, 0.75f };
        GLfloat cloud2R[] = { 0.08f, 0.10f, 0.08f, 0.07f };
        for (int c = 0; c < 4; c++)
        {
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(cloud2X[c], cloud2Y[c]);
            for (i = 0; i <= triangleAmount; i++)
                glVertex2f(cloud2X[c] + cloud2R[c] * cos(i * twicePi / triangleAmount), cloud2Y[c] + cloud2R[c] * sin(i * twicePi / triangleAmount));
            glEnd();
        }
    }
    else
    {
        for (float sx = -1.10f; sx <= 1.10f; sx += 0.20f)
        {
            glColor3f(0.02f, 0.02f, 0.12f);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(sx, 0.90f);
            for (i = 0; i <= triangleAmount; i++)
                glVertex2f(sx + 0.35f * cos(i * twicePi / triangleAmount), 0.90f + 0.35f * sin(i * twicePi / triangleAmount));
            glEnd();
        }

        for (float sx = -1.10f; sx <= 1.10f; sx += 0.18f)
        {
            glColor3f(0.04f, 0.05f, 0.18f);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(sx, 0.60f);
            for (i = 0; i <= triangleAmount; i++)
                glVertex2f(sx + 0.32f * cos(i * twicePi / triangleAmount), 0.60f + 0.32f * sin(i * twicePi / triangleAmount));
            glEnd();
        }

        for (float sx = -1.10f; sx <= 1.10f; sx += 0.16f)
        {
            glColor3f(0.08f, 0.10f, 0.25f);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(sx, 0.32f);
            for (i = 0; i <= triangleAmount; i++)
                glVertex2f(sx + 0.28f * cos(i * twicePi / triangleAmount), 0.32f + 0.28f * sin(i * twicePi / triangleAmount));
            glEnd();
        }

        glColor3f(1.0f, 1.0f, 0.9f);
        glPointSize(2.5f);
        glBegin(GL_POINTS);
        glVertex2f(-0.85f, 0.85f);
        glVertex2f(-0.65f, 0.75f);
        glVertex2f(-0.45f, 0.92f);
        glVertex2f(-0.25f, 0.80f);
        glVertex2f(-0.10f, 0.88f);
        glVertex2f( 0.15f, 0.95f);
        glVertex2f( 0.35f, 0.82f);
        glVertex2f( 0.55f, 0.90f);
        glVertex2f( 0.80f, 0.85f);
        glVertex2f(-0.90f, 0.65f);
        glVertex2f(-0.35f, 0.60f);
        glVertex2f( 0.45f, 0.68f);
        glVertex2f( 0.90f, 0.60f);
        glEnd();
    }

    if (isDay == 1)
    {
        glPushMatrix();
        glTranslatef(birdPosition, 0.0f, 0.0f);

        glColor3f(0.10f, 0.10f, 0.10f);
        glLineWidth(2.5f);

        float w = 0.02f * sin(wingOffset);

        glBegin(GL_LINES);
        glVertex2f(-0.10f, 0.75f);
        glVertex2f(-0.06f, 0.78f + w);
        glVertex2f(-0.06f, 0.78f + w);
        glVertex2f(-0.02f, 0.75f);

        glVertex2f(0.02f, 0.82f);
        glVertex2f(0.06f, 0.85f + w);
        glVertex2f(0.06f, 0.85f + w);
        glVertex2f(0.10f, 0.82f);

        glVertex2f(0.14f, 0.74f);
        glVertex2f(0.18f, 0.77f + w);
        glVertex2f(0.18f, 0.77f + w);
        glVertex2f(0.22f, 0.74f);

        glVertex2f(-0.22f, 0.80f);
        glVertex2f(-0.18f, 0.83f + w);
        glVertex2f(-0.18f, 0.83f + w);
        glVertex2f(-0.14f, 0.80f);
        glEnd();

        glPopMatrix();
    }

    x = 0.72f;
    y = 0.72f;

    if (isDay == 1)
    {
        radius = 0.10f;
        glColor3f(1.0f, 0.85f, 0.20f);
        glLineWidth(2.5f);
        glBegin(GL_LINES);
        for (i = 0; i < 12; i++)
        {
            glVertex2f(x + (radius + 0.02f) * cos(i * twicePi / 12), y + (radius + 0.02f) * sin(i * twicePi / 12));
            glVertex2f(x + (radius + 0.13f) * cos(i * twicePi / 12), y + (radius + 0.13f) * sin(i * twicePi / 12));
        }
        glEnd();

        glColor3f(1.0f, 0.92f, 0.30f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
        glEnd();
    }
    else
    {
        radius = 0.08f;
        glColor3f(0.95f, 0.95f, 0.85f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
        glEnd();

        glColor3f(0.04f, 0.05f, 0.18f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x + 0.035f, y + 0.025f);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f((x + 0.035f) + 0.075f * cos(i * twicePi / triangleAmount), (y + 0.025f) + 0.075f * sin(i * twicePi / triangleAmount));
        glEnd();
    }

    for (float bx = -1.0f; bx <= 1.0f; bx += 0.10f)
    {
        glColor3f(0.12f, 0.45f, 0.18f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(bx, 0.15f);
        for (i = 0; i <= 15; i++)
            glVertex2f(bx + 0.08f * cos(i * PI / 15), 0.15f + 0.040f * sin(i * PI / 15));
        glEnd();
    }

    GLfloat treeBaseX[] = { -0.96f, -0.82f, -0.68f, -0.52f, -0.38f, -0.22f, -0.06f, 0.10f, 0.26f, 0.45f, 0.65f, 0.88f };
    GLfloat treeBaseY[] = {  0.15f,  0.15f,  0.15f,  0.15f,  0.15f,  0.15f,  0.15f, 0.15f, 0.15f, 0.15f, 0.15f, 0.15f };

    for (int t = 0; t < 12; t++)
    {
        glColor3f(0.40f, 0.22f, 0.08f);
        glBegin(GL_QUADS);
        glVertex2f(treeBaseX[t] - 0.020f, treeBaseY[t]);
        glVertex2f(treeBaseX[t] + 0.020f, treeBaseY[t]);
        glVertex2f(treeBaseX[t] + 0.015f, treeBaseY[t] + 0.15f);
        glVertex2f(treeBaseX[t] - 0.015f, treeBaseY[t] + 0.15f);
        glEnd();

        GLfloat offsets[3][2] = { {-0.048f, 0.15f}, {0.048f, 0.15f}, {0.0f, 0.22f} };
        GLfloat leafColors[3][3] = { {0.18f, 0.58f, 0.20f}, {0.15f, 0.50f, 0.18f}, {0.25f, 0.68f, 0.25f} };

        for (int l = 0; l < 3; l++)
        {
            GLfloat cx = treeBaseX[t] + offsets[l][0];
            GLfloat cy = treeBaseY[t] + offsets[l][1];
            GLfloat cr = 0.075f;

            glColor3fv(leafColors[l]);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(cx, cy);
            for (i = 0; i <= triangleAmount; i++)
                glVertex2f(cx + cr * cos(i * twicePi / triangleAmount), cy + cr * sin(i * twicePi / triangleAmount));
            glEnd();
        }
    }

    for (float gx = -1.0f; gx <= 1.0f; gx += 0.08f)
    {
        glColor3f(0.14f, 0.52f, 0.16f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(gx, 0.15f);
        for (i = 0; i <= 15; i++)
            glVertex2f(gx + 0.065f * cos(i * PI / 15), 0.15f + 0.035f * sin(i * PI / 15));
        glEnd();
    }

    GLfloat grassTuftX[] = { -0.90f, -0.74f, -0.62f, -0.45f, -0.32f, -0.15f, 0.02f, 0.18f, 0.35f, 0.52f, 0.70f, 0.85f };
    for (int gt = 0; gt < 12; gt++)
    {
        glColor3f(0.20f, 0.68f, 0.22f);
        glBegin(GL_TRIANGLES);
        glVertex2f(grassTuftX[gt] - 0.015f, 0.15f);
        glVertex2f(grassTuftX[gt] - 0.005f, 0.15f);
        glVertex2f(grassTuftX[gt] - 0.020f, 0.20f);

        glVertex2f(grassTuftX[gt] - 0.005f, 0.15f);
        glVertex2f(grassTuftX[gt] + 0.005f, 0.15f);
        glVertex2f(grassTuftX[gt], 0.22f);

        glVertex2f(grassTuftX[gt] + 0.005f, 0.15f);
        glVertex2f(grassTuftX[gt] + 0.015f, 0.15f);
        glVertex2f(grassTuftX[gt] + 0.020f, 0.20f);
        glEnd();
    }


    GLfloat hutPos[] = { -0.80f, -0.56f, -0.25f, 0.44f };
    GLfloat wallColors[4][3] = {
        {0.85f, 0.68f, 0.48f},
        {0.90f, 0.75f, 0.55f},
        {0.82f, 0.64f, 0.45f},
        {0.88f, 0.70f, 0.50f}
    };
    GLfloat roofColors[4][3] = {
        {0.72f, 0.22f, 0.15f},
        {0.55f, 0.25f, 0.12f},
        {0.68f, 0.18f, 0.12f},
        {0.75f, 0.30f, 0.18f}
    };

    for (int h = 0; h < 4; h++)
    {
        glColor3fv(wallColors[h]);
        glBegin(GL_QUADS);
        glVertex2f(hutPos[h], 0.15f);
        glVertex2f(hutPos[h] + 0.13f, 0.15f);
        glVertex2f(hutPos[h] + 0.13f, 0.25f);
        glVertex2f(hutPos[h], 0.25f);
        glEnd();

        glColor3fv(roofColors[h]);
        glBegin(GL_TRIANGLES);
        glVertex2f(hutPos[h] - 0.02f, 0.25f);
        glVertex2f(hutPos[h] + 0.15f, 0.25f);
        glVertex2f(hutPos[h] + 0.065f, 0.35f);
        glEnd();

        glColor3f(0.35f, 0.18f, 0.08f);
        glBegin(GL_QUADS);
        glVertex2f(hutPos[h] + 0.050f, 0.15f);
        glVertex2f(hutPos[h] + 0.080f, 0.15f);
        glVertex2f(hutPos[h] + 0.080f, 0.22f);
        glVertex2f(hutPos[h] + 0.050f, 0.22f);
        glEnd();

        if (isDay == 1)
            glColor3f(0.25f, 0.50f, 0.70f);
        else
            glColor3f(1.00f, 0.92f, 0.25f);

        glBegin(GL_QUADS);
        glVertex2f(hutPos[h] + 0.015f, 0.175f);
        glVertex2f(hutPos[h] + 0.038f, 0.175f);
        glVertex2f(hutPos[h] + 0.038f, 0.215f);
        glVertex2f(hutPos[h] + 0.015f, 0.215f);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(hutPos[h] + 0.092f, 0.175f);
        glVertex2f(hutPos[h] + 0.115f, 0.175f);
        glVertex2f(hutPos[h] + 0.115f, 0.215f);
        glVertex2f(hutPos[h] + 0.092f, 0.175f);
        glEnd();
    }

    GLfloat bX1 = -0.08f;
    glColor3f(0.92f, 0.88f, 0.80f);
    glBegin(GL_QUADS);
    glVertex2f(bX1, 0.15f);
    glVertex2f(bX1 + 0.16f, 0.15f);
    glVertex2f(bX1 + 0.16f, 0.44f);
    glVertex2f(bX1, 0.44f);
    glEnd();

    glColor3f(0.82f, 0.78f, 0.70f);
    glBegin(GL_QUADS);
    glVertex2f(bX1 + 0.16f, 0.15f);
    glVertex2f(bX1 + 0.24f, 0.15f);
    glVertex2f(bX1 + 0.24f, 0.36f);
    glVertex2f(bX1 + 0.16f, 0.36f);
    glEnd();

    glColor3f(0.40f, 0.25f, 0.20f);
    glBegin(GL_QUADS);
    glVertex2f(bX1 - 0.01f, 0.44f);
    glVertex2f(bX1 + 0.17f, 0.44f);
    glVertex2f(bX1 + 0.17f, 0.46f);
    glVertex2f(bX1 - 0.01f, 0.46f);
    glEnd();

    GLfloat winY1[] = { 0.20f, 0.32f };
    GLfloat winX1[] = { -0.06f, 0.02f };
    for (int wy = 0; wy < 2; wy++) {
        for (int wx = 0; wx < 2; wx++) {
            if (isDay == 1)
                glColor3f(0.30f, 0.65f, 0.85f);
            else
                glColor3f(1.00f, 0.92f, 0.25f);
            glBegin(GL_QUADS);
            glVertex2f(winX1[wx], winY1[wy]);
            glVertex2f(winX1[wx] + 0.04f, winY1[wy]);
            glVertex2f(winX1[wx] + 0.04f, winY1[wy] + 0.07f);
            glVertex2f(winX1[wx], winY1[wy] + 0.07f);
            glEnd();
        }
    }

    GLfloat bX2 = 0.76f;
    glColor3f(0.85f, 0.88f, 0.90f);
    glBegin(GL_QUADS);
    glVertex2f(bX2, 0.15f);
    glVertex2f(bX2 + 0.14f, 0.15f);
    glVertex2f(bX2 + 0.14f, 0.40f);
    glVertex2f(bX2, 0.40f);
    glEnd();

    glColor3f(0.35f, 0.30f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(bX2 - 0.01f, 0.40f);
    glVertex2f(bX2 + 0.15f, 0.40f);
    glVertex2f(bX2 + 0.15f, 0.42f);
    glVertex2f(bX2 - 0.01f, 0.42f);
    glEnd();

    GLfloat winY2[] = { 0.20f, 0.30f };
    for (int wy = 0; wy < 2; wy++) {
        if (isDay == 1)
            glColor3f(0.30f, 0.65f, 0.85f);
        else
            glColor3f(1.00f, 0.92f, 0.25f);
        glBegin(GL_QUADS);
        glVertex2f(bX2 + 0.04f, winY2[wy]);
        glVertex2f(bX2 + 0.10f, winY2[wy]);
        glVertex2f(bX2 + 0.10f, winY2[wy] + 0.06f);
        glVertex2f(bX2 + 0.04f, winY2[wy] + 0.06f);
        glEnd();
    }

    glColor3f(0.20f, 0.62f, 0.18f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.00f);
    glVertex2f( 1.0f, 0.00f);
    glVertex2f( 1.0f, 0.15f);
    glVertex2f(-1.0f, 0.15f);
    glEnd();

    radius = 0.050f;
    for (GLfloat sx = -0.95f; sx <= 0.95f; sx += 0.10f)
    {
        glColor3f(0.55f, 0.55f, 0.52f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(sx, 0.05f);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f(sx + radius * cos(i * twicePi / triangleAmount), 0.05f + (radius * 0.6f) * sin(i * twicePi / triangleAmount));
        glEnd();
    }

    glBegin(GL_QUADS);
    if (isDay == 1)
    {
        glColor3f(0.10f, 0.45f, 0.80f);
        glVertex2f(-1.0f,  0.00f);
        glVertex2f( 1.0f,  0.00f);
        glColor3f(0.04f, 0.28f, 0.58f);
        glVertex2f( 1.0f, -0.60f);
        glVertex2f(-1.0f, -0.60f);
    }
    else
    {
        glColor3f(0.05f, 0.20f, 0.40f);
        glVertex2f(-1.0f,  0.00f);
        glVertex2f( 1.0f,  0.00f);
        glColor3f(0.02f, 0.10f, 0.25f);
        glVertex2f( 1.0f, -0.60f);
        glVertex2f(-1.0f, -0.60f);
    }
    glEnd();

    glColor3f(0.40f, 0.70f, 0.95f);
    glLineWidth(1.8f);
    for (float wy = -0.10f; wy >= -0.50f; wy -= 0.10f)
    {
        glBegin(GL_LINE_STRIP);
        for (float wx = -1.0f; wx <= 1.0f; wx += 0.05f)
        {
            float waveY = wy + 0.01f * sin(wx * 12.0f + waveOffset);
            glVertex2f(wx, waveY);
        }
        glEnd();
    }

    if (isDay == 1)
    {
        glPushMatrix();
        glTranslatef(position1 + 0.35f, -0.10f, 0.0f);

        glColor3f(0.48f, 0.24f, 0.08f);
        glBegin(GL_QUADS);
        glVertex2f(-0.13f, 0.00f);
        glVertex2f( 0.13f, 0.00f);
        glVertex2f( 0.18f, 0.06f);
        glVertex2f(-0.18f, 0.06f);
        glEnd();

        glColor3f(0.85f, 0.20f, 0.15f);
        glBegin(GL_QUADS);
        glVertex2f(-0.07f, 0.03f);
        glVertex2f(-0.03f, 0.03f);
        glVertex2f(-0.035f, 0.09f);
        glVertex2f(-0.065f, 0.09f);
        glEnd();

        glColor3f(0.92f, 0.72f, 0.58f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.05f, 0.11f);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f(-0.05f + 0.02f * cos(i * twicePi / triangleAmount), 0.11f + 0.02f * sin(i * twicePi / triangleAmount));
        glEnd();

        glColor3f(0.15f, 0.10f, 0.05f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.05f, 0.12f);
        for (i = 0; i <= 20; i++)
            glVertex2f(-0.05f + 0.021f * cos(i * PI / 20), 0.12f + 0.015f * sin(i * PI / 20));
        glEnd();

        glColor3f(0.60f, 0.35f, 0.12f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.05f, 0.07f);
        glVertex2f( 0.04f, -0.04f);
        glEnd();

        glColor3f(0.18f, 0.45f, 0.85f);
        glBegin(GL_QUADS);
        glVertex2f( 0.03f, 0.03f);
        glVertex2f( 0.07f, 0.03f);
        glVertex2f( 0.065f, 0.09f);
        glVertex2f( 0.035f, 0.09f);
        glEnd();

        glColor3f(0.92f, 0.72f, 0.58f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.05f, 0.11f);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f(0.05f + 0.02f * cos(i * twicePi / triangleAmount), 0.11f + 0.02f * sin(i * twicePi / triangleAmount));
        glEnd();

        glColor3f(0.15f, 0.10f, 0.05f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.05f, 0.12f);
        for (i = 0; i <= 20; i++)
            glVertex2f(0.05f + 0.021f * cos(i * PI / 20), 0.12f + 0.015f * sin(i * PI / 20));
        glEnd();

        glColor3f(0.60f, 0.35f, 0.12f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(0.05f, 0.07f);
        glVertex2f(0.14f, -0.04f);
        glEnd();

        glPopMatrix();

        glPushMatrix();
        glTranslatef(position2 - 0.45f, -0.28f, 0.0f);

        glColor3f(0.42f, 0.20f, 0.06f);
        glBegin(GL_QUADS);
        glVertex2f(-0.17f, 0.00f);
        glVertex2f( 0.17f, 0.00f);
        glVertex2f( 0.23f, 0.06f);
        glVertex2f(-0.23f, 0.06f);
        glEnd();

        glColor3f(0.95f, 0.55f, 0.15f);
        glBegin(GL_QUADS);
        glVertex2f(-0.12f, 0.03f);
        glVertex2f(-0.08f, 0.03f);
        glVertex2f(-0.085f, 0.09f);
        glVertex2f(-0.115f, 0.09f);
        glEnd();

        glColor3f(0.92f, 0.72f, 0.58f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.10f, 0.11f);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f(-0.10f + 0.02f * cos(i * twicePi / triangleAmount), 0.11f + 0.02f * sin(i * twicePi / triangleAmount));
        glEnd();

        glColor3f(0.12f, 0.08f, 0.04f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.10f, 0.12f);
        for (i = 0; i <= 20; i++)
            glVertex2f(-0.10f + 0.021f * cos(i * PI / 20), 0.12f + 0.015f * sin(i * PI / 20));
        glEnd();

        glColor3f(0.60f, 0.35f, 0.12f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.10f, 0.07f);
        glVertex2f(-0.01f, -0.04f);
        glEnd();

        glColor3f(0.20f, 0.70f, 0.30f);
        glBegin(GL_QUADS);
        glVertex2f(-0.02f, 0.03f);
        glVertex2f( 0.02f, 0.03f);
        glVertex2f( 0.015f, 0.09f);
        glVertex2f(-0.015f, 0.09f);
        glEnd();

        glColor3f(0.92f, 0.72f, 0.58f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.00f, 0.11f);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f(0.00f + 0.02f * cos(i * twicePi / triangleAmount), 0.11f + 0.02f * sin(i * twicePi / triangleAmount));
        glEnd();

        glColor3f(0.12f, 0.08f, 0.04f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.00f, 0.12f);
        for (i = 0; i <= 20; i++)
            glVertex2f(0.00f + 0.021f * cos(i * PI / 20), 0.12f + 0.015f * sin(i * PI / 20));
        glEnd();

        glColor3f(0.60f, 0.35f, 0.12f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(0.00f, 0.07f);
        glVertex2f(0.09f, -0.04f);
        glEnd();

        glColor3f(0.85f, 0.85f, 0.20f);
        glBegin(GL_QUADS);
        glVertex2f( 0.08f, 0.03f);
        glVertex2f( 0.12f, 0.03f);
        glVertex2f( 0.115f, 0.09f);
        glVertex2f( 0.085f, 0.09f);
        glEnd();

        glColor3f(0.92f, 0.72f, 0.58f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.10f, 0.11f);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f(0.10f + 0.02f * cos(i * twicePi / triangleAmount), 0.11f + 0.02f * sin(i * twicePi / triangleAmount));
        glEnd();

        glColor3f(0.12f, 0.08f, 0.04f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.10f, 0.12f);
        for (i = 0; i <= 20; i++)
            glVertex2f(0.10f + 0.021f * cos(i * PI / 20), 0.12f + 0.015f * sin(i * PI / 20));
        glEnd();

        glColor3f(0.60f, 0.35f, 0.12f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(0.10f, 0.07f);
        glVertex2f(0.19f, -0.04f);
        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslatef(position1 - 0.05f, -0.46f, 0.0f);

        glColor3f(0.38f, 0.18f, 0.05f);
        glBegin(GL_QUADS);
        glVertex2f(-0.17f, 0.00f);
        glVertex2f( 0.17f, 0.00f);
        glVertex2f( 0.23f, 0.06f);
        glVertex2f(-0.23f, 0.06f);
        glEnd();

        glColor3f(0.18f, 0.65f, 0.85f);
        glBegin(GL_QUADS);
        glVertex2f(-0.12f, 0.03f);
        glVertex2f(-0.08f, 0.03f);
        glVertex2f(-0.085f, 0.09f);
        glVertex2f(-0.115f, 0.09f);
        glEnd();

        glColor3f(0.92f, 0.72f, 0.58f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.10f, 0.11f);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f(-0.10f + 0.02f * cos(i * twicePi / triangleAmount), 0.11f + 0.02f * sin(i * twicePi / triangleAmount));
        glEnd();

        glColor3f(0.12f, 0.08f, 0.04f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.10f, 0.12f);
        for (i = 0; i <= 20; i++)
            glVertex2f(-0.10f + 0.021f * cos(i * PI / 20), 0.12f + 0.015f * sin(i * PI / 20));
        glEnd();

        glColor3f(0.60f, 0.35f, 0.12f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.10f, 0.07f);
        glVertex2f(-0.01f, -0.04f);
        glEnd();

        glColor3f(0.85f, 0.20f, 0.25f);
        glBegin(GL_QUADS);
        glVertex2f(-0.02f, 0.03f);
        glVertex2f( 0.02f, 0.03f);
        glVertex2f( 0.015f, 0.09f);
        glVertex2f(-0.015f, 0.09f);
        glEnd();

        glColor3f(0.92f, 0.72f, 0.58f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.00f, 0.11f);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f(0.00f + 0.02f * cos(i * twicePi / triangleAmount), 0.11f + 0.02f * sin(i * twicePi / triangleAmount));
        glEnd();

        glColor3f(0.12f, 0.08f, 0.04f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.00f, 0.12f);
        for (i = 0; i <= 20; i++)
            glVertex2f(0.00f + 0.021f * cos(i * PI / 20), 0.12f + 0.015f * sin(i * PI / 20));
        glEnd();

        glColor3f(0.60f, 0.35f, 0.12f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(0.00f, 0.07f);
        glVertex2f(0.09f, -0.04f);
        glEnd();

        glColor3f(0.60f, 0.25f, 0.70f);
        glBegin(GL_QUADS);
        glVertex2f( 0.08f, 0.03f);
        glVertex2f( 0.12f, 0.03f);
        glVertex2f( 0.115f, 0.09f);
        glVertex2f( 0.085f, 0.09f);
        glEnd();

        glColor3f(0.92f, 0.72f, 0.58f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.10f, 0.11f);
        for (i = 0; i <= triangleAmount; i++)
            glVertex2f(0.10f + 0.02f * cos(i * twicePi / triangleAmount), 0.11f + 0.02f * sin(i * twicePi / triangleAmount));
        glEnd();

        glColor3f(0.12f, 0.08f, 0.04f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.10f, 0.12f);
        for (i = 0; i <= 20; i++)
            glVertex2f(0.10f + 0.021f * cos(i * PI / 20), 0.12f + 0.015f * sin(i * PI / 20));
        glEnd();

        glColor3f(0.60f, 0.35f, 0.12f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(0.10f, 0.07f);
        glVertex2f(0.19f, -0.04f);
        glEnd();

        glPopMatrix();
    }

    glColor3f(0.24f, 0.68f, 0.20f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.60f);
    glVertex2f( 1.0f, -0.60f);
    glVertex2f( 1.0f, -1.00f);
    glVertex2f(-1.0f, -1.00f);
    glEnd();


    if (isDay == 1)
    {
        float pX[] = { -0.88f, -0.66f, -0.44f, -0.22f, 0.00f, 0.22f, 0.44f, 0.66f, 0.88f };
        GLfloat shirtColors[9][3] = {
            {0.85f, 0.22f, 0.20f}, {0.18f, 0.50f, 0.88f}, {0.95f, 0.75f, 0.10f},
            {0.15f, 0.70f, 0.35f}, {0.88f, 0.40f, 0.15f}, {0.65f, 0.25f, 0.75f},
            {0.20f, 0.75f, 0.85f}, {0.85f, 0.35f, 0.65f}, {0.90f, 0.50f, 0.20f}
        };

        for (int p = 0; p < 9; p++)
        {
            float px = pX[p];
            float armMove = 0.015f * sin(armOffset + p);

            glColor3f(0.15f, 0.20f, 0.35f);
            glBegin(GL_QUADS);
            glVertex2f(px - 0.03f, -0.96f);
            glVertex2f(px - 0.005f, -0.96f);
            glVertex2f(px - 0.005f, -0.84f);
            glVertex2f(px - 0.03f, -0.84f);
            glVertex2f(px + 0.005f, -0.96f);
            glVertex2f(px + 0.03f, -0.96f);
            glVertex2f(px + 0.03f, -0.84f);
            glVertex2f(px + 0.005f, -0.84f);
            glEnd();

            glColor3f(0.10f, 0.10f, 0.10f);
            glBegin(GL_QUADS);
            glVertex2f(px - 0.035f, -0.98f);
            glVertex2f(px, -0.98f);
            glVertex2f(px, -0.96f);
            glVertex2f(px - 0.035f, -0.96f);
            glVertex2f(px, -0.98f);
            glVertex2f(px + 0.035f, -0.98f);
            glVertex2f(px + 0.035f, -0.96f);
            glVertex2f(px, -0.96f);
            glEnd();

            glColor3fv(shirtColors[p]);
            glBegin(GL_QUADS);
            glVertex2f(px - 0.035f, -0.84f);
            glVertex2f(px + 0.035f, -0.84f);
            glVertex2f(px + 0.03f, -0.72f);
            glVertex2f(px - 0.03f, -0.72f);
            glEnd();

            glLineWidth(4.0f);
            glBegin(GL_LINES);
            glVertex2f(px - 0.025f, -0.74f);
            glVertex2f(px - 0.065f, -0.64f + armMove);
            glVertex2f(px + 0.025f, -0.74f);
            glVertex2f(px + 0.065f, -0.64f - armMove);
            glEnd();

            glColor3f(0.92f, 0.72f, 0.58f);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(px - 0.065f, -0.64f + armMove);
            for (i = 0; i <= 15; i++)
                glVertex2f(px - 0.065f + 0.012f * cos(i * twicePi / 15), (-0.64f + armMove) + 0.012f * sin(i * twicePi / 15));
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(px + 0.065f, -0.64f - armMove);
            for (i = 0; i <= 15; i++)
                glVertex2f(px + 0.065f + 0.012f * cos(i * twicePi / 15), (-0.64f - armMove) + 0.012f * sin(i * twicePi / 15));
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(px, -0.67f);
            for (i = 0; i <= triangleAmount; i++)
                glVertex2f(px + 0.030f * cos(i * twicePi / triangleAmount), -0.67f + 0.034f * sin(i * twicePi / triangleAmount));
            glEnd();

            glColor3f(0.12f, 0.08f, 0.04f);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(px, -0.655f);
            for (i = 0; i <= 20; i++)
                glVertex2f(px + 0.032f * cos(i * PI / 20), -0.655f + 0.026f * sin(i * PI / 20));
            glEnd();
        }
    }
    else
    {
        glColor3f(0.90f, 0.40f, 0.10f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.95f, -0.95f);
        glVertex2f(-0.55f, -0.95f);
        glVertex2f(-0.75f, -0.65f);
        glEnd();

        glColor3f(0.70f, 0.25f, 0.05f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.85f, -0.95f);
        glVertex2f(-0.55f, -0.95f);
        glVertex2f(-0.75f, -0.65f);
        glEnd();

        glColor3f(0.15f, 0.08f, 0.05f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.80f, -0.95f);
        glVertex2f(-0.70f, -0.95f);
        glVertex2f(-0.75f, -0.75f);
        glEnd();

        glColor3f(0.40f, 0.20f, 0.10f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.45f, -0.95f);
        glVertex2f(-0.35f, -0.88f);
        glVertex2f(-0.35f, -0.95f);
        glVertex2f(-0.45f, -0.88f);
        glEnd();

        glColor3f(0.95f, 0.20f, 0.10f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.46f, -0.93f);
        glVertex2f(-0.34f, -0.93f);
        glVertex2f(-0.40f, -0.70f);
        glEnd();

        glColor3f(1.0f, 0.55f, 0.10f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.44f, -0.93f);
        glVertex2f(-0.36f, -0.93f);
        glVertex2f(-0.40f, -0.75f);
        glEnd();

        glColor3f(1.0f, 0.95f, 0.20f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.42f, -0.93f);
        glVertex2f(-0.38f, -0.93f);
        glVertex2f(-0.40f, -0.80f);
        glEnd();

        glColor3f(0.15f, 0.60f, 0.75f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.20f, -0.95f);
        glVertex2f( 0.20f, -0.95f);
        glVertex2f( 0.00f, -0.65f);
        glEnd();

        glColor3f(0.08f, 0.40f, 0.55f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.10f, -0.95f);
        glVertex2f( 0.20f, -0.95f);
        glVertex2f( 0.00f, -0.65f);
        glEnd();

        glColor3f(0.05f, 0.10f, 0.15f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.05f, -0.95f);
        glVertex2f( 0.05f, -0.95f);
        glVertex2f( 0.00f, -0.75f);
        glEnd();

        glColor3f(0.40f, 0.20f, 0.10f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(0.35f, -0.95f);
        glVertex2f(0.45f, -0.88f);
        glVertex2f(0.45f, -0.95f);
        glVertex2f(0.35f, -0.88f);
        glEnd();

        glColor3f(0.95f, 0.20f, 0.10f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.34f, -0.93f);
        glVertex2f(0.46f, -0.93f);
        glVertex2f(0.40f, -0.70f);
        glEnd();

        glColor3f(1.0f, 0.55f, 0.10f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.36f, -0.93f);
        glVertex2f(0.44f, -0.93f);
        glVertex2f(0.40f, -0.75f);
        glEnd();

        glColor3f(1.0f, 0.95f, 0.20f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.38f, -0.93f);
        glVertex2f(0.42f, -0.93f);
        glVertex2f(0.40f, -0.80f);
        glEnd();

        glColor3f(0.25f, 0.70f, 0.30f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.55f, -0.95f);
        glVertex2f(0.95f, -0.95f);
        glVertex2f(0.75f, -0.65f);
        glEnd();

        glColor3f(0.15f, 0.45f, 0.20f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.65f, -0.95f);
        glVertex2f(0.95f, -0.95f);
        glVertex2f(0.75f, -0.65f);
        glEnd();

        glColor3f(0.05f, 0.15f, 0.08f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.70f, -0.95f);
        glVertex2f(0.80f, -0.95f);
        glVertex2f(0.75f, -0.75f);
        glEnd();
    }


    glLineWidth(1.0f);
    glDisable(GL_LIGHTING);
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(50, 50);

    glutCreateWindow("Traditional Boat Race and the Titas River");

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);

    init();

    glutTimerFunc(100, update, 0);

    glutMainLoop();

    return 0;
}
