#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "stb_image.h"
#include <vector>

#include "Entity.h"

class Game
{
public:
	void render(Shader shader);
	void renderTempQuad(Shader shader);
	void init(GLFWwindow* window, Shader shader);
    std::vector<Entity> entities;  // Store all character entities

    // Load texture by ID
    GLuint loadTexture(const char* textureID);
    // Method to create a mob entity
    void makeEntity(float width, float height, const std::string& subtype, GLuint textureID);
    // Method to render all entities
    void renderEntitiesByTag(const std::string& tag, GLuint shader);

private:

};

