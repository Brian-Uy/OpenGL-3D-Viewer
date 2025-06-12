#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Prototype
void framebuffer_size_callback(GLFWwindow* window, int width, int height); // Window resize callback
void processInput(GLFWwindow* window); // Keyboard and mouse input etc.

// Window's width and height
int windowWidth = 1280;
int windowHieght = 720;

int main(void) {
    // Initialise and configure GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Creating window object
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHieght, "3D Viewer", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialise GLAD (function pointer for OpenGL)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set the size of rendering window
    glViewport(0, 0, windowWidth, windowHieght);

    // Call this function everytime the window is resized
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // User inputs
        processInput(window);

        // Clear the screen and set to the specified colour
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        // Render commands





        glfwSwapBuffers(window); // Swap buffers (double buffer)
        glfwPollEvents(); // Checks for events
    }

    glfwTerminate();
    return 0;
}


// Definitions
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}