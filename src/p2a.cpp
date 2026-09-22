#include "p2a.h"

int main() {
    assert(morton3d(1,1,1) == 7);
    assert(morton3d(1,2,4) == 273); // holy moly this actually works I did it
}