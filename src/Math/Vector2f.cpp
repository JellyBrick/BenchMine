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

#include "Math\Vector2f.h"

Vector2f::Vector2f() {
	this->x = 0;
	this->y = 0;
}

Vector2f::Vector2f(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2f& Vector2f::add(float value) {
	this->x += value;
	this->y += value;
	return *this;
}

Vector2f& Vector2f::add(const Vector2f& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vector2f& Vector2f::substract(float value) {
	this->x -= value;
	this->y -= value;
	return *this;
}

Vector2f& Vector2f::substract(const Vector2f& other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vector2f& Vector2f::multiply(float value) {
	this->x *= value;
	this->y *= value;
	return *this;
}

Vector2f& Vector2f::multiply(const Vector2f& other) {
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}

Vector2f& Vector2f::divide(float value) {
	this->x /= value;
	this->y /= value;
	return *this;
}

Vector2f& Vector2f::divide(const Vector2f& other) {
	this->x /= other.x;
	this->y /= other.y;
	return *this;
}

Vector2f Vector2f::operator+(float value) {
	return this->add(value);
}

Vector2f Vector2f::operator+(const Vector2f& other) {
	return this->add(other);
}

Vector2f Vector2f::operator-(float value) {
	return this->substract(value);
}

Vector2f Vector2f::operator-(const Vector2f& other) {
	return this->substract(other);
}

Vector2f Vector2f::operator*(float value) {
	return this->multiply(value);
}

Vector2f Vector2f::operator*(const Vector2f& other) {
	return this->multiply(other);
}

Vector2f Vector2f::operator/(float value) {
	return this->divide(value);
}

Vector2f Vector2f::operator/(const Vector2f& other) {
	return this->divide(other);
}

Vector2f& Vector2f::operator+=(const Vector2f& other) {
	return this->add(other);
}

Vector2f& Vector2f::operator-=(const Vector2f& other) {
	return this->substract(other);
}

Vector2f& Vector2f::operator*=(const Vector2f& other) {
	return this->multiply(other);
}

Vector2f& Vector2f::operator/=(const Vector2f& other) {
	return this->divide(other);
}

bool Vector2f::operator==(const Vector2f& other) {
	return this->x == other.x &&  this->y == other.y;
}

bool Vector2f::operator!=(const Vector2f& other) {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const Vector2f& vec) {
	stream << "Vector2f(" << vec.x << ", " << vec.y << ")";
	return stream;
}