#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell
{
	char str[16];
	struct cell* next;
}CELL;

void Create(CELL* headCell, const char* buf);
void Index(CELL* headCell);

int main()
{
	char str[16];

	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("Input Item:");
		scanf_s("%s", str, 16);
		Create(&head, str);
		Index(&head);
		printf("\n");
	}
	return 0;
}

void Create(CELL* headCell, const char* buf)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	if (newCell != nullptr)
	{
		strcpy_s(newCell->str, 16, buf);
		// 新規作成するセルのポインタ->値 = 値;
		newCell->next = nullptr;
	}
	while (headCell->next != nullptr)
	{
		headCell = headCell->next;
	}
	headCell->next = newCell;
}

void Index(CELL* headCell)
{
	printf("-------------------LIST--------------------");
	while (headCell->next != nullptr)
	{
		headCell = headCell->next;
		printf("\nInserted Item: %s\n", headCell->str);
	}
	printf("-------------------END---------------------");
}