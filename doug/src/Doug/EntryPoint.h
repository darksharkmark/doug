#pragma once

#ifdef DOUG_PLATFORM_WINDOWS

extern Doug::Application* Doug::CreateApplication();

int main(int argc, char** argv)
{
	DOUG_CORE_INFO("min function called");

	Doug::Log::Init();

	DOUG_CORE_INFO("Initialized log!");

	auto app = Doug::CreateApplication();
	app->Run();

	delete app;
	app = nullptr;
}

#endif