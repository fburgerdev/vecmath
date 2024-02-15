#include <iostream>
#include <sstream>
#include "constants.hpp"
#include "arithmetic.hpp"
#include "matrixstruct.hpp"
#include "matrixarithmetic.hpp"
#include "matrixfunc.hpp"
#include "matrixconstruct.hpp"
#include "matrixalias.hpp"
#include "vectorfunc.hpp"
#include "vectoralias.hpp"

namespace Math {
    template<typename T, address N, address M>
    string to_string(const Matrix<T, N, M>& mat) {
        std::stringstream sstream;
        sstream << "(";
        for (address n = 0; n < N; ++n) {
            sstream << "(";
            for (address m = 0; m < M; ++m) {
                sstream << mat.at(n, m);
                if (m + 1 < M) {
                    sstream << " ";
                }
            }
            sstream << ((n + 1 < N) ? ") " : ")");
        }
        sstream << ")";
        return sstream.str();
    }
    template<typename T, address N, address M>
    std::ostream& operator<<(std::ostream& stream, const Matrix<T, N, M>& mat) {
        return stream << to_string(mat);
    }
}