#include "InputSystem.h"


namespace Society {
	InputSystem::InputSystem()
	{

		for (int i = 0; i < 1024; i++)
		{
			m_keys[i] = KeyState::Released;
		}
	}

	bool InputSystem::IsKeyPressed(int key)
	{
		if (m_keys[key] == KeyState::Pressed)
			return true;
		return false;
	}

	bool InputSystem::IsKeyReleased(int key)
	{
		if (m_keys[key] == KeyState::Released)
			return true;
		return false;
	}

	bool InputSystem::IsKeyHeld(int key)
	{
		if (m_keys[key] == KeyState::Held)
			return true;
		return false;
	}


}
