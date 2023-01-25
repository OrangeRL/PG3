#include<stdio.h>
#include"Enemy.h"

int main()
{
	Enemy enemy;
	int input;


	while (true)
	{
		//‘±‚¯‚é‚©‚Ç‚¤‚©“ü—Í‚³‚¹‚é
		printf("0:exit \n1:continue==> ");
		scanf_s("%d", &input);
		if (input == 0)

			break;

		enemy.Update();

		enemy.Draw();
	}


	return 0;
}