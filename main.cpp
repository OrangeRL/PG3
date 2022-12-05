#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

void SetTimeout(std::function<void()> func, int second)
{
	Sleep(second);
	func();
}

int main(int argc, const char* argv[])
{
	//入力
	int input;
	printf("サイコロの結果が:\n偶数だと思うなら : '0'\n奇数だと思うなら : '1'\n'0'か'1'を入力をしてください\n");
	scanf_s("%d", &input);

	//答えの決定
	int answer = 0;
	srand(time(nullptr));

	answer = rand() % 100;

	//関数の作成
	std::function<void()> judgeFunc = [&]()
	{

		printf("%d\n", answer);
		if (answer % 2 == 0 and input == 0)
		{
			printf("正解\n");
		}
		else if (answer % 2 == 1 and input == 1)
		{
			printf("正解\n");
		}
		else
		{
			printf("不正解\n");
		}

	};

	printf("\nローディング。。。\n");

	//実行
	SetTimeout(judgeFunc, 2700);

	return 0;
}
