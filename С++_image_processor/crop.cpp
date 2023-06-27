#include "crop.h"

Crop::Crop(const uint32_t &width, const uint32_t &height) {
    width_ = width;
    height_ = height;
}

Image Crop::Apply(const Image &image) const {
    Image output(height_, width_);
    size_t i_output = 0;
    for (size_t i = std::max(static_cast<int32_t>(image.GetHeight()) - static_cast<int32_t>(height_), 0);
         i < image.GetHeight(); ++i) {
        size_t j_output = 0;
        for (size_t j = 0; j < static_cast<size_t>(std::min(width_, image.GetWidth())); ++j) {
            output.SetPixel(i_output, j_output, image.GetPixel(static_cast<int32_t>(i), static_cast<int32_t>(j)));
            ++j_output;
        }
        ++i_output;
    }
    return output;
}