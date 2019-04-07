#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <tclap/CmdLine.h>

bool array_2d_contains_number(const std::vector<std::vector<long>>& array_2d, long number, size_t row_count, size_t column_count);

int main(int argc, char * * argv) {
    try {
        TCLAP::CmdLine cmd("Find Number in a 2D Array", ' ', "0.1");

        TCLAP::ValueArg<long> numberArg("n", "number", "The number of find in the input 2D array", true, 0, "long");
        TCLAP::ValueArg<size_t> rowArg("r", "rows", "Row of the 2D array", true, 0, "size_t");
        TCLAP::ValueArg<size_t> columnArg("c", "columns", "Column of the 2D array", true, 0," size_t");
        TCLAP::UnlabeledMultiArg<long> numbersArg("numbers", "Numbers in the 2D array", true, "long");

        cmd.add(numberArg);
        cmd.add(rowArg);
        cmd.add(columnArg);
        cmd.add(numbersArg);

        cmd.parse(argc, argv);

        const long number = numberArg.getValue();
        const size_t rows = rowArg.getValue();
        const size_t columns = columnArg.getValue();
        const std::vector<long> numbers = numbersArg.getValue();

        assert(numbers.size() == rows * columns);

        std::vector<std::vector<long>> array_2d;
        array_2d.reserve(rows);

        for (int row = 0; row < rows; row ++) {
            std::vector<long> array;
            array.reserve(columns);
            for (int column = 0; column < columns; column ++) {
                array.push_back(numbers[row * columns + column]);
            }
            array_2d.push_back(array);
        }

        if (array_2d_contains_number(array_2d, number, rows, columns)) {
            std::cout << "Contains: " << number << "." << std::endl;
        } else {
            std::cout << "Does not contains: " << number << "." << std::endl;
        }

    } catch (TCLAP::ArgException &e) {
        std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
    }

    return 0;
}

bool array_2d_contains_number(
        const std::vector<std::vector<long>>& array_2d,
        const long number,
        const size_t row_count,
        const size_t column_count
    )
{
    assert(array_2d.size() == row_count);
    for (size_t row = 0; row < row_count; row ++) {
        assert(array_2d[row].size() == column_count);
    }

    size_t row(0);

    size_t column(std::max((size_t)0, column_count - 1));

    while (row < row_count && column >= 0) {
        auto evaluated_number = array_2d[row][column];

        if (evaluated_number == number) {
            return true;
        } else if (evaluated_number > number) {
            column -= 1;
        } else if (evaluated_number < number) {
            row += 1;
        }
    }

    return false;
}
