#include "Application.h"

#include <Blink/Events/KeyEvent.h>
#include "Blink/Log.h"

namespace Blink {
	Application::Application() {
		
	}

	Application::~Application() {

	}

	void Application::Run() {
		// Arbitrary
		KeyPressedEvent e(5, 10);

		if (e.IsInCategory(EventCategoryMouse)) {
			BLINK_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput)) {
			BLINK_TRACE(e);
		}

		while (true);
	}
}