#include "Vector2f.h"

#include "Vector2i.h"

Vector2f::Vector2f() {
	this->x = 0;
	this->y = 0;
}

Vector2f::Vector2f(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2f::Vector2f(float scalar) {
	this->x = this->y = scalar;
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

bool Vector2f::operator==(const Vector2f& other) const {
	return this->x == other.x &&  this->y == other.y;
}

bool Vector2f::operator!=(const Vector2f& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const Vector2f& vec) {
	stream << "Vector2f(" << vec.x << ", " << vec.y << ")";
	return stream;
}

Vector2f Vector2f::fromVector2i(const Vector2i& other) {
	return { (int)other.x, (int)other.y };
}

void Vector2f::serialize(const Vector2f& vector, RakLib::ByteBuffer& byteBuffer) {
	byteBuffer.putFloat(vector.x);
	byteBuffer.putFloat(vector.y);
}

Vector2f Vector2f::deserialize(RakLib::ByteBuffer& byteBuffer) {
	return { byteBuffer.getFloat(), byteBuffer.getFloat() };
}

