#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

#include <iostream>

#include "glad.h"
#include "glfw3.h"
#include "stb_image.h"

class WindowManager
{
private:
    const unsigned int SCREEN_WIDTH = 800;
    const unsigned int SCREEN_HEIGHT = 800;

    GLFWwindow* window;
    const char* title;

public:
    WindowManager(const char* title)
    {
        this->title = title;
    }

    void init()
    {
        // Initialize GLFW
        if (!glfwInit())
        {
            std::cout << "GLFW initialization failed!" << std::endl;
            return;
        }

        // Tell GLFW what version of OpenGL we are using 
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create the window
        window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title, NULL, NULL);

        // Error check if the window fails to create
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }

        // Introduce the window into the current context
        glfwMakeContextCurrent(window);

        // Load GLAD so it configures OpenGL
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return;
        }

        // Specify the viewport of OpenGL in the Window
        glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

        // Enables the depth buffer
        glEnable(GL_DEPTH_TEST);
    }

    void game()
    {
        // Main while loop
        while (!glfwWindowShouldClose(window))
        {
            // Specify the color of the background
            glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

            // Clean the back buffer and assign the new color to it
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Swap the back buffer with the front buffer
            glfwSwapBuffers(window);

            // Take care of all GLFW events
            glfwPollEvents();
        }

        // Delete window before ending the program
        //glfwDestroyWindow(window);

        // Terminate GLFW before ending the program
        glfwTerminate();
    }
};

#endif