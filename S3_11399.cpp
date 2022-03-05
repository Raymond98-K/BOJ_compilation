#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//�׸��� �˰���
//�� ��� �ջ������ �ð��� ��� �����ȴ� ����̴�.
//���� �ð��� ���� �ɸ��� ������� ����� �ؾ� �Ѵ�.

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;

	vector<int> people(n + 1);  //����� �迭 �ʱ�ȭ
	vector<int> time(n + 1);  //�� �ο��� �ҿ�ð� �迭 �ʱ�ȭ

	for (int i = 1; i <= n; ++i)
	{
		cin >> time[i];
	}

	sort(time.begin(), time.end());  //�������� ����

	int result = 0;  //��°� �ʱ�ȭ
	int time_cnt = 0;  //���� �ҿ�ð��� �ʱ�ȭ
	for (int i = 1; i <= n; ++i)
	{
		time_cnt += time[i];  //�����ð� ���
		result += time_cnt;  //�� ���
	}

	cout << result;  //���

	return 0;
}