#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Blink {
	class BLINK_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define BLINK_CORE_TRACE(...) ::Blink::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BLINK_CORE_INFO(...)  ::Blink::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BLINK_CORE_WARN(...)  ::Blink::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BLINK_CORE_ERROR(...) ::Blink::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BLINK_CORE_FATAL(...) ::Blink::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define BLINK_TRACE(...)      ::Blink::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BLINK_INFO(...)       ::Blink::Log::GetClientLogger()->info(__VA_ARGS__)
#define BLINK_WARN(...)       ::Blink::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BLINK_ERROR(...)      ::Blink::Log::GetClientLogger()->error(__VA_ARGS__)
#define BLINK_FATAL(...)      ::Blink::Log::GetClientLogger()->fatal(__VA_ARGS__)
