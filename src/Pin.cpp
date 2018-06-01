#include "Pin.h"

Pin::Pin()
{
    headRadius = 0.05f;
    baseRadius = 0.1f;
    height = 0.5f;
    slices = 50;
    stacks = 50;
    neckHeight = 1.5f;
}

Pin::~Pin()
{
    //dtor
}

void Pin::setValues(GLfloat x, GLfloat y, GLfloat z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Pin::drawPin() {
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(x,y,z);
        glutSolidSphere(headRadius,slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x,-1.0f,z);
        glRotated(180,0,1,1);
        glutSolidCone(baseRadius,height,slices,stacks);
    glPopMatrix();
}

GLfloat Pin::getY() {
    return y;
}

GLfloat Pin::getZ() {
    return z
}

void Pin::setY {
    this->y = y;
}

void Pin::setZ {
    this->z = z;
}
