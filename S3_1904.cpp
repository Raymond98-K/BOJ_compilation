#include <iostream>
#include <vector>
using namespace std;

//그냥 쓰다보니 규칙이 나왔다. 피보나치와 동일하게 DP[N} = DP[N-2] + DP[N-1]
//DP[N-2]번째의 경우들에서 뒤에 00을 붙이는 경우 + DP[N-1]번째의 경우에서 앞에 1을 붙이는 경우
//위의 방식대로 하면 중복되는 것도 없고 깔끔하게 나온다.

#define MAX_NUM 1000001
#define MOD 15746
vector<int> table(MAX_NUM);  //사용할 DP정의

//int search(int cnt);  //사용할 함수 선언 - 함수사용시 메모리 21432KB 시간24ms
//반복문 사용시 메모리 5928KB 시간 8ms로 반복문이 훨씬 빠르다. 역시 재귀는 무겁다...

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	table[1] = 1;
	table[2] = 2;  //기저 조건 정의

	int n;
	cin >> n;

	/*
	int answer;
	answer = search(n);  //함수 호출

	cout << answer;  //정답 출력
	*/

	for (int i = 3; i <= n; ++i)  //그냥 반복문으로 DP 채우기
	{
		table[i] = (table[i - 2] + table[i - 1]) % MOD;
	}

	cout << table[n];


	return 0;
}

/*
int search(int cnt)
{
	if (table[cnt] != 0)  //만약 DP에 저장된 값이 있다면
	{
		return table[cnt];  //해당 값을 꺼내 사용한다.
	}

	else  //그렇지 않고 저장된 값이 없다면
	{
		table[cnt] = (search(cnt - 2) + search(cnt - 1)) % MOD;  //점화식에 맞게 계산한다.
		return table[cnt];
	}
}
*/
