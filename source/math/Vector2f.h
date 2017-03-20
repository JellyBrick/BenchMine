#pragma once

#include <ostream>

class Vector2f
{
public:
	float x, y;

public:
	Vector2f();
	Vector2f(float x, float y);


	//Math functions
	Vector2f& add(float value);
	Vector2f& add(const Vector2f&);

	Vector2f& substract(float value);
	Vector2f& substract(const Vector2f&);

	Vector2f& multiply(float value);
	Vector2f& multiply(const Vector2f&);

	Vector2f& divide(float value);
	Vector2f& divide(const Vector2f&);

	Vector2f operator+(float);
	Vector2f operator+(const Vector2f&);

	Vector2f operator-(float);
	Vector2f operator-(const Vector2f&);

	Vector2f operator*(float);
	Vector2f operator*(const Vector2f&);

	Vector2f operator/(float);
	Vector2f operator/(const Vector2f&);

	Vector2f& operator+=(const Vector2f&);
	Vector2f& operator-=(const Vector2f&);
	Vector2f& operator*=(const Vector2f&);
	Vector2f& operator/=(const Vector2f&);

	bool operator==(const Vector2f&);
	bool operator!=(const Vector2f&);

	friend std::ostream& operator<<(std::ostream& stream, const Vector2f& vec);

};
