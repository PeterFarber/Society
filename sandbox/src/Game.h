#ifndef GAME_H
#define GAME_H

#include <Society.h>
// Represents the current state of the game
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};


class Game
{
private:
	/* data */
	Society::Window* m_window;

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

public:
	Game();
	~Game();

	void Init(unsigned int width, unsigned int height, const char* title);
	void ProcessInput(float dt);
	void Update(float dt);
	void Render();

	void Run();

};



#endif

