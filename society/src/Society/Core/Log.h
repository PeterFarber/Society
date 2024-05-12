#pragma once

#include "Base.h"
#include "spdlog/spdlog.h"

namespace Society {
	class DECLSPEC Log
	{
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
#define SC_CORE_TRACE(...) ::Society::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SC_CORE_INFO(...) ::Society::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SC_CORE_WARN(...) ::Society::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SC_CORE_ERROR(...) ::Society::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SC_CORE_FATAL(...) ::Society::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SC_TRACE(...) ::Society::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SC_INFO(...) ::Society::Log::GetClientLogger()->info(__VA_ARGS__)
#define SC_WARN(...) ::Society::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SC_ERROR(...) ::Society::Log::GetClientLogger()->error(__VA_ARGS__)
#define SC_FATAL(...) ::Society::Log::GetClientLogger()->fatal(__VA_ARGS__)

