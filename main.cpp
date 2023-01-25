#include <stdio.h>
#include <stdlib.h>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

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