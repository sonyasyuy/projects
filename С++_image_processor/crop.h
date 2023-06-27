#include "filter.h"

class Crop : public Filter {
public:
    Crop(const uint32_t& width, const uint32_t& height);
    Image Apply(const Image& image) const override;

private:
    uint32_t width_;
    uint32_t height_;
};