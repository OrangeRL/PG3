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
	//����
	int input;
	printf("�T�C�R���̌��ʂ�:\n�������Ǝv���Ȃ� : '0'\n����Ǝv���Ȃ� : '1'\n'0'��'1'����͂����Ă�������\n");
	scanf_s("%d", &input);

	//�����̌���
	int answer = 0;
	srand(time(nullptr));

	answer = rand() % 100;

	//�֐��̍쐬
	std::function<void()> judgeFunc = [&]()
	{

		printf("%d\n", answer);
		if (answer % 2 == 0 and input == 0)
		{
			printf("����\n");
		}
		else if (answer % 2 == 1 and input == 1)
		{
			printf("����\n");
		}
		else
		{
			printf("�s����\n");
		}

	};

	printf("\n���[�f�B���O�B�B�B\n");

	//���s
	SetTimeout(judgeFunc, 2700);

	return 0;
}
