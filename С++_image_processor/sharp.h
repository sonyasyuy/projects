#include "filter.h"

class Sharp : public Filter {
public:
    Sharp(){};
    Image Apply(const Image &image) const override;
};