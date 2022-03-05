#include <iostream>
#include <vector>
using namespace std;

//DFS + ��Ʈ��ŷ
//15649�� �⺻������ ������ ���������̶�� ������ �ϳ� �� �߰��Ѵ�.

void MyDFS_15650(int N, int M, int cnt, int num, vector<int> table, vector<bool> isVisited);  //DFS�Լ� ����, num���� ���� �������� ������ ������Ų��.

int S3_15650(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> table(9, 0);
	vector<bool> isVisited(9, false);  //���͵� �ʱ�ȭ (1~8 �̴� �˳��ϰ� + �������� ���� 9)

	int intN, intM;
	cin >> intN >> intM;

	MyDFS_15650(intN, intM, 0, 1, table, isVisited);  //�Լ� ȣ��, num�� �ʱⰪ�� 1

	return 0;
}


//cnt == intM�̶�� ���������� ��� ����� ������ ����ϰ�
//cnt != intM�̶�� isVisited�� true�� �ϰ� MyDFS(int N, int M, cnt + 1)�� ȣ��
void MyDFS_15650(int N, int M, int cnt, int num, vector<int> table, vector<bool> isVisited)
{
	if (cnt == M)  //intM��ŭ�� ���� �迭�� ����Ǿ��ٸ� ���
	{
		for (int i = 1; i <= cnt; ++i)
		{
			cout << table[i] << " ";
		}

		cout << "\n";

		return;
	}

	for (int i = num; i <= N; ++i)  //�װ� �ƴ϶�� ��Ʈ��ŷ ����, �̹��� i=num���ʹ�.
	{
		if (isVisited[i] == false)  //���� �湮�� ������ ����
		{
			isVisited[i] = true;  //�湮�������� ����
			table[cnt + 1] = i;  //���Ϳ� �� ����
			MyDFS_15650(N, M, cnt + 1, i + 1, table, isVisited);  //���� ������ ȣ��, i+1�� ȣ���ؼ� ���������� ���ų� ���� ��츦 �����Ѵ�.
			isVisited[i] = false;  //�ش� ����� ��� ���� üũ�� ���� �湮�� �ٽ� ���������� ����
		}
	}

	return;
}