#pragma once
#include "common.hpp"

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