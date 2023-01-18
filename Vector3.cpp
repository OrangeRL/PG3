#include "Vector3.h"
#include <cmath>

#define PI 3.1415926545
Vector3::Vector3()
	:x(0), y(0), z(0)
{
}

Vector3::Vector3(float x, float y, float z)
	: x(x), y(y), z(z)
{
}

float Vector3::length() const
{
	return (float)sqrt(x * x + y * y + z * z);
}

Vector3& Vector3::normalize()
{
	float len = length();
	if (len != 0)
	{
		return *this /= len;
	}
	return *this;
}

float Vector3::dot(const Vector3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::cross(const Vector3& v) const
{
	Vector3 temp;
	temp.x = this->y * v.z - this->z * v.y;
	temp.y = this->z * v.x - this->x * v.z;
	temp.z = this->x * v.y - this->y * v.x;
	return temp;
}

Vector3 Vector3::operator+() const
{
	return *this;
}

//-----------------------------------------
Vector3 Vector3::operator-() const
{
	return Vector3();
}
Vector3& Vector3::operator+=(const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
Vector3& Vector3::operator-=(const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
Vector3& Vector3::operator*=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}
Vector3& Vector3::operator/=(float s)
{
	x /= s;
	y /= s;
	z /= s;
	return *this;
}
//Vector3 クラスに属さない関数群
//二項演算子
const Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	return temp += v2;
}
const Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	return temp -= v2;
}
const Vector3 operator*(const Vector3& v, float s)
{
	Vector3 temp(v);
	return temp *= s;
}
const Vector3 operator*(float s, const Vector3& v)
{
	return v * s;
}
const Vector3 operator/(const Vector3& v, float s)
{
	Vector3 temp(v);
	return temp /= s;
}
//線形補間
const Vector3 lerp(const Vector3& start, const Vector3& end, const float t)
{
	float y = t;
	//return start * (1.0f - y) + end * y;
	return start * (1.0f - t) + end * t;
}
const Vector3 easeIn(const Vector3& start, const Vector3& end, const float t)
{
	float y = (pow(2, 8 * t) - 1) / 255;;
	return start * (1.0f - y) + end * y;
	//return start * sin(1.5707963f - t) + end * t * y * y;
}
const Vector3 easeOut(const Vector3& start, const Vector3& end, float t)
{
	float y = 1 - pow(2, -8 * t);;
	//return start * sin(1.0f - t) + end * (--t);
	//return start * sin(1.0f - y) + end * t * y * y;
	return start * (1.0f - y) + end * y;
}

Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs) {
	return 
	{
	   lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z,  // 1
	   lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,  // i
	   lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,  // j
	   lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w   // k
	};
}
Quaternion IdentityQuaternion()
{
	return {0,0,0,0};
}

Quaternion Conjugate(const Quaternion& quaternion)
{
	return Quaternion(-quaternion.x, -quaternion.y, -quaternion.z, quaternion.w);
}

float Norm(const Quaternion& quaternion)
{
	return sqrt(pow(quaternion.x, 2.0f) + pow(quaternion.y, 2.0f) + pow(quaternion.z, 2.0f) + pow(quaternion.w, 2.0f));
}

Quaternion Normalize(const Quaternion& quaternion)
{
	return Quaternion(quaternion.x / Norm(quaternion), quaternion.y / Norm(quaternion), quaternion.z / Norm(quaternion), quaternion.w / Norm(quaternion));
}

Quaternion Inverse(const Quaternion& quaternion)
{
	float n = pow(Norm(quaternion), 2.0f);
	return Quaternion(Conjugate(quaternion).x / n, Conjugate(quaternion).y / n, Conjugate(quaternion).z / n, Conjugate(quaternion).w / n);
	
}