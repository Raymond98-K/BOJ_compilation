#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//stirngŸ���� ���Ϳ� ���ڸ� �ְ� sort�� �ϵ� sort�� compare ���ڸ� ������ �߰��Ѵ�.
//�ܾ �ߺ��� ��� �ѹ��� ����ϴ°Ϳ� ����!!

bool compare(string first, string second);

int S5_1181(void)
{
	vector<string> table;  //���� ����
	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)
	{
		string stringS;
		cin >> stringS;

		table.push_back(stringS);
	}

	sort(table.begin(), table.end(), compare);

	cout << table[0] << "\n";  //�켱 ù��° �ܾ �׳� ��� ��

	for (int i = 1; i < intN; ++i)  //�ߺ� �˻縦 �����ϸ� ������ ���
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