#include <iostream>
using namespace std;

//������ ���� ������ �̾��� ���� ���ڴ� �ش� ������ ���ڸ��� ������ �ִ�.(1������ 0Ȥ�� 2 ����)
//0�� 9�� ���� 1�� 8 �̿ܿ��� �� �� ����.
//���� N�� ���ڿ� ���� 0�� 9�� ������ ���� i�� ������ ��� ���� ������ DP[N][i]�� �Ѵٸ� 
//DP[N][i] = DP[N-1][i-1] + DP[N-1][i+1]�� �����Ѵ�.
//0�� 9�� ���ؼ� DP[N][0] = DP[N-1][1], DP[N][9] = DP[N-1][8]�� �����Ѵ�.

#define RANGE_OF_N 101
#define RANGE_OF_NUM 10
#define MOD_RESULT 1000000000

void StairNumbers(int n);  //����� �Լ� �ʱ�ȭ.
int table[RANGE_OF_N][RANGE_OF_NUM] = { 0, };    //����� DP�ʱ�ȭ

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
	table[1][9] = 1; //���� ���� �ʱ�ȭ
	
	int result = 0;  //���� ��� ��
	int n;
	cin >> n;

	StairNumbers(n);  //�Լ� ����

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
	for (int i = 2; i <= n; ++i)  //���� ���� ��ŭ �ݺ� ���� i-1������ 2���� ����
	{
		for (int j = 0; j <= 9; ++j)  //0~9���� ���ڸ��� ����
		{
			if (j == 0)  //�켱 j==0�� ��� �� ���� ���� 1�� �� �� �ִ�.
			{
				table[i][0] = table[i - 1][1] % MOD_RESULT;
			}

			else if (j == 9)  // j==9��� �� ���� ���� 8�� �� �� �ִ�.
			{
				table[i][9] = table[i - 1][8] % MOD_RESULT;
			}

			else  //�� ���� ��쿣 �� �������� ���� �� ���ִ� ����� ��(+1,-1)�� ���� ���ϱ⸦ ������ �ش�.
			{
				table[i][j] = (table[i - 1][j - 1] + table[i - 1][j + 1]) % MOD_RESULT;
			}

		}
	}
}