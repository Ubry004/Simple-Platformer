#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "stb_image.h"

class Entity {
public:
    float width, height;
    std::string subtype;
    GLuint textureID;
    GLuint VAO, VBO;

    // Constructor to initialize the entity with customizable properties
    Entity(float w, float h, const std::string& sub, GLuint tex)
        : width(w), height(h), subtype(sub), textureID(tex) {
        setupQuad();
    }

    // Setup VAO and VBO for the quad
    // w and h will be read in depending on the size of the texture image
    void setupQuad();

    void render(GLuint shader);

    // Destructor to clean up VAO and VBO
    ~Entity() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }
};

