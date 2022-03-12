#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1번규칙은 DP[N] = DP[N/3] + 1, 2번은  DP[N] = DP[N/2] + 1, 3번은 DP[N-1] + 1 이다.
//다만 예제2의 10과 같은 경우 2로 나누어 떨어져 2를 나누고 5에서 -1 이후 4에서 다시 /2, 2에서 /2을 한것이 아니라
//처음에 -1, 9에서 /3, 3에서 /3을 한 것이 최솟값이다. 
//그럼 무조건 나눌수 있으면 나누는것이 정답이 아니라는 뜻
//그냥 다해보고 min()함수로 비교해서 집어넣자

#define MAX_NUM 1000001

vector<int> table(MAX_NUM, MAX_NUM);  //사용할 DP용 배열 선언

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	table[1] = 0;
	table[2] = 1;
	table[3] = 1;
	//기저 조건 초기화
	//1은 연산이 필요없고, 2는 -1혹은/2, 3은 /3 한번으로 1을 만들 수 있다.


	for (int i = 4; i <= n; ++i)  //그 이후 부터
	{
		if (i % 3 == 0)  //해당 수가 1번째 조건을 만족한다면
		{
			table[i] = table[i / 3] + 1;
		}

		//else if가 아니라 if다. i가 2와 3의 공배수일 때 값이 다를 수 있으니까 주의하자
		if (i % 2 == 0)  //해당 수가 2번째 조건을 만족한다면
		{
			table[i] = min(table[i], table[i / 2] + 1);
		}

		//마지막으로 3번 조건에 대해서 검사
		table[i] = min(table[i], table[i - 1] + 1);
		
	}

	cout << table[n];  //답 출력


	return 0;
}