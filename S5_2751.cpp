#include <iostream>
#include <algorithm>
using namespace std;

int table_2751[1000000];

//B1_2750과 동일하다... 
//나중에 다른 방식의 정렬을 사용하여 풀어보자

int S5_2751(void)
{
	//시간 감소를 위해 싱크를 풀어주기
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int intN;
	cin >> intN;


	//벡터에 수 집어넣기
	for (int i = 0; i < intN; ++i)
	{
		cin >> table_2751[i];
	}

	sort(table_2751, table_2751 + intN);  //오름차순 정렬

	for (int i = 0; i < intN; ++i)
	{
		cout << table_2751[i] << "\n";  //endl대신 \n입력(시간 때문에)
	}

	return 0;
}