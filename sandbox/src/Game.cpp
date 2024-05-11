
#include "Game.h"
#include <Society.h>
#include <glm/gtc/matrix_transform.hpp>

Game::Game(/* args */)
{
	Society::Log::Init();
	SC_CORE_WARN("Initialized Log!");
}

Game::~Game()
{
	delete m_window;
}

void Game::Init(unsigned int width, unsigned int height, const char* title)
{
	m_window = new Society::Window(width, height, title);

	// // load shaders
	Society::ResourceManager::LoadShader("resources/shaders/vertex.glsl", "resources/shaders/fragment.glsl", nullptr, "sprite");
	// configure shaders
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);
	Society::ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	Society::ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
	// set render-specific controls
	// load textures
	Society::ResourceManager::LoadTexture("resources/textures/Subject.png", true, "face");

}

void Game::ProcessInput(float dt)
{
	Society::InputSystem* input = Society::InputSystem::GetInstance();
	if (input->IsKeyPressed(GLFW_KEY_W)) {
		SC_CORE_INFO("W key pressed");

	}
}

void Game::Update(float dt)
{
}

void Game::Render()
{
	Society::Texture2D texture = Society::ResourceManager::GetTexture("face");
	Society::Shader shader = Society::ResourceManager::GetShader("sprite");
	Society::SpriteRenderer spriteRenderer;
	spriteRenderer.SetShader(&shader);
	spriteRenderer.DrawSprite(texture, glm::vec3(200.0f, 200.0f, 0.0f), glm::vec3(533.0f * .25f, 928.0f * .25f, 1.0f), 0, glm::vec3(1.0f, 1.0f, 1.0f));

}

void Game::Run()
{
	while (!m_window->ShouldClose()) {
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		m_window->Clear();

		ProcessInput(deltaTime);
		Update(deltaTime);
		Render();

		m_window->SwapBuffers();
	}
}
