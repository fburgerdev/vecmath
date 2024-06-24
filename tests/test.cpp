#include "common.hpp"
#include "vecmath.hpp"

using namespace Math;
int main() {
    cout << lerp(Vec2f(1, 1), Vec2f(0.5, 0), 0.5f);
    cout << RotationMatrix(Vec3f(0, 0, PI_HALFS)) << endl;
    cout << resize<8, 7>(normalize(Identity<float, 4>()).insert(Identity<int, 2>(), { 1, 0 })) << endl;
    cout << Identity<int, 4>() * 3.f << endl;
    cout << "Hello World!" << endl;
    return EXIT_SUCCESS;
}