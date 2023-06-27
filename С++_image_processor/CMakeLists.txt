add_executable(
    image_processor
    image_processor.cpp
        writer.h writer.cpp sharp.h sharp.cpp reader.h reader.cpp picture.cpp parser.h parser.cpp negative.h negative.cpp matrix.cpp grayscale.h grayscale.cpp exceptions.cpp edge.h edge.cpp crop.h crop.cpp blur.h blur.cpp apply_filter.h apply_filter.cpp)