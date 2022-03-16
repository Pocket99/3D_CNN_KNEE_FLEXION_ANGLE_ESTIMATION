////
////#include <windows.h>
////
////#include <Shlobj.h>
////
////// Direct2D Header Files
////#include <d2d1.h>
////// Kinect Header files
////#include<Kinect.h>
////#include <gl/glut.h>
////#define width 1920
////#define height 1080
////#pragma comment (lib, "d2d1.lib")
////// OpenGL Variables
////GLuint textureId;              // ID of the texture to contain Kinect RGB Data
////GLubyte data[width * height * 4];  // BGRA array containing the texture data
////IKinectSensor* sensor;         // Kinect sensor
////IColorFrameReader* reader;     // Kinect color data source
////
////bool initKinect() {
////    if (FAILED(GetDefaultKinectSensor(&sensor))) {
////        return false;
////    }
////    if (sensor) {
////        sensor->Open();
////
////        IColorFrameSource* framesource = NULL;
////        sensor->get_ColorFrameSource(&framesource);
////        framesource->OpenReader(&reader);
////        if (framesource) {
////            framesource->Release();
////            framesource = NULL;
////        }
////        return true;
////    }
////    else {
////        return false;
////    }
////}
////
////void getKinectData(GLubyte* dest) {
////    IColorFrame* frame = NULL;
////    if (SUCCEEDED(reader->AcquireLatestFrame(&frame))) {
////        frame->CopyConvertedFrameDataToArray(width * height * 4, data, ColorImageFormat_Bgra);
////    }
////    if (frame) frame->Release();
////}
////int main(void)
////{
////    if (!initKinect()) return 1;
////    GLFWwindow* window;
////
////    /* Initialize the library */
////    if (!glfwInit())
////        return -1;
////
////    /* Create a windowed mode window and its OpenGL context */
////    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
////    if (!window)
////    {
////        glfwTerminate();
////        return -1;
////    }
////
////    /* Make the window's context current */
////    glfwMakeContextCurrent(window);
////    // Initialize textures
////    glGenTextures(1, &textureId);
////    glBindTexture(GL_TEXTURE_2D, textureId);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
////    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, (GLvoid*)data);
////    glBindTexture(GL_TEXTURE_2D, 0);
////
////    // OpenGL setup
////    glClearColor(0, 0, 0, 0);
////    glClearDepth(1.0f);
////    glEnable(GL_TEXTURE_2D);
////
////    // Camera setup
////    glViewport(0, 0, width, height);
////    glMatrixMode(GL_PROJECTION);
////    glLoadIdentity();
////    glOrtho(0, width, height, 0, 1, -1);
////    glMatrixMode(GL_MODELVIEW);
////    glLoadIdentity();
////    /* Loop until the user closes the window */
////    while (!glfwWindowShouldClose(window))
////    {
////        /* Render here */
////        glClear(GL_COLOR_BUFFER_BIT);
////
////        /* Swap front and back buffers */
////        glfwSwapBuffers(window);
////
////        /* Poll for and process events */
////        glfwPollEvents();
////    }
////
////    glfwTerminate();
////    return 0;
////}
//
//
//
//
//
//
//#include"glut.h"
//
//#include <cmath>
//#include <cstdio>
//#include <iostream>
//#include <Windows.h>
//#include <Ole2.h>
//#include <Kinect.h>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//// We'll be using buffer objects to store the kinect point cloud
//GLuint vboId;
//GLuint cboId;
//GLubyte data[width * height * 4];  // BGRA array containing the texture data
//// Intermediate Buffers
//unsigned char rgbimage[colorwidth * colorheight * 4];    // Stores RGB color image
//ColorSpacePoint depth2rgb[width * height];             // Maps depth pixels to rgb pixels
//CameraSpacePoint depth2xyz[width * height];			 // Maps depth pixels to 3d coordinates
//
//// Kinect Variables
//IKinectSensor* sensor;             // Kinect sensor
//IMultiSourceFrameReader* reader;   // Kinect data source
//ICoordinateMapper* mapper;         // Converts between depth, color, and 3d coordinates
//
//// Body tracking variables
//BOOLEAN tracked;                            // Whether we see a body
//Joint joints[JointType_Count];              // List of joints in the tracked body
//
//bool initKinect() {
//	if (FAILED(GetDefaultKinectSensor(&sensor))) {
//		return false;
//	}
//	if (sensor) {
//		sensor->get_CoordinateMapper(&mapper);
//
//		sensor->Open();
//		/*sensor->OpenMultiSourceFrameReader(
//			FrameSourceTypes::FrameSourceTypes_Depth | FrameSourceTypes::FrameSourceTypes_Color| FrameSourceTypes::FrameSourceTypes_Body,
//			&reader);*/
//		sensor->OpenMultiSourceFrameReader(
//			FrameSourceTypes::FrameSourceTypes_Depth | FrameSourceTypes::FrameSourceTypes_Color | FrameSourceTypes::FrameSourceTypes_Body,
//			&reader);
//		return reader;
//	}
//	else {
//		return false;
//	}
//}
//
//void getDepthData(IMultiSourceFrame* frame, GLubyte* dest) {
//	IDepthFrame* depthframe;
//	IDepthFrameReference* frameref = NULL;
//	frame->get_DepthFrameReference(&frameref);
//	frameref->AcquireFrame(&depthframe);
//	if (frameref) frameref->Release();
//
//	if (!depthframe) return;
//
//	// Get data from frame
//	unsigned int sz;
//	unsigned short* buf;
//	depthframe->AccessUnderlyingBuffer(&sz, &buf);
//
//	// Write vertex coordinates
//	mapper->MapDepthFrameToCameraSpace(width * height, buf, width * height, depth2xyz);
//	float* fdest = (float*)dest;
//	for (int i = 0; i < sz; i++) {
//		*fdest++ = depth2xyz[i].X;
//		*fdest++ = depth2xyz[i].Y;
//		*fdest++ = depth2xyz[i].Z;
//	}
//
//	// Fill in depth2rgb map
//	mapper->MapDepthFrameToColorSpace(width * height, buf, width * height, depth2rgb);
//	if (depthframe) depthframe->Release();
//}
//
//void getRgbData(IMultiSourceFrame* frame, GLubyte* dest) {
//	IColorFrame* colorframe;
//	IColorFrameReference* frameref = NULL;
//	frame->get_ColorFrameReference(&frameref);
//	frameref->AcquireFrame(&colorframe);
//	if (frameref) frameref->Release();
//
//	if (!colorframe) return;
//
//	// Get data from frame
//	colorframe->CopyConvertedFrameDataToArray(colorwidth * colorheight * 4, rgbimage, ColorImageFormat_Rgba);
//
//	// Write color array for vertices
//	float* fdest = (float*)dest;
//	for (int i = 0; i < width * height; i++) {
//		ColorSpacePoint p = depth2rgb[i];
//		// Check if color pixel coordinates are in bounds
//		if (p.X < 0 || p.Y < 0 || p.X > colorwidth || p.Y > colorheight) {
//			*fdest++ = 0;
//			*fdest++ = 0;
//			*fdest++ = 0;
//		}
//		else {
//			int idx = (int)p.X + colorwidth * (int)p.Y;
//			*fdest++ = rgbimage[4 * idx + 0] / 255.;
//			*fdest++ = rgbimage[4 * idx + 1] / 255.;
//			*fdest++ = rgbimage[4 * idx + 2] / 255.;
//		}
//		// Don't copy alpha channel
//	}
//
//	if (colorframe) colorframe->Release();
//}
//
//void getBodyData(IMultiSourceFrame* frame) {
//	IBodyFrame* bodyframe;
//	IBodyFrameReference* frameref = NULL;
//	frame->get_BodyFrameReference(&frameref);
//	frameref->AcquireFrame(&bodyframe);
//	if (frameref) frameref->Release();
//
//	if (!bodyframe) return;
//
//	IBody* body[BODY_COUNT] = { 0 };;
//	bodyframe->GetAndRefreshBodyData(BODY_COUNT, body);
//	for (int i = 0; i < BODY_COUNT; i++) {
//		body[i]->get_IsTracked(&tracked);
//		if (tracked) {
//			body[i]->GetJoints(JointType_Count, joints);
//			break;
//		}
//	}
//
//	if (bodyframe) bodyframe->Release();
//}
//
//void getKinectData() {
//	IMultiSourceFrame* frame = NULL;
//	if (SUCCEEDED(reader->AcquireLatestFrame(&frame))) {
//		/*GLubyte* ptr;
//		glBindBuffer(GL_ARRAY_BUFFER, vboId);
//		ptr = (GLubyte*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
//		if (ptr) {
//			getDepthData(frame, ptr);
//		}
//		glUnmapBuffer(GL_ARRAY_BUFFER);
//		glBindBuffer(GL_ARRAY_BUFFER, cboId);
//		ptr = (GLubyte*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
//		if (ptr) {
//			getRgbData(frame, ptr);
//		}*/
//		glUnmapBuffer(GL_ARRAY_BUFFER);
//		getBodyData(frame);
//	}
//	if (frame) frame->Release();
//
//}
//
//
//void rotateCamera() {
//	static double angle = 0.;
//	static double radius = 3.;
//	double x = radius * sin(angle);
//	double z = radius * (1 - cos(angle)) - radius / 2;
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(x, 0, z, 0, 0, radius / 2, 0, 1, 0);
//	angle += 0.002;
//}
//
//void drawKinectData() {
//	getKinectData();
//	//rotateCamera();
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_COLOR_ARRAY);
//
//	glBindBuffer(GL_ARRAY_BUFFER, vboId);
//	glVertexPointer(3, GL_FLOAT, 0, NULL);
//
//	glBindBuffer(GL_ARRAY_BUFFER, cboId);
//	glColorPointer(3, GL_FLOAT, 0, NULL);
//
//	glPointSize(1.f);
//	glDrawArrays(GL_POINTS, 0, width * height);
//
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glDisableClientState(GL_COLOR_ARRAY);
//
//	if (tracked) {
//		// Draw some arms
//		const CameraSpacePoint& lh = joints[JointType_WristLeft].Position;
//		const CameraSpacePoint& le = joints[JointType_ElbowLeft].Position;
//		const CameraSpacePoint& ls = joints[JointType_ShoulderLeft].Position;
//		const CameraSpacePoint& rh = joints[JointType_WristRight].Position;
//		const CameraSpacePoint& re = joints[JointType_ElbowRight].Position;
//		const CameraSpacePoint& rs = joints[JointType_ShoulderRight].Position;
//		const CameraSpacePoint& left_hip = joints[JointType_HipLeft].Position;
//		const CameraSpacePoint& left_knee = joints[JointType_KneeLeft].Position;
//		const CameraSpacePoint& left_ankle = joints[JointType_AnkleLeft].Position;
//		const CameraSpacePoint& right_hip = joints[JointType_HipRight].Position;
//		const CameraSpacePoint& right_knee = joints[JointType_KneeRight].Position;
//		const CameraSpacePoint& right_ankle = joints[JointType_AnkleRight].Position;
//		glBegin(GL_LINES);
//		glColor3f(1.0f, 0.f, 0.f);
//
//		glVertex3f(lh.X, lh.Y, lh.Z);
//		std::cout<<"WristLeft:" << lh.X <<" : "<< lh.Y <<" : "<< lh.Z << std::endl;
//		glVertex3f(le.X, le.Y, le.Z);
//		std::cout << "ElbowLeft:" << le.X << " : " << le.Y << " : " << le.Z << std::endl;
//		glVertex3f(le.X, le.Y, le.Z);
//		glVertex3f(ls.X, ls.Y, ls.Z);
//		std::cout << "ShoulderLeft:" << ls.X << " : " << ls.Y << " : " << ls.Z << std::endl;
//
//		glVertex3f(rh.X, rh.Y, rh.Z);
//		std::cout << "WristRight:" << rh.X << " : " << rh.Y << " : " << rh.Z << std::endl;
//		glVertex3f(re.X, re.Y, re.Z);
//		std::cout << "ElbowRight:" << re.X << " : " << re.Y << " : " << re.Z << std::endl;
//		glVertex3f(re.X, re.Y, re.Z);
//		glVertex3f(rs.X, rs.Y, rs.Z);
//		std::cout << "ShoulderRight:" << rs.X << " : " << rs.Y << " : " << rs.Z << std::endl;
//
//
//		glVertex3f(left_hip.X, left_hip.Y, left_hip.Z);
//		glVertex3f(left_knee.X, left_knee.Y, left_knee.Z);
//		glVertex3f(left_knee.X, left_knee.Y, left_knee.Z);
//		glVertex3f(left_ankle.X, left_ankle.Y, left_ankle.Z);
//
//		glVertex3f(right_hip.X, right_hip.Y, right_hip.Z);
//		glVertex3f(right_knee.X, right_knee.Y, right_knee.Z);
//		glVertex3f(right_knee.X, right_knee.Y, right_knee.Z);
//		glVertex3f(right_ankle.X, right_ankle.Y, right_ankle.Z);
//		glEnd();
//	}
//}
//
//int main(int argc, char* argv[]) {
//	/*std::cout << "OpenCV_Version: " << CV_VERSION <<std::endl;
//
//   Mat img = imread("C:/Users/zlf97/Pictures/Camera Roll/1.jpg");
//
//   imshow("picture", img);
//   waitKey(0);
//   return 0;*/
//
//	if (!init(argc, argv)) return 1;
//	if (!initKinect()) return 1;
//
//	// OpenGL setup
//	glClearColor(0, 0, 0, 0);
//	glClearDepth(1.0f);
//
//	// Set up array buffers
//	const int dataSize = width * height * 3 * 4;
//	glGenBuffers(1, &vboId);
//	glBindBuffer(GL_ARRAY_BUFFER, vboId);
//	glBufferData(GL_ARRAY_BUFFER, dataSize, 0, GL_DYNAMIC_DRAW);
//	glGenBuffers(1, &cboId);
//	glBindBuffer(GL_ARRAY_BUFFER, cboId);
//	glBufferData(GL_ARRAY_BUFFER, dataSize, 0, GL_DYNAMIC_DRAW);
//
//	// Camera setup
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, width / (GLdouble)height, 0.1, 1000);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(0, 0, 0, 0, 0, 1, 0, 1, 0);
//
//	// Main loop
//	execute();
//	return 0;
//}
//

//tutorial 1

#include <Windows.h>
#include <Ole2.h>
#include <iostream>
#include <Kinect.h>
#include "glut.h"
#include <fstream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <sstream>
#include <vector>
using namespace cv;
#define width 1920
#define height 1080
std::ofstream outfile;
std::ofstream rgbfile;
// OpenGL Variables
GLuint textureId;              // ID of the texture to contain Kinect RGB Data
GLubyte data[width * height * 4];  // BGRA array containing the texture data

// Kinect variables
IKinectSensor* sensor;         // Kinect sensor
IMultiSourceFrameReader* reader;       // Kinect color data source
IColorFrameReader* color_reader;     // Kinect color data source
ICoordinateMapper* mapper;         // Converts between depth, color, and 3d coordinates
unsigned char rgbimage[colorwidth * colorheight * 4];    // Stores RGB color image

BOOLEAN tracked;                            // Whether we see a body
Joint joints[JointType_Count];              // List of joints in the tracked body
Mat matFrame;
IColorFrameSource* mySource = nullptr;       //第2步获取Source
int     height1 = 0, width1 = 0;                  //取得宽和高等下用
IFrameDescription* myDescription1 = nullptr;
VideoWriter writer;
int counter = 0;
std::string img_name;
unsigned char rgb_vec [150][colorwidth * colorheight * 4] ;
CRITICAL_SECTION cs;
Mat* image;
DWORD WINAPI matThread(__in LPVOID lpParameter) {
	EnterCriticalSection(&cs);//加锁 接下来的代码处理过程中不允许其他线程进行操作，除非遇到LeaveCriticalSection
	//for (auto m : rgb_vec) {
	//	std::ostringstream oss;

	//	img_name = "./images/gray";
	//	oss << img_name << counter++ << ".jpg";

	//	//imwrite(oss.str(), *m);
	//}
	LeaveCriticalSection(&cs);//解锁 到EnterCriticalSection之间代码资源已经释放了，其他线程可以进行操作   
	return 0;
}

bool initKinect() {
	if (FAILED(GetDefaultKinectSensor(&sensor))) {
		return false;
	}
	if (sensor) {
		sensor->Open();
		sensor->OpenMultiSourceFrameReader(
			 FrameSourceTypes::FrameSourceTypes_Color | FrameSourceTypes::FrameSourceTypes_Body,
			&reader);
		
			//		(int)capture.get(CAP_PROP_FRAME_HEIGHT));
		sensor->get_ColorFrameSource(&mySource);
		mySource->get_FrameDescription(&myDescription1);
		myDescription1->get_Height(&height1);
		myDescription1->get_Width(&width1);
		Mat temp(colorheight, colorwidth, CV_8UC4);
		std::cout << "height1"<< colorheight << "width1"<< colorwidth << std::endl;
		matFrame = temp;
		Size S = Size(colorwidth, colorheight);
		writer.open("color.mp4", VideoWriter::fourcc('M', 'P', '4', 'V'), 24.0, S);
		return reader;
		/*sensor->Open();
		IColorFrameSource* framesource = NULL;
		sensor->get_ColorFrameSource(&framesource);
		framesource->OpenReader(&color_reader);
		if (framesource) {
			framesource->Release();
			framesource = NULL;
		}
		return true;*/
	}
	else {
		return false;
	}

}

void getBodyData(IMultiSourceFrame* frame) {
	IBodyFrame* bodyframe;
	IBodyFrameReference* frameref = NULL;
	frame->get_BodyFrameReference(&frameref);
	frameref->AcquireFrame(&bodyframe);
	if (frameref) frameref->Release();

	if (!bodyframe) return;

	IBody* body[BODY_COUNT] = { 0 };;
	bodyframe->GetAndRefreshBodyData(BODY_COUNT, body);
	for (int i = 0; i < BODY_COUNT; i++) {
		body[i]->get_IsTracked(&tracked);
		if (tracked) {
			body[i]->GetJoints(JointType_Count, joints);
			break;
		}
	}

	if (bodyframe) bodyframe->Release();
}

void getKinectData() {
	//std::cout <<" getKinectData"<< std::endl;
	IMultiSourceFrame* frame = NULL;//IColorFrame IMultiSourceFram
	if (SUCCEEDED(reader->AcquireLatestFrame(&frame))) {
		//frame->CopyConvertedFrameDataToArray(width * height * 4, data, ColorImageFormat_Bgra);
		
		IColorFrame* colorframe;
		IColorFrameReference* frameref = NULL;
		frame->get_ColorFrameReference(&frameref);
		frameref->AcquireFrame(&colorframe);
		if (frameref) frameref->Release();

		if (!colorframe) return;

		// Get data from frame
		colorframe->CopyConvertedFrameDataToArray(colorwidth * colorheight * 4, rgbimage, ColorImageFormat_Bgra);
		colorframe->CopyConvertedFrameDataToArray(colorwidth * colorheight * 4, (BYTE*)matFrame.data, ColorImageFormat_Bgra);
		
		
		//std::cout << "size of mat" <<sizeof(image)<< std::endl;
		namedWindow("TEST1", WINDOW_NORMAL);
		imshow("TEST1", matFrame);
		

		image = new Mat(colorheight, colorwidth, CV_8UC4, rgbimage);
		std::ostringstream oss;

		img_name = "./images/gray";
		oss << img_name << counter++ << ".bmp";
		imwrite(oss.str(), *image);
		getBodyData(frame);
		if (tracked) {
			// Draw some arms
			const CameraSpacePoint& lh = joints[JointType_WristLeft].Position;
			const CameraSpacePoint& le = joints[JointType_ElbowLeft].Position;
			const CameraSpacePoint& ls = joints[JointType_ShoulderLeft].Position;
			const CameraSpacePoint& rh = joints[JointType_WristRight].Position;
			const CameraSpacePoint& re = joints[JointType_ElbowRight].Position;
			const CameraSpacePoint& rs = joints[JointType_ShoulderRight].Position;
			const CameraSpacePoint& left_hip = joints[JointType_HipLeft].Position;
			const CameraSpacePoint& left_knee = joints[JointType_KneeLeft].Position;
			const CameraSpacePoint& left_ankle = joints[JointType_AnkleLeft].Position;
			const CameraSpacePoint& right_hip = joints[JointType_HipRight].Position;
			const CameraSpacePoint& right_knee = joints[JointType_KneeRight].Position;
			const CameraSpacePoint& right_ankle = joints[JointType_AnkleRight].Position;
			//glBegin(GL_LINES);
			//glColor3f(1.0f, 0.f, 0.f);

			//glVertex3f(lh.X, lh.Y, lh.Z);
			////std::cout<<"WristLeft:" << lh.X <<" : "<< lh.Y <<" : "<< lh.Z << std::endl;
			//glVertex3f(le.X, le.Y, le.Z);
			////std::cout << "ElbowLeft:" << le.X << " : " << le.Y << " : " << le.Z << std::endl;
			//glVertex3f(le.X, le.Y, le.Z);
			//glVertex3f(ls.X, ls.Y, ls.Z);
			////std::cout << "ShoulderLeft:" << ls.X << " : " << ls.Y << " : " << ls.Z << std::endl;

			//glVertex3f(rh.X, rh.Y, rh.Z);
			////std::cout << "WristRight:" << rh.X << " : " << rh.Y << " : " << rh.Z << std::endl;
			//glVertex3f(re.X, re.Y, re.Z);
			////std::cout << "ElbowRight:" << re.X << " : " << re.Y << " : " << re.Z << std::endl;
			//glVertex3f(re.X, re.Y, re.Z);
			//glVertex3f(rs.X, rs.Y, rs.Z);
			//std::cout << "ShoulderRight:" << rs.X << " : " << rs.Y << " : " << rs.Z << std::endl;




			//glVertex3f(right_hip.X, right_hip.Y, right_hip.Z);
			std::cout << "right_hip:" << right_hip.X << " : " << right_hip.Y << " : " << right_hip.Z << std::endl;
			outfile << right_hip.X << " " << right_hip.Y << " " << right_hip.Z << std::endl;
			//glVertex3f(right_knee.X, right_knee.Y, right_knee.Z);
			std::cout << "right_knee:" << right_knee.X << " : " << right_knee.Y << " : " << right_knee.Z << std::endl;
			outfile << right_knee.X << " " << right_knee.Y << " " << right_knee.Z << std::endl;
			//glVertex3f(right_knee.X, right_knee.Y, right_knee.Z);
			//glVertex3f(right_ankle.X, right_ankle.Y, right_ankle.Z);
			std::cout << "right_ankle:" << right_ankle.X << " : " << right_ankle.Y << " : " << right_ankle.Z << std::endl;
			outfile << right_ankle.X << " " << right_ankle.Y << " " << right_ankle.Z << std::endl;


			//glVertex3f(left_hip.X, left_hip.Y, left_hip.Z);
			std::cout << "left_hip:" << left_hip.X << " : " << left_hip.Y << " : " << left_hip.Z << std::endl;
			outfile << left_hip.X << " " << left_hip.Y << " " << left_hip.Z << std::endl;
			//glVertex3f(left_knee.X, left_knee.Y, left_knee.Z);
			std::cout << "left_knee:" << left_knee.X << " : " << left_knee.Y << " : " << left_knee.Z << std::endl;
			outfile << left_knee.X << " " << left_knee.Y << " " << left_knee.Z << std::endl;
			//glVertex3f(left_knee.X, left_knee.Y, left_knee.Z);
			//glVertex3f(left_ankle.X, left_ankle.Y, left_ankle.Z);
			std::cout << "left_ankle:" << left_ankle.X << " : " << left_ankle.Y << " : " << left_ankle.Z << std::endl;
			outfile << left_ankle.X << " " << left_ankle.Y << " " << left_ankle.Z << std::endl;
			//glEnd();
		}
		

		
	
		//writer.write(image);
		if (colorframe) colorframe->Release();
		
	}
	if (frame) frame->Release();
	
}

void drawKinectData() {
	glBindTexture(GL_TEXTURE_2D, textureId);
	getKinectData();
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, (GLvoid*)rgbimage);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0, 0, 0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(width, 0, 0);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(width, height, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0, height, 0.0f);
		glEnd();
	
}


int main(int argc, char* argv[]) {
	
	if (!init(argc, argv)) return 1;
	if (!initKinect()) return 1;
	outfile.open("kinect_angle.txt");
	// Initialize textures
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, (GLvoid*)rgbimage);
	glBindTexture(GL_TEXTURE_2D, 0);

	// OpenGL setup
	glClearColor(0, 0, 0, 0);
	glClearDepth(1.0f);
	glEnable(GL_TEXTURE_2D);

	// Camera setup
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Main loop
	execute();
	std::cout << "ending" << std::endl;
	
	/*HANDLE hThread;
	InitializeCriticalSection(&cs);
	hThread = CreateThread(NULL, 0, matThread, NULL, 0, NULL);*/
	outfile.close();
	writer.release();
	

	return 0;
}

//#include <Kinect.h>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
//#include <string>
//#include <iostream>
//using   namespace   cv;
//
//
//int main(void)
//{
//	//IKinectSensor* mySensor = nullptr;
//	//GetDefaultKinectSensor(&mySensor);  //获取感应器
//	//mySensor->Open();           //打开感应器
//
//	//double time0 = static_cast<double>(getTickCount());
//	//IDepthFrameSource* mySource = nullptr;   //取得深度数据
//	//mySensor->get_DepthFrameSource(&mySource);
//
//	//int height = 0, width = 0;
//	//IFrameDescription* myDescription = nullptr;  //取得深度数据的分辨率
//	//mySource->get_FrameDescription(&myDescription);
//	//myDescription->get_Height(&height);
//	//myDescription->get_Width(&width);
//	//myDescription->Release();
//
//	//IDepthFrameReader* myReader = nullptr;
//	//mySource->OpenReader(&myReader);    //打开深度数据的Reader
//
//	//IDepthFrame* myFrame = nullptr;
//	//Mat temp(height, width, CV_16UC1);    //建立图像矩阵
//	//Mat img(height, width, CV_8UC1);
//
//
//	IKinectSensor* mySensor1 = nullptr;           //第1步打开Sensor
//	GetDefaultKinectSensor(&mySensor1);
//	mySensor1->Open();
//
//	IColorFrameSource* mySource1 = nullptr;       //第2步获取Source
//	mySensor1->get_ColorFrameSource(&mySource1);
//
//	int     height1 = 0, width1 = 0;                  //取得宽和高等下用
//	IFrameDescription* myDescription1 = nullptr;
//	mySource1->get_FrameDescription(&myDescription1);
//	myDescription1->get_Height(&height1);
//	myDescription1->get_Width(&width1);
//
//	IColorFrameReader* myReader1 = nullptr;       //第3步打开Reader
//	mySource1->OpenReader(&myReader1);
//
//	Mat img1(height1, width1, CV_8UC4);
//	IColorFrame* myFrame1 = nullptr;
//
//
//	double rate = 30;
//	std::cout << "Frame rate: " << rate << "fps" << std::endl;
//	int delay = 1000 / rate;
//	//long long i = 0;
//	//std::string b = "depth";
//	//std::string ext = ".bmp";
//
//	//std::string b1 = "color";
//	VideoCapture capture(0);
//	cv::Size S = cv::Size((int)capture.get(CAP_PROP_FRAME_WIDTH),
//		(int)capture.get(CAP_PROP_FRAME_HEIGHT));
//	cv::VideoWriter write;
//	write.open("color.mp4", VideoWriter::fourcc('M', 'P', '4', 'V'), 30.0, S,true);
//	//	VideoProcessor processor;
//	int count = 0;
//	while (1)
//	{
//		//		double time0 = static_cast<double>(getTickCount());
//				//第4步获取Frame
//		 if (SUCCEEDED(myReader1->AcquireLatestFrame(&myFrame1))) {
//			 UINT    size1 = 0;
//			std::cout << "rbg" << "\n" << std::endl;
//			myFrame1->CopyConvertedFrameDataToArray(width1 * height1 * 4, (BYTE*)img1.data, ColorImageFormat_Bgra);
//
//			
//			imshow("TEST1", img1);
//			write.write(img1);
//			myFrame1->Release();
//		}
//	/*	cout << "rbg" << "\n" << endl;
//		capture >> img1;
//		if (img1.empty())break;
//		++count;
//
//		imshow("TEST1", img1);
//		write << img1;*/
////		if (SUCCEEDED(myReader->AcquireLatestFrame(&myFrame)) && SUCCEEDED(myReader1->AcquireLatestFrame(&myFrame1)))//通过Reader尝试获取最新的一帧深度数据，放入深度帧中,并判断是否成功获取
////		{
////			
////			
////			myFrame->CopyFrameDataToArray(height * width, (UINT16*)temp.data); //先把数据存入16位的图像矩阵中
////			temp.convertTo(img, CV_8UC1, 255.0 / 4500);   //再把16位转换为8位
////			imshow("TEST", img);
////
////			UINT    size1 = 0;
////			myFrame1->CopyConvertedFrameDataToArray(width1 * height1 * 4, (BYTE*)img1.data, ColorImageFormat_Bgra);
////			imshow("TEST", img1);
////
////
////
////
////			std::string name(b);
////			std::ostringstream ss; ss << i; name += ss.str(); //i++;
////			name += ext;
////
////			std::cout << name << std::endl;
////
////
////			std::string name1(b1);
////			std::ostringstream ss1; ss1 << i; name1 += ss1.str(); i++;
////			name1 += ext;
////
////			std::cout << name1 << std::endl;
////
////			//			cv::imwrite(name, img);
////
////
////			if (cv::waitKey(delay) >= 0)
////				return 0;
////
////			write << img1;
////
////			/*
////			VideoProcessor processor;
////			processor.setDelay(1000. / 30.0);
////			processor.setOutput("depth.avi", -1, 30);
//////			cv::Mat frame = img.clone();
////			processor.run();
////			*/
////
////			write.open("depth.mp4", VideoWriter::fourcc('M', 'P', '4', 'V'), 30.0, Size(512, 424));
////			//write.write(img);
////			write << img;
////
////
////
////			myFrame->Release();
////
////			myFrame1->Release();
////		}
////		else
////		{
////						//cout << "It cannot get a new  image!!!" << "\n" << endl;
////		}
//
//
//
//		if (waitKey(30) == VK_ESCAPE)
//			break;
//	}
//	write.release();
//	//myReader->Release();        //释放不用的变量并且关闭感应器
//	//mySource->Release();
//	//mySensor->Close();
//	//mySensor->Release();
//	myReader1->Release();        //释放不用的变量并且关闭感应器
//	mySource1->Release();
//	mySensor1->Close();
//	mySensor1->Release();
//	return 0;
//}