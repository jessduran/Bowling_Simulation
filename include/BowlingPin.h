#ifndef BOWLINGPIN_H
#define BOWLINGPIN_H

#include <windows.h>
#include <GL/glut.h>


class BowlingPin
{
    public:
        BowlingPin();
        ~BowlingPin();
        void drawBowlingPin(GLfloat, GLfloat, GLfloat);
        GLfloat getX();
        GLfloat getY();
        GLfloat getZ();
        GLfloat getWidth();
        void setY(GLfloat);
        void setZ(GLfloat);

    protected:
        int slices = 50;
        int stacks = 50;
        GLfloat height = 0.5f;
        GLfloat base = 0.1f;
        GLfloat radius = 0.05f;
        GLfloat width = radius*2;
        GLfloat x, y, z;
    private:
};

#endif // BOWLINGPIN_H
