#pragma once

#include <ostream>

#include <RakLib/network/ByteBuffer.h>

class Vector3i;
class Vector3f {
public:
	float x, y, z;

public:
	Vector3f();
	Vector3f(float scalar);
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

	bool operator==(const Vector3f&) const;
	bool operator!=(const Vector3f&) const;

	friend std::ostream& operator<<(std::ostream& stream, const Vector3f& vec);

	static Vector3f fromVector3i(const Vector3i& other);

	static void serialize(const Vector3f& vector, RakLib::ByteBuffer& byteBuffer);

	static Vector3f deserialize(RakLib::ByteBuffer& byteBuffer);
};