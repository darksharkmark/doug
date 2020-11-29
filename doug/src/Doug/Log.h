#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Doug {

	class DOUG_API Log
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
#define DOUG_CORE_TRACE(...)	::Doug::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DOUG_CORE_INFO(...)		::Doug::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DOUG_CORE_WARN(...)		::Doug::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DOUG_CORE_ERROR(...)	::Doug::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DOUG_CORE_FATAL(...)	::Doug::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros
#define DOUG_TRACE(...)	::Doug::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DOUG_INFO(...)	::Doug::Log::GetClientLogger()->info(__VA_ARGS__)
#define DOUG_WARN(...)	::Doug::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DOUG_ERROR(...)	::Doug::Log::GetClientLogger()->error(__VA_ARGS__)
#define DOUG_FATAL(...)	::Doug::Log::GetClientLogger()->fatal(__VA_ARGS__)
