#pragma once

#ifdef BLINK_PLATFORM_WINDOWS

extern Blink::Application* Blink::CreateApplication();

int main(int argc, char** argv) {
	Blink::Log::Init();
	auto app = Blink::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif
