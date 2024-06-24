#pragma once
#include "common.hpp"

namespace Math {
    // pi
    inline constexpr float PI = 3.1415926;
    inline constexpr float PI_HALFS = PI / 2;
    inline constexpr float TAU = 2 * PI;
    // deg
    inline constexpr float DEG_0 = 0;
    inline constexpr float DEG_90 = PI / 2;
    inline constexpr float DEG_180 = PI / 2;
    inline constexpr float DEG_270 = 5 * PI / 4;
    inline constexpr float DEG_360 = 2 * PI;
    // euler
    inline constexpr float EULER = 2.7182818;
    inline constexpr float EULER_HALFS = EULER / 2;
    // golden ratio
    inline constexpr float GOLDEN_RATIO = 1.618033;
}