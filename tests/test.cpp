#include "common.hpp"
#include "vecmath.hpp"

using namespace Math;
int main() {
    cout << Math::atan(PI_HALFS) << endl;
    cout << Math::atan(-PI) << endl;
    cout << Math::abs(-2) << endl;
    cout << Math::tan(PI_HALFS) << endl;
    cout << Math::tan(PI) << endl;
    cout << Math::tan(3.f) << endl;
    cout << Math::asin(10.f) << endl;
    // cout < Math::abs("HALLO") << endl;
    cout << Math::sqrt(3.0f) << endl;
    cout << Math::ceil(3.5) << endl;
    cout << Math::max(1, 2, 41, -2, 1 , 241, 23)  << endl;
    cout << Math::min(10, 2, 41, -2, 1 , 241, 23)  << endl;

    cout << lerp(Vec2F(1, 1), Vec2F(0.5, 0), 0.5f);
    cout << RotationMatrix(Vec3F(0, 0, PI_HALFS)) << endl;
    cout << resize<8, 7>(normalize(Identity<float, 4>()).insert(Identity<int, 2>(), { 1, 0 })) << endl;
    cout << Identity<int, 4>() * 3.f << endl;
    cout << "Hello World!" << endl;
    return EXIT_SUCCESS;
}