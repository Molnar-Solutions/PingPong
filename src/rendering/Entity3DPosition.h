#ifndef POSITION_CLASS_H
#define POSITION_CLASS_H

#include "glad.h"

class Entity3DPosition
{
private:
	GLfloat x, y, z;
public:
	Entity3DPosition(GLfloat x, GLfloat y, GLfloat z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

#endif