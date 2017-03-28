#pragma once

#include <ostream>

class Vector2i {
public:
	int x, y;

public:
	Vector2i();
	Vector2i(int scalar);
	Vector2i(int x, int y);


	//Math functions
	Vector2i& add(int value);
	Vector2i& add(const Vector2i&);

	Vector2i& substract(int value);
	Vector2i& substract(const Vector2i&);

	Vector2i& multiply(int value);
	Vector2i& multiply(const Vector2i&);

	Vector2i& divide(int value);
	Vector2i& divide(const Vector2i&);

	Vector2i operator+(int);
	Vector2i operator+(const Vector2i&);

	Vector2i operator-(int);
	Vector2i operator-(const Vector2i&);

	Vector2i operator*(int);
	Vector2i operator*(const Vector2i&);

	Vector2i operator/(int);
	Vector2i operator/(const Vector2i&);

	Vector2i& operator+=(const Vector2i&);
	Vector2i& operator-=(const Vector2i&);
	Vector2i& operator*=(const Vector2i&);
	Vector2i& operator/=(const Vector2i&);

	bool operator==(const Vector2i&) const;
	bool operator!=(const Vector2i&) const;

	friend std::ostream& operator<<(std::ostream& stream, const Vector2i& vec);
};
