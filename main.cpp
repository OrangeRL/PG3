#include<list>
#include <iostream>

using namespace std;

int main()
{
	list<const char*>stations = 
	{ 
		"Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
		"Uguisudani","Nippori","Tabata","Komagome","Sugamo","Otsuka","Ikebukuro",
		"Mejiro","Takadanobaba","Shin-Okubo","Shinjuku","Yoyogi","Harajuku",
		"Shibuya","Ebisu","Meguro","Gotanda","Osaki","Shinagawa","Tamachi",
		"Hamamatsucho","Shimbashi","Yurakucho" 
	};
	//出力
	cout << "---1970年の駅一覧---" << endl;

	for (const char* station : stations) 
	{
		cout << station << endl;
	}

	//西日暮里(1971年開業)を挿入
	for (list<const char*>::iterator itr = stations.begin(); itr != stations.end(); ++itr) 
	{
		if (*itr == "Tabata") 
		{
			itr = stations.insert(itr, "Nishi - Nippori");
			++itr;
		}
	}
	//出力
	cout << "---2019年の駅一覧---" << endl;
	for (const char* station : stations) 
	{
		cout << station << endl;
	}
	//高輪ゲートウェイ(2020年開業)を挿入
	for (list<const char*>::iterator itr = stations.begin(); itr != stations.end(); ++itr) 
	{
		if (*itr == "Tamachi") 
		{
			itr = stations.insert(itr, "Takanawa - Gateway");
			++itr;
		}
	}
	//出力
	cout << "---2022年の駅一覧---" << endl;
	for (const char* station : stations) 
	{
		cout << station << endl;
	}

	return 0;
}