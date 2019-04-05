#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <set>

#include "parse_numbers_from_args.h"

std::unique_ptr<std::set<long>> find_duplicate_numbers_in_array(std::vector<long>& numbers);

int main(int argc, char * * argv) {
    auto numbers = parse_numbers_from_args(argc, argv);

    auto duplicatedNumbers = find_duplicate_numbers_in_array(* numbers);

    for (auto &number: * duplicatedNumbers) {
        std::cout << "Duplicated number: " << number << std::endl;
    }

    return 0;
}

std::unique_ptr<std::set<long>> find_duplicate_numbers_in_array(std::vector<long>& numbers) {
    auto table = std::make_unique<std::unordered_map<long, int>>();

    auto duplicated_numbers = std::make_unique<std::set<long>>();

    for (auto &number: numbers) {
        auto number_iterator = table -> find(number);
        if (number_iterator == table -> cend()) {
            table -> emplace(number, 1);
        } else {
            duplicated_numbers -> insert(number);
        }
    }

    return duplicated_numbers;
}
