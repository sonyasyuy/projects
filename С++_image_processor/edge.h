#include "filter.h"

class Edge : public Filter {
public:
    explicit Edge(const int32_t& threshold) : threshold_(threshold){};
    Image Apply(const Image& image) const override;

private:
    int32_t threshold_;
};