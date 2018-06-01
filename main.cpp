#include <windows.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

char title[] = "3D Shapes";
int slices = 50;
int stacks = 50;
GLfloat x_pos = 0;
GLfloat z_pos = 0;
GLfloat speed = 0.001f;
bool rolling = false;
double a = 0;
GLfloat max_z = -5.0f;
GLfloat test = 0.0f;

void renderH1(std::string str, GLfloat px, GLfloat py, int r, int g, int b){
    int l = str.size(), i;

    glPushMatrix();
        glRasterPos3f(px, py, 0);
        for(i = 0; i < l; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
        }
    glPopMatrix();
}

void renderP(std::string str, GLfloat px, GLfloat py, int r, int g, int b){
    int l = str.size(), i;
    float x = 0.0f;
    glPushMatrix();
        glRasterPos3f(px, py, 0);
        for(i = 0; i < l; i++){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
            x += 0.048f;
        }
}

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    gluLookAt(0.0, 0.0, 1.0f,
              0.0, -0.1f, 0.0,
              0.0, 1.0f, 0.0);
}

void display() {
    if (rolling && z_pos > max_z){
        const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
        double a = t*90.0;
        z_pos -= speed;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glColor3d(1,0,0);

    renderH1("BOWLING SIMULATION", -0.45f, 0.254f, 253, 184, 19);
    renderP("Controls: ", -0.45f, 0.22f, 253, 184, 19);
    renderP("LEFT and RIGHT arrow keys", -0.4f, 0.19f, 253, 184, 19);
    renderP("SPACE BAR to release ball", -0.4f, 0.16f, 253, 184, 19);
    renderP("'s' to start again", -0.4f, 0.13f, 253, 184, 19);


    // ball
    glPushMatrix();
        glTranslated(x_pos,-0.5f,z_pos);
        glRotated(-90,0,1,0);
        glRotated(a,0,0,1);
        glutSolidSphere(0.1f,slices,stacks);
    glPopMatrix();


    // cone
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0,-0.5f,-9.0f);
        glutSolidSphere(0.05f,slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-1.0f,-9.0f);
        glRotated(180,0,1,1);
        glutSolidCone(0.1f,0.5f,slices,stacks);
    glPopMatrix();

    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex3f( 1.0f, 0.0f, -10.0f);
        glVertex3f(-1.0f, 0.0f, -10.0f);
        glVertex3f(-1.0f,  -1.0f, -10.0f);
        glVertex3f( 1.0f,  -1.0f, -10.0f);

        // floor
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f,  -1.0f, -10.0f);
        glVertex3f( 1.0f,  -1.0f, -10.0f);
        glVertex3f( 1.0f,  -1.0f, 0.0f);
        glVertex3f(-1.0f,  -1.0f, 0.0f);

        glColor3f(0,0,0);
        glVertex3f(-1.0f,  -1.0f, -10.0f);
        glVertex3f(-0.8f,  -1.0f, -10.0f);
        glVertex3f(-0.8f,  -1.0f, 0.0f);
        glVertex3f(-1.0f,  -1.0f, 0.0f);

        glColor3f(0,0,0);
        glVertex3f(0.8f,  -1.0f, -10.0f);
        glVertex3f(1.0f,  -1.0f, -10.0f);
        glVertex3f(1.0f,  -1.0f, 0.0f);
        glVertex3f(0.8f,  -1.0f, 0.0f);

    glEnd();
    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void idle(void){
    glutPostRedisplay();
}

void resetDefaults(){
    z_pos = 0;
    x_pos = 0;
    speed = 0.001f;
    rolling = false;
}

static void key(unsigned char key, int x, int y){
    if (key == 32) {
        rolling = true;
    }
    if (key == 's') {
        resetDefaults();
    }

    glutPostRedisplay();
}

void specialKey(int key, int x, int y){
    glutSetKeyRepeat(1);

    switch(key) {
    case GLUT_KEY_RIGHT:
        x_pos += 0.001;
        break;
    case GLUT_KEY_LEFT:
        x_pos -= 0.001;
        break;
    case GLUT_KEY_UP:
        test += 0.001;
        break;
    case GLUT_KEY_DOWN:
        test -= 0.001;
        break;
    }

    cout << test << endl;
}


const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(key);
    glutSpecialFunc(specialKey);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    initGL();
    glutMainLoop();
    return 0;
}
