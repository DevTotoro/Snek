#include <memory>
#include <iostream>
#include "Core/Application.h"

int main(int argc, char** args)
{
    try
    {
        auto app = std::make_unique<Application>();
        app->Run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "[ERROR]: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
