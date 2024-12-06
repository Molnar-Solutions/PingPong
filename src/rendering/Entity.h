#ifndef ENTITY_CLASS_H
#define ENTITY_CLASS_H

#include "glad.h"
#include "Texture.h"
#include "Entity3DPosition.h"

class Entity
{
private:
	Texture texture;
	Entity3DPosition pos;

	GLfloat vertices[];
	GLfloat indices[];
public:
	Entity(GLfloat vertices[], GLfloat indices, Entity3DPosition pos,
		Texture texture)
	{	
		this->vertices = vertices;
		this->indices = indices;
		this->pos = pos;
		this->texture = texture;
	}
};

#endif