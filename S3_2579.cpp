#include <iostream>
#include <algorithm>
using namespace std;
//� ��� n�� ���ؼ� �� ����� ��������� �ִ��� �ٷ� ���� ����� ����� ��� Ȥ�� 2ĭ ���� ����� ����� ���� ���� �� �ִ�.
//�׷��� ������ ����� ������ ��ƾ� �Ѵٴ� ������ �ִ�.
//�׷��ٸ� ������ ��ܱ������� �� ��ĭ�� ���� �ʾҴٸ� DP[N] = DP[N-2] + ������ ��� ����
//�� ��ĭ�� ��Ҵٸ� DP[N] = DP[N-3] + ������ �� ��� ���� + ������ ��� ������ �ȴ�.
//���� �� ���� ���� �� ū ����(max�Լ� Ȱ��) DP�� �����ϸ� �ȴ�.
//�߰�) �迭�� DP�ϳ��� ����� ��� ���� ����� �� ����� ������ ������� ����� �� ���� �ȴ�. �׳� �迭 �ΰ� ����.

#define MAX_NUM 301

int table[MAX_NUM] = { 0, };  //����� DP �迭 ����
int stairs[MAX_NUM] = { 0, };  //�Է¹��� ��� ���� ����� �迭 ����

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int total_stairs;
	cin >> total_stairs;  //�� ��� ���� �Է�

	for (int i = 1; i <= total_stairs; ++i)
	{
		cin >> stairs[i];  //�� ����� ���� �Է�
	}

	table[1] = stairs[1];
	table[2] = stairs[1] + stairs[2];
	table[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);  //���� ���� �ʱ�ȭ
	//���� ù��°, �ι�°, ����° ��ܿ� ���ؼ� DP�� �迭�� ���� �����ߴ�.
	//ù��°�� �׳� ù��° ����� ����, �ι�°�� ù��°�� �ι�° ����� ��� ����� ��,
	//���������� ����°�� (ù��° + ����°)�� ���� (�ι�° + ����°)�� ���ؼ� ���� ū ���� �����Ѵ�.
	
	for (int i = 4; i <= total_stairs; ++i)  //���� 4��° ��ܿ��� ����
	{
		//��ȭ�Ŀ� �°� ���� ���� ����
		table[i] = max(table[i - 2] + stairs[i], table[i - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << table[total_stairs];  //���� �� ���

	return 0;
}
