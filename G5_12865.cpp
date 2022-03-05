#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//가치, 무게, DP 이렇게 3가지 배열 사용
//점화식은 i번째 물건을 넣었을때 무게 j에 대해서 i번째를 안넣고(무게 초과)+그 이전꺼까지 vs i번째를 넣고 이전꺼도 넣는것 비교
//따라서 DP[i][j] = max(DP[i-1][j], 가치[i]+DP[i-1][j-무게[i]])

#define MAX_COUNT 101
#define MAX_WEIGHT 100001

vector<int> value(MAX_COUNT);  //i번째 물건의 가치를 나타내는 배열
vector<int> weight(MAX_COUNT);  //i번째 물건의 무게를 나타내는 배열
vector<vector<int>> knapsack(MAX_COUNT, vector<int>(MAX_WEIGHT));  
//사용할 DP. i번째 물건이 j무게일때의 가치
//예제1에서 (6, 13), (4, 8)에 대해서 DP[1][6] == 13, DP[2][4] == 8, DP[2][6] = 13

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;  //물품수와 최대무게 입력

	for (int i = 1; i <= n; ++i)
	{
		cin >> weight[i];
		cin >> value[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j - weight[i] >= 0)  //물건을 넣을 수 있다면
			{
				knapsack[i][j] = max(knapsack[i - 1][j], value[i] + knapsack[i - 1][j - weight[i]]);  //점화식을 통해 DP 작성
			}

			else  //물건을 못넣는다면
			{
				knapsack[i][j] = knapsack[i - 1][j];  //그 이전 DP값을 넣어준다.
			}


		}
	}

	cout << knapsack[n][k];  //답 출력

	return 0;
}