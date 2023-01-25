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
	//‰Šú‰»
	void Initialize(float width, float height);
	//–ÊÏ
	float size() override { return width * height; };
	//•Ï”‚Ì•\¦
	void draw() override
	{
		printf("rectangle width	: %f\n", width);
		printf("rectangle width	: %f\n", height);
	}
};