#pragma once

#ifdef DOUG_PLATFORM_WINDOWS

extern Doug::Application* Doug::CreateApplication();

int main(int argc, char** argv)
{
	Doug::Log::Init();

	DOUG_CORE_INFO("main function called");

	DOUG_CORE_INFO("Initialized log!");

	auto app = Doug::CreateApplication();
	app->Run();

	delete app;
	app = nullptr;
}

#endif