#pragma once

#ifdef DOUG_PLATFORM_WINDOWS

extern Doug::Application* Doug::CreateApplication();

int main(int argc, char** argv)
{
	printf("Doug started!");
	auto app = Doug::CreateApplication();
	app->Run();

	delete app;
	app = nullptr;
}

#endif