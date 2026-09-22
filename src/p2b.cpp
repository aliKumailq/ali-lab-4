#include <vector>
#include <random>
#include "p2a.h"

constexpr uint64_t X = 256;
constexpr uint64_t Y = 256;
constexpr uint64_t Z = 256;
constexpr uint64_t SIZE = X * Y * Z;


inline uint64_t coord(uint64_t x, uint64_t y, uint64_t z) {
    return z*(X*Y) + y*X + x;

}

inline uint64_t coordK(uint64_t x, uint64_t y, uint64_t z) {
    return z*(4*4) + y*4 + x;

}






inline void fill_row_matrix(std::vector<uint64_t>& shape) {
    std::mt19937_64 rand_numb(0);
    for (uint64_t z = 0; z < Z; ++z) {
        for (uint64_t y = 0; y < Y; ++y) {
            for (uint64_t x = 0; x < X; ++x) {
                shape.at(coord(x,y,z)) = rand_numb();
            }
        }
    }

}

inline void copy_matrix_to_morton(const std::vector<uint64_t>& row, std::vector<uint64_t>& morton_vec) {
    for (uint64_t z = 0; z < Z; ++z) {
        for (uint64_t y = 0; y < Y; ++y) {

            for (uint64_t x = 0; x < X; ++x) {
                morton_vec.at(morton3d(x,y,z)) = row.at(coord(x,y,z));
            }
        }
    }

}

inline std::vector<uint64_t> row_kernal() {
    std::vector<uint64_t> kernal(64,0);
    for (uint64_t z = 0; z < 4; ++z) {
        for (uint64_t y = 0; y < 4; ++y) {
            for (uint64_t x = 0; x < 4; ++x) {
                kernal.at(coordK(x,y,z)) = x + y + z;
            }
        }
    } return kernal;
}

inline std::vector<uint64_t> morton_kernal() {
    std::vector<uint64_t> kernal(64,0);
    for (uint64_t z = 0; z < 4; ++z) {
        for (uint64_t y = 0; y < 4; ++y) {
            for (uint64_t x = 0; x < 4; ++x) {
                kernal.at(morton3d(x,y,z)) = x + y + z;
            }
        }
    } return kernal;
}

inline void convolution_row_order(std::vector<uint64_t> row, std::vector<uint64_t> kernal, std::vector<uint64_t> conv) {
    for (uint64_t i = 0; i < 4 ; ++i) {
        for (uint64_t iz = i * Z; iz < (i * Z) + Z ; ++iz) {

            for (uint64_t j = 0; j < 4; ++j) {
                for (uint64_t jy = j * Y; jy < (j*Y) + Y; ++jy ) {

                    for (uint64_t t = 0; t < 4; ++t) {
                        for (uint64_t tx = t * X; tx < t*X + X; ++tx) {
                            
                        }
                    }
                }
            }
        }

    }
}



int main() { 
    std::vector<uint64_t> row_major(SIZE,0);
    fill_row_matrix(row_major);
    std::vector<uint64_t> morton_vec(SIZE,0);
    copy_matrix_to_morton(row_major, morton_vec);
    auto rKernal = row_kernal();
    auto mKernal = morton_kernal();


    
    
    return 0; }
