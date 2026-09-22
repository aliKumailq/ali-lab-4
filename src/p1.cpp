#include <vector>
#include <random>
#include "timer.h"
#include <utility>
#include <cassert>
#include <iostream>

constexpr uint64_t ROW_SIZE = 4000;
constexpr uint64_t COLUMN_SIZE = 4000;
constexpr uint64_t MATRIX_SIZE = ROW_SIZE * COLUMN_SIZE;
using time_val = std::pair<uint64_t, uint64_t>;

void fill_matrix_row_major(std::vector<uint64_t>& matrix) {

    std::mt19937_64 rand_numb(0);
    for (uint64_t i = 0; i < ROW_SIZE; ++i) { // for each row
        for (uint64_t j = 0; j < COLUMN_SIZE; ++j) {
                matrix.at(ROW_SIZE * i + j) = rand_numb();
        }

    }
}


void fill_matrix_column_major(std::vector<uint64_t>& matrix) {
    std::mt19937_64 rand_numb(0);
    for (uint64_t j = 0; j < COLUMN_SIZE; ++j) {
        for (uint64_t i = 0; i < ROW_SIZE; ++i) {
             matrix.at(ROW_SIZE * i + j) = rand_numb();
        }
    }
}


time_val sum_matrix_row_order(std::vector<uint64_t>& matrix) {
    uint64_t sum = 0;
    Timer clock;
    for (uint64_t i = 0; i < ROW_SIZE; ++i) { // for each row
        for (uint64_t j = 0; j < COLUMN_SIZE; ++j) {
                sum += matrix.at(ROW_SIZE * i + j);
        }

    }

    auto time = clock.click<Timer::Micros>();
    return time_val(time, sum);
}


time_val sum_matrix_column_order(std::vector<uint64_t>& matrix) {

    uint64_t sum = 0;

    Timer clock;
    for (uint64_t j = 0; j < COLUMN_SIZE; ++j) {
        for (uint64_t i = 0; i < ROW_SIZE; ++i) {
            sum += matrix[ROW_SIZE * i + j];
        }
    }
    auto time = clock.click<Timer::Micros>();
    return time_val(time, sum);
}


int main() { 

    std::vector<uint64_t> row_major_matrix(MATRIX_SIZE, 0);
    fill_matrix_row_major(row_major_matrix);
    auto row_major_time = sum_matrix_row_order(row_major_matrix);
    row_major_matrix.clear();
    row_major_matrix.shrink_to_fit();


    std::vector<uint64_t> column_major_matrix(MATRIX_SIZE, 0);
    fill_matrix_column_major(column_major_matrix);
    auto column_major_time = sum_matrix_column_order(column_major_matrix);
    column_major_matrix.clear();
    column_major_matrix.shrink_to_fit();


    assert(row_major_time.second == column_major_time.second);

    auto print_results = [](const time_val& val) -> void {
        std::cout << val.first << " " << val.second << "\n";

    };

    print_results(row_major_time);
    print_results(column_major_time);

    
    
    
    
    }
