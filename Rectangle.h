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
	//初期化
	void Initialize(float width, float height);
	//面積
	float size() override { return width * height; };
	//変数の表示
	void draw() override
	{
		printf("rectangle width	: %f\n", width);
		printf("rectangle width	: %f\n", height);
	}
};