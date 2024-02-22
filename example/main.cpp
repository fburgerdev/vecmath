#include <iostream>
#include "to_string.hpp"

using namespace Math;
template<address N, address M>
void dosth(int (&&arr)[N][M]) {
    std::cout << N << std::endl;
}
int main() {
    Vec4f vec(1, 2, 3, 4);
    Mat4f mat({ 
        1, 2, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    });
    std::cout << "Hello World!" << std::endl;
    std::cout << transposed(mat) * mat<< std::endl;
    std::cout << dot(vec) << std::endl;
    return EXIT_SUCCESS;
}