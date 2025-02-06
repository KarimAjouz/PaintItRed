//
// Created by Karim Ajouz  on 03/02/2025.
//

#ifndef ERRORLOGGING_H
#define ERRORLOGGING_H
#include <string>

namespace ZEngine
{

    class ErrorLogging
    {
    public:
        static void LogError(const std::string& message);
        static void LogWarning(const std::string& message);
        static void FatalError(const std::string& message);

        static void LogDebug(const std::string& message);
    };

} // ZEngine

#endif //ERRORLOGGING_H
