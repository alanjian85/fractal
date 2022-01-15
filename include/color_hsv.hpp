#ifndef FRACTAL_COLOR_HSV_HPP
#define FRACTAL_COLOR_HSV_HPP

namespace fractal {
    struct color_rgb;

    struct color_hsv {
        double h;
        double s;
        double v;

        operator color_rgb() const noexcept;
    };
}

#endif