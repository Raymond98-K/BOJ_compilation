#include <iostream>
#include <vector>
using namespace std;

//DFS + ��Ʈ��ŷ
//15650 + 15651 ��, ���������� �̾Ƴ��� + �ߺ��Ȱ� ����ϱ� �� �����ȴ�.
//�񳻸������� �������� �� �ߺ��� ������ ��Ÿ���� ������ �� �� �ִ�. 
//�� �״�� 1 1 1 2 �� ���������� �ƴϴϱ� ������ �����Ѵ�.

//DFS�Լ� ����, num���� ���� �ϴ� �������� ������ ������Ų��.
void MyDFS(int N, int M, int cnt, int num, vector<int> table, vector<bool> isVisited);  

int S3_15652(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> table(9, 0);
	vector<bool> isVisited(9, false);  //���͵� �ʱ�ȭ (1~8 �̴� �˳��ϰ� + �������� ���� 9)

	int intN, intM;
	cin >> intN >> intM;

	MyDFS(intN, intM, 0, 1, table, isVisited);  //�Լ� ȣ��, num�� �ʱⰪ�� 1

	return 0;
}


void MyDFS(int N, int M, int cnt, int num, vector<int> table, vector<bool> isVisited)
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
			table[cnt + 1] = i;  //���Ϳ� �� ����

			//���� ������ ȣ��, �̹��� i+1�� �ƴ� i�� ȣ���ؼ� �������� ���� ��쵵 ����Ѵ�.
			MyDFS(N, M, cnt + 1, i, table, isVisited);  
		}

		//�ߺ��� ��� �ǹǷ� �ݺ��� �������� �湮�������� ����
		isVisited[i] = true;  
		
		
	}

	return;
}