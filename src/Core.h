#pragma once

#include <iostream>

#ifdef NDEBUG
#define ASSERT(condition, message) if (!condition) throw std::runtime_error(message);
#else
#define ASSERT(condition, message) if (!condition) { std::cerr << "[ASSERTION]: " << message << std::endl; __debugbreak(); }
#endif // NDEBUG

#define CORE_LOG(message) std::cout << "[CORE]: " << message << std::endl;
