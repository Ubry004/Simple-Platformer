#include "MenuTool.h"

// Toggles
bool activated = false;
bool menuToggle = false;

void MenuTool::renderGrid(GLFWwindow* window)
{
    createGrid(window, setupQuad());
}

void MenuTool::hideGrid(GLFWwindow* window)
{

}

bool MenuTool::activate()
{
    activated = true;
    return true;
}

bool MenuTool::deactivate()
{
    activated = false;
    return false;
}

bool MenuTool::check()
{
    if (activated == true) {
        return true;
    }
    else {
        return false;
    }
}

void MenuTool::createGrid(GLFWwindow* window, GLuint VAO)
{
    gridShader.use();

    // Set uniform variables
    gridShader.setFloat("lineWidth", 1.0f);          // in pixels
    gridShader.setInt("screenWidth", 256);
    gridShader.setInt("screenHeight", 224);
    gridShader.setInt("cellSize", 16);               // in pixels

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

}

void MenuTool::handleInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && !menuToggle) {
        activated = !activated;  // Toggle the activated state
        menuToggle = true;  // Mark that the key has been pressed

        // Print messages based on the new activated state
        if (activated) {
            std::cout << "Debug mode has been activated\n";
        }
        else {
            std::cout << "Debug mode has been deactivated\n";
        }
    }

    // Once the key is released, reset menuToggle to allow future toggling
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_RELEASE) {
        menuToggle = false;
    }

    // Debug controls
    if (activated) {
        renderGrid(window);

    }
}

GLuint MenuTool::setupQuad()
{
    float vertices[] = {
            -1.0f,  1.0f,
            -1.0f, -1.0f,
             1.0f, -1.0f,
             1.0f,  1.0f
    };

    GLuint indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return VAO;
}
