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
	//—v‘f‚Ì‘€ì‚Ì‘€ì”Ô†
	int menuNumber = 0;

	//—v‘f‚Ì•\¦‚Ì‘€ì”Ô†
	int selectNumber = 0;

	while (true)
	{
		cout << "[—v‘f‚Ì‘€ì]\n";
		cout << "1.—v‘f‚Ì•\¦\n";
		cout << "2.—v‘f‚Ì‘}“ü\n";

		if (list.Size() > 0)
		{
			cout << "3.—v‘f‚Ì•ÒW\n";
			cout << "4.—v‘f‚Ìíœ\n";
		}
		cout << "----------------------------------\n";
		cout << "‘€ì‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢\n";

		if (menuNumber == 0)
		{
			//‘€ì”Ô†‚ğæ“¾
			scanf_s("%d", &menuNumber);
		}
		system("cls");

		switch (menuNumber)
		{
		case 1://—v‘f‚Ì•\¦
			Display(list, menuNumber, selectNumber);
			break;

		case 2://ÅŒã”ö‚É—v‘f‚ğ’Ç‰Á
			Insert(list, menuNumber);
			break;

		case 3://”CˆÓ‚ÌêŠ‚Ì’l‚ğ•ÏX
			Edit(list, menuNumber);
			break;
		case 4://”CˆÓ‚ÌêŠ‚Ìíœ
			Delete(list, menuNumber);
			break;
		}
	}

	return 0;
}

template <typename Type>
void Display(List<Type>& list, int& operationNumber, int& displayOperationNumber) {
	cout << "[—v‘f‚Ì•\¦]\n";
	cout << "1.—v‘f‚Ìˆê——•\¦\n";
	cout << "2.‡”Ô‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦\n";
	cout << "9.—v‘f‘€ì‚É–ß‚é\n";
	cout << endl;
	cout << "‘€ì‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢" << endl;

	//‘€ì”Ô†‚ğæ“¾
	cin >> displayOperationNumber;
	system("cls");

	switch (displayOperationNumber) {
	case 1:
		cout << "[—v‘f‚Ìˆê——•\¦]" << endl;

		//ˆê——•\¦
		list.Dump();

		cout << "—v‘f”:" << list.Size() << endl;

		break;
	case 2:
		cout << "[‡”Ô‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦]" << endl;
		cout << "•\¦‚µ‚½‚¢—v‘f‚Ì‡”Ô‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢B" << endl;

		//w’è‚·‚é”Ô†‚ğæ“¾
		int specifyNumber;
		cin >> specifyNumber;
		cout << endl;


		//w’è‚µ‚Ä•\¦
		list.ElementSpecification(specifyNumber);

		break;

	case 9:
		operationNumber = 0;
		break;
	}

	//—v‘f‘€ì‚É–ß‚ç‚È‚©‚Á‚½‚ç
	if (displayOperationNumber == 1 || displayOperationNumber == 2)
	{
		cout << endl;
		cout << "----------------------------------" << endl;
		cout << "1.—v‘f‚Ì•\¦‚É–ß‚é" << endl;
		cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << endl;

		//‘€ì”Ô†‚ğæ“¾
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
	cout << "[ƒŠƒXƒg—v‘f‚Ì‘}“ü]" << endl;
	cout << endl;
	cout << "—v‘f‚ğ’Ç‰ÁêŠ‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢BÅŒã”ö‚É’Ç‰Á‚·‚éê‡‚Í‰½‚à“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B" << endl;

	string insertNumber;
	while (getchar() != '\n');

	getline(cin, insertNumber);

	if (insertNumber == "")
	{
		cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		Type element{};

		cin >> element;

		list.PushBack(element);

		cout << "—v‘f" << element << "‚ª" << "ÅŒã”ö‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << endl;
	}
	else
	{
		int index = atoi(insertNumber.c_str());

		cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		Type element{};

		cin >> element;

		list.Insert(element, index);

		cout << "—v‘f" << element << "‚ª" << index << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << endl;
	}

	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "9.—v‘f‘€ì‚É–ß‚é" << endl;

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
	cout << "[—v‘f‚Ì•ÒW]" << endl;
	cout << endl;
	cout << "•ÒW‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;

	int elementNumber;
	cin >> elementNumber;
	cout << endl;

	if (list.Search(elementNumber))
	{
		cout << elementNumber << "”Ô–Ú‚Ì—v‘f‚Ì•ÏX‚·‚é’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" << endl;

		Type changeElement{};
		cin >> changeElement;

		list.ChangeValue(changeElement, elementNumber);
		cout << endl;
		cout << elementNumber << "”Ô–Ú‚Ì—v‘f‚Ì’l‚ª" << '"' << changeElement << '"' << "‚É•ÏX‚³‚ê‚Ü‚µ‚½" << endl;
	}
	else
	{
		cout << elementNumber << "”Ô–Ú‚Ì—v‘f‚Ì‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B" << endl;
	}


	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "9.—v‘f‘€ì‚É–ß‚é" << endl;
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
	cout << "[—v‘f‚Ìíœ]" << endl;
	cout << endl;
	cout << "íœ‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢" << endl;

	int elementNumber;
	cin >> elementNumber;
	cout << endl;

	if (list.Search(elementNumber))
	{
		cout << elementNumber << "”Ô–Ú‚Ì—v‘f" << '"' << list.GetCell(elementNumber) << '"' << "íœ‚µ‚Ü‚µ‚½" << endl;

		list.Delete(elementNumber);

		cout << endl;
	}
	else
	{
		cout << elementNumber << "”Ô–Ú‚Ì—v‘f‚Ì‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B" << endl;
	}

	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "9.—v‘f‘€ì‚É–ß‚é" << endl;

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