#pragma once
#include <stdio.h>
#include "IShape.h"

class Circle : public IShape
{
public:

	float r;
	//‰Šú‰»
	void Initialize(float radius);
	//–ÊÏ
	float size() override { return r * r * 3.14159265359; };
	//•Ï”‚Ì•\¦
	void draw() override { printf("circle radius	: %f\n", r); }
};
