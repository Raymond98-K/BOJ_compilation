#include <iostream>
#include <vector>
using namespace std;

//DFS + ��Ʈ��ŷ
//cnt�� M�� ���� �� �� ���� isVisited���� ������ ���� ���͸� ����� ���

void MyDFS_15649(int N, int M, int cnt);  //DFS�Լ� ����

vector<int> table_15649(9, 0);
vector<bool> isVisited_15649(9, false);  //���͵� �ʱ�ȭ (1~8 �̴� �˳��ϰ� + �������� ���� 9)

int S3_15649(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int intN, intM;
	cin >> intN >> intM;

	MyDFS_15649(intN, intM, 0);  //�Լ� ȣ��

	return 0;
}


//cnt == intM�̶�� ���������� ��� ����� ������ ����ϰ�
//cnt != intM�̶�� isVisited�� true�� �ϰ� MyDFS(int N, int M, cnt + 1)�� ȣ��
void MyDFS_15649(int N, int M, int cnt)
{
	if (cnt == M)  //intM��ŭ�� ���� �迭�� ����Ǿ��ٸ� ���
	{
		for (int i = 1; i <= cnt; ++i)
		{
			cout << table_15649[i] << " ";
		}

		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; ++i)  //�װ� �ƴ϶�� ��Ʈ��ŷ ����
	{
		if (isVisited_15649[i] == false)  //���� �湮�� ������ ����
		{
			isVisited_15649[i] = true;  //�湮�������� ����
			table_15649[cnt + 1] = i;  //���Ϳ� �� ����
			MyDFS_15649(N, M, cnt + 1);  //���� ������ ȣ��
			isVisited_15649[i] = false;  //�ش� ����� ��� ���� üũ�� ���� �湮�� �ٽ� ���������� ����
		}
	}

	return;
}