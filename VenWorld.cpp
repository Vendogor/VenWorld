#include "VenWorld.h"

GLfloat point[] = {
     0.0f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
};

GLfloat colors[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

int g_winSizeX = 640;
int g_winSizeY = 480;

void glfw_windowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    g_winSizeX = width;
    g_winSizeY = height;
    glViewport(0, 0, g_winSizeX, g_winSizeY);
}

void glfw_KeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}


int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "ERROR! —— glfwInit failed!" << std::endl;
        return -1;
    }

    // options openGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pWindow = glfwCreateWindow(g_winSizeX, g_winSizeY, "VenWorld", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "ERROR! —— glfwCreateWindow failed!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // callbacks
    glfwSetWindowSizeCallback(pWindow, glfw_windowSizeCallback);
    glfwSetKeyCallback(pWindow, glfw_KeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);
	
	if (!gladLoadGL())
	{
		std::cout << "ERROR! —— Can`t load GLAD!" << std::endl;
		return -1;
	}
	
    std::cout << "Render: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL ver.: " << glGetString(GL_VERSION) << std::endl;
	
	
	glClearColor(0,1,1,1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }   

    glfwTerminate();
    return 0;
}