#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��ġ, ����, DP �̷��� 3���� �迭 ���
//��ȭ���� i��° ������ �־����� ���� j�� ���ؼ� i��°�� �ȳְ�(���� �ʰ�)+�� ���������� vs i��°�� �ְ� �������� �ִ°� ��
//���� DP[i][j] = max(DP[i-1][j], ��ġ[i]+DP[i-1][j-����[i]])

#define MAX_COUNT 101
#define MAX_WEIGHT 100001

vector<int> value(MAX_COUNT);  //i��° ������ ��ġ�� ��Ÿ���� �迭
vector<int> weight(MAX_COUNT);  //i��° ������ ���Ը� ��Ÿ���� �迭
vector<vector<int>> knapsack(MAX_COUNT, vector<int>(MAX_WEIGHT));  
//����� DP. i��° ������ j�����϶��� ��ġ
//����1���� (6, 13), (4, 8)�� ���ؼ� DP[1][6] == 13, DP[2][4] == 8, DP[2][6] = 13

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;  //��ǰ���� �ִ빫�� �Է�

	for (int i = 1; i <= n; ++i)
	{
		cin >> weight[i];
		cin >> value[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j - weight[i] >= 0)  //������ ���� �� �ִٸ�
			{
				knapsack[i][j] = max(knapsack[i - 1][j], value[i] + knapsack[i - 1][j - weight[i]]);  //��ȭ���� ���� DP �ۼ�
			}

			else  //������ ���ִ´ٸ�
			{
				knapsack[i][j] = knapsack[i - 1][j];  //�� ���� DP���� �־��ش�.
			}


		}
	}

	cout << knapsack[n][k];  //�� ���

	return 0;
}