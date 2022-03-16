#include "glut.h"

void draw() {
    drawKinectData();
    glutSwapBuffers();
}

void execute() {
    glutMainLoop();
}

bool init(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(k_width, k_height);
    glutCreateWindow("Kinect SDK Tutorial");
    glutDisplayFunc(draw);
    glutIdleFunc(draw);
    glewInit();
    return true;
}
//new thread

