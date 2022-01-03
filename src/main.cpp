#include <complex>
#include <fstream>

constexpr auto max_iteration = 50;

constexpr auto mandelbrot(std::complex<double> c) noexcept {
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
    image << "P2\n";
    image << width << ' ' << height << '\n';
    image << "255\n";

    for (auto y = height - 1; y >= 0; --y) {
        for (auto x = 0; x < width; ++x) {
            auto real = static_cast<double>(x) / (width - 1) * 3 - 2;
            auto imag = static_cast<double>(y) / (height - 1) * 2 - 1;

            auto color = mandelbrot({real, imag});
            image << static_cast<int>(color * 255) << ' ';
        }
        image << '\n';
    }
}