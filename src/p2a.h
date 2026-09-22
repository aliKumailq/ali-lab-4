#include <vector>
#include <random>
#include <utility>
#include <cassert>
#include <iostream>

inline uint64_t morton3d(uint64_t x, uint64_t y, uint64_t z) {
    uint64_t answer = 0;

    auto kth = [](const uint64_t& val, const uint64_t& k) -> uint64_t {
        return (val >> k) & 1 ;

    };

    for (uint64_t i = 0; i < 64 ; ++i) {
        auto micro_answer = kth(x, i) | (kth(y,i) << 1) | (kth(z,i) << 2);
                        // ith bit of x in least sig position
                        // ith bit of z in most sig position
        answer = answer | (micro_answer << 3 * i); // shifting it left to put it in its proper spot in final answer
        
        // thank god I took 229

    } return answer;
}