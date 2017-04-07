#include "Vector3i.h"

#include "Vector3f.h"

Vector3i::Vector3i() : x(0), y(0), z(0) {}

Vector3i::Vector3i(int scalar) : x(scalar), y(scalar), z(scalar) {}

Vector3i::Vector3i(int x, int y, int z) : x(x), y(y), z(z) {}

Vector3i& Vector3i::add(int value) {
	x += value;
	y += value;
	z += value;
	return *this;
}

Vector3i& Vector3i::add(const Vector3i& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3i& Vector3i::substract(int value) {
	x -= value;
	y -= value;
	z -= value;
	return *this;
}

Vector3i& Vector3i::substract(const Vector3i& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3i& Vector3i::multiply(int value) {
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Vector3i& Vector3i::multiply(const Vector3i& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	return *this;
}

Vector3i& Vector3i::divide(int value) {
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

Vector3i& Vector3i::divide(const Vector3i& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	return *this;
}

Vector3i Vector3i::operator+(int value) {
	return add(value);
}

Vector3i Vector3i::operator+(const Vector3i& other) {
	return add(other);
}

Vector3i Vector3i::operator-(int value) {
	return substract(value);
}

Vector3i Vector3i::operator-(const Vector3i& other) {
	return substract(other);
}

Vector3i Vector3i::operator*(int value) {
	return multiply(value);
}

Vector3i Vector3i::operator*(const Vector3i& other) {
	return multiply(other);
}

Vector3i Vector3i::operator/(int value) {
	return divide(value);
}

Vector3i Vector3i::operator/(const Vector3i& other) {
	return divide(other);
}

Vector3i& Vector3i::operator+=(const Vector3i& other) {
	return add(other);
}

Vector3i& Vector3i::operator-=(const Vector3i& other) {
	return substract(other);
}

Vector3i& Vector3i::operator*=(const Vector3i& other) {
	return multiply(other);
}

Vector3i& Vector3i::operator/=(const Vector3i& other) {
	return divide(other);
}

bool Vector3i::operator==(const Vector3i& other) const {
	return x == other.x &&  y == other.y && z == other.z;
}

bool Vector3i::operator!=(const Vector3i& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const Vector3i& vec) {
	stream << "Vector3i(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return stream;
}

Vector3i Vector3i::fromVector3f(const Vector3f& vec3f) {
	return { static_cast<int>(vec3f.x), static_cast<int>(vec3f.y), static_cast<int>(vec3f.z) };
}

void Vector3i::serialize(const Vector3i& vector, RakLib::ByteBuffer& byteBuffer) {
	byteBuffer.putInt(vector.x);
	byteBuffer.putInt(vector.y);
	byteBuffer.putInt(vector.z);
}

Vector3i Vector3i::deserialize(RakLib::ByteBuffer& byteBuffer) {
	return { byteBuffer.getInt(), byteBuffer.getInt(), byteBuffer.getInt() };
}