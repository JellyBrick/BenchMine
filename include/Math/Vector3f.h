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
#ifndef VECTOR3F_H_
#define VECTOR3F_H_

#include <ostream>

class Vector3f
{
public:
	float x, y, z;

public:
	Vector3f();
	Vector3f(float x, float y, float z);


	//Math functions
	Vector3f& add(float value);
	Vector3f& add(const Vector3f&);

	Vector3f& substract(float value);
	Vector3f& substract(const Vector3f&);

	Vector3f& multiply(float value);
	Vector3f& multiply(const Vector3f&);

	Vector3f& divide(float value);
	Vector3f& divide(const Vector3f&);

	Vector3f operator+(float);
	Vector3f operator+(const Vector3f&);

	Vector3f operator-(float);
	Vector3f operator-(const Vector3f&);

	Vector3f operator*(float);
	Vector3f operator*(const Vector3f&);

	Vector3f operator/(float);
	Vector3f operator/(const Vector3f&);

	Vector3f& operator+=(const Vector3f&);
	Vector3f& operator-=(const Vector3f&);
	Vector3f& operator*=(const Vector3f&);
	Vector3f& operator/=(const Vector3f&);

	bool operator==(const Vector3f&);
	bool operator!=(const Vector3f&);

	friend std::ostream& operator<<(std::ostream& stream, const Vector3f& vec);

};

#endif