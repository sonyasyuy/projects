#include "grayscale.h"
#include <algorithm>

Image Grayscale::Apply(const Image &image) const {
    const double r = 0.299;
    const double g = 0.587;
    const double b = 0.114;
    const double hi = 255.;
    Image output(image.GetHeight(), image.GetWidth());
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            Pixel pixel = image.GetPixel(static_cast<int32_t>(i), static_cast<int32_t>(j));
            uint8_t tmp_color =
                static_cast<uint8_t>(std::clamp(r * pixel.red_ + g * pixel.green_ + b * pixel.blue_, 0., hi));
            output.SetPixel(i, j, Pixel(tmp_color, tmp_color, tmp_color));
        }
    }
    return output;
}
