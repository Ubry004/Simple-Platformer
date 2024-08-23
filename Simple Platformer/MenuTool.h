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
	void renderGrid(GLFWwindow* window);
	void hideGrid(GLFWwindow* window);
	void createGrid(GLFWwindow* window, GLuint VAO);

	bool activate();
	bool deactivate();
	bool check();
	void handleInput(GLFWwindow* window);

	GLuint setupQuad();

private:
	Shader gridShader;
	GLFWwindow* window;
	bool ePressed = false;
};

