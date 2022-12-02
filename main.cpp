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
	//要素の操作の操作番号
	int menuNumber = 0;

	//要素の表示の操作番号
	int selectNumber = 0;

	while (true)
	{
		cout << "[要素の操作]\n";
		cout << "1.要素の表示\n";
		cout << "2.要素の挿入\n";

		if (list.Size() > 0)
		{
			cout << "3.要素の編集\n";
			cout << "4.要素の削除\n";
		}
		cout << "----------------------------------\n";
		cout << "操作を選択してください\n";

		if (menuNumber == 0)
		{
			//操作番号を取得
			scanf_s("%d", &menuNumber);
		}
		system("cls");

		switch (menuNumber)
		{
		case 1://要素の表示
			Display(list, menuNumber, selectNumber);
			break;

		case 2://最後尾に要素を追加
			Insert(list, menuNumber);
			break;

		case 3://任意の場所の値を変更
			Edit(list, menuNumber);
			break;
		case 4://任意の場所の削除
			Delete(list, menuNumber);
			break;
		}
	}

	return 0;
}

template <typename Type>
void Display(List<Type>& list, int& operationNumber, int& displayOperationNumber) {
	cout << "[要素の表示]\n";
	cout << "1.要素の一覧表示\n";
	cout << "2.順番を指定して要素を表示\n";
	cout << "9.要素操作に戻る\n";
	cout << endl;
	cout << "操作を選択してください" << endl;

	//操作番号を取得
	cin >> displayOperationNumber;
	system("cls");

	switch (displayOperationNumber) {
	case 1:
		cout << "[要素の一覧表示]" << endl;

		//一覧表示
		list.Dump();

		cout << "要素数:" << list.Size() << endl;

		break;
	case 2:
		cout << "[順番を指定して要素を表示]" << endl;
		cout << "表示したい要素の順番を指定してください。" << endl;

		//指定する番号を取得
		int specifyNumber;
		cin >> specifyNumber;
		cout << endl;


		//指定して表示
		list.ElementSpecification(specifyNumber);

		break;

	case 9:
		operationNumber = 0;
		break;
	}

	//要素操作に戻らなかったら
	if (displayOperationNumber == 1 || displayOperationNumber == 2)
	{
		cout << endl;
		cout << "----------------------------------" << endl;
		cout << "1.要素の表示に戻る" << endl;
		cout << "2.要素の操作に戻る" << endl;

		//操作番号を取得
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
	cout << "[リスト要素の挿入]" << endl;
	cout << endl;
	cout << "要素を追加場所を指定してください。最後尾に追加する場合は何も入力しないでください。" << endl;

	string insertNumber;
	while (getchar() != '\n');

	getline(cin, insertNumber);

	if (insertNumber == "")
	{
		cout << "追加する要素の値を入力してください" << endl;
		Type element{};

		cin >> element;

		list.PushBack(element);

		cout << "要素" << element << "が" << "最後尾に挿入されました" << endl;
	}
	else
	{
		int index = atoi(insertNumber.c_str());

		cout << "追加する要素の値を入力してください" << endl;
		Type element{};

		cin >> element;

		list.Insert(element, index);

		cout << "要素" << element << "が" << index << "番目に挿入されました" << endl;
	}

	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "9.要素操作に戻る" << endl;

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
	cout << "[要素の編集]" << endl;
	cout << endl;
	cout << "編集したい要素の番号を入力してください" << endl;

	int elementNumber;
	cin >> elementNumber;
	cout << endl;

	if (list.Search(elementNumber))
	{
		cout << elementNumber << "番目の要素の変更する値を入力してください。" << endl;

		Type changeElement{};
		cin >> changeElement;

		list.ChangeValue(changeElement, elementNumber);
		cout << endl;
		cout << elementNumber << "番目の要素の値が" << '"' << changeElement << '"' << "に変更されました" << endl;
	}
	else
	{
		cout << elementNumber << "番目の要素のが見つかりませんでした。" << endl;
	}


	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "9.要素操作に戻る" << endl;
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
	cout << "[要素の削除]" << endl;
	cout << endl;
	cout << "削除したい要素の番号を指定してください" << endl;

	int elementNumber;
	cin >> elementNumber;
	cout << endl;

	if (list.Search(elementNumber))
	{
		cout << elementNumber << "番目の要素" << '"' << list.GetCell(elementNumber) << '"' << "削除しました" << endl;

		list.Delete(elementNumber);

		cout << endl;
	}
	else
	{
		cout << elementNumber << "番目の要素のが見つかりませんでした。" << endl;
	}

	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "9.要素操作に戻る" << endl;

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