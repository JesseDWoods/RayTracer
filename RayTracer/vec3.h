#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
private:
	float e[3];
public:

	vec3() {
		e[0] = 0.0;
		e[1] = 0.0;
		e[2] = 0.0;
	}
	vec3(float e0, float e1, float e2) {
		e[0] = e0;
		e[1] = e1;
		e[2] = e2;
	}
	inline float x() const {
		return e[0];
	}
	inline float y() const {
		return e[1];
	}
	inline float z() const {
		return e[2];
	}
	inline float r() const {
		return e[0];
	}
	inline float g() const {
		return e[1];
	}
	inline float b() const {
		return e[2];
	}
	inline const vec3& operator+() const {
		return *this;
	}
	inline vec3 operator-() const {
		return vec3(-e[0], -e[1], -e[2]);
	}
	inline float operator[](int a) const {
		return e[a];
	}
	inline float& operator[](int a) {
		return e[a];
	}

	inline vec3& operator+=(const vec3& v2);
	inline vec3& operator-=(const vec3& v2);
	inline vec3& operator*=(const vec3& v2);
	inline vec3& operator/=(const vec3& v2);
	inline vec3& operator*=(const float t);
	inline vec3& operator/=(const float t);

	inline float length() const {
		return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	}
	inline float squared_length() const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}
	inline void make_unit_vector();
};

inline std::istream& operator>>(std::istream& is, vec3& t) {
	is >> t[0] >> t[1] >> t[2];
	return is;
}
inline std::ostream& operator<<(std::ostream& os, const vec3& t) {
	os << t[0] << " " << t[1] << " " << t[2];
	return os;
}
inline void vec3::make_unit_vector() {
	float k = float(1.0 / this->length());
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}
inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
	return vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}
inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
	return vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}
inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
	return vec3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}
inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
	return vec3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}
inline vec3 operator*(float a, const vec3 &v1) {
	return vec3(v1[0] * a, v1[1] * a, v1[2] * a);
}
inline vec3 operator/(vec3 &v1, float a) {
	return vec3(v1[0] / a, v1[1] / a, v1[2] / a);
}
inline vec3 operator*(const vec3 &v1, float a) {
	return vec3(v1[0] * a, v1[1] * a, v1[2] * a);
}
inline float dot(const vec3 &v1, const vec3 &v2) {
	return (v1[0] * v2[0]) + (v1[1] * v2[1]) + (v1[2] * v2[2]);
}
inline vec3 cross(const vec3 &v1, const vec3 &v2) {
	return vec3((v1[1] * v2[2]) - (v1[2] * v2[1]), (v1[0] * v2[2]) - (v1[2] * v2[0]), (v1[0] * v2[1]) - (v1[1] * v2[0]));
}
inline vec3& vec3::operator+=(const vec3 &v) {
	e[0] += v[0];
	e[1] += v[1];
	e[2] += v[2];
	return *this;
}
inline vec3& vec3::operator-=(const vec3 &v) {
	e[0] -= v[0];
	e[1] -= v[1];
	e[2] -= v[2];
	return *this;
}
inline vec3& vec3::operator*=(const vec3 &v) {
	e[0] *= v[0];
	e[1] *= v[1];
	e[2] *= v[2];
	return *this;
}
inline vec3& vec3::operator/=(const vec3 &v) {
	e[0] /= v[0];
	e[1] /= v[1];
	e[2] /= v[2];
	return *this;
}
inline vec3& vec3::operator*=(const float v) {
	e[0] += v;
	e[1] += v;
	e[2] += v;
	return *this;
}
inline vec3& vec3::operator/=(const float v) {
	float t = float(1.0 / v);
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}
inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}
