#pragma once

#include <ostream>

class Vector3f;

class Vector3i {
public:
	int x, y, z;

public:
	Vector3i();
	Vector3i(int scalar);
	Vector3i(int x, int y, int z);


	//Math functions
	Vector3i& add(int value);
	Vector3i& add(const Vector3i&);

	Vector3i& substract(int value);
	Vector3i& substract(const Vector3i&);

	Vector3i& multiply(int value);
	Vector3i& multiply(const Vector3i&);

	Vector3i& divide(int value);
	Vector3i& divide(const Vector3i&);

	Vector3i operator+(int);
	Vector3i operator+(const Vector3i&);

	Vector3i operator-(int);
	Vector3i operator-(const Vector3i&);

	Vector3i operator*(int);
	Vector3i operator*(const Vector3i&);

	Vector3i operator/(int);
	Vector3i operator/(const Vector3i&);

	Vector3i& operator+=(const Vector3i&);
	Vector3i& operator-=(const Vector3i&);
	Vector3i& operator*=(const Vector3i&);
	Vector3i& operator/=(const Vector3i&);

	bool operator==(const Vector3i&) const;
	bool operator!=(const Vector3i&) const;

	friend std::ostream& operator<<(std::ostream& stream, const Vector3i& vec);

	static Vector3i fromVector3f(const Vector3f& vec3f);
};