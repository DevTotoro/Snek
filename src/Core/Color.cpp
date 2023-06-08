#include "Color.h"

// Constants
const Color Color::BLACK = Color(0, 0, 0, 255);
const Color Color::WHITE = Color(255, 255, 255, 255);
const Color Color::RED = Color(255, 0, 0, 255);
const Color Color::GREEN = Color(0, 255, 0, 255);
const Color Color::BLUE = Color(0, 0, 255, 255);
const Color Color::YELLOW = Color(255, 255, 0, 255);
const Color Color::MAGENTA = Color(255, 0, 255, 255);
const Color Color::CYAN = Color(0, 255, 255, 255);
const Color Color::TRANSPARENT = Color(0, 0, 0, 0);

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : r(r), g(g), b(b), a(a) {}

Color::~Color() = default;
