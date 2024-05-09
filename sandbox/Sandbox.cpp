#include "SCConfig.h"
#include <Society.h>

class Sandbox : public Society::Application {
	public:
	Sandbox() {
	}

	~Sandbox() {
	}
};

Society::Application* Society::CreateApplication() {
	return new Sandbox();
}
