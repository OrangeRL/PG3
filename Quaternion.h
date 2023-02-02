#pragma once
#include "Vector3.h"
#include "Matrix4.h"

struct Quaternion
{
	Vector3 v;
	float w;
	Quaternion(float x, float y, float z, float w)
	{
		this->v.x = x;
		this->v.y = y;
		this->v.z = z;
		this->w = w;
	}
	Quaternion()
	{
		this->v.x = 0;
		this->v.y = 0;
		this->v.z = 0;
		this->w = 0;
	};
};

//�P��Quaternion��Ԃ�
Quaternion IdentityQuaternion();
//��
Quaternion Multiply(const Quaternion& q1, const Quaternion& q2);
//����Quaternion��Ԃ�
Quaternion Conjugate(const Quaternion& quaternion);
//Quaternion��norm��Ԃ�
float Norm(const Quaternion& quaternion);
//���K��
Quaternion Normalize(const Quaternion& quaternion);
//�tQuaternion��Ԃ�
Quaternion Inverse(const Quaternion& quaternion);

//�C�ӎ���]��\��Quaternion�̐���
Quaternion MakeAxisAngle(const Vector3& vector, float angle);
//�x�N�g����Quaternion�ŉ�]���������ʂ̃x�N�g�������߂�
Vector3 RotateVector(const Vector3& vector, const Quaternion& quaternion);
//quaternion�����]�s������߂�
Matrix4 MakeRotateMatrix(const Quaternion& quaternion);
//���ʐ��`���
Quaternion Slerp(const Quaternion& q0, const Quaternion& q1, float t);
//u����v�ւ̉�]�𐶐�
Quaternion DirectionToDirection(const Vector3& u, const Vector3& v);
