#pragma once
#include "struct.hpp"

namespace Math {
    // negate
    template<typename T, address N, address M>
    auto operator-(const Matrix<T, N, M>& mat) {
        Matrix<T, N, M> out;
        for (address i = 0; i < N * M; ++i) {
            out.at(i) = -mat.at(i);
        }
        return out;
    }
    // add
    template<typename T, address N, address M>
    auto& operator+=(Matrix<T, N, M>& mat, const Matrix<T, N, M>& other) {
        for (address i = 0; i < N * M; ++i) {
            mat.at(i) += other.at(i);
        }
        return mat;
    }
    // subtract
    template<typename T, address N, address M>
    auto& operator-=(Matrix<T, N, M>& mat, const Matrix<T, N, M>& other) {
        for (address i = 0; i < N * M; ++i) {
            mat.at(i) -= other.at(i);
        }
        return mat;
    }
    // multiply (scalar)
    template<typename T, address N, address M>
    auto& operator*=(Matrix<T, N, M>& mat, auto scalar) {
        for (address i = 0; i < N * M; ++i) {
            mat.at(i) *= scalar;
        }
        return mat;
    }
    // divide (scalar)
    template<typename T, address N, address M>
    auto& operator/=(Matrix<T, N, M>& mat, auto scalar) {
        for (address i = 0; i < N * M; ++i) {
            mat.at(i) /= scalar;
        }
        return mat;
    }
    // sum
    template<typename T, address N, address M>
    auto operator+(const Matrix<T, N, M>& mat, const Matrix<T, N, M>& other) {
        Matrix<T, N, M> out(mat);
        out += other;
        return out;
    }
    // difference
    template<typename T, address N, address M>
    auto operator-(const Matrix<T, N, M>& mat, const Matrix<T, N, M>& other) {
        Matrix<T, N, M> out(mat);
        out -= other;
        return out;
    }
    // product (scalar)
    template<typename T, address N, address M>
    auto operator*(const Matrix<T, N, M>& mat, auto scalar) {
        Matrix<T, N, M> out(mat);
        out *= scalar;
        return out;
    }
    // quotient (scalar)
    template<typename T, address N, address M>
    auto operator/(const Matrix<T, N, M>& mat, auto scalar) {
        Matrix<T, N, M> out(mat);
        out /= scalar;
        return out;
    }
    
    // product (matrix)
    template<typename T, address N, address M, address L>
    auto operator*(const Matrix<T, N, M>& mat1, const Matrix<T, M, L>& mat2) {
        Matrix<T, N, L> out;
        for (address n = 0; n < N; ++n) {
            for (address l = 0; l < L; ++l) {
                for (address m = 0; m < M; ++m) {
                    out.at(n, l) += mat1.at(n, m) * mat2.at(m, l);
                }
            }
        }
        return out;
    }
    // multiply (matrix)
    template<typename T, address N>
    auto& operator*=(Matrix<T, N>& mat1, const Matrix<T, N>& mat2) {
        mat1 = mat1 * mat2;
        return mat1;
    }
}