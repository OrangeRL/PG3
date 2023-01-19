#include "Quaternion.h"
#include "cmath"
#include "math.h"
#define PI 3.141592
Quaternion Multiply(const Quaternion& q1, const Quaternion& q2)
{
	Quaternion q = IdentityQuaternion();
	q.w = (q1.w * q2.w) - q1.v.dot(q2.v);
	q.v = q1.v.cross(q2.v) + (q1.v * q2.w) + (q2.v * q1.w);
	return q;
}

Quaternion IdentityQuaternion()
{
	return { 0,0,0,0 };
}


Quaternion Conjugate(const Quaternion& quaternion)
{
    return Quaternion(-quaternion.v.x, -quaternion.v.y, -quaternion.v.z, quaternion.w);
}

float Norm(const Quaternion& quaternion)
{
    return sqrt(pow(quaternion.v.x, 2.0f) + pow(quaternion.v.y, 2.0f) + pow(quaternion.v.z, 2.0f) + pow(quaternion.w, 2.0f));
}

Quaternion Normalize(const Quaternion& quaternion)
{
    return Quaternion(quaternion.v.x / Norm(quaternion), quaternion.v.y / Norm(quaternion), quaternion.v.z / Norm(quaternion), quaternion.w / Norm(quaternion));
}

Quaternion Inverse(const Quaternion& quaternion)
{
    float n = pow(Norm(quaternion), 2.0f);
    return Quaternion(Conjugate(quaternion).v.x / n, Conjugate(quaternion).v.y / n, Conjugate(quaternion).v.z / n, Conjugate(quaternion).w / n);
}

Quaternion MakeAxisAngle(const Vector3& vector, float angle)
{
    Quaternion q;

    Vector3 v = vector;
    v.normalize();

    q.w = cos(angle / 2);
    q.v = v.normalize() * sin(angle / 2);

    return q;
}

Vector3 RotateVector(const Vector3& vector, const Quaternion& quaternion)
{
    Quaternion q1(vector.x, vector.y, vector.z, 0);
    Quaternion q2;
    q2 = Multiply(Multiply(quaternion, q1), Inverse(quaternion));

    return Vector3(q2.v.x, q2.v.y, q2.v.z);
}

Matrix4 MakeRotateMatrix(const Quaternion& quaternion)
{
    float x = quaternion.v.x;
    float y = quaternion.v.y;
    float z = quaternion.v.z;
    float w = quaternion.w;
    Matrix4 m1
    {
        pow(w,2.0f) + pow(x,2.0f) - pow(y,2.0f) - pow(z,2.0f),  2 * (x * y + w * z),    2 * (x * z - w * y),    0,
        2 * (x * y - w * z),    pow(w,2.0f) - pow(x,2.0f) + pow(y,2.0f) - pow(z,2.0f),  2 * (y * z + w * x),    0,
        2 * (x * z + w * y),    2 * (y * z - w * x),    pow(w,2.0f) - pow(x,2.0f) - pow(y,2.0f) + pow(z,2.0f),  0,
        0,0,0,1
    };
    return m1;
}