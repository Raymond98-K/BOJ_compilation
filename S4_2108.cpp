#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//순서대로 우선 오름차순 정렬( sort() )을 한 뒤
//산술평균은 그냥 계산
//중앙값은 벡터의 중앙값
//최빈값은 계수정렬
//범위는 그냥 계산

int S4_2108(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> table;  //입력받을 수들을 저장할 벡터
	vector<int> tableMode(8001);  //최빈값 계산용 벡터
	double arithmetic = 0;  //산술평균 초기화. 범위를 고려해 double로 설정

	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)
	{
		int num;
		cin >> num;

		tableMode[4000 + num]++;  //4000을 기준으로 정렬
		
		table.push_back(num);  //전체 수 벡터에 push back

		arithmetic += num;  //산술평균 계산
	}

	cout << round(arithmetic/intN) << "\n";  //산술평균 최종계산 및 출력

	sort(table.begin(), table.end());  //오름차순 정렬

	cout << table[intN / 2] << "\n";  //중앙값 계산 및 출력


	int count = -1;  //최빈값 등장횟수 초기화
	int mode = 8001;  //최빈값 초기화
	int isSecond = 2;  //두번째 값인지 판단하는 요소 2면 두번째 값이다.

	for (int i = 0; i < 8001; ++i)
	{
		if (count < tableMode[i])
		{
			count = tableMode[i];  //등장횟수 갱신
			mode = i - 4000;  //최빈값 갱신
			isSecond = 1;  //첫등장이므로 갱신
		}

		else if (count == tableMode[i] && isSecond == 1)
		{
			mode = i - 4000;
			isSecond = 2;  //두번째 등장임을 알리고 더이상의 갱신을 막음
		}
	}

	cout << mode << "\n";  //최빈값 출력
	

	cout << table[intN - 1] - table[0];  //범위 계산 및 출력




	return 0;
}