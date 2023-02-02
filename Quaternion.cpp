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

Quaternion Slerp(const Quaternion& q0, const Quaternion& q1, float t)
{
    Quaternion q2 = q0;
    Quaternion q3 = q1;

    //ì‡êœ
    float dot = q2.v.dot(q3.v);

    if (dot < 0)
    {
        q2 = Conjugate(q2);   //Ç‡Ç§ï–ï˚ÇÃâÒì]ÇóòópÇ∑ÇÈ
        dot = -dot;     //ì‡êœÇ‡îΩì]
    }

    //Ç»Ç∑äpÇãÅÇﬂÇÈ
    float theta = std::acos(dot);

    //thetaÇ∆sinÇégÇ¡Çƒï‚äÆåWêîscale0,scale1ÇãÅÇﬂÇÈ
    float scale0 = (sin((1 - t) * theta) / sin(theta));
    float scale1 = (sin(t * theta) / sin(theta));

    /*return scale0 * q2 + scale1 * q3*/
    return Quaternion(q2.v.x * scale0 + q3.v.x * scale1, q2.v.y * scale0 + q3.v.y * scale1,
        q2.v.z * scale0 + q3.v.z * scale1, q2.w * scale0 + q3.w * scale1);
}
Quaternion DirectionToDirection(const Vector3& u, const Vector3& v)
{
    Vector3 v1 = u;
    Vector3 v2 = v;

    //uÇ∆vÇê≥ãKâªÇµÇƒì‡êœÇãÅÇﬂÇÈ
    float dot = v1.normalize().dot(v2.normalize());
    //u,vÇÃäOêœ
    Vector3 cross = v1.cross(v2);
    //é≤Çê≥ãKâª
    Vector3 axis = cross.normalize();
    //íPà ÉxÉNÉgÉãÇ≈ì‡êœÇÇ∆Ç¡ÇƒÇ¢ÇÈÇÃÇ≈acosÇ≈äpìxÇãÅÇﬂÇÈ
    float theta = std::acos(dot);

    return MakeAxisAngle(axis, theta);
}