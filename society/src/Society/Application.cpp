#include "../scpch.h"

#include "Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Society
{

	Application::Application()
	{

		// glfwSetErrorCallback(error_callback);

		if (!glfwInit())
			exit(EXIT_FAILURE);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow(1280, 768, "OpenGL Triangle", NULL, NULL);
		if (!m_window)
		{
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		// glfwSetKeyCallback(window, key_callback);

		glfwMakeContextCurrent(m_window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		glfwSwapInterval(1);
	}

	Application::~Application()
	{
		glfwDestroyWindow(m_window);

		glfwTerminate();
		exit(EXIT_SUCCESS);
	}

	void Application::Run()
	{
		while (!glfwWindowShouldClose(m_window))
		{
			int width, height;
			glfwGetFramebufferSize(m_window, &width, &height);
			const float ratio = width / (float)height;

			glViewport(0, 0, width, height);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}
	}
};