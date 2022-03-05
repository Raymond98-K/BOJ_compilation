#include <iostream>
using namespace std;

//마지막 숫자 다음에 이어져 나올 숫자는 해당 마지막 숫자마다 정해져 있다.(1다음엔 0혹은 2 뿐임)
//0과 9는 각각 1과 8 이외에는 올 수 없다.
//길이 N의 숫자에 대해 0과 9를 제외한 숫자 i로 끝나는 계단 수의 갯수를 DP[N][i]라 한다면 
//DP[N][i] = DP[N-1][i-1] + DP[N-1][i+1]이 성립한다.
//0과 9에 대해선 DP[N][0] = DP[N-1][1], DP[N][9] = DP[N-1][8]이 성립한다.

#define RANGE_OF_N 101
#define RANGE_OF_NUM 10
#define MOD_RESULT 1000000000

void StairNumbers(int n);  //사용할 함수 초기화.
int table[RANGE_OF_N][RANGE_OF_NUM] = { 0, };    //사용할 DP초기화

int S1_10844(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	table[1][1] = 1;
	table[1][2] = 1;
	table[1][3] = 1;
	table[1][4] = 1;
	table[1][5] = 1;
	table[1][6] = 1;
	table[1][7] = 1;
	table[1][8] = 1;
	table[1][9] = 1; //기저 조건 초기화
	
	int result = 0;  //최종 출력 값
	int n;
	cin >> n;

	StairNumbers(n);  //함수 실행

	for (int i = 0; i <= 9; ++i)
	{
		result += table[n][i];
		result %= MOD_RESULT;

	}

	cout << result;

	
	return 0;
}


void StairNumbers(int n)
{
	for (int i = 2; i <= n; ++i)  //숫자 길이 만큼 반복 밑의 i-1때문에 2부터 시작
	{
		for (int j = 0; j <= 9; ++j)  //0~9까지 숫자마다 진행
		{
			if (j == 0)  //우선 j==0일 경우 그 이전 수는 1만 올 수 있다.
			{
				table[i][0] = table[i - 1][1] % MOD_RESULT;
			}

			else if (j == 9)  // j==9라면 그 이전 수는 8만 올 수 있다.
			{
				table[i][9] = table[i - 1][8] % MOD_RESULT;
			}

			else  //그 외의 경우엔 그 이전수에 대해 올 수있는 경우의 수(+1,-1)에 대해 더하기를 진행해 준다.
			{
				table[i][j] = (table[i - 1][j - 1] + table[i - 1][j + 1]) % MOD_RESULT;
			}

		}
	}
}