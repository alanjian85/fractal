#include <cmath>
#include <complex>
#include <fstream>

#include "color_rgb.hpp"
#include "color_hsv.hpp"
using namespace fractal;

constexpr auto mandelbrot(std::complex<double> c) noexcept {
    constexpr auto max_iteration = 50;

    std::complex<double> z;
    auto i = 0;
    for (i = 0; i < max_iteration; ++i) {
        if (std::abs(z) > 2)
            break;
        z = z * z + c;
    }
    return static_cast<double>(i) / max_iteration;
}

int main() {
    const int width = 800;
    const int height = 600;

    std::ofstream image("image.ppm");
    image << "P3\n";
    image << width << ' ' << height << '\n';
    image << "255\n";

    for (auto y = height - 1; y >= 0; --y) {
        for (auto x = 0; x < width; ++x) {
            auto r = std::lerp(-2, 1, static_cast<double>(x) / (width - 1));
            auto i = std::lerp(-1, 1, static_cast<double>(y) / (height - 1));

            auto m = mandelbrot({r, i});
            
            color_hsv hsv;
            hsv.h = m;
            hsv.s = 1;
            hsv.v = m < 1 ? 1 : 0;
            
            color_rgb color = hsv;

            image << static_cast<int>(color.r * 255) << ' ';
            image << static_cast<int>(color.g * 255) << ' ';
            image << static_cast<int>(color.b * 255) << ' ';
        }
        image << '\n';
    }
}