#include "Vector2f.h"

#include "Vector2i.h"

Vector2f::Vector2f() : x(0), y(0) {}

Vector2f::Vector2f(float x, float y) : x(x), y(y) {}

Vector2f::Vector2f(float scalar) : x(scalar), y(scalar){}

Vector2f& Vector2f::add(float value) {
	x += value;
	y += value;
	return *this;
}

Vector2f& Vector2f::add(const Vector2f& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vector2f& Vector2f::substract(float value) {
	x -= value;
	y -= value;
	return *this;
}

Vector2f& Vector2f::substract(const Vector2f& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2f& Vector2f::multiply(float value) {
	x *= value;
	y *= value;
	return *this;
}

Vector2f& Vector2f::multiply(const Vector2f& other) {
	x *= other.x;
	y *= other.y;
	return *this;
}

Vector2f& Vector2f::divide(float value) {
	x /= value;
	y /= value;
	return *this;
}

Vector2f& Vector2f::divide(const Vector2f& other) {
	x /= other.x;
	y /= other.y;
	return *this;
}

Vector2f Vector2f::operator+(float value) {
	return add(value);
}

Vector2f Vector2f::operator+(const Vector2f& other) {
	return add(other);
}

Vector2f Vector2f::operator-(float value) {
	return substract(value);
}

Vector2f Vector2f::operator-(const Vector2f& other) {
	return substract(other);
}

Vector2f Vector2f::operator*(float value) {
	return multiply(value);
}

Vector2f Vector2f::operator*(const Vector2f& other) {
	return multiply(other);
}

Vector2f Vector2f::operator/(float value) {
	return divide(value);
}

Vector2f Vector2f::operator/(const Vector2f& other) {
	return divide(other);
}

Vector2f& Vector2f::operator+=(const Vector2f& other) {
	return add(other);
}

Vector2f& Vector2f::operator-=(const Vector2f& other) {
	return substract(other);
}

Vector2f& Vector2f::operator*=(const Vector2f& other) {
	return multiply(other);
}

Vector2f& Vector2f::operator/=(const Vector2f& other) {
	return divide(other);
}

bool Vector2f::operator==(const Vector2f& other) const {
	return x == other.x &&  y == other.y;
}

bool Vector2f::operator!=(const Vector2f& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const Vector2f& vec) {
	stream << "Vector2f(" << vec.x << ", " << vec.y << ")";
	return stream;
}

Vector2f Vector2f::fromVector2i(const Vector2i& other) {
	return { static_cast<float>(other.x), static_cast<float>(other.y ) };
}

void Vector2f::serialize(const Vector2f& vector, RakLib::ByteBuffer& byteBuffer) {
	byteBuffer.putFloat(vector.x);
	byteBuffer.putFloat(vector.y);
}

Vector2f Vector2f::deserialize(RakLib::ByteBuffer& byteBuffer) {
	return { byteBuffer.getFloat(), byteBuffer.getFloat() };
}