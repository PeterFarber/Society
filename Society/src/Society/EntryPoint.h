#pragma once


extern Society::Application* Society::CreateApplication();

int main(int argc, char** argv)
{
	Society::Log::Init();
	SC_CORE_WARN("Initialized Log!");
	SC_INFO("Hello! Var={0}{1}", 5, 5);

	auto app = Society::CreateApplication();
	app->Run();
	delete app;
}

