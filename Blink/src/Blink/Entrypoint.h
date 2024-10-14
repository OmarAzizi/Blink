#pragma once

#ifdef BLINK_PLATFORM_WINDOWS

extern Blink::Application* Blink::CreateApplication();

int main(int argc, char** argv) {
	Blink::Log::Init();
	BLINK_CORE_WARN("Initialized Logger!");
	int a = 5;
	BLINK_INFO("Hello! Var={0}", a);

	auto app = Blink::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif
