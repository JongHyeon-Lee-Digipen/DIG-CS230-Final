/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Logger.cpp
Project: CS230
Author: Jemin.Shin
Creation date: 3/27/2022
-----------------------------------------------------------------*/
#include <iostream>    // cout.rdbuf
#include <string>
#include "Logger.h"


using namespace std;

CS230::Logger::Logger(Severity severity, bool useConsole, std::chrono::system_clock::time_point StartTime_Value)
    : minLevel(severity), outStream("Trace.log") ,StartTime(StartTime_Value)
{
	if (useConsole == true) {
		outStream.set_rdbuf(std::cout.rdbuf());
	}
}

CS230::Logger::~Logger() {
	outStream.flush();
	outStream.close();
}

void CS230::Logger::Log(CS230::Logger::Severity severity, std::string message)
{
    if (minLevel <= severity)
    {
        switch (severity) 
        {
        case CS230::Logger::Severity::Verbose:
                outStream.precision(4);
                outStream << '[' << std::fixed << GetSecondsSinceStart() << "]\t";
                outStream << "Verb\t";
                outStream << message << std::endl;
                break;
        case CS230::Logger::Severity::Debug:
                outStream.precision(4);
                outStream << '[' << std::fixed << GetSecondsSinceStart() << "]\t";
                outStream << "Debug\t";
                outStream << message << std::endl;
                break;
        case CS230::Logger::Severity::Event:
                outStream.precision(4);
                outStream << '[' << std::fixed << GetSecondsSinceStart() << "]\t";
                outStream << "Event\t";
                outStream << message << std::endl;
                break;
        case CS230::Logger::Severity::Error:
                outStream.precision(4);
                outStream << '[' << std::fixed << GetSecondsSinceStart() << "]\t";
                outStream << "Error \t";
                outStream << message << std::endl;
                break;
        }
    }
}