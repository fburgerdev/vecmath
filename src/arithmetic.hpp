#pragma once
#include "common.hpp"

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