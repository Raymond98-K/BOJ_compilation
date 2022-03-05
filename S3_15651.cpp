#include <iostream>
#include <vector>
using namespace std;

//DFS + ��Ʈ��ŷ
//15650�� ��¦ �ٸ���. �̹��� �ߺ��� �Ű澲�� �ʰ� ����ؾ� �Ѵ�.
//��� ���� ������� �׷��� ����� ���� �ߺ��� �Ű�Ⱦ��� -> �׳� ��� ��츦 �� �̾ƶ��
//������ �ߺ��� ���� ����. 1 1 1 2 �� 1 1 2 1�� �ٸ��ϱ�.

//DFS�Լ� ����
void MyDFS(int N, int M, int cnt, vector<int> table);

int S3_15651(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> table(9, 0);
	//�̹����� �湮�� üũ�ϴ� ���Ͱ� ���� ������ �ʿ䰡 ����.

	int intN, intM;
	cin >> intN >> intM;

	MyDFS(intN, intM, 0, table);  //�Լ� ȣ��

	return 0;
}


//cnt == intM�̶�� ���������� ��� ����� ������ ����ϰ�
//cnt != intM�̶�� isVisited�� true�� �ϰ� MyDFS(int N, int M, cnt + 1)�� ȣ��
void MyDFS(int N, int M, int cnt, vector<int> table)
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

	for (int i = 1; i <= N; ++i)  //�װ� �ƴ϶��
	{
		//Ư���� ���� ���� ��ü�� �� �ݺ��Ѵ�.

		table[cnt + 1] = i;  //���Ϳ� �� ����
		MyDFS(N, M, cnt + 1, table);  //���� ������ ȣ��. 

	}

	return;
}