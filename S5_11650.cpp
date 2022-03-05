#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// pair<int, int> 형 변수를 담는 벡터 선언 후 sort()를 실행하면 된다.

int S5_11650(void)
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
		cin >> coord.first >> coord.second;  //좌표 입력

		table.push_back(coord);  //벡터에 push back
	}

	sort(table.begin(), table.end());  //오름차순 정렬

	for (int i = 0; i < intN; ++i)
	{
		cout << table[i].first << " " << table[i].second << "\n";  //출력
	}



	return 0;
}