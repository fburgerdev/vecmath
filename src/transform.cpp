#include "transform.hpp"
#include "arithmetic.hpp"

namespace Math {
    // translate, rotate, scale
    Mat4f translate(Vec3f translate) {
        return Mat4f({
            0, 0, 0, translate.x,
            0, 0, 0, translate.y,
            0, 0, 0, translate.z,
            0, 0, 0, 1
        });
    }
    Mat4f rotate(Vec3f rotation) {
        Mat4f out;
        float sina = sin(rotation.y);
        float cosa = cos(rotation.y);
        float sinb = sin(rotation.x);
        float cosb = cos(rotation.x);
        float sinc = sin(rotation.z);
        float cosc = cos(rotation.z);

        out.at(0, 0) = cosa * cosc + sina * sinc * sinb;
        out.at(0, 1) = cosa * sinc - sina * sinb * cosc;
        out.at(0, 2) = sina * cosb;

        out.at(1, 0) = -sinc * cosb;
        out.at(1, 1) = cosb * cosc;
        out.at(1, 2) = sinb;

        out.at(2, 0) = -sina * cosc + cosa * sinc * sinb;
        out.at(2, 1) = -sina * sinc - cosa * sinb * cosc;
        out.at(2, 2) = cosa * cosb;

        out.at(3, 3) = 1;
        return out;
    }
    Mat4f scale(Vec3f scale) {
        return Mat4f({
            scale.x, 0, 0, 0,
            0, scale.y, 0, 0,
            0, 0, scale.z, 0,
            0, 0, 0, 1
        });
    }
}