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
    auto numbers_count = numbers.size();

    for (int i = 0; i < numbers_count; i++) {
        while (numbers[i] != i && numbers[i] != numbers[numbers[i]]) {
            auto indexed_number = numbers[i];
            numbers[i] = numbers[indexed_number];
            numbers[indexed_number] = indexed_number;
        }
    }

    auto duplicated_numbers = std::make_unique<std::set<long>>();

    for (int i = 0; i < numbers_count; i++) {
        if (numbers[i] != i) {
            duplicated_numbers -> insert(numbers[i]);
        }
    }

    return duplicated_numbers;
}
