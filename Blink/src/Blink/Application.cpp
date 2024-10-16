#include "blinkpch.h"
#include "Application.h"

#include <Blink/Events/KeyEvent.h>
#include "Blink/Log.h"
#include "GLFW/glfw3.h"

namespace Blink {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_IsRunning) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}