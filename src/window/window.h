#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

#include <vector>
#include <iostream>

#include "glad.h"
#include "glfw3.h"
#include "stb_image.h"

#include "rendering/Entity.h"
#include "math/StandardMath.h"

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
        /* Register my math class */
        StandardMath math;

        /* Register shaders */
        Shader shaderProgram("D:\\Organizations\\Molnar-Solutions\\PingPongGame\\src\\shaders\\files\\default.vert",
            "D:\\Organizations\\Molnar-Solutions\\PingPongGame\\src\\shaders\\files\\default.frag");

        /* Define entities */
        std::vector<GLfloat> vertices = {
            // coords            /  colors           / texture
            -0.5f, 0.0, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
            -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   1.0, 0.0f,
            0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
            0.5f, 0.0f, 0.f,     0.0f, 1.0f, 0.0f,   1.0f, 0.1f
        };

        std::vector<GLuint> indices = {
            0, 1, 2,
            0, 2, 3
        };

        std::string texPath = "D:\\Organizations\\Molnar-Solutions\\PingPongGame\\src\\assets\\block.png";

        Texture block(texPath.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
        block.texUnit(shaderProgram, "tex0", 0);

        Entity rectangle(vertices, indices, 8, block, Vector3f(0.0f, 0.0f, -0.5f),
            Vector3f(0.0f, 0.0f, 0.0f), 1);

        // Main while loop
        while (!glfwWindowShouldClose(window))
        {
            // Specify the color of the background
            glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

            // Clean the back buffer and assign the new color to it
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            /* Rendering phrase */
            shaderProgram.Activate();

            block.Bind();
            rectangle.getVAO().Bind();

            /* Draw primitives, number of indices, datatype of indices, index of indices */
            glDrawElements(GL_TRIANGLES, vertices.size() / indices.size(), GL_UNSIGNED_INT, 0);

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