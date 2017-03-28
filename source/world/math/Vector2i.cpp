#include "Vector2i.h"

Vector2i::Vector2i() {
	this->x = 0;
	this->y = 0;
}

Vector2i::Vector2i(int x, int y) {
	this->x = x;
	this->y = y;
}

Vector2i::Vector2i(int scalar) {
	this->x = this->y = scalar;
}

Vector2i& Vector2i::add(int value) {
	this->x += value;
	this->y += value;
	return *this;
}

Vector2i& Vector2i::add(const Vector2i& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vector2i& Vector2i::substract(int value) {
	this->x -= value;
	this->y -= value;
	return *this;
}

Vector2i& Vector2i::substract(const Vector2i& other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vector2i& Vector2i::multiply(int value) {
	this->x *= value;
	this->y *= value;
	return *this;
}

Vector2i& Vector2i::multiply(const Vector2i& other) {
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}

Vector2i& Vector2i::divide(int value) {
	this->x /= value;
	this->y /= value;
	return *this;
}

Vector2i& Vector2i::divide(const Vector2i& other) {
	this->x /= other.x;
	this->y /= other.y;
	return *this;
}

Vector2i Vector2i::operator+(int value) {
	return this->add(value);
}

Vector2i Vector2i::operator+(const Vector2i& other) {
	return this->add(other);
}

Vector2i Vector2i::operator-(int value) {
	return this->substract(value);
}

Vector2i Vector2i::operator-(const Vector2i& other) {
	return this->substract(other);
}

Vector2i Vector2i::operator*(int value) {
	return this->multiply(value);
}

Vector2i Vector2i::operator*(const Vector2i& other) {
	return this->multiply(other);
}

Vector2i Vector2i::operator/(int value) {
	return this->divide(value);
}

Vector2i Vector2i::operator/(const Vector2i& other) {
	return this->divide(other);
}

Vector2i& Vector2i::operator+=(const Vector2i& other) {
	return this->add(other);
}

Vector2i& Vector2i::operator-=(const Vector2i& other) {
	return this->substract(other);
}

Vector2i& Vector2i::operator*=(const Vector2i& other) {
	return this->multiply(other);
}

Vector2i& Vector2i::operator/=(const Vector2i& other) {
	return this->divide(other);
}

bool Vector2i::operator==(const Vector2i& other) const {
	return this->x == other.x &&  this->y == other.y;
}

bool Vector2i::operator!=(const Vector2i& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const Vector2i& vec) {
	stream << "Vector2i(" << vec.x << ", " << vec.y << ")";
	return stream;
}