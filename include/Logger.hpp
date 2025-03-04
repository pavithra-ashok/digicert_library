#pragma once

#include <iostream>
#include <fstream>
#include <memory>

namespace Library {

    enum class LogLevel { INFO, WARNING, ERROR };

    class Logger {
    private:
        std::ofstream logFile;
        static std::unique_ptr<Logger> instance;
        Logger();
        static bool loggingEnabled;
    public:
        ~Logger();
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        static Logger* getInstance();

        void log(LogLevel level, const std::string& message);
        static void enableLogging();
        static void disableLogging();
    };

#define LOG_INFO(msg) Logger::getInstance()->log(LogLevel::INFO, msg)
#define LOG_WARNING(msg) Logger::getInstance()->log(LogLevel::WARNING, msg)
#define LOG_ERROR(msg) Logger::getInstance()->log(LogLevel::ERROR, msg)
}