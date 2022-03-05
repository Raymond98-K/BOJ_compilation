#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

//15650?? 과 비슷한 원리 인데 그대로 하니까 시간초과가 뜬다 
//14/23을 구했으면 23/14는 볼 필요가 없으니까 이를 해결해야 한다.
//설마 벡터라서 느린건가?????

#define maxMembers 21  //선수 최대 인원

void MakeTeam(int member, int cnt, int n);  
//member는 현재 구성이 나뉠 사람 번호, cnt는 현재 팀 구성이 끝난 사람 수
int result = 999999999;  //최종 출력 값. 초기값은 문제에서 불가능할 정도로 높게.
int soccer[maxMembers][maxMembers];  //이중 벡터 선언 -> 배열로 변경
bool is_in_team[maxMembers];  //해당 번호의 사람이 현재 팀에 있는지 확인용 벡터 -> 배열로 변경

int S2_14889(void)
{
	time_t start, end;
	double time_check;

	start = time(NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> soccer[i][j];
		}
	}

	MakeTeam(1, 0, n);  //함수 호출

	cout << result;  //출력


	end = time(NULL);

	time_check = (double)(end - start);
	cout << time_check/CLOCKS_PER_SEC;

	return 0;
}


void MakeTeam(int member, int cnt, int n)
{
	if (cnt == n / 2)  //절반이 되면 팀 구성이 완료된 것
	{
		int sum_of_start = 0;  //start 팀의 파워 초기화
		int sum_of_link = 0;  //link 팀의 파워 초기화
		int calc = 0;  //각 팀 파워 차이 초기화

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (is_in_team[i] == true && is_in_team[j] == true)  //둘다 start 팀에 있다면
				{
					sum_of_start += soccer[i][j];  //start팀 팀파워 갱신
				}

				if (is_in_team[i] == false && is_in_team[j] == false)  //둘다 link 팀에 있다면
				{
					sum_of_link += soccer[i][j];  //link팀 팀파워 갱신
				}
			}

		}

		//팀파워가 작은 쪽으로 result 갱신
		calc = abs(sum_of_start - sum_of_link);

		if (result > calc)
		{
			result = calc;
		}

		return;  //함수 종료
	}

	//그게 아니라면 가능한 경우를 전부 찾아본다.
	//단, 인원이 6명일 경우를 예시로 첫번째 선수가 i=1일때 마지막 조합인 156 / 234 는 
	//첫번째 선수가 i=2일때 맨 처음 조합인 234/ 156 과 같다.
	//따라서 조건을 cnt+1<= i < N 까지 하면 딱 맞아 떨어진다.
	
	for (int i = member; i < n; ++i)
	{
		is_in_team[i] = true;  //해당 인원의 팀(start) 참가 여부를 갱신 false -> true 
		MakeTeam(member + 1, cnt + 1, n);  //다음 인원에 대한 함수 호출
		//함수가 끝났다면 해당 인원에 대한 조합이 끝난 것
		is_in_team[i] = false;  //해당 인원의 팀 참가 여부를 갱신 true -> false
	}

}


//벡터랑 배열 시간차이 약 30ms





