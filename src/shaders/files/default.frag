#version 330 core

out vec4 FragColor;

in vec3 color;
in vec2 pass_vertexTexture;

uniform sampler2D tex0;

void main(void)
{
	FragColor = texture(tex0, pass_vertexTexture);
}