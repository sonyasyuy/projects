#include "filter.h"

class Matrix : public Filter {
public:
    Matrix();
    explicit Matrix(const std::vector<std::vector<float>>& matrix);
    Image Apply(const Image& image) const override;

private:
    std::vector<std::vector<float>> matrix_;
};