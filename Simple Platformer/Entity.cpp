#include "Entity.h"

// This class represents the individual entities with properties like width, height, subtype, and texture, etc

void Entity::setupQuad()
{
    float vertices[] = {
        // Positions      // Texture Coords
         0.0f, 0.0f,      0.0f, 0.0f,  // Bottom-left
         width, 0.0f,     1.0f, 0.0f,  // Bottom-right
         width, height,   1.0f, 1.0f,  // Top-right
         0.0f, height,    0.0f, 1.0f   // Top-left
    };

    // Generate and bind VAO and VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Entity::render(GLuint shader)
{
    // Use shader program
    glUseProgram(shader);

    glBindTexture(GL_TEXTURE_2D, textureID);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);  // Drawing quad with 4 vertices
    glBindVertexArray(0);

    glUseProgram(0);  // Unbind shader program
}
