#include <Doug.h>

class Sandbox : public Doug::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Doug::Application* Doug::CreateApplication()
{
	return new Sandbox();
}
