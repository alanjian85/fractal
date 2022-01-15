#include <cmath>
#include <complex>
#include <fstream>

#include "color_rgb.hpp"
#include "color_hsv.hpp"
#include "framebuffer.hpp"
using namespace fractal;

auto mandelbrot(std::complex<double> c) noexcept {
    constexpr auto max_iteration = 50;

    std::complex<double> z;
    auto i = 0;
    for (i = 0; i < max_iteration; ++i) {
        if (std::abs(z) > 2)
            break;
        z = z * z + c;
    }
    return (i + 1 - std::log(std::log2(std::abs(z)))) / (max_iteration - 1);
}

int main() {
    const int width = 800;
    const int height = 600;

    std::ofstream image("image.ppm");
    framebuffer fb(width, height);

    for (framebuffer::size_type y = 0; y < height; ++y) {
        for (framebuffer::size_type x = 0; x < width; ++x) {
            auto r = std::lerp(-2, 1, static_cast<double>(x) / (width - 1));
            auto i = std::lerp(-1, 1, 1 - static_cast<double>(y) / (height - 1));

            auto m = mandelbrot({r, i});
            
            color_hsv hsv;
            hsv.h = m;
            hsv.s = 1;
            hsv.v = m < 1 ? 1 : 0;
            
            fb(x, y) = hsv;
        }
    }

    image << fb;
    return 0;
}