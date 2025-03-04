#include "Logger.hpp"

namespace Library {
    std::unique_ptr<Logger> Logger::instance = nullptr;
    bool Logger::loggingEnabled = false;

    Logger::Logger() {
        logFile.open("library.log", std::ios::app); // Append mode
    }

    Logger::~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
    void Logger::enableLogging() {
        loggingEnabled = true;
    }
    void Logger::disableLogging() {
        loggingEnabled = true;
    }

    Logger* Logger::getInstance() {
        if (!instance) {
            instance = std::unique_ptr<Logger>(new Logger());
        }
        return instance.get();
    }

    void Logger::log(LogLevel level, const std::string& message) {
        if (loggingEnabled) {
            std::string levelStr;
            switch (level) {
                case LogLevel::INFO: levelStr = "[INFO] "; break;
                case LogLevel::WARNING: levelStr = "[WARNING] "; break;
                case LogLevel::ERROR: levelStr = "[ERROR] "; break;
            }

            if (logFile.is_open()) {
                logFile << levelStr << message << std::endl;
            }
        }
    }
}
