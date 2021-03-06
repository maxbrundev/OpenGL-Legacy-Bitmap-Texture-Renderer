﻿#include "pch.h"

#include "Shape.h"

Shape shape;

GLuint dirt;
GLuint wood;
GLuint sand;

void LoadBMP(const char* p_location, GLuint& p_texture)
{
	if (p_texture != 0)
		glDeleteTextures(1, &p_texture);
	
	UINT8* datBuff[2] = { nullptr, nullptr };

	std::ifstream file(p_location, std::ios::binary);
	if (!file)
	{
		std::cout << "Failure to open bitmap file.\n";
	}

	datBuff[0] = new UINT8[sizeof(BITMAPFILEHEADER)];
	datBuff[1] = new UINT8[sizeof(BITMAPINFOHEADER)];

	file.read((char*)datBuff[0], sizeof(BITMAPFILEHEADER));
	file.read((char*)datBuff[1], sizeof(BITMAPINFOHEADER));

	BITMAPFILEHEADER* bmpHeader = (BITMAPFILEHEADER*)datBuff[0];
	BITMAPINFOHEADER* bmpInfo = (BITMAPINFOHEADER*)datBuff[1];

	if (bmpHeader->bfType != 0x4D42)
	{
		std::cout << "File \"" << p_location << "\" isn't a bitmap file\n";
	}

	UINT8* pixels = new UINT8[bmpInfo->biSizeImage];

	file.seekg(bmpHeader->bfOffBits);
	file.read((char*)pixels, bmpInfo->biSizeImage);

	UINT8 tmpRGB = 0;
	for (unsigned long i = 0; i < bmpInfo->biSizeImage; i += 3)
	{
		tmpRGB = pixels[i];
		pixels[i] = pixels[i + 2];
		pixels[i + 2] = tmpRGB;
	}

	glGenTextures(1, &p_texture);
	glBindTexture(GL_TEXTURE_2D, p_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmpInfo->biWidth, bmpInfo->biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);

	std::cout << "Texture \"" << p_location << "\" successfully loaded.\n";

	glBindTexture(p_texture, NULL);

	delete[] datBuff[0];
	delete[] datBuff[1];
	delete[] pixels;
}

void Keyboard(unsigned char p_key, int p_x, int p_y)
{
	shape.HandleEvent(p_key);

	switch (p_key)
	{
	case 'a':
		LoadBMP("Texture/dirt.bmp", dirt);
		glBindTexture(GL_TEXTURE_2D, dirt);
		break;

	case 'b':
		LoadBMP("Texture/wood.bmp", wood);
		glBindTexture(GL_TEXTURE_2D, wood);
		break;

	case 'c':
		LoadBMP("Texture/sand.bmp", sand);
		glBindTexture(GL_TEXTURE_2D, sand);
		break;

	default:
		break;
	}
}

void Refresh(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 2, 0, 0, 0, 0, 1, 0);

	shape.Update();

	glutSwapBuffers();
	glutPostRedisplay();
}

void Init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_TEXTURE_2D);

	LoadBMP("Texture/dirt.bmp", dirt);
}

void Reshape(int width, int height)
{
	glViewport(0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, static_cast<GLfloat>(width) / static_cast<GLfloat>(height), 0.1, 100);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Texture Renderer");

	Init();

	glutReshapeFunc(Reshape);
	glutIdleFunc(Refresh);
	glutDisplayFunc(Refresh);
	glutKeyboardFunc(Keyboard);

	glutMainLoop();
}
