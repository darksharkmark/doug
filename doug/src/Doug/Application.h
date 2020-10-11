#pragma once

#include "Core.h"

namespace Doug
{
	class DOUG_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};


	// to be defind in client (e.g. the game)
	Application* CreateApplication();

}

