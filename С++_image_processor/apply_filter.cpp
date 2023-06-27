#include "apply_filter.h"

void FilterApplier::Apply(const Image& image) {
    for (const auto& [filter_name, filter_args] : arguments_) {
        if (filter_name == "-crop") {
            if (filter_args.size() != static_cast<size_t>(2)) {
                throw WrongAmountOfFilterArguments(filter_name, 2);
            }
            Crop filter(static_cast<int32_t>(filter_args[0]), static_cast<int32_t>(filter_args[0]));
            filter.Apply(image);
        } else if (filter_name == "-edge") {
            if (filter_args.size() != static_cast<size_t>(1)) {
                throw WrongAmountOfFilterArguments(filter_name, 1);
            }
            Edge filter(static_cast<int32_t>(filter_args[0]));
            filter.Apply(image);
        } else if (filter_name == "-blur") {
            if (filter_args.size() != static_cast<size_t>(1)) {
                throw WrongAmountOfFilterArguments(filter_name, 1);
            }
            GaussianBlur filter(filter_args[0]);
            filter.Apply(image);
        } else if (filter_name == "-gs") {
            if (filter_args.size() != static_cast<size_t>(0)) {
                throw WrongAmountOfFilterArguments(filter_name, 0);
            }
            Grayscale filter;
            filter.Apply(image);
        } else if (filter_name == "-neg") {
            if (filter_args.size() != static_cast<size_t>(0)) {
                throw WrongAmountOfFilterArguments(filter_name, 0);
            }
            Negative filter;
            filter.Apply(image);
        } else if (filter_name == "-sharp") {
            if (filter_args.size() != static_cast<size_t>(0)) {
                throw WrongAmountOfFilterArguments(filter_name, 0);
            }
            Sharp filter;
            filter.Apply(image);
        } else {
            throw WrongFilterName(filter_name);
        }
    }
}