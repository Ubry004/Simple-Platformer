#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class MenuTool
{
public:
	MenuTool()
		: gridShader("shaders/vsGrid.txt", "shaders/fsGrid.txt") 
	{}
	void displayGrid(GLFWwindow* window);
	void setupGrid(GLFWwindow* window, GLuint VAO);
	GLuint setupQuad();

private:
	Shader gridShader;
	GLFWwindow* window;
};

