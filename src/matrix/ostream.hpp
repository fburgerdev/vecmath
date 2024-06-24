#pragma once
#include "struct.hpp"

namespace Math {
    // ostream << matrix
    template <typename T, address N, address M>
    std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& mat) {
        // lines
        string lines[N];
        string numbers[N];
        for (address j = 0; j < M; ++j) {
            // numbers
            for (address i = 0; i < N; ++i) {
                numbers[i] = std::to_string(mat.at(i, j));
            }
            // max
            address max = 0;
            for (address i = 0; i < N; ++i) {
                max = max < numbers[i].size() ? numbers[i].size() : max;
            }
            // padding
            for (address i = 0; i < N; ++i) {
                lines[i].push_back('|');
                for (address j = 0; j < (max - numbers[i].size() + 1) / 2; ++j) {
                    lines[i].push_back(' ');
                }
                lines[i] += numbers[i];
                for (address j = 0; j < (max - numbers[i].size()) / 2; ++j) {
                    lines[i].push_back(' ');
                }
            }
        }
        // stream
        os << '\n';
        for (address i = 0; i < N; ++i) {
            os << lines[i] << '|' << '\n';
        }
        return os;
    }
}