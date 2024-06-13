#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "stb_image.h"

class Game
{
public:
	void render(Shader shader);
	void renderTempQuad(Shader shader);
private:

};

