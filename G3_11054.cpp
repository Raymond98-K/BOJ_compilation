#include <iostream>
#include <vector>
using namespace std;

//앞뒤로 나눠서 증가하는 부분수열 ~ 기준점 ~ 감소하는 부분수열 길이 합 구하면 되는 문제
//해당 원소의 인덱스를 기준으로 현재 원소가 작다면/크다면 DP갱신
//DP[n] = n번째 원소에 대해서 가장 긴 바이토닉 수열의 길이
//DP[N] = MAX( DP[이전값] + 1, DP[N] )

#define MAX_NUM 1001

vector<int> table(MAX_NUM);  //수를 입력받을 기본 배열
vector<int> going_up(MAX_NUM, 1);  //기준점 기준 왼쪽의 증가하는 부분수열. 초기값은 자기자신이 포함되므로 1
vector<int> going_down(MAX_NUM, 1);  //기준점 기준 오른쪽의 감소하는 부분수열. 초기값은 위와 같은 이유로 1

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> table[i];
	}

	for (int i = 1; i <= n; ++i)  //기준값 반복
	{
		for (int j = 1; j <= i; ++j)  //기준값 이전까지 반복
		{
			//기준값이 현재값보다 크고 DP 길이가 갱신이 된다면
			if (table[i] > table[j] && going_up[i] < going_up[j] + 1)
			{
				going_up[i] = going_up[j] + 1;  //DP 상승배열 갱신
			}
		}
	}

	for (int i = n; i > 0; --i)  //위의 내용과 동일하지만 뒤에서 부터
	{
		for (int j = n; j >= i; --j)  //역시 동일, 뒤에서 부터
		{
			//기준값이 현재값보다 크고 DP 길이가 갱신이 된다면
			if (table[i] > table[j] && going_down[i] < going_down[j] + 1)
			{
				going_down[i] = going_down[j] + 1;
			}
		}
	}

	int max_length = going_up[1] + going_down[1] - 1;  //-1 안하면 해당 기준값이 겹침!!!

	for (int i = 2; i <= n; ++i)
	{
		if (max_length < going_up[i] + going_down[i] - 1)  //현재 최대 길이가 현재 부분수열길이 합보다 작다면
		{
			max_length = going_up[i] + going_down[i] - 1;  //최대 길이 갱신
		}
	}

	cout << max_length;  //정답 출력

	return 0;
}