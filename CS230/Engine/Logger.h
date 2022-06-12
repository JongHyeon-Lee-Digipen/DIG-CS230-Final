
#pragma once
#include <string>
#include <fstream>
#include<chrono>

namespace CS230 {
	class Logger {
	public:
		enum class Severity {
			Verbose,			
			Debug,			
			Event,			
			Error,			
		};

		Logger(Severity severity, bool useConsole , std::chrono::system_clock::time_point StartTime_Value);
		~Logger();

		virtual void LogError(std::string text) { Log(Severity::Error, text); }
		virtual void LogEvent(std::string text) { Log(Severity::Event, text); }
		virtual void LogDebug(std::string text) { Log(Severity::Debug, text); }
		virtual void LogVerbose(std::string text) { Log(Severity::Verbose, text); }

	private:
		void Log(Severity, std::string displayText);

		std::ofstream outStream;
		Severity minLevel;
		std::chrono::system_clock::time_point StartTime;
		double GetSecondsSinceStart()
		{
			return std::chrono::duration<double>(std::chrono::system_clock::now() - StartTime).count();
		}

		

	};
}