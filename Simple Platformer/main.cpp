#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

#include "Shader.h"
#include "MenuTool.h"
#include "Game.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, MenuTool debug);

// WINDOW PROPERTIES
const int SCR_WIDTH = 256;
const int SCR_HEIGHT = 224;
const char* TITLE = "I Love Pop'n Magic!";

int main() {

    //Initialize OpenGL through GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, TITLE, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    // Create shaders
    Shader shader("shaders/vs.txt", "shaders/fs.txt");

    // Create MenuTool
    MenuTool debug;
    Game game;
    
    //-------------------------------------------------------------------------------------------------

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 0.95f, 0.64f, 1.0f); // Banana by default
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // render
        game.renderTempQuad(shader);
        
        // input
        processInput(window, debug);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void processInput(GLFWwindow* window, MenuTool debug)
{
    // Debug Controls
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        debug.displayGrid(window);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

