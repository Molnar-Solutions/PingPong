#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include "glad.h"
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string get_file_contents(const char* filename);

class Shader
{
public:
	/* Reference ID of the Shader program */
	GLuint ID;

	/* Constructor that build the Shader Program from 2 different shader */
	Shader(const char* vertexFile, const char* fragmentFile);

	/* Activates the Shader Program */
	void Activate();

	/* Deletes the Shader Program */
	void Delete();

	void printShaderContents(const char* vertexFile, const char* fragmentFile);
private:
	// Checks if the different Shaders have compiled properly
	void compileErrors(unsigned int shader, const char* type);
};

#endif