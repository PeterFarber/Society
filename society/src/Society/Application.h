#pragma once

#include "Core.h"

class GLFWwindow;
namespace Society
{
	class DECLSPEC Application
	{
	private:
		GLFWwindow *m_window;

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// // To be defined in CLIENT
	Application *CreateApplication();
};
