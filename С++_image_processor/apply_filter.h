#pragma once

#include "crop.h"
#include "grayscale.h"
#include "negative.h"
#include "matrix.h"
#include "sharp.h"
#include "edge.h"
#include "blur.h"
#include "exceptions.h"

class FilterApplier {
public:
    explicit FilterApplier(const std::vector<std::pair<std::string, std::vector<float>>>& arguments)
        : arguments_(arguments){};
    void Apply(const Image& image);

private:
    std::vector<std::pair<std::string, std::vector<float>>> arguments_;
};