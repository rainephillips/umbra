#include "Umbra/Application.h"

#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

int main()
{
#if _DEBUG
	// These flags turn on the memory leak tracking tools
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// This function will enable a breakpoint when the program
	// reaches a piece of memory with the matching ID
#endif

	Application* app = new Application();

	const int exitCode = app->Run();

	delete app;

	return exitCode;
}