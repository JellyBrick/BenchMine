#include "Vector3f.h"

#include "Vector3i.h"

Vector3f::Vector3f() : x(0), y(0), z(0) {}

Vector3f::Vector3f(float scalar) : x(scalar), y(scalar), z(scalar) {}

Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3f& Vector3f::add(float value) {
	x += value;
	y += value;
	z += value;
	return *this;
}

Vector3f& Vector3f::add(const Vector3f& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3f& Vector3f::substract(float value) {
	x -= value;
	y -= value;
	z -= value;
	return *this;
}

Vector3f& Vector3f::substract(const Vector3f& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3f& Vector3f::multiply(float value) {
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Vector3f& Vector3f::multiply(const Vector3f& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	return *this;
}

Vector3f& Vector3f::divide(float value) {
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

Vector3f& Vector3f::divide(const Vector3f& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	return *this;
}

Vector3f Vector3f::operator+(float value) {
	return add(value);
}

Vector3f Vector3f::operator+(const Vector3f& other) {
	return add(other);
}

Vector3f Vector3f::operator-(float value) {
	return substract(value);
}

Vector3f Vector3f::operator-(const Vector3f& other) {
	return substract(other);
}

Vector3f Vector3f::operator*(float value) {
	return multiply(value);
}

Vector3f Vector3f::operator*(const Vector3f& other) {
	return multiply(other);
}

Vector3f Vector3f::operator/(float value) {
	return divide(value);
}

Vector3f Vector3f::operator/(const Vector3f& other) {
	return divide(other);
}

Vector3f& Vector3f::operator+=(const Vector3f& other) {
	return add(other);
}

Vector3f& Vector3f::operator-=(const Vector3f& other) {
	return substract(other);
}

Vector3f& Vector3f::operator*=(const Vector3f& other) {
	return multiply(other);
}

Vector3f& Vector3f::operator/=(const Vector3f& other) {
	return divide(other);
}

bool Vector3f::operator==(const Vector3f& other) const {
	return x == other.x &&  y == other.y && z == other.z;
}

bool Vector3f::operator!=(const Vector3f& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const Vector3f& vec) {
	stream << "Vector3f(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return stream;
}

Vector3f Vector3f::fromVector3i(const Vector3i& other) {
	return { (float)other.x, (float)other.y, (float)other.z };
}

void Vector3f::serialize(const Vector3f& vector, RakLib::ByteBuffer& byteBuffer) {
	byteBuffer.putFloat(vector.x);
	byteBuffer.putFloat(vector.y);
	byteBuffer.putFloat(vector.z);
}

Vector3f Vector3f::deserialize(RakLib::ByteBuffer& byteBuffer) {
	return { byteBuffer.getFloat(), byteBuffer.getFloat(), byteBuffer.getFloat() };
}