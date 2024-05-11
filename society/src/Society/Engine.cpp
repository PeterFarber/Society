// #include "Engine.h"

// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <scpch.h>

// #include "Log.h"
// #include "Window.h"
// #include "Events.h"

// #include "Components/Transform.h"
// #include "Components/Renderable.h"
// #include "Systems/RenderSystem.h"
// #include "Systems/PlayerControlSystem.h"

// namespace Society {


// 	Engine::Engine(unsigned int width, unsigned int height, const char* title) {


// 		// m_window = new Window(width, height, title);
// 		// m_coordinator = new Coordinator();

// 		// m_coordinator->Init();
// 		// m_coordinator->RegisterComponent<Transform>();
// 		// m_coordinator->RegisterComponent<Renderable>();
// 		// m_renderSystem = m_coordinator->RegisterSystem<RenderSystem>();
// 		// {
// 		// 	Signature signature;
// 		// 	signature.set(m_coordinator->GetComponentType<Transform>());
// 		// 	signature.set(m_coordinator->GetComponentType<Renderable>());
// 		// 	m_coordinator->SetSystemSignature<RenderSystem>(signature);
// 		// }

// 		// m_renderSystem->Init(width, height);
// 		// m_renderSystem->SetCoordinator(m_coordinator);

// 		// m_playerControlSystem = m_coordinator->RegisterSystem<PlayerControlSystem>();
// 		// {
// 		// 	Signature signature;
// 		// 	signature.set(m_coordinator->GetComponentType<Transform>());
// 		// 	m_coordinator->SetSystemSignature<PlayerControlSystem>(signature);
// 		// }
// 		// m_playerControlSystem->Init();
// 		// m_playerControlSystem->SetCoordinator(m_coordinator);


// 	}


// 	void Engine::Run() {

// 		while (!m_window->ShouldClose()) {
// 			float currentFrame = glfwGetTime();
// 			deltaTime = currentFrame - lastFrame;
// 			lastFrame = currentFrame;

// 			m_window->Clear();

// 			// m_playerControlSystem->Update(deltaTime);
// 			// m_renderSystem->Update(deltaTime);

// 			m_window->SwapBuffers();
// 		}
// 	}

// 	Engine::~Engine() {
// 		delete m_window;
// 		// delete m_coordinator;
// 	}

// }  // namespace Society

