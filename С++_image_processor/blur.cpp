#include <cmath>
#include "blur.h"

Image GaussianBlur::Apply(const Image &image) const {
    const int k = 6;
    int32_t matrix_size = static_cast<int32_t>(ceilf(k * sigma_));
    if (matrix_size % 2 == 0) {
        matrix_size += 1;
    }
    std::vector<float> coefficients(matrix_size);
    double pi = std::atan(1) * 4;
    int32_t radius = matrix_size / 2;
    for (int32_t i = 0; i < matrix_size; ++i) {
        coefficients[i] =
            1 / static_cast<float>((std::sqrt(2 * pi * sigma_ * sigma_))) *
            std::exp(-static_cast<float>((i - radius)) * static_cast<float>((i - radius)) / (2 * sigma_ * sigma_));
    }
    uint32_t height = image.GetHeight();
    uint32_t width = image.GetWidth();
    Image output(height, width);
    for (int32_t i = 0; i < static_cast<int32_t>(height); ++i) {
        for (int32_t j = 0; j < static_cast<int32_t>(width); ++j) {
            float red = 0;
            float green = 0;
            float blue = 0;
            for (int32_t delta_i = -radius + 1; delta_i != radius; ++delta_i) {
                Pixel tmp_pixel = image.GetPixel(i + delta_i, j);
                float multiplier = coefficients[delta_i + radius - 1];
                red += static_cast<float>(tmp_pixel.red_) * multiplier;
                green += static_cast<float>(tmp_pixel.green_) * multiplier;
                blue += static_cast<float>(tmp_pixel.blue_) * multiplier;
            }
            output.SetPixel(i, j, Pixel(red, green, blue));
        }
    }
    for (int32_t i = 0; i < static_cast<int32_t>(height); ++i) {
        for (int32_t j = 0; j < static_cast<int32_t>(width); ++j) {
            float red = 0;
            float green = 0;
            float blue = 0;
            for (int32_t delta_j = -radius + 1; delta_j != radius; ++delta_j) {
                Pixel tmp_pixel = output.GetPixel(i, j + delta_j);
                float multiplier = coefficients[delta_j + radius - 1];
                red += static_cast<float>(tmp_pixel.red_) * multiplier;
                green += static_cast<float>(tmp_pixel.green_) * multiplier;
                blue += static_cast<float>(tmp_pixel.blue_) * multiplier;
            }
            output.SetPixel(i, j, Pixel(red, green, blue));
        }
    }
    return output;
}