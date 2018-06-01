#ifndef PIN_H
#define PIN_H

#include <windows.h>
#include <GL/glut.h>
#include <Math.h>

class Pin
{
    public:
        Pin();
        ~Pin();
        void drawPin();
        void setValues(GLfloat, GLfloat, GLfloat);
        GLfloat getX();
        GLfloat getY();
        GLfloat getZ();
        GLfloat setY(GLfloat);
        GLfloat setZ(GLfloat);

    protected:
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat headRadius;
        GLfloat baseRadius;
        GLfloat height;
        GLfloat neckHeight;
        int slices;
        int stacks;

    private:
};

#endif // PIN_H
