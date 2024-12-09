#ifndef ENTITY_CLASS_H
#define ENTITY_CLASS_H

#include "glad.h"
#include "Texture.h"

#include <vector>
#include "math/Vector3f.h"

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

class Entity
{
private:
	VAO vao;
	VBO vbo;
	EBO ebo;

	Vector3f position;
	Vector3f rotation;
	Texture texture;

	GLfloat rotX = 0.0f;
	GLfloat rotY = 0.0f;
	GLfloat rotZ = 0.0f;
	GLfloat scale = 1.0f;

	/*
	
	Next time: the drawing is not working :(
	
	*/

	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;
public:
	Entity(std::vector<GLfloat> vert,
			std::vector<GLuint> ind,
			int strideLength,
			Texture text,
			Vector3f pos,
			Vector3f rot,
			GLfloat scale
		   )
	{	
		this->vertices = vert;
		this->indices = ind;
		this->position = pos;
		this->rotation = rot;
		this->texture = text;
		this->scale = scale;

		this->vao = VAO();
		this->vao.Bind();

		/* Generate Vertex Buffer Object and links it to vertices */
		this->vbo = VBO(vert);
		this->ebo = EBO(ind);
							//    slot  dimension  data type       stride length                             offset	  	
		this->vao.LinkAttrib(vbo, 0,    3,            GL_FLOAT,       strideLength * sizeof(GLfloat),           (void*)0);
		this->vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, strideLength * sizeof(GLfloat), (void*) (3 * sizeof(GLfloat)));
		this->vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, strideLength * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));

		/* Unbind all to prevent accidentally modifying them */
		this->vao.Unbind();
		this->vbo.Unbind();
		this->ebo.Unbind();
	}

	VAO getVAO()
	{
		return this->vao;
	}

	void increasePosition(GLfloat dX, GLfloat dY, GLfloat dZ)
	{
		position.addToX(dX);
		position.addToY(dY);
		position.addToZ(dZ);
	}

	void increaseRotation(GLfloat dX, GLfloat dY, GLfloat dZ)
	{
		this->rotX += dX;
		this->rotY += dY;
		this->rotZ += dZ;
	}

	Vector3f getPosition()
	{
		return position;
	}

	Vector3f getRotation()
	{
		return rotation;
	}

	Texture getTexture()
	{
		return texture;
	}

	GLfloat getScale()
	{
		return scale;
	}

	void setScale(GLfloat scale)
	{
		this->scale = scale;
	}

	void setPosition(Vector3f newPosition)
	{
		this->position.setX(newPosition.getX());
		this->position.setY(newPosition.getY());
		this->position.setZ(newPosition.getZ());
	}
};

#endif