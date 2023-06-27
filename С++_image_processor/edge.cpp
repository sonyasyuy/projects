#include "edge.h"
#include "matrix.h"
#include "grayscale.h"

Image Edge::Apply(const Image &image) const {
    Grayscale filter1;
    const int aboba = 255;
    Matrix filter2({{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}});
    Image output = filter1.Apply(image);
    output = filter2.Apply(output);
    size_t height = image.GetHeight();
    size_t width = image.GetWidth();
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            if (output.GetPixel(static_cast<int32_t>(i), static_cast<int32_t>(j)).red_ > threshold_) {
                output.SetPixel(i, j, Pixel(aboba, aboba, aboba));
            } else {
                output.SetPixel(i, j, Pixel());
            }
        }
    }
    return output;
}