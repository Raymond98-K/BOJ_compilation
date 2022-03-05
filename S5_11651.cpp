#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 11650과 같다. 다만 저장 순서를 바꾸면 된다.

int S5_11651(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> table;  //벡터 선언

	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)
	{
		pair<int, int> coord;
		cin >> coord.second >> coord.first;  //좌표 입력, y값부터 입력한다!!

		table.push_back(coord);  //벡터에 push back
	}

	sort(table.begin(), table.end());  //오름차순 정렬

	for (int i = 0; i < intN; ++i)
	{
		cout << table[i].second << " " << table[i].first << "\n";  //출력도 반대로 해줘야 x,y로 나온다.
	}



	return 0;
}