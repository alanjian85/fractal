#include "framebuffer.hpp"
using namespace fractal;

#include <algorithm>

std::ostream& fractal::operator<<(std::ostream& lhs, const framebuffer& rhs) noexcept {
    lhs << "P3\n"
        << rhs.width_ << ' ' << rhs.height_ << '\n'
        << "255\n";
    for (framebuffer::size_type y = 0; y < rhs.height_; ++y) {
        for (framebuffer::size_type x = 0; x < rhs.width_; ++x) {
            auto r = std::clamp(static_cast<int>(rhs(x, y).r * 255), 0, 255);
            auto g = std::clamp(static_cast<int>(rhs(x, y).g * 255), 0, 255);
            auto b = std::clamp(static_cast<int>(rhs(x, y).b * 255), 0, 255);
        
            lhs << r << ' ' << g << ' ' << b << ' ';
        }
        lhs << '\n';
    }

    return lhs;
}