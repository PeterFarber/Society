#pragma once

#include "Core.h"

namespace Society {
	class SC_API Application
	{

		public:
		Application();
		virtual ~Application();

		void Run();


	};

	// To be defined in CLIENT
	Application	* CreateApplication();
};

