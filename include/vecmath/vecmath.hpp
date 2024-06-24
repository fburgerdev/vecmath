#pragma once
// #include <...> (HPPMERGE)
#include <ranges>
#include <memory>
#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include <set>
#include <unordered_map>
#include <functional>
#include <optional>
#include <iostream>
#include <concepts>


// #include "common.hpp" (HPPMERGE)
namespace Math {
    // ranges
    namespace stdr = std::ranges;

    // types
    // types :: address
    using address = std::size_t;
    // types :: int
    using int8 = std::int8_t;
    using int16 = std::int16_t;
    using int32 = std::int32_t;
    using int64 = std::int64_t;
    // types :: uint
    using uint8 = std::uint8_t;
    using uint16 = std::uint16_t;
    using uint32 = std::uint32_t;
    using uint64 = std::uint64_t;
    // types :: string
    using string = std::string;
    using string_view = std::string_view;

    // container
    // container :: sequential
    template<typename T, address N>
    using Array = std::array<T, N>;
    template<typename T>
    using List = std::vector<T>;
    template<typename T>
    using Stack = std::stack<T>;
    template<typename T>
    using Queue = std::queue<T>;
    template<typename T>
    using Deque = std::deque<T>;
    // container :: tree
    template<typename T>
    using Set = std::set<T>;
    template<typename Key, typename Value>
    using Map = std::map<Key, Value>;
    // container :: hash
    template<typename T>
    using HashSet = std::unordered_set<T>;
    template<typename Key, typename Value>
    using HashMap = std::unordered_map<Key, Value>;

    // move semantics
    using std::forward;
    using std::move;

    // smart pointers
    using std::make_unique;
    using std::make_shared;
    using std::unique_ptr;
    using std::shared_ptr;
    using std::weak_ptr;

    // function
    using std::function;

    // templates
    template<typename T>
    using Opt = std::optional<T>;

    // debug
    using std::cout;
    using std::endl;
}

// #include "constants.hpp" (HPPMERGE)
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

// #include "arithmetic.hpp" (HPPMERGE)
namespace Math {
    // abs
    int8 abs(int8 x);
    int16 abs(int16 x);
    int32 abs(int32 x);
    int64 abs(int64 x);
    float abs(float x);
    double abs(double x);
    
    // sqrt
    float sqrt(float x);
    double sqrt(double x);

    // trig
    // :: sin
    float sin(float x);
    double sin(double x);
    // :: cos
    float cos(float x);
    double cos(double x);
    // :: tan
    float tan(float x);
    double tan(double x);
    // :: asin
    float asin(float x);
    double asin(double x);
    // :: acos
    float acos(float x);
    double acos(double x);
    // :: atan
    float atan(float x);
    double atan(double x);

    // exp / log
    // :: exp
    float exp(float x);
    double exp(double x);
    // :: ln
    float ln(float x);
    double ln(double x);
    // :: log2
    float log2(float x);
    double log2(double x);
    // :: log10
    float log10(float x);
    double log10(double x);
    // :: pow
    float pow(float base, float exponent);
    double pow(double base, double exponent);
    // :: pow2
    float pow2(float x);
    double pow2(double x);
    // :: pow3
    float pow3(float x);
    double pow3(double x);
    // :: pow4
    float pow4(float x);
    double pow4(double x);

    // max / min
    template<typename T1, typename T2, typename... TRest>
    auto max(const T1& val1, const T2& val2, const TRest&&... rest) {
        if constexpr(sizeof...(TRest) == 0) {
            return val1 < val2 ? val2 : val1;
        }
        else {
            return max(val1 < val2 ? val2 : val1, rest...);
        }
    }
    template<typename T1, typename T2, typename... TRest>
    auto min(const T1& val1, const T2& val2, const TRest&&... rest) {
        if constexpr(sizeof...(TRest) == 0) {
            return val2 < val1 ? val2 : val1;
        }
        else {
            return max(val2 < val1 ? val2 : val1, rest...);
        }
    }
}

// #include "struct.hpp" (HPPMERGE)
namespace Math {
    // Matrix
    template<typename T, address N, address M = N>
    class Matrix {
    public:
        // constructor
        Matrix() {
            for (address i = 0; i < N * M; ++i) {
                m_Data[i] = (T)0;
            } 
        }
        Matrix(T (&values)[N * M]) {
            for (address i = 0; i < N * M; ++i) {
                m_Data[i] = values[i];
            }
        }
        Matrix(T (&&values)[N * M]) {
            for (address i = 0; i < N * M; ++i) {
                m_Data[i] = values[i];
            }
        }
        Matrix(T (&values)[N][M]) {
            for (address n = 0; n < N; ++n) {
                for (address m = 0; m < M; ++m) {
                    m_Data[M * n + m] = values[n][m];
                }
            }
        }
        Matrix(T (&&values)[N][M]) {
            for (address n = 0; n < N; ++n) {
                for (address m = 0; m < M; ++m) {
                    m_Data[M * n + m] = values[n][m];
                }
            }
        }
        template<typename U>
        Matrix(const Matrix<U, N, M>& mat) {
            for (address i = 0; i < N * M; ++i) {
                m_Data[i] = (T)mat.at(i);
            }
        }
        // access
        // :: at
        T& at(address index) {
            return m_Data[index];
        }
        const T& at(address index) const {
            return m_Data[index];
        }
        T& at(address n, address m) {
            return m_Data[M * n + m];
        }
        const T& at(address n, address m) const {
            return m_Data[M * n + m];
        }
        // :: operator[]
        T& operator[](address index) {
            return at(index);
        }
        const T& operator[](address index) const {
            return at(index);
        }
        // :: data
        T* data() {
            return m_Data;
        }
        const T* data() const {
            return m_Data;
        }
        // insert
        template<typename U, address N2, address M2>
        auto insert(const Matrix<U, N2, M2>& value, const Matrix<address, 2, 1>& where);
    private:
        // data
        T m_Data[N * M];
    };
    // Matrix 2 x 1
    template<typename T>
    class Matrix<T, 2, 1> {
    public:
        // constructor
        Matrix()
            : Matrix((T)0) {}
        Matrix(T value)
            : Matrix(value, value) {}
        Matrix(T x, T y)
            : x(x), y(y) {}
        template<typename U>
        Matrix(const Matrix<U, 2, 1>& vec)
            : Matrix((T)vec.at(0), (T)vec.at(1)) {}
        // access
        // :: at
        T& at(address index) {
            return index == 0 ? x : y;
        }
        const T& at(address index) const {
            return index == 0 ? x : y;
        }
        T& at(address n, address m) {
            return at(n);
        }
        const T& at(address n, address m) const {
            return at(n);
        }
        // :: operator[]
        T& operator[](address index) {
            return at(index);
        }
        const T& operator[](address index) const {
            return at(index);
        }
        // insert
        template<typename U, address N2, address M2>
        auto insert(const Matrix<U, N2, M2>& value, const Matrix<address, 2, 1>& where);
        // values
        T x, y;
    };
    // Matrix 3 x 1
    template<typename T>
    class Matrix<T, 3, 1> {
    public:
        // constructor
        Matrix()
            : Matrix((T)0) {}
        Matrix(T value)
            : Matrix(value, value, value) {}
        Matrix(T x, T y, T z)
            : x(x), y(y), z(z) {}
        Matrix(const Matrix<T, 2, 1>& xy, T z)
            : Matrix(xy.x, xy.y, z) {}
        Matrix(T x, const Matrix<T, 2, 1>& yz)
            : Matrix(x, yz.x, yz.y) {}
        template<typename U>
        Matrix(const Matrix<U, 3, 1>& vec)
            : Matrix((T)vec.at(0), (T)vec.at(1), (T)vec.at(2)) {}
        // access
        // :: at
        T& at(address index) {
            return index == 0 ? x : (index == 1 ? y : z);
        }
        const T& at(address index) const {
            return index == 0 ? x : (index == 1 ? y : z);
        }
        T& at(address n, address m) {
            return at(n);
        }
        const T& at(address n, address m) const {
            return at(n);
        }
        // :: operator[]
        T& operator[](address index) {
            return at(index);
        }
        const T& operator[](address index) const {
            return at(index);
        }
        // insert
        template<typename U, address N2, address M2>
        auto insert(const Matrix<U, N2, M2>& value, const Matrix<address, 2, 1>& where);
        // values
        T x, y, z;
    };
    // Matrix 4 x 1
    template<typename T>
    class Matrix<T, 4, 1> {
    public:
        // constructor
        Matrix()
            : Matrix((T)0) {}
        Matrix(T value)
            : Matrix(value, value, value, value) {}
        Matrix(T x, T y, T z, T w)
            : x(x), y(y), z(z), w(w) {}
        Matrix(const Matrix<T, 2, 1>& xy, T z, T w)
            : Matrix(xy.x, xy.y, z, w) {}
        Matrix(T x, const Matrix<T, 2, 1>& yz, T w)
            : Matrix(x, yz.x, yz.y, w) {}
        Matrix(T x, T y, const Matrix<T, 2, 1>& zw)
            : Matrix(x, y, zw.x, zw.y) {}
        Matrix(const Matrix<T, 2, 1>& xy, const Matrix<T, 2, 1>& yz)
            : Matrix(xy.x, xy.y, yz.x, yz.y) {}
        Matrix(const Matrix<T, 3, 1>& xyz, T w)
            : Matrix(xyz.x, xyz.y, xyz.z, w) {}
        Matrix(T x, const Matrix<T, 3, 1>& yzw)
            : Matrix(x, yzw.x, yzw.y, yzw.z) {}
        template<typename U>
        Matrix(const Matrix<U, 4, 1>& vec)
            : Matrix((T)vec.at(0), (T)vec.at(1), (T)vec.at(2), (T)vec.at(3)) {}
        // access
        // :: at
        T& at(address index) {
            return index == 0 ? x : (index == 1 ? y : (index == 2 ? z : w));
        }
        const T& at(address index) const {
            return index == 0 ? x : (index == 1 ? y : (index == 2 ? z : w));
        }
        T& at(address n, address m) {
            return at(n);
        }
        const T& at(address n, address m) const {
            return at(n);
        }
        // :: operator[]
        T& operator[](address index) {
            return at(index);
        }
        const T& operator[](address index) const {
            return at(index);
        }
        // insert
        template<typename U, address N2, address M2>
        auto insert(const Matrix<U, N2, M2>& value, const Matrix<address, 2, 1>& where);
        // values
        T x, y, z, w;
    };
}

// #include "construct.hpp" (HPPMERGE)
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

// #include "operator.hpp" (HPPMERGE)
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

// #include "alias.hpp" (HPPMERGE)
namespace Math {
    // generic
    template<typename T>
    using Mat2 = Matrix<T, 2>;
    template<typename T>
    using Mat3 = Matrix<T, 3>;
    template<typename T>
    using Mat4 = Matrix<T, 4>;
    template<typename T>
    using Mat2x3 = Matrix<T, 2, 3>;
    template<typename T>
    using Mat2x4 = Matrix<T, 2, 4>;
    template<typename T>
    using Mat3x2 = Matrix<T, 3, 2>;
    template<typename T>
    using Mat3x4 = Matrix<T, 3, 4>;
    template<typename T>
    using Mat4x2 = Matrix<T, 4, 2>;
    template<typename T>
    using Mat4x3 = Matrix<T, 4, 3>;
    // float
    using Mat2f = Mat2<float>;
    using Mat3f = Mat3<float>;
    using Mat4f = Mat4<float>;
    using Mat2x3f = Mat2x3<float>;
    using Mat2x4f = Mat2x4<float>;
    using Mat3x2f = Mat3x2<float>;
    using Mat3x4f = Mat3x4<float>;
    using Mat4x2f = Mat4x2<float>;
    using Mat4x3f = Mat4x3<float>;
    // double
    using Mat2d = Mat2<double>;
    using Mat3d = Mat3<double>;
    using Mat4d = Mat4<double>;
    using Mat2x3d = Mat2x3<double>;
    using Mat2x4d = Mat2x4<double>;
    using Mat3x2d = Mat3x2<double>;
    using Mat3x4d = Mat3x4<double>;
    using Mat4x2d = Mat4x2<double>;
    using Mat4x3d = Mat4x3<double>;
    // int
    using Mat2i = Mat2<int>;
    using Mat3i = Mat3<int>;
    using Mat4i = Mat4<int>;
    using Mat2x3i = Mat2x3<int>;
    using Mat2x4i = Mat2x4<int>;
    using Mat3x2i = Mat3x2<int>;
    using Mat3x4i = Mat3x4<int>;
    using Mat4x2i = Mat4x2<int>;
    using Mat4x3i = Mat4x3<int>;
    // uint
    using Mat2u = Mat2<uint>;
    using Mat3u = Mat3<uint>;
    using Mat4u = Mat4<uint>;
    using Mat2x3u = Mat2x3<uint>;
    using Mat2x4u = Mat2x4<uint>;
    using Mat3x2u = Mat3x2<uint>;
    using Mat3x4u = Mat3x4<uint>;
    using Mat4x2u = Mat4x2<uint>;
    using Mat4x3u = Mat4x3<uint>;

    // vector alias
    // :: generic
    template<typename T, address N>
    using Vector = Matrix<T, N, 1>;
    template<typename T>
    using Vec2 = Vector<T, 2>;
    template<typename T>
    using Vec3 = Vector<T, 3>;
    template<typename T>
    using Vec4 = Vector<T, 4>;
    // :: float
    using Vec2f = Vec2<float>;
    using Vec3f = Vec3<float>;
    using Vec4f = Vec4<float>;
    // :: double
    using Vec2d = Vec2<double>;
    using Vec3d = Vec3<double>;
    using Vec4d = Vec4<double>;
    // :: int
    using Vec2i = Vec2<int32>;
    using Vec3i = Vec3<int32>;
    using Vec4i = Vec4<int32>;
    // :: uint
    using Vec2u = Vec2<uint32>;
    using Vec3u = Vec3<uint32>;
    using Vec4u = Vec4<uint32>;
}

// #include "norm.hpp" (HPPMERGE)
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

// #include "ostream.hpp" (HPPMERGE)
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

// #include "3d.hpp" (HPPMERGE)
namespace Math {
    // translate
    template<floating_point T>
    auto TranslationMatrix(Vec3<T> translation) {
        return Mat4<T>({
            1, 0, 0, translation.x,
            0, 1, 0, translation.y,
            0, 0, 1, translation.z,
            0, 0, 0, 1
        });
    }
    // rotate
    template<floating_point T>
    auto RotationMatrix(Vec3<T> euler_rotation) {
        Mat3<T> mat;
        // sin / cos
        T sinx = sin(euler_rotation.x);
        T cosx = cos(euler_rotation.x);
        T siny = sin(euler_rotation.y);
        T cosy = cos(euler_rotation.y);
        T sinz = sin(euler_rotation.z);
        T cosz = cos(euler_rotation.z);
        // roll -> pitch -> yaw (ccw)
        mat.at(0, 0) = cosy * cosz - sinx * siny * sinz;
        mat.at(0, 1) = sinx * siny * cosz + cosy * sinz;
        mat.at(0, 2) = -cosx * siny;
        mat.at(1, 0) = -cosx * sinz;
        mat.at(1, 1) = cosx * cosz;
        mat.at(1, 2) = sinx;
        mat.at(2, 0) = siny * cosz + sinx * cosy * sinz;
        mat.at(2, 1) = -sinx * cosy * cosz + siny * sinz;
        mat.at(2, 2) = cosx * cosy;
        return mat;
    }
    // scale
    template<floating_point T>
    auto ScaleMatrix(Vec3<T> scale) {
        return Mat3<T>({
            scale.x, 0, 0,
            0, scale.y, 0,
            0, 0, scale.z,
        });
    }

    // world space -> camera space
    template<floating_point T>
    auto ModelMatrix(Vec3<T> position, Vec3<T> rotation, Vec3<T> scale) {
        Mat4<T> out;
        out.insert(ScaleMatrix(scale) * RotationMatrix(rotation), { 0, 0 });
        out.insert(Vec4<T>(position, 1), { 3, 0 });
        return out;
    }
    // camera space -> local space
    template<floating_point T>
    auto ViewMatrix(Vec3<T> position, Vec3<T> rotation) {
        Mat4<T> out;
        out.insert(transpose(RotationMatrix(rotation)), { 0, 0 });
        out.insert(Vec4<T>(-position, 1), { 3, 0 });
        return out;
    }
    // local space -> clip space (OPENGL specific)
    template<floating_point T>
    auto PerspectiveMatrix(Vec2<T> zRange, T FoV, T aspect_ratio) {
        Mat4<T> mat;
        // clip x, y
        mat.at(0, 0) = 1.0 / tan(FoV / 2);
        mat.at(1, 1) = -aspect_ratio / tan(FoV / 2); // (negation is OPENGL specific since y-axis is inverted)
        // clip z to [-1, 1] (OPENGL specific)
        mat.at(2, 2) = 2 * zRange.y / (zRange.y - zRange.x) - 1;
        mat.at(2, 3) = -2 * zRange.x * zRange.y / (zRange.y - zRange.x);
        mat.at(3, 2) = 1;
        return mat;
    }
}

// #include "curves.hpp" (HPPMERGE)
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