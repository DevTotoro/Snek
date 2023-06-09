#pragma once
#include <SDL.h>

class Color
{
public:
    Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255);
    ~Color();

public:
    uint8_t r, g, b, a;

public:
    // Constants
    static const Color BLACK;
    static const Color WHITE;
    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color YELLOW;
    static const Color MAGENTA;
    static const Color CYAN;
    static const Color TRANSPARENT;
};
