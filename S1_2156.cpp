#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//���Ǽ� �ִ� ��쿡 ���Ͽ� DP���, �ִ� ����
//table�� ������ �迭, wine�� DP��� ���� ��
//i��° ������ ���ο��� �����Ҷ� ���� ���� ���� �� �ִ� �� wine[i]��
// 1. i��°�� ������ �ʰ� �� ���������� ���� ��(3���� �Ұ������� ����)
// 2. i��°�� ���ð� i-1��°�� �ȸ��ð�, i-2��°������ ���� ��
// 3. i��°�� i-1��°�� ���ð� i-3��°������ ���ž� 
//�̷��� 3���� max���� �ȴ�.


int table[10001] = { 0, };  //������ �� �迭 �ʱ�ȭ
int wine[10001] = { 0, };  //����� DP �ʱ�ȭ

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> table[i];
	}

	wine[1] = table[1];
	wine[2] = wine[1] + table[2];  //�������� �ʱ�ȭ


	for (int i = 3; i <= n; ++i)
	{
		wine[i] = max(wine[i - 1], max(table[i] + wine[i - 2], table[i] + table[i - 1] + wine[i - 3]));
		//������ ���� ��ȭ���� ����� DP����
		//������� 1���� ���, 2���� ���, 3���� ��� �̴�.
	}


	cout << wine[n];  //�� ���


	return 0;
}