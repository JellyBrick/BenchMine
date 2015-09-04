/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* @author InusualZ
*
*
*/

#ifndef VECTOR2F_H_
#define VECTOR2F_H_

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

#endif