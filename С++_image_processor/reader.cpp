#include "reader.h"
#include "exceptions.h"

template <typename T>
void Read(std::ifstream &input, T &variable) {
    input.read(reinterpret_cast<char *>(&variable), sizeof(variable));
}

void Skip(std::ifstream &input, int32_t bytes_amount) {
    input.seekg(bytes_amount, std::ios::cur);
}

Image ReadImage(const std::string &path) {
    std::ifstream input(path, std::ios::in | std::ios::binary);
    uint32_t size = 0;
    uint32_t offset = 0;
    if (input.is_open()) {
        char file_type_1 = 0;
        char file_type_2 = 0;
        Read(input, file_type_1);
        Read(input, file_type_2);
        if (file_type_1 != 'B' or file_type_2 != 'M') {
            throw WrongFileFormat();
        }
        Read(input, size);
        Skip(input, 4);
        Read(input, offset);
        Skip(input, 4);
        int32_t width = 0;
        int32_t height = 0;
        Read(input, width);
        Read(input, height);
        Skip(input, 2);
        uint16_t bits_per_pixel = 0;
        Read(input, bits_per_pixel);
        const int format = 24;
        if (bits_per_pixel != format) {
            throw WrongBmpFormat();
        }
        input.seekg(offset, std::ios::beg);
        size_t padding_length = PaddingLength(width);
        Image read_file(std::abs(height), width);
        for (size_t i = 0; i < std::abs(height); ++i) {
            for (size_t j = 0; j < static_cast<size_t>(width); ++j) {
                Pixel pixel;
                Read(input, pixel.blue_);
                Read(input, pixel.green_);
                Read(input, pixel.red_);
                if (height > 0) {
                    read_file.SetPixel(i, j, pixel);
                } else {
                    read_file.SetPixel(std::abs(height) - i - 1, j, pixel);
                }
            }
            Skip(input, static_cast<int32_t>(padding_length));
        }
        input.close();
        return read_file;
    } else {
        throw WrongInputFilePath();
    }
}