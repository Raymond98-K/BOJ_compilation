#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//pair 사용, 오름차순 정렬은 종료 시간을 우선으로 정렬 한다.
//시작시간이 빨라도 종료시간이 한참 후라면 선택해선 안되기 때문에 종료시간 기준으로 정렬해야한다!!
//벡터에 저장된 값들을 정렬하고 이후 끝나는 시간이 다음 시작시간과 겹치지 않게 cnt++

bool compare(pair<unsigned int, unsigned int> pair1, pair<unsigned int, unsigned int> pair2);  //sort사용을 위한 compare 함수

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<unsigned int, unsigned int>> time_table(n);

	for (int i = 0; i < n; ++i)
	{
		pair<unsigned int, unsigned int> schedule;

		cin >> schedule.first >> schedule.second;

		time_table[i] = schedule;  //모든 시간표를 벡터에 저장
	}


	sort(time_table.begin(), time_table.end(), compare);  //first와 second값을 통해 정렬되도록 정렬

	int cnt = 1;  //출력될 회의의 갯수 초기화. 이미 첫 회의는 실행 하는 것이 확정 이므로 초깃값==1
	unsigned int end_time = time_table[0].second;  //이전 회의 종료 시간 초기화. 초깃값은 첫번째 회의의 종료시간

	for (int i = 1; i < n; ++i)  //범위에 주의!!
	{
		if (time_table[i].first >= end_time)  //현재 회의의 시작 시간이 이전 회의의 종료시간 이상일 경우
		{
			end_time = time_table[i].second;  //이전 회의의 종료시간 값을 현재 회의의 종료시간으로 갱신
			cnt++;  //횟수++
		}
	}

	cout << cnt;  //출력

	return 0;
}



bool compare(pair<unsigned int, unsigned int> pair1, pair<unsigned int, unsigned int> pair2)
{
	if (pair1.second == pair2.second)  //만약 두 회의의 종료 시간이 같다면
	{
		return pair1.first < pair2.first;  //시작 시간 기준 오름차순 정렬
	}

	else
	{
		return pair1.second < pair2.second;  //종료 시간이 다르다면 종료 시간 기준 오름차순 정렬
	}
}