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

#include "Math\Vector3f.h"

Vector3f::Vector3f()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3f::Vector3f(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3f& Vector3f::add(float value)
{
	this->x += value;
	this->y += value;
	this->z += value;
	return *this;
}

Vector3f& Vector3f::add(const Vector3f& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

Vector3f& Vector3f::substract(float value)
{
	this->x -= value;
	this->y -= value;
	this->z -= value;
	return *this;
}

Vector3f& Vector3f::substract(const Vector3f& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

Vector3f& Vector3f::multiply(float value)
{
	this->x *= value;
	this->y *= value;
	this->z *= value;
	return *this;
}

Vector3f& Vector3f::multiply(const Vector3f& other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
	return *this;
}

Vector3f& Vector3f::divide(float value)
{
	this->x /= value;
	this->y /= value;
	this->z /= value;
	return *this;
}

Vector3f& Vector3f::divide(const Vector3f& other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
	return *this;
}

Vector3f Vector3f::operator+(float value)
{
	return this->add(value);
}

Vector3f Vector3f::operator+(const Vector3f& other)
{
	return this->add(other);
}

Vector3f Vector3f::operator-(float value)
{
	return this->substract(value);
}

Vector3f Vector3f::operator-(const Vector3f& other)
{
	return this->substract(other);
}

Vector3f Vector3f::operator*(float value)
{
	return this->multiply(value);
}

Vector3f Vector3f::operator*(const Vector3f& other)
{
	return this->multiply(other);
}

Vector3f Vector3f::operator/(float value)
{
	return this->divide(value);
}

Vector3f Vector3f::operator/(const Vector3f& other)
{
	return this->divide(other);
}

Vector3f& Vector3f::operator+=(const Vector3f& other)
{
	return this->add(other);
}

Vector3f& Vector3f::operator-=(const Vector3f& other)
{
	return this->substract(other);
}

Vector3f& Vector3f::operator*=(const Vector3f& other)
{
	return this->multiply(other);
}

Vector3f& Vector3f::operator/=(const Vector3f& other)
{
	return this->divide(other);
}

bool Vector3f::operator==(const Vector3f& other)
{
	return this->x == other.x &&  this->y == other.y && this->z == other.z;
}

bool Vector3f::operator!=(const Vector3f& other)
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const Vector3f& vec)
{
	stream << "Vector3f(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return stream;
}