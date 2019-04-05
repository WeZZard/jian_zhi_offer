#include "parse_numbers_from_args.h"

std::unique_ptr<std::vector<long>> parse_numbers_from_args(int argc, char * * argv) {
    auto numbers = std::make_unique<std::vector<long>>();
    numbers -> reserve(static_cast<size_t>(argc));

    char * end = nullptr;

    for (int i = 0; i < argc; i ++) {
        char * potential_numbers = argv[i];

        auto number = std::strtol(potential_numbers, &end, 10);

        if (number == 0) {
            if ((potential_numbers)[0] == '0' && (potential_numbers)[1] == '\0') {
                numbers -> push_back(0);
            } else {
                // do nothing
            }
        } else {
            numbers -> push_back(number);
        }
    }

    return numbers;
}