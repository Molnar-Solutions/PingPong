#ifndef VECTOR_CLASS_H
#define VECTOR3F_CLASS_H

#include "glad.h"
#include <vector>

class Vector3f
{
private:
	std::vector<GLfloat> coords = { 0.0f, 0.0f, 0.0f };
public:
	Vector3f() {}

	Vector3f(GLfloat x, GLfloat y, GLfloat z)
	{
		this->coords[0] = x;
		this->coords[1] = y;
		this->coords[2] = z;
	}

	void setX(GLfloat coord)
	{
		this->coords[0] = coord;
	}

	void setY(GLfloat coord)
	{
		this->coords[1] = coord;
	}

	void setZ(GLfloat coord) 
	{
		this->coords[2] = coord;
	}

	GLfloat getX()
	{
		return coords[0];
	}

	GLfloat getY()
	{
		return coords[1];
	}

	GLfloat getZ()
	{
		return coords[2];
	}

	void addToX(GLfloat amount)
	{
		this->coords[0] += amount;
	}

	void addToY(GLfloat amount)
	{
		this->coords[1] += amount;
	}

	void addToZ(GLfloat amount)
	{
		this->coords[2] += amount;
	}
};

#endif