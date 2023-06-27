#include "filter.h"

class GaussianBlur : public Filter {
public:
    explicit GaussianBlur(const float& sigma) : sigma_(sigma){};
    Image Apply(const Image& image) const override;

private:
    float sigma_;
};