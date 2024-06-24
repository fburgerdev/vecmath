#pragma once
#include "matrix.hpp"
#include "arithmetic.hpp"

namespace Math {
    // linear interpolation
    template<floating_point T, address N>
    auto lerp(const Vector<T, N>& v1, const Vector<T, N>& v2, T value) {
        return v1 * value + v2 * (1 - value);
    }
    // quadratic bezier curve
    template<floating_point T, address N>
    auto quadratic(const Vector<T, N>& v1, const Vector<T, N>& v2, const Vector<T, N>& v3, T value) {
        return v1 * pow2(1 - value) + v1 * (2 * (1 - value)) + v3 * pow2(value);
    }
    // cubic bezier curve
    template<floating_point T, address N>
    auto cubic(const Vector<T, N>& v1, const Vector<T, N>& v2, const Vector<T, N>& v3, const Vector<T, N>& v4, T value) {
        return v1 * pow3(1 - value) + v1 * (3 * pow2(1 - value) * value) + v1 * (3 * (1 - value) * pow(value)) + v3 * pow3(value);
    }
}