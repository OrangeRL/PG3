#pragma once
#include <stdio.h>
#include "IShape.h"

class Rectangle : public IShape
{
public:
	//width
	float width;
	//height
	float height;
	//������
	void Initialize(float width, float height);
	//�ʐ�
	float size() override { return width * height; };
	//�ϐ��̕\��
	void draw() override
	{
		printf("rectangle width	: %f\n", width);
		printf("rectangle width	: %f\n", height);
	}
};