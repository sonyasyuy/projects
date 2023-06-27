#include <algorithm>
#include "matrix.h"
Matrix::Matrix() {
    matrix_ = {{0}};
}

Matrix::Matrix(const std::vector<std::vector<float>>& matrix) {
    if (matrix.size() != matrix[0].size() || matrix.size() % 2 == 0) {
        matrix_ = {{0}};
    } else {
        matrix_ = matrix;
    }
}

Image Matrix::Apply(const Image& image) const {
    uint32_t height = image.GetHeight();
    uint32_t width = image.GetWidth();
    int32_t radius = static_cast<int32_t>(matrix_.size() / 2 + 1);
    Image output(height, width);
    for (int32_t i = 0; i < static_cast<int32_t>(height); ++i) {
        for (int32_t j = 0; j < static_cast<int32_t>(width); ++j) {
            float red = 0;
            float green = 0;
            float blue = 0;
            for (int32_t delta_i = -radius + 1; delta_i != radius; ++delta_i) {
                for (int32_t delta_j = -radius + 1; delta_j != radius; ++delta_j) {
                    Pixel tmp_pixel = image.GetPixel(i + delta_i, j + delta_j);
                    float multiplier = matrix_[delta_i + radius - 1][delta_j + radius - 1];
                    red += static_cast<float>(tmp_pixel.red_) * multiplier;
                    green += static_cast<float>(tmp_pixel.green_) * multiplier;
                    blue += static_cast<float>(tmp_pixel.blue_) * multiplier;
                }
            }
            output.SetPixel(i, j, Pixel(red, green, blue));
        }
    }
    return output;
}