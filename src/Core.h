#pragma once

#include <iostream>

#ifdef NDEBUG
#define ASSERT(condition, message) if (!condition) throw std::runtime_error(message);
#else
#define ASSERT(condition, message) if (!condition) { std::cerr << "Assertion failed: " << message << std::endl; __debugbreak(); }
#endif // NDEBUG

#define LOG(message) std::cout << "- " << message << std::endl;
