#include <iostream>
#include <vector>
using namespace std;

//�� ����� w(a,b,c) ���� ���� DP�� ����� Ȱ���غ���
//a b c�ϱ� �׳� 3���� �迭�� �Ẹ��

#define MAX_RANGE 21

int w(int a, int b, int c);  //�Լ� ����
vector<vector<vector<int>>> w_dp(MAX_RANGE, vector<vector<int>>(MAX_RANGE, vector<int>(MAX_RANGE)));  //DP�� 3���� ����
//==DP[21][21][21]

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	vector<int> table(4);  //���ڸ� ������ ���� �ʱ�ȭ

	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)  //���� �� -1�� ��� break
		{
			break;
		}

		else
		{
			table[1] = a;
			table[2] = b;
			table[3] = c;  //�� �Ҵ�
		}

		cout << "w(" << table[1] << ", " << table[2] << ", " << table[3] << ") = " << w(table[1], table[2], table[3]);
		cout << "\n";
		//�Լ� ȣ�� �� ��Ŀ� �°� ���

	}

	return 0;
}


int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)  //������ ����
	{
		return 1;
	}

	else if (a > 20 || b > 20 || c > 20)  //������ ����
	{
		return w(20, 20, 20);
	}

	//�Ʒ��� DP ������ �ִ� �κ��� 20���� ū ��� �Ʒ��� ��ġ�ؾ� ���� ���� �Ȼ���!!
	else if (w_dp[a][b][c] != 0)  //DP�� ���� ã�� �� ���� ���
	{
		return w_dp[a][b][c];  //DP���� ���� ã�� ����
	}

	else if (a < b && b < c)
	{
		w_dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);  //DP�� �� ����

		return w_dp[a][b][c];  //DP���� ���� ã�� ����
	}

	else  //������ ���������� �ٷ� ���� ���ó�� DP�� ���� �����ϰ� �������ִ� ������� ����
	{
		w_dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

		return w_dp[a][b][c];
	}

}