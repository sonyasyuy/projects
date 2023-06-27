#include "sharp.h"
#include "matrix.h"

Image Sharp::Apply(const Image &image) const {
    const int ch = 5;
    Matrix filter({{0, -1, 0}, {-1, ch, -1}, {0, -1, 0}});
    return filter.Apply(image);
}