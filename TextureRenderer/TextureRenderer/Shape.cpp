#include "pch.h"
#include "Shape.h"

void Shape::Draw()
{
	if (isLine)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (isAxis)
		Axis();

	Cube();
}

void Shape::Update()
{
	glRotatef(m_angle, 1.0f, 0.0f, 0.0f);
	glRotatef(m_angle, 0.0f, 1.0f, 0.0f);
	glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

	Draw();

	m_angle += 1.0f;

	if (m_angle >= 360.0f)
		m_angle = 0.0f;
}

void Shape::HandleEvent(unsigned char p_key)
{
	switch (p_key)
	{
	case 'e':
		isLine = !isLine;
		break;
	case '3':
		isAxis = !isAxis;
		break;
	default:
		break;
	}
}

void Shape::Axis()
{
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glScalef(0.7f, 0.7f, 0.7f);
	glLineWidth(2.0f);
	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.7f, 0.7f, 0.7f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(1.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glutSolidCone(0.1, 0.2, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.7f, 0.7f, 0.7f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 1.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glutSolidCone(0.1, 0.2, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.7f, 0.7f, 0.7f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, 1.0f);
	glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
	glutSolidCone(0.1, 0.2, 10, 10);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Shape::Cube()
{
	glPushMatrix();
	glLineWidth(2.0f);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(0, 1);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1, 1);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1, 0);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glLineWidth(2.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(0, 1);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1, 1);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1, 0);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glLineWidth(2.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(0, 1);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1, 1);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1, 0);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	glLineWidth(2.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(0, 1);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1, 1);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1, 0);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
	glLineWidth(2.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(0, 1);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1, 1);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1, 0);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glLineWidth(2.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0, 1);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1, 1);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(1, 0);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();
	glPopMatrix();
}