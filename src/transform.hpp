#pragma once
#include "matrixalias.hpp"
#include "vectoralias.hpp"

namespace Math {
    // translate, rotate, scale
    Mat4f translate(Vec3f translate);
    Mat4f rotate(Vec3f rotation);
    Mat4f scale(Vec3f scale);
}