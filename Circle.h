#pragma once
#include <stdio.h>
#include "IShape.h"

class Circle : public IShape
{
public:

	float r;
	//������
	void Initialize(float radius);
	//�ʐ�
	float size() override { return r * r * 3.14159265359; };
	//�ϐ��̕\��
	void draw() override { printf("circle radius	: %f\n", r); }
};
