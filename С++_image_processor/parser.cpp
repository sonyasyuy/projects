#include "parser.h"

Parameters ParseCmdLine(int argc, const char* argv[]) {
    Parser parser(argc, argv);
    return parser.ParseLine();
}

void PrintInfo() {
    std::cout << "Справка о формате входных данных:\n\n"
                 "{имя программы} {путь к входному файлу} {путь к выходному файлу} [-{имя фильтра 1} [параметр фильтра "
                 "1] [параметр фильтра 2] ...] [-{имя фильтра 2} [параметр фильтра 1] [параметр фильтра 2] ...] ...\n\n"
              << std::endl;
}

Parameters Parser::ParseLine() {
    Parameters output;
    if (argc_ == 1) {
        PrintInfo();
        std::cout << "\n" << std::endl;
        throw NoInputFilePath();
    } else if (argc_ == 2) {
        throw NoOutputFilePath();
    } else if (argc_ == 3) {
        PrintInfo();
        std::cout << " " << std::endl;
        throw NoAppliedFilters();
    } else {
        pos_ = 3;
        while (pos_ < argc_) {
            std::string command = argv_[pos_];
            if (command.find("-") != std::string::npos) {
                std::vector<float> float_arguments;
                ++pos_;
                while (pos_ < argc_ && std::string(argv_[pos_]).find("-") == std::string::npos) {
                    std::string argument = argv_[pos_];
                    float_arguments.push_back(std::stof(argument));
                    ++pos_;
                }
                output.push_back(std::make_pair(command, float_arguments));
            } else {
                throw WrongArgumentSyntax();
            }
        }
    }
    return output;
}