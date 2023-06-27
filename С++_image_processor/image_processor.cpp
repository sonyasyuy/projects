#include "parser.h"
#include "reader.h"
#include "writer.h"
#include "apply_filter.h"

int main(int argc, const char** argv) {
    try {
        std::vector<std::pair<std::string, std::vector<float>>> arguments =
            ParseCmdLine(argc, reinterpret_cast<const char**>(argv));
        Image input = ReadImage(argv[1]);
        FilterApplier applier(arguments);
        Image output = applier.Apply(input);
        WriteImage(output, argv[2]);
    } catch (const NoInputFilePath& e) {
        std::cout << e.what() << std::endl;
    } catch (const NoOutputFilePath& e) {
        std::cout << e.what() << std::endl;
    } catch (const NoAppliedFilters& e) {
        std::cout << e.what() << std::endl;
    } catch (const WrongArgumentSyntax& e) {
        std::cout << e.what() << std::endl;
    } catch (const WrongInputFilePath& e) {
        std::cout << e.what() << std::endl;
    } catch (const WrongFileFormat& e) {
        std::cout << e.what() << std::endl;
    } catch (const WrongBmpFormat& e) {
        std::cout << e.what() << std::endl;
    } catch (const WrongFilterName& e) {
        std::cout << e.what() << std::endl;
    } catch (const WrongAmountOfFilterArguments& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error happened." << std::endl;
    }
    return 0;
}