#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//stirng타입의 벡터에 문자를 넣고 sort를 하되 sort에 compare 인자를 구현해 추가한다.
//단어가 중복될 경우 한번만 출력하는것에 주의!!

bool compare(string first, string second);

int S5_1181(void)
{
	vector<string> table;  //벡터 선언
	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)
	{
		string stringS;
		cin >> stringS;

		table.push_back(stringS);
	}

	sort(table.begin(), table.end(), compare);

	cout << table[0] << "\n";  //우선 첫번째 단어를 그냥 출력 후

	for (int i = 1; i < intN; ++i)  //중복 검사를 진행하며 나머지 출력
	{
		if (table[i - 1] != table[i])
		{
			cout << table[i] << "\n";
		}
	}


	return 0;
}


bool compare(string first, string second)
{
	if (first.size() == second.size())
	{
		return first < second;
	}

	else
	{
		return first.size() < second.size();
	}
}