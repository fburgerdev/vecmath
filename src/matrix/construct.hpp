#pragma once
#include "struct.hpp"
#include "arithmetic.hpp"

namespace Math {
    // identity matrix
    template<typename T, address N>
    auto Identity() {
        Matrix<T, N, N> out;
        for (address n = 0; n < N; ++n) {
            out.at(n, n) = (T)1;
        }
        return out;
    }
    // insert matrix
    template<typename T, address N, address M>
    template<typename U, address N2, address M2>
    auto Matrix<T, N, M>::insert(const Matrix<U, N2, M2>& value, const Matrix<address, 2, 1>& where) {
        for (address n = 0; n < min(N - where.x, N2); ++n) {
            for (address m = 0; m < min(M - where.y, M2); ++m) {
                at(where.x + n, where.y + m) = (T)value.at(n, m);
            }
        }
        return *this;
    }
    template<typename T>
    template<typename U, address N2, address M2>
    auto Matrix<T, 2, 1>::insert(const Matrix<U, N2, M2>& value, const Matrix<address, 2, 1>& where) {
        for (address n = 0; n < min(2 - where.x, N2); ++n) {
            for (address m = 0; m < min(1 - where.y, M2); ++m) {
                at(where.x + n, where.y + m) = (T)value.at(n, m);
            }
        }
        return *this;
    }
    template<typename T>
    template<typename U, address N2, address M2>
    auto Matrix<T, 3, 1>::insert(const Matrix<U, N2, M2>& value, const Matrix<address, 2, 1>& where) {
        for (address n = 0; n < min(3 - where.x, N2); ++n) {
            for (address m = 0; m < min(1 - where.y, M2); ++m) {
                at(where.x + n, where.y + m) = (T)value.at(n, m);
            }
        }
        return *this;
    }
    template<typename T>
    template<typename U, address N2, address M2>
    auto Matrix<T, 4, 1>::insert(const Matrix<U, N2, M2>& value, const Matrix<address, 2, 1>& where) {
        for (address n = 0; n < min(4 - where.y, N2); ++n) {
            for (address m = 0; m < min(1 - where.x, M2); ++m) {
                at(where.y + n, where.x + m) = (T)value.at(n, m);
            }
        }
        return *this;
    }
    // resize matrix
    template<address N2, address M2, typename T, address N, address M>
    auto resize(const Matrix<T, N, M>& mat) {
        Matrix<T, N2, M2> out;
        out.insert(mat, { 0, 0 });
        return out;
    }
}