#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 11650�� ����. �ٸ� ���� ������ �ٲٸ� �ȴ�.

int S5_11651(void)
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
		cin >> coord.second >> coord.first;  //��ǥ �Է�, y������ �Է��Ѵ�!!

		table.push_back(coord);  //���Ϳ� push back
	}

	sort(table.begin(), table.end());  //�������� ����

	for (int i = 0; i < intN; ++i)
	{
		cout << table[i].second << " " << table[i].first << "\n";  //��µ� �ݴ�� ����� x,y�� ���´�.
	}



	return 0;
}