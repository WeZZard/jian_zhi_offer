#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char * * argv) {
    if (argc == 0) {
        std::cout << "You must give the file name of the input 2D array." << std::endl;
        return 1;
    }

    auto path = argv[0];

    std::ofstream input_file;
    input_file.open (path);

    if (input_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            std::cout << line << '\n';
        }
        input_file.close();
    } else {
        std::cout << "File: \"" << path << "\" open failed." << std::endl;
    }

    return 0;
}