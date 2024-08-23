#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

#include "Shader.h"
#include "MenuTool.h"
#include "Game.h"

//TO-DO
/*
* 
* Rendering entities
* 
* 
* 
*/

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, MenuTool debug);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

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
    glfwSetKeyCallback(window, key_callback);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    // Create shaders
    Shader shader("shaders/vs.txt", "shaders/fs.txt");
    
    // Create Debug State
    MenuTool debug;

    //Create Game State
    Game game;
    //game.init();

    //-------------------------------------------------------------------------------------------------

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 0.95f, 0.64f, 1.0f); // Banana by default
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // render
        //game.renderTempQuad(shader);
        
        
        // input
        processInput(window, debug);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void processInput(GLFWwindow* window, MenuTool debug)
{
    // Debug Controls
    debug.handleInput(window);

    // Menu Controls


}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Empty for now
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    float aspect_ratio = 1024.0f / 896.0f;
    int wVP; 
    int hVP; //default values

    float requiredHVP = width * (1.0f / aspect_ratio);

    if (requiredHVP > height) {
        float requiredWVP = height * aspect_ratio;

        if (requiredWVP > width) {
            std::cout << "Error: Could not resize window while preserving aspect ratio\n";
        }
        else {
            wVP = static_cast<int>(requiredWVP);
            hVP = height;
        }
    }
    else {
        wVP = width;
        hVP = static_cast<int>(requiredHVP);
    }

    glViewport(0, 0, wVP, hVP);
}

