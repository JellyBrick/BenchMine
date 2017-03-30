#include "Vector3i.h"

#include "Vector3f.h"

Vector3i::Vector3i() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3i::Vector3i(int scalar) {
	this->x = this->y = this->z = 0;
}

Vector3i::Vector3i(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3i& Vector3i::add(int value) {
	this->x += value;
	this->y += value;
	this->z += value;
	return *this;
}

Vector3i& Vector3i::add(const Vector3i& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

Vector3i& Vector3i::substract(int value) {
	this->x -= value;
	this->y -= value;
	this->z -= value;
	return *this;
}

Vector3i& Vector3i::substract(const Vector3i& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

Vector3i& Vector3i::multiply(int value) {
	this->x *= value;
	this->y *= value;
	this->z *= value;
	return *this;
}

Vector3i& Vector3i::multiply(const Vector3i& other) {
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
	return *this;
}

Vector3i& Vector3i::divide(int value) {
	this->x /= value;
	this->y /= value;
	this->z /= value;
	return *this;
}

Vector3i& Vector3i::divide(const Vector3i& other) {
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
	return *this;
}

Vector3i Vector3i::operator+(int value) {
	return this->add(value);
}

Vector3i Vector3i::operator+(const Vector3i& other) {
	return this->add(other);
}

Vector3i Vector3i::operator-(int value) {
	return this->substract(value);
}

Vector3i Vector3i::operator-(const Vector3i& other) {
	return this->substract(other);
}

Vector3i Vector3i::operator*(int value) {
	return this->multiply(value);
}

Vector3i Vector3i::operator*(const Vector3i& other) {
	return this->multiply(other);
}

Vector3i Vector3i::operator/(int value) {
	return this->divide(value);
}

Vector3i Vector3i::operator/(const Vector3i& other) {
	return this->divide(other);
}

Vector3i& Vector3i::operator+=(const Vector3i& other) {
	return this->add(other);
}

Vector3i& Vector3i::operator-=(const Vector3i& other) {
	return this->substract(other);
}

Vector3i& Vector3i::operator*=(const Vector3i& other) {
	return this->multiply(other);
}

Vector3i& Vector3i::operator/=(const Vector3i& other) {
	return this->divide(other);
}

bool Vector3i::operator==(const Vector3i& other) const {
	return this->x == other.x &&  this->y == other.y && this->z == other.z;
}

bool Vector3i::operator!=(const Vector3i& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const Vector3i& vec) {
	stream << "Vector3i(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return stream;
}

Vector3i Vector3i::fromVector3f(const Vector3f& vec3f) {
	return { ((int)vec3f.x, (int)vec3f.y, (int)vec3f.z) };
}

void Vector3i::serialize(const Vector3i& vector, RakLib::ByteBuffer& byteBuffer) {
	byteBuffer.putInt(vector.x);
	byteBuffer.putInt(vector.y);
	byteBuffer.putInt(vector.z);
}

Vector3i Vector3i::deserialize(RakLib::ByteBuffer& byteBuffer) {
	return { byteBuffer.getInt(), byteBuffer.getInt(), byteBuffer.getInt() };
}