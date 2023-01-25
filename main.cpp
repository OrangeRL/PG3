#include <stdio.h>
#include <stdlib.h>
class IShape
{
	virtual void draw() = 0;
};

class Circle : public IShape
{
public:

	float r;
	//初期化
	void Initialize(float radius);
	//面積
	float size();
	//変数の表示
	void draw();
};

void Circle::Initialize(float r)
{
	this->r = r;
}

float Circle::size()
{
	return r * r * 3.14;
}

void Circle::draw()
{
	printf("circle radius	: %f\n", r);
}

class Rectangle
{
public:
	//width
	float width;
	//height
	float height;
	//初期化
	void Initialize(float width, float height);
	//面積
	float size();
	//変数の表示
	void draw();
};

void Rectangle::Initialize(float width, float height)
{
	this->width = width;
	this->height = height;
}

float Rectangle::size()
{
	return width * height;
}

void Rectangle::draw()
{
	printf("rectangle width	: %f\n", width);
	printf("rectangle height: %f\n", height);
}

int main()
{
	Circle circle;
	Rectangle rectangle;

	circle.Initialize(10);
	rectangle.Initialize(20, 30);

	circle.draw();
	rectangle.draw();

	printf("circle area	: %f\n", circle.size());
	printf("rectangle area	: %f\n", rectangle.size());

	system("pause");

	return 0;
}