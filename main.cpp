#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

using namespace std;

template <typename Type>
void Display(List<Type>& list, int& select, int& menu);
template <typename Type>
void Insert(List<Type>& list, int& select);
template <typename Type>
void Edit(List<Type>& list, int& select);
template <typename Type>
void Delete(List<Type>& list, int& select);

int main()
{
	List<string> list;
	list.PushBack("banana");
	list.PushBack("apple");
	list.PushBack("orange");
	//�v�f�̑���̑���ԍ�
	int menuNumber = 0;

	//�v�f�̕\���̑���ԍ�
	int selectNumber = 0;

	while (true)
	{
		cout << "[�v�f�̑���]\n";
		cout << "1.�v�f�̕\��\n";
		cout << "2.�v�f�̑}��\n";

		if (list.Size() > 0)
		{
			cout << "3.�v�f�̕ҏW\n";
			cout << "4.�v�f�̍폜\n";
		}
		cout << "----------------------------------\n";
		cout << "�����I�����Ă�������\n";

		if (menuNumber == 0)
		{
			//����ԍ����擾
			scanf_s("%d", &menuNumber);
		}
		system("cls");

		switch (menuNumber)
		{
		case 1://�v�f�̕\��
			Display(list, menuNumber, selectNumber);
			break;

		case 2://�Ō���ɗv�f��ǉ�
			Insert(list, menuNumber);
			break;

		case 3://�C�ӂ̏ꏊ�̒l��ύX
			Edit(list, menuNumber);
			break;
		case 4://�C�ӂ̏ꏊ�̍폜
			Delete(list, menuNumber);
			break;
		}
	}

	return 0;
}

template <typename Type>
void Display(List<Type>& list, int& operationNumber, int& displayOperationNumber) {
	cout << "[�v�f�̕\��]\n";
	cout << "1.�v�f�̈ꗗ�\��\n";
	cout << "2.���Ԃ��w�肵�ėv�f��\��\n";
	cout << "9.�v�f����ɖ߂�\n";
	cout << endl;
	cout << "�����I�����Ă�������" << endl;

	//����ԍ����擾
	cin >> displayOperationNumber;
	system("cls");

	switch (displayOperationNumber) {
	case 1:
		cout << "[�v�f�̈ꗗ�\��]" << endl;

		//�ꗗ�\��
		list.Dump();

		cout << "�v�f��:" << list.Size() << endl;

		break;
	case 2:
		cout << "[���Ԃ��w�肵�ėv�f��\��]" << endl;
		cout << "�\���������v�f�̏��Ԃ��w�肵�Ă��������B" << endl;

		//�w�肷��ԍ����擾
		int specifyNumber;
		cin >> specifyNumber;
		cout << endl;


		//�w�肵�ĕ\��
		list.ElementSpecification(specifyNumber);

		break;

	case 9:
		operationNumber = 0;
		break;
	}

	//�v�f����ɖ߂�Ȃ�������
	if (displayOperationNumber == 1 || displayOperationNumber == 2)
	{
		cout << endl;
		cout << "----------------------------------" << endl;
		cout << "1.�v�f�̕\���ɖ߂�" << endl;
		cout << "2.�v�f�̑���ɖ߂�" << endl;

		//����ԍ����擾
		cin >> displayOperationNumber;

		system("cls");
		switch (displayOperationNumber)
		{
		case 1:
			operationNumber = 1;
			break;
		case 2:
			operationNumber = 0;
			break;
		default:
			break;
		}
	}
}

template <typename Type>
void Insert(List<Type>& list, int& operationNum)
{
	cout << "[���X�g�v�f�̑}��]" << endl;
	cout << endl;
	cout << "�v�f��ǉ��ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B" << endl;

	string insertNumber;
	while (getchar() != '\n');

	getline(cin, insertNumber);

	if (insertNumber == "")
	{
		cout << "�ǉ�����v�f�̒l����͂��Ă�������" << endl;
		Type element{};

		cin >> element;

		list.PushBack(element);

		cout << "�v�f" << element << "��" << "�Ō���ɑ}������܂���" << endl;
	}
	else
	{
		int index = atoi(insertNumber.c_str());

		cout << "�ǉ�����v�f�̒l����͂��Ă�������" << endl;
		Type element{};

		cin >> element;

		list.Insert(element, index);

		cout << "�v�f" << element << "��" << index << "�Ԗڂɑ}������܂���" << endl;
	}

	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "9.�v�f����ɖ߂�" << endl;

	cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 2;
	}
}

template <typename Type>
void Edit(List<Type>& list, int& operationNumber)
{
	cout << "[�v�f�̕ҏW]" << endl;
	cout << endl;
	cout << "�ҏW�������v�f�̔ԍ�����͂��Ă�������" << endl;

	int elementNumber;
	cin >> elementNumber;
	cout << endl;

	if (list.Search(elementNumber))
	{
		cout << elementNumber << "�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B" << endl;

		Type changeElement{};
		cin >> changeElement;

		list.ChangeValue(changeElement, elementNumber);
		cout << endl;
		cout << elementNumber << "�Ԗڂ̗v�f�̒l��" << '"' << changeElement << '"' << "�ɕύX����܂���" << endl;
	}
	else
	{
		cout << elementNumber << "�Ԗڂ̗v�f�̂�������܂���ł����B" << endl;
	}


	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "9.�v�f����ɖ߂�" << endl;
	cin >> operationNumber;
	system("cls");

	if (operationNumber == 9)
	{
		operationNumber = 0;
	}
	else
	{
		operationNumber = 3;
	}

}

template <typename Type>
void Delete(List<Type>& list, int& operationNumber)
{
	cout << "[�v�f�̍폜]" << endl;
	cout << endl;
	cout << "�폜�������v�f�̔ԍ����w�肵�Ă�������" << endl;

	int elementNumber;
	cin >> elementNumber;
	cout << endl;

	if (list.Search(elementNumber))
	{
		cout << elementNumber << "�Ԗڂ̗v�f" << '"' << list.GetCell(elementNumber) << '"' << "�폜���܂���" << endl;

		list.Delete(elementNumber);

		cout << endl;
	}
	else
	{
		cout << elementNumber << "�Ԗڂ̗v�f�̂�������܂���ł����B" << endl;
	}

	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "9.�v�f����ɖ߂�" << endl;

	cin >> operationNumber;
	system("cls");

	if (operationNumber == 9)
	{
		operationNumber = 0;
	}
	else
	{
		operationNumber = 4;
	}
}