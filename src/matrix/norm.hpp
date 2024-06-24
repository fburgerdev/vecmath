#pragma once
#include "alias.hpp"
#include "arithmetic.hpp"
#include <concepts> // std::floating_point

namespace Math {
    // floating
    using std::floating_point;

    // inner product
    template<typename T, address N, address M>
    auto inner(const Matrix<T, N, M>& mat1, const Matrix<T, N, M>& mat2) {
        T out = 0;
        for (address i = 0; i < N * M; ++i) {
            out += mat1.at(i) * mat2.at(i);
        }
        return out;
    }
    template<typename T, address N, address M>
    auto inner(const Matrix<T, N, M>& mat) {
        return inner(mat, mat);
    }
    // transposed matrix
    template<typename T, address N, address M>
    auto transpose(const Matrix<T, N, M>& mat) {
        Matrix<T, M, N> out;
        for (address n = 0; n < N; ++n) {
            for (address m = 0; m < N; ++m) {
                out.at(N * m + n) = mat.at(M * n + m);
            }
        }
        return out;
    }
    // norm
    template<floating_point T, address N, address M>
    auto norm(const Matrix<T, N, M>& mat) {
        return sqrt(inner(mat));
    }
    // normalize
    template<floating_point T, address N, address M>
    auto normalize(const Matrix<T, N, M>& mat) {
        return mat / norm(mat);
    }

    // vector specific operations
    // :: dot product
    template<typename T, address N>
    auto dot(const Vector<T, N>& vec1, const Vector<T, N>& vec2) {
        T out = 0;
        for (address n = 0; n < N; ++n) {
            out += vec1.at(n) * vec2.at(n);
        }
        return out;
    }
    template<typename T, address N>
    auto dot(const Vector<T, N>& v) {
        return dot(v, v);
    }
    // :: cross product
    template<typename T>
    auto cross(const Vec3<T>& v1, const Vec3<T>& v2) {
        return Vec3<T>(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
    }
    // :: length
    template<floating_point T, address N>
    auto length(const Vector<T, N>& v) {
        return sqrt(dot(v));
    }
    // :: distance
    template<floating_point T, address N>
    auto distance(const Vector<T, N>& v1, const Vector<T, N>& v2) {
        return length(v2 - v1);
    }
}