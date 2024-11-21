#include "IMAT2912.h"
#include "scene.h"


int main()
{
	// Start the singleton application
	std::shared_ptr<SC::Application> application(SC::Application::getInstance());
	application->init();

	// Start the renderer
	SC::Renderer::init();

	Scene scene;

	float elapsedTime = 0.f;

	while (application->isRunning())
	{
		elapsedTime += application->resetTimer();

		scene.onUpdate(elapsedTime);

		scene.onDraw();

		application->updateWindow(elapsedTime);
		elapsedTime = 0.f;
	}
	
	// Stop the renderer
	SC::Renderer::shutdown();

	return 0;
}