#ifndef FRACTAL_FRAMEBUFFER_HPP
#define FRACTAL_FRAMEBUFFER_HPP

#include <iostream>
#include <vector>

#include "color_rgb.hpp"

namespace fractal {
    class framebuffer {
        friend std::ostream& operator<<(std::ostream& lhs, const framebuffer& rhs) noexcept;
    public:
        using size_type = std::vector<color_rgb>::size_type;

        framebuffer(size_type width, size_type height) noexcept
            : width_(width), height_(height),
              data_(width * height)
        {

        }

        color_rgb& operator()(size_type x, size_type y) noexcept {
            return data_[y * width_ + x];
        }

        const color_rgb& operator()(size_type x, size_type y) const noexcept {
            return data_[y * width_ + x];
        }
    private:
        size_type width_, height_;
        std::vector<color_rgb> data_;
    };

    std::ostream& operator<<(std::ostream& lhs, const framebuffer& rhs) noexcept;
}

#endif