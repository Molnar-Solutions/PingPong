#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

out vec3 color;
out vec2 pass_vertexTexture;

void main(void)
{
	vec4 worldPosition = transformationMatrix * vec4(aPos, 1.0);
	pass_vertexTexture = aTex;

	gl_Position = projectionMatrix * viewMatrix * worldPosition;
}