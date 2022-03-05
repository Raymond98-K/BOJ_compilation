#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// pair<int, int> �� ������ ��� ���� ���� �� sort()�� �����ϸ� �ȴ�.

int S5_11650(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> table;  //���� ����

	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)
	{
		pair<int, int> coord;
		cin >> coord.first >> coord.second;  //��ǥ �Է�

		table.push_back(coord);  //���Ϳ� push back
	}

	sort(table.begin(), table.end());  //�������� ����

	for (int i = 0; i < intN; ++i)
	{
		cout << table[i].first << " " << table[i].second << "\n";  //���
	}



	return 0;
}