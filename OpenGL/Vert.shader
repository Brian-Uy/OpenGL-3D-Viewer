#version 330 core

layout (location = 0) in vec3 position;

void main(void) {
	gl_position = vec4(position.x, position.y ,position.z, 1.0f);
}