#include "BowlingPin.h"

BowlingPin::BowlingPin()
{
    //ctor
}

BowlingPin::~BowlingPin()
{
    //dtor
}

void BowlingPin::drawBowlingPin(GLfloat x, GLfloat y, GLfloat z){
    this->x = x;
    this->y = y;
    this->z = z;

    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(x,y,z);
        glutSolidSphere(radius,slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x,y-0.5,z);
        glRotated(180,0,1,1);
        glutSolidCone(base,height,slices,stacks);
    glPopMatrix();
}

GLfloat BowlingPin::getX(){
    return x;
}

GLfloat BowlingPin::getY(){
    return y;
}

GLfloat BowlingPin::getZ(){
    return z;
}

GLfloat BowlingPin::getWidth(){
    return width;
}

void BowlingPin::setY(GLfloat y){
    this->y = y;
}

void BowlingPin::setZ(GLfloat z){
    this->z = z;
}
