#ifndef SC_WINDOW_H
#define SC_WINDOW_H
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "Events.h"
namespace Society
{

	class Window
	{
	private:
		/* data */
		GLFWwindow* m_window;
		unsigned int m_width, m_height;
		const char* m_title;
	public:
		Window(unsigned int width, unsigned int height, const char* title);
		~Window();
		void Update();
		void Clear();
		void SwapBuffers();
		bool ShouldClose();

		unsigned int GetWidth() { return m_width; }
		unsigned int GetHeight() { return m_height; }

	private:
		static void error_callback(int error, const char* description);

		static void window_close_callback(GLFWwindow* window);
		static void window_size_callback(GLFWwindow* window, int width, int height);
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		static void window_content_scale_callback(GLFWwindow* window, float xscale, float yscale);
		static void window_pos_callback(GLFWwindow* window, int xpos, int ypos);
		static void window_iconify_callback(GLFWwindow* window, int iconified);
		static void window_maximize_callback(GLFWwindow* window, int maximized);
		static void window_focus_callback(GLFWwindow* window, int focused);
		static void window_refresh_callback(GLFWwindow* window);

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void character_callback(GLFWwindow* window, unsigned int codepoint);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		static void cursor_enter_callback(GLFWwindow* window, int entered);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
		static void joystick_callback(int jid, int event);
		static void drop_callback(GLFWwindow* window, int count, const char** paths);
	};
}  // namespace Society



#endif
