/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Vec2.inl
Author: Jemin.Shin
Creation date: 2022/03/23
-----------------------------------------------------------------*/
#include "Vec2.h"

namespace math
{

	inline constexpr vec2 vec2::operator+=(const vec2& v1) noexcept
	{
		x += v1.x;
		y += v1.y;
		return *this;
	}

	inline constexpr vec2 math::vec2::operator+(const vec2& v1) noexcept
	{
		return { x + v1.x, y + v1.y };
	}
	inline constexpr vec2 vec2::operator-=(const vec2& v1) noexcept
	{
		x -= v1.x;
		y -= v1.y;
		return *this;
	}

	inline constexpr vec2 vec2::operator*=(const vec2& v1) noexcept
	{

		return *this = *this * v1;
	}

	inline constexpr vec2 vec2::operator*=(const double Num) noexcept
	{

		return *this = *this * Num;
	}

	inline constexpr vec2 vec2::operator/=(const vec2& v1) noexcept
	{
		return *this = *this / v1;
	}

	inline constexpr vec2 vec2::operator/=(const double Num) noexcept
	{
		return *this = *this / Num;
	}
	[[nodiscard]] inline constexpr double math::vec2::LengthSquared() noexcept
	{
		return (x * x + y * y);
	}

	[[nodiscard]] inline constexpr  vec2 vec2::Normalize() noexcept
	{
		return vec2(x / LengthSquared(), y / LengthSquared());
	}

	[[nodiscard]] inline constexpr vec2 math::operator-(const vec2& v1) noexcept
	{
		return vec2(v1.x * -1, v1.y * -1);
	}

	[[nodiscard]] inline constexpr bool math::operator==(const vec2& v1, const vec2& v2) noexcept
	{
		return math::is_equal(v1.x, v2.x) && math::is_equal(v1.y, v2.y);
	}

	[[nodiscard]] inline constexpr bool operator!=(const vec2& v1, const vec2& v2) noexcept
	{
		return !(math::is_equal(v1.x, v2.x) && math::is_equal(v1.y, v2.y));
	}
	[[nodiscard]] inline  constexpr vec2 math::operator+(const vec2& v1, const vec2& v2) noexcept
	{
		return vec2(v1.x + v2.x, v1.y + v2.y);
	}
	[[nodiscard]] inline constexpr vec2 math::operator-(const vec2& v1, const vec2& v2) noexcept
	{
		return vec2(v1.x - v2.x, v1.x - v2.x);
	}


	[[nodiscard]] inline  constexpr vec2 math::operator/(const vec2& v1, const vec2& v2) noexcept
	{
		return vec2(v1.x / v1.x, v2.y / v2.y);
	}
	[[nodiscard]] inline  constexpr vec2 math::operator/(const vec2& v1, const double Num) noexcept
	{
		return vec2(v1.x / Num, v1.y / Num);
	}

	[[nodiscard]] inline  constexpr vec2 math::operator*(const vec2& v1, const vec2& v2) noexcept
	{
		return vec2(v1.x * v1.x, v2.y * v2.y);
	}
	[[nodiscard]] inline constexpr vec2 math::operator*(const vec2& v1, const double Num) noexcept
	{
		return vec2(v1.x * Num, v1.y * Num);
	}

	[[nodiscard]] inline  constexpr vec2 math::operator*(const double Num, const vec2& v1) noexcept
	{
		return vec2(Num * v1.x, Num * v1.y);
	}

	//////////////////////////////////////////////////////////////////////

	inline constexpr ivec2 ivec2::operator+=(const ivec2& v1) noexcept
	{
		*this = *this + v1;
		return *this;
	}

	inline constexpr ivec2 ivec2::operator-=(const ivec2& v1) noexcept
	{
		*this = *this - v1;
		return *this;
	}

	inline constexpr ivec2 ivec2::operator*=(const ivec2& v1) noexcept
	{
		return *this = *this * v1;
	}

	inline constexpr ivec2 ivec2::operator*=(const int Num) noexcept
	{

		return *this = *this * Num;
	}




	inline constexpr ivec2 ivec2::operator/=(const ivec2& v1) noexcept
	{
		return *this = *this / v1;
	}

	inline constexpr ivec2 ivec2::operator/=(const int Num) noexcept
	{
		return *this = *this / Num;
	}



	[[nodiscard]] inline constexpr ivec2 math::operator-(const ivec2& v1) noexcept
	{
		return ivec2(-1 * v1.x, -1 * v1.y);
	}

	[[nodiscard]] inline constexpr bool math::operator==(const ivec2& v1, const ivec2& v2) noexcept
	{
		return math::is_equal(v1.x, v2.x) && math::is_equal(v1.y, v2.y);
	}

	[[nodiscard]] inline constexpr bool operator!=(const ivec2& v1, const ivec2& v2) noexcept
	{
		return !(math::is_equal(v1.x, v2.x) && math::is_equal(v1.y, v2.y));
	}
	[[nodiscard]] inline constexpr ivec2 math::operator+(const ivec2& v1, const ivec2& v2) noexcept
	{
		return ivec2(v1.x + v2.x, v1.x + v2.x);
	}
	[[nodiscard]] inline constexpr ivec2 math::operator-(const ivec2& v1, const ivec2& v2) noexcept
	{
		return ivec2(v1.x - v2.x, v1.x - v2.x);
	}

	[[nodiscard]] inline constexpr ivec2 math::operator/(const ivec2& v1, const ivec2& v2) noexcept
	{
		return ivec2(v1.x / v1.x, v2.y / v2.y);
	}
	[[nodiscard]] inline constexpr ivec2 math::operator/(const ivec2& v1, const double Num) noexcept
	{
		return ivec2(v1.x / static_cast<int>(Num), v1.y / static_cast<int>(Num));
	}

	[[nodiscard]] inline constexpr vec2 operator/(const double Num, const ivec2& v1) noexcept
	{
		return static_cast<vec2>(v1.x / Num, v1.y / Num);
	}

	inline constexpr ivec2 math::operator*(const ivec2& v1, const ivec2& v2) noexcept
	{
		return ivec2(v1.x * v1.x, v2.y * v2.y);
	}

	inline constexpr ivec2 math::operator*(const int Num, const ivec2& v1) noexcept
	{
		return ivec2(Num * v1.x, Num * v1.y);
	}

	inline constexpr ivec2 math::operator*(const ivec2& v1, const int Num) noexcept
	{
		return ivec2(v1.x * Num, v1.y * Num);
	}

	[[nodiscard]] inline constexpr math::ivec2::operator vec2() noexcept
	{
		return vec2(static_cast<double>(x), static_cast<double>(y));
	}

	[[nodiscard]] inline constexpr vec2 operator*(const double Num, const ivec2& v1) noexcept
	{
		return vec2(v1.x * Num, v1.y * Num);
	}

	[[nodiscard]] inline constexpr vec2 operator*(const ivec2& v1, const double Num) noexcept
	{
		return vec2(Num * v1.x, Num * v1.y);
	}



}
