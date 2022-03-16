#pragma once
#include <Windows.h>
#include <gl/glew.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
const int k_width = 1920;
const int k_height = 1080;
const int colorwidth = 1920;
const int colorheight = 1080;

void drawKinectData();
bool init(int argc, char* argv[]);
void draw();
void execute();