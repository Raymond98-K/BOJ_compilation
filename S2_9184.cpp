#include <iostream>
#include <vector>
using namespace std;

//각 경우의 w(a,b,c) 값에 대해 DP를 만들어 활용해보자
//a b c니까 그냥 3차원 배열을 써보자

#define MAX_RANGE 21

int w(int a, int b, int c);  //함수 선언
vector<vector<vector<int>>> w_dp(MAX_RANGE, vector<vector<int>>(MAX_RANGE, vector<int>(MAX_RANGE)));  //DP용 3차원 벡터
//==DP[21][21][21]

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	vector<int> table(4);  //숫자를 저장할 벡터 초기화

	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)  //세개 다 -1일 경우 break
		{
			break;
		}

		else
		{
			table[1] = a;
			table[2] = b;
			table[3] = c;  //값 할당
		}

		cout << "w(" << table[1] << ", " << table[2] << ", " << table[3] << ") = " << w(table[1], table[2], table[3]);
		cout << "\n";
		//함수 호출 및 양식에 맞게 출력

	}

	return 0;
}


int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)  //기존과 동일
	{
		return 1;
	}

	else if (a > 20 || b > 20 || c > 20)  //기존과 동일
	{
		return w(20, 20, 20);
	}

	//아래의 DP 리턴이 있는 부분은 20보다 큰 경우 아래에 위치해야 범위 오류 안생김!!
	else if (w_dp[a][b][c] != 0)  //DP로 값을 찾을 수 있을 경우
	{
		return w_dp[a][b][c];  //DP에서 값을 찾아 리턴
	}

	else if (a < b && b < c)
	{
		w_dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);  //DP에 값 저장

		return w_dp[a][b][c];  //DP에서 값을 찾아 리턴
	}

	else  //기존과 동일하지만 바로 위의 경우처럼 DP에 값을 저장하고 리턴해주는 방식으로 변경
	{
		w_dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

		return w_dp[a][b][c];
	}

}