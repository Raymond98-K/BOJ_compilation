#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1����Ģ�� DP[N] = DP[N/3] + 1, 2����  DP[N] = DP[N/2] + 1, 3���� DP[N-1] + 1 �̴�.
//�ٸ� ����2�� 10�� ���� ��� 2�� ������ ������ 2�� ������ 5���� -1 ���� 4���� �ٽ� /2, 2���� /2�� �Ѱ��� �ƴ϶�
//ó���� -1, 9���� /3, 3���� /3�� �� ���� �ּڰ��̴�. 
//�׷� ������ ������ ������ �����°��� ������ �ƴ϶�� ��
//�׳� ���غ��� min()�Լ��� ���ؼ� �������

#define MAX_NUM 1000001

vector<int> table(MAX_NUM, MAX_NUM);  //����� DP�� �迭 ����

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
	//���� ���� �ʱ�ȭ
	//1�� ������ �ʿ����, 2�� -1Ȥ��/2, 3�� /3 �ѹ����� 1�� ���� �� �ִ�.


	for (int i = 4; i <= n; ++i)  //�� ���� ����
	{
		if (i % 3 == 0)  //�ش� ���� 1��° ������ �����Ѵٸ�
		{
			table[i] = table[i / 3] + 1;
		}

		//else if�� �ƴ϶� if��. i�� 2�� 3�� ������� �� ���� �ٸ� �� �����ϱ� ��������
		if (i % 2 == 0)  //�ش� ���� 2��° ������ �����Ѵٸ�
		{
			table[i] = min(table[i], table[i / 2] + 1);
		}

		//���������� 3�� ���ǿ� ���ؼ� �˻�
		table[i] = min(table[i], table[i - 1] + 1);
		
	}

	cout << table[n];  //�� ���


	return 0;
}