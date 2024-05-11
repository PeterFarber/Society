
#include <glad/glad.h>


#include "scpch.h"
#include "Window.h"
#include "Log.h"


#include "EventSystem.h"
#include "InputSystem.h"

namespace Society {

	void Window::Update()
	{
		// int width, height;
		// glfwGetFramebufferSize(m_window, &width, &height);
		// const float ratio = width / (float)height;

	}

	void Window::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(m_window);
	}

	Window::Window(unsigned int width, unsigned int height, const char* title) : m_width(width), m_height(height), m_title(title)
	{
		glfwSetErrorCallback(error_callback);

		if (!glfwInit())
			exit(EXIT_FAILURE);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if (!m_window) {
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		// glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		// glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GLFW_TRUE);
		if (glfwRawMouseMotionSupported()) {
			SC_CORE_INFO("Raw mouse motion supported");
			glfwSetInputMode(m_window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
		}

		glfwSetWindowCloseCallback(m_window, window_close_callback);
		glfwSetWindowSizeCallback(m_window, window_size_callback);
		glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
		// void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		// 	// Your key callback implementation here
		// }

		// // ...

		glfwSetKeyCallback(m_window, key_callback);

		glfwMakeContextCurrent(m_window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		glfwSwapInterval(1);
	}

	void Window::error_callback(int error, const char* description) {
		SC_CORE_ERROR("Error: {0}", description);
	}

	void Window::window_close_callback(GLFWwindow* window) {
		EventSystem::GetInstance()->NotifyObservers(new WindowEvent(EVENT_TYPE::WINDOW_CLOSE, -1, -1, -1, -1, -1, -1, -1, -1, -1));
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	void Window::window_size_callback(GLFWwindow* window, int width, int height) {
		EventSystem::GetInstance()->NotifyObservers(new WindowEvent(EVENT_TYPE::WINDOW_RESIZE, width, height, -1, -1, -1, -1, -1, -1, -1));
		glViewport(0, 0, width, height);
	}

	void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		EventSystem::GetInstance()->NotifyObservers(new WindowEvent(EVENT_TYPE::WINDOW_RESIZE, width, height, -1, -1, -1, -1, -1, -1, -1));
		glViewport(0, 0, width, height);
	}

	void Window::window_content_scale_callback(GLFWwindow* window, float xscale, float yscale) {
		EventSystem::GetInstance()->NotifyObservers(new WindowEvent(EVENT_TYPE::WINDOW_CONTENT_SCALE, -1, -1, xscale, yscale, -1, -1, -1, -1, -1));
	}

	void Window::window_pos_callback(GLFWwindow* window, int xpos, int ypos) {
		EventSystem::GetInstance()->NotifyObservers(new WindowEvent(EVENT_TYPE::WINDOW_POS, -1, -1, -1, -1, xpos, ypos, -1, -1, -1));
	}

	void Window::window_iconify_callback(GLFWwindow* window, int iconified) {
		EventSystem::GetInstance()->NotifyObservers(new WindowEvent(EVENT_TYPE::WINDOW_ICONIFY, -1, -1, -1, -1, -1, -1, iconified, -1, -1));
		if (iconified) {
			// The window was iconified
		}
		else {
			// The window was restored
		}
	}

	void Window::window_maximize_callback(GLFWwindow* window, int maximized) {
		EventSystem::GetInstance()->NotifyObservers(new WindowEvent(EVENT_TYPE::WINDOW_MAXIMIZE, -1, -1, -1, -1, -1, -1, -1, maximized, -1));
	}

	void Window::window_focus_callback(GLFWwindow* window, int focused) {
		EventSystem::GetInstance()->NotifyObservers(new WindowEvent(EVENT_TYPE::WINDOW_FOCUS, -1, -1, -1, -1, -1, -1, -1, -1, focused));
	}

	void Window::window_refresh_callback(GLFWwindow* window) {
		EventSystem::GetInstance()->NotifyObservers(new WindowEvent(EVENT_TYPE::WINDOW_REFRESH, -1, -1, -1, -1, -1, -1, -1, -1, -1));
		glfwSwapBuffers(window);
	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		InputSystem::GetInstance()->SetKeyState(key, (KeyState)action);
		// EVENT_TYPE type;
		// switch (action) {
		// case GLFW_PRESS:
		// 	type = EVENT_TYPE::KEY_PRESSED;
		// 	break;
		// case GLFW_RELEASE:
		// 	type = EVENT_TYPE::KEY_RELEASED;
		// 	break;
		// case GLFW_REPEAT:
		// 	type = EVENT_TYPE::KEY_REPEATED;
		// 	break;
		// }
		// KeyEvent* e = new KeyEvent(type, key, scancode, action, mods);
		// EventSystem::GetInstance()->NotifyObservers(e);

		// delete e;
		// SC_CORE_INFO("Key: {0}, Scancode: {1}, Action: {2}, Mods: {3}", key, scancode, action, mods);
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	void Window::character_callback(GLFWwindow* window, unsigned int codepoint) {
		// SC_CORE_INFO("Character: {0}", codepoint);
	}

	void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
		// SC_CORE_INFO("Cursor position: {0}, {1}", xpos, ypos);
	}

	void Window::cursor_enter_callback(GLFWwindow* window, int entered) {
		// SC_CORE_INFO("Cursor enter: {0}", entered);
		if (entered)
		{
			// The cursor entered the content area of the window
		}
		else
		{
			// The cursor left the content area of the window
		}
	}

	void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		// SC_CORE_INFO("Mouse button: {0}, Action: {1}, Mods: {2}", button, action, mods);
	}

	void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
		// SC_CORE_INFO("Scroll: {0}, {1}", xoffset, yoffset);
	}

	void Window::joystick_callback(int jid, int event) {
		// SC_CORE_INFO("Joystick: {0}, Event: {1}", jid, event);
		if (event == GLFW_CONNECTED)
		{
			// The joystick was connected
		}
		else if (event == GLFW_DISCONNECTED)
		{
			// The joystick was disconnected
		}
	}

	void Window::drop_callback(GLFWwindow* window, int count, const char** paths) {
		SC_CORE_INFO("Drop: {0}", count);
		for (int i = 0; i < count; i++)
		{
			SC_CORE_INFO("Path: {0}", paths[i]);
		}
	}


	Window::~Window()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		exit(EXIT_SUCCESS);
	}

}
