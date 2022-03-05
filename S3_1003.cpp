#include <iostream>
#include <vector>
using namespace std;

vector<int> fibo_DP_1003(41);  //����� DP �ʱ�ȭ

//������ �ִ� �Լ��� �״�� ����ϸ� �ð����ѿ� �ɸ���.
//DP�� ����ϵ��� ���� �Ͽ� �ð� ������ �� ����.
//�����ϸ鼭 �˰� �� ���. fibo(n)���� 0�� ���� Ƚ���� fibo(n-1)�� ����
//1�� ���� Ƚ���� fibo(n)�� ����. ��...

int fibonacci_1003(int n) {
	if (n == 0) {  //���� 0�� ��� zero ī��Ʈ ����

		return 0;
	}
	else if (n == 1) {  //���� 1�� ��� one ī��Ʈ ����

		return 1;
	}

	if (fibo_DP_1003[n] != 0)  //���� DP�� ����� ���� ���� ���
	{
		return fibo_DP_1003[n];  //�ش� ���� ����
	}


	else {
		fibo_DP_1003[n] = fibonacci_1003(n - 1) + fibonacci_1003(n - 2);

		return fibo_DP_1003[n];  //DP�� ���� ���� �� �ش� ���� ����
	}
}

int S3_1003(void)
{
	fibo_DP_1003[0] = 0;
	fibo_DP_1003[1] = 1;
	fibo_DP_1003[2] = 1;
	//DP�� ��������(ó���� ��������� �ϴ� ��) �ʱ�ȭ
	//�ش� �������� 0 1 1 2 3 5 ... �� �����ϱ⶧���� �׿� �°� �ʱ�ȭ ���ش�.


	int testCase;
	cin >> testCase;

	vector<int> table(testCase + 1);  //�׽�Ʈ ���̽� ��ŭ �迭 �ʱ�ȭ(0�� ���� = 0)

	for (int i = 1; i <= testCase; ++i)
	{
		cin >> table[i];
	}

	for (int i = 1; i <= testCase; ++i)
	{
		fibonacci_1003(table[i]);

		if (table[i] == 0)  //���� 0�ϰ�� ���� ���(���� ��)
		{
			cout << 1 << " " << 0 << "\n";
		}

		else  //�� ���� ��� �ش� �� ���� ��° �Ǻ���ġ ���� ���� �ش� ����°�� �Ǻ���ġ ���� �� ���
		{
			cout << fibo_DP_1003[table[i] - 1] << " " << fibo_DP_1003[table[i]] << "\n";  //���� ���
		}

	}

	return 0;
}