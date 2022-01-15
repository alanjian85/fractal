#include "color_hsv.hpp"
using namespace fractal;

#include <cmath>

#include "color_rgb.hpp"

color_hsv::operator color_rgb() const noexcept {
    color_rgb rgb;
    double h = this->h * 360, s = this->s, v = this->v;

    if (h == 360) {
        h = 0;
    } else {
        h /= 60;
    }
    auto fract = h - std::floor(h);

    auto p = v * (1 - s);
    auto q = v * (1 - s * fract);
    auto t = v * (1 - s * (1 - fract));

    if (0 <= h && h < 1)
        rgb = {v, t, p};
    else if (1 <= h && h < 2)
        rgb = {q, v, p};
    else if (2 <= h && h < 3)
        rgb = {p, v, t};
    else if (3 <= h && h < 4)
        rgb = {p, q, v};
    else if (4 <= h && h < 5)
        rgb = {t, p, v};
    else if (5 <= h && h < 6)
        rgb = {v, p, q};
    else
        rgb = {0, 0, 0};

    return rgb;
}