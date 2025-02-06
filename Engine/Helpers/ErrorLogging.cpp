//
// Created by Karim Ajouz  on 03/02/2025.
//

#include "ErrorLogging.h"

#include <iostream>
#include <ostream>

namespace ZEngine
{
    void ErrorLogging::LogError(const std::string& message)
    {
        std::cerr << message << std::endl;
    }

    void ErrorLogging::LogWarning(const std::string& message)
    {
        std::cout << "WARNING: " + message << std::endl;
    }

    void ErrorLogging::FatalError(const std::string& message)
    {
        std::cerr << message << std::endl;
        throw std::runtime_error(message);

    }

    void ErrorLogging::LogDebug(const std::string& message)
    {
        std::cout << "DEBUG: " + message << std::endl;
    }
} // ZEngine