#include "negative.h"

Image Negative::Apply(const Image &image) const {
    const int neg = 255;
    Image output(image.GetHeight(), image.GetWidth());
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            Pixel pixel = image.GetPixel(static_cast<int32_t>(i), static_cast<int32_t>(j));
            output.SetPixel(i, j, Pixel(neg - pixel.red_, neg - pixel.green_, neg - pixel.blue_));
        }
    }
    return output;
}