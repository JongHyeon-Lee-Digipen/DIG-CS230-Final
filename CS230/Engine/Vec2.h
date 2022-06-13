/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Vec2.h
Author: Jemin.Shin
Creation date: 2022/03/23
-----------------------------------------------------------------*/
#pragma once
#include <cmath>
#include <limits>


namespace math
{
    [[nodiscard]] constexpr double abs(double d) noexcept { return (d < 0.0) ? -d : d; }

    [[nodiscard]] constexpr bool is_equal(double d1, double d2) noexcept
    {
        return abs(d1 - d2) <= std::numeric_limits<double>::epsilon() * abs(d1 + d2);
    }

    [[nodiscard]] constexpr bool is_equal(int i1, int i2) noexcept { return i1 == i2; }

    struct vec2
    {

        double x{}, y{};
        constexpr vec2() noexcept = default;
        constexpr explicit vec2(double value) noexcept
            : x(value), y(value) {}
        constexpr vec2(double x_value, double y_value) noexcept
            :x(x_value), y(y_value) {}

        constexpr vec2 operator+=(const vec2& v1)noexcept;
        constexpr vec2 operator+(const vec2& v1)noexcept;
        constexpr vec2 operator-=(const vec2& v1)noexcept;

        constexpr vec2 operator*=(const vec2& v1)noexcept;
        constexpr vec2 operator*=(const double Num) noexcept;

        constexpr vec2 operator/=(const vec2& v1)noexcept;
        constexpr vec2 operator/=(const double Num)noexcept;

        constexpr double LengthSquared() noexcept;
        constexpr vec2 Normalize() noexcept;
    };
    [[nodiscard]] constexpr bool operator==(const vec2& v1, const vec2& v2) noexcept;
    [[nodiscard]] constexpr bool operator!=(const vec2& v1, const vec2& v2) noexcept;
    [[nodiscard]] constexpr vec2 operator+(const vec2& v1, const vec2& v2) noexcept;
    [[nodiscard]] constexpr vec2 operator-(const vec2& v1) noexcept;
    [[nodiscard]] constexpr vec2 operator-(const vec2& v1, const vec2& v2) noexcept;
    [[nodiscard]] constexpr vec2 operator/(const vec2& v1, const vec2& v2) noexcept;
    [[nodiscard]] constexpr vec2 operator/(const vec2& v1, const double Num) noexcept;
    [[nodiscard]] constexpr vec2 operator*(const vec2& v1, const vec2& v2) noexcept;
    [[nodiscard]] constexpr vec2 operator*(const vec2& v1, const double Num) noexcept;
    [[nodiscard]] constexpr vec2 operator*(const  double Num, const vec2& v1) noexcept;

    struct ivec2
    {
        int x{}, y{};
        constexpr ivec2() noexcept = default;
        constexpr explicit ivec2(int value) noexcept
            : x(value), y(value) {}

        constexpr ivec2(int x_value, int  y_value) noexcept
            :x(x_value), y(y_value) {}

        constexpr ivec2 operator+=(const ivec2& v1)noexcept;
        constexpr ivec2 operator-=(const ivec2& v1)noexcept;
        constexpr ivec2 operator*=(const ivec2& v1)noexcept;
        constexpr ivec2 operator*=(const int Num) noexcept;

        constexpr ivec2 operator/=(const ivec2& v1)noexcept;
        constexpr ivec2 operator/=(const int Num)noexcept;

        constexpr operator vec2() noexcept;
    };
    [[nodiscard]] constexpr bool operator==(const ivec2& v1, const ivec2& v2) noexcept;
    [[nodiscard]] constexpr bool operator!=(const ivec2& v1, const ivec2& v2) noexcept;
    [[nodiscard]] constexpr ivec2 operator+(const ivec2& v1, const ivec2& v2) noexcept;
    [[nodiscard]] constexpr ivec2 operator-(const ivec2& v1) noexcept;
    [[nodiscard]] constexpr ivec2 operator-(const ivec2& v1, const ivec2& v2) noexcept;
    [[nodiscard]] constexpr ivec2 operator/(const ivec2& v1, const ivec2& v2) noexcept;
    [[nodiscard]] constexpr ivec2 operator/(const ivec2& v1, const double Num) noexcept;
   // [[nodiscard]] constexpr vec2 operator/(const double Num, const ivec2& v1) noexcept;
    [[nodiscard]] constexpr ivec2 operator*(const ivec2& v1, const ivec2& v2) noexcept;
    [[nodiscard]] constexpr ivec2 operator*(const int Num, const ivec2& v1) noexcept;
    [[nodiscard]] constexpr ivec2 operator*(const ivec2& v1, const int Num) noexcept;

    [[nodiscard]] constexpr vec2 operator*(const double Num, const ivec2& v1) noexcept;
    [[nodiscard]] constexpr vec2 operator*(const ivec2& v1, const double Num) noexcept;


}

#include "Vec.inl"
