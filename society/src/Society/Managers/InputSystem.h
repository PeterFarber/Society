#ifndef SC_INPUTSYSTEM_H
#define SC_INPUTSYSTEM_H

#include "../Interfaces/ISingleton.h"
#include <GLFW/glfw3.h>

namespace Society {

	enum class KeyState
	{
		Pressed,
		Released,
		Held
	};

	class InputSystem : public ISingleton<InputSystem>
	{
	private:

		KeyState m_keys[1024];

	public:
		InputSystem();
		bool IsKeyPressed(int key);
		bool IsKeyReleased(int key);
		bool IsKeyHeld(int key);

		// static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		void SetKeyState(int key, KeyState state) { m_keys[key] = state; }
	};

}



#endif 
