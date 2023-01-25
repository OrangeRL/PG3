#pragma once
#include <stdio.h>
#include "IShape.h"

class Circle : public IShape
{
public:

	float r;
	//初期化
	void Initialize(float radius);
	//面積
	float size() override { return r * r * 3.14159265359; };
	//変数の表示
	void draw() override { printf("circle radius	: %f\n", r); }
};
