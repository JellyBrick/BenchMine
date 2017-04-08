#include "Vector2i.h"

#include "Vector2f.h"

Vector2i::Vector2i() : x(0), y(0) {}

Vector2i::Vector2i(int x, int y) : x(x), y(y) {}

Vector2i::Vector2i(int scalar) : x(scalar), y(scalar) {}

Vector2i& Vector2i::add(int value) {
	x += value;
	y += value;
	return *this;
}

Vector2i& Vector2i::add(const Vector2i& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vector2i& Vector2i::substract(int value) {
	x -= value;
	y -= value;
	return *this;
}

Vector2i& Vector2i::substract(const Vector2i& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2i& Vector2i::multiply(int value) {
	x *= value;
	y *= value;
	return *this;
}

Vector2i& Vector2i::multiply(const Vector2i& other) {
	x *= other.x;
	y *= other.y;
	return *this;
}

Vector2i& Vector2i::divide(int value) {
	x /= value;
	y /= value;
	return *this;
}

Vector2i& Vector2i::divide(const Vector2i& other) {
	x /= other.x;
	y /= other.y;
	return *this;
}

Vector2i Vector2i::operator+(int value) {
	return add(value);
}

Vector2i Vector2i::operator+(const Vector2i& other) {
	return add(other);
}

Vector2i Vector2i::operator-(int value) {
	return substract(value);
}

Vector2i Vector2i::operator-(const Vector2i& other) {
	return substract(other);
}

Vector2i Vector2i::operator*(int value) {
	return multiply(value);
}

Vector2i Vector2i::operator*(const Vector2i& other) {
	return multiply(other);
}

Vector2i Vector2i::operator/(int value) {
	return divide(value);
}

Vector2i Vector2i::operator/(const Vector2i& other) {
	return divide(other);
}

Vector2i& Vector2i::operator+=(const Vector2i& other) {
	return add(other);
}

Vector2i& Vector2i::operator-=(const Vector2i& other) {
	return substract(other);
}

Vector2i& Vector2i::operator*=(const Vector2i& other) {
	return multiply(other);
}

Vector2i& Vector2i::operator/=(const Vector2i& other) {
	return divide(other);
}

bool Vector2i::operator==(const Vector2i& other) const {
	return x == other.x &&  y == other.y;
}

bool Vector2i::operator!=(const Vector2i& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const Vector2i& vec) {
	stream << "Vector2i(" << vec.x << ", " << vec.y << ")";
	return stream;
}

Vector2i Vector2i::fromVector2f(const Vector2f& other) {
	return { static_cast<int>(other.x), static_cast<int>(other.y) };
}


void Vector2i::serialize(const Vector2i& vector, RakLib::ByteBuffer& byteBuffer) {
	byteBuffer.putInt(vector.x);
	byteBuffer.putInt(vector.y);
}

Vector2i Vector2i::deserialize(RakLib::ByteBuffer& byteBuffer) {
	return { byteBuffer.getInt(), byteBuffer.getInt() };
}