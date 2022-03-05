#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//그리디 알고리즘
//이 경우 앞사람부터 시간이 계속 누적된는 방식이다.
//따라서 시간이 적게 걸리는 순서대로 출금을 해야 한다.

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;

	vector<int> people(n + 1);  //사람들 배열 초기화
	vector<int> time(n + 1);  //각 인원별 소요시간 배열 초기화

	for (int i = 1; i <= n; ++i)
	{
		cin >> time[i];
	}

	sort(time.begin(), time.end());  //오름차순 정렬

	int result = 0;  //출력값 초기화
	int time_cnt = 0;  //누적 소요시간값 초기화
	for (int i = 1; i <= n; ++i)
	{
		time_cnt += time[i];  //누적시간 계산
		result += time_cnt;  //값 계산
	}

	cout << result;  //출력

	return 0;
}