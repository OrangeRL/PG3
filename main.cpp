#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef void (*PFunc)(int*);

void DispResult(int* answer) {
	srand(time(NULL));
	int result = rand() % 6 + 1;

	printf("\n出目 : %d\n", result);

	if (result % 2 == 0)
	{
		printf("結果 : 偶数\n\n");
	}
	else
	{
		printf("結果 : 奇数\n\n");
	}

	if (result % 2 == *answer)
	{
		printf("正解！！！\n");
	}
	else
	{
		printf("不正解...\n");
	}
}

void SetTimeOut(PFunc p, int answer) {
	// コールバック関数を呼び出す
	Sleep(3000);
	p(&answer);
}

int main(void) {

	printf("\nサイコロの結果が:\n偶数だと思うなら:'0'\n奇数だと思うなら:'1'\n'0'か'1'を入力をしてください\n");
	printf("入力:");

	int answer;
	scanf_s("%d", &answer);

	if (answer != 0 && answer != 1)
	{
		printf("\nError!\n");
		return 0;
	}
	
	printf("\nローディング。。。\n");

	PFunc p;
	p = DispResult;
	SetTimeOut(p, answer);

	return 0;
}