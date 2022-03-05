#include <iostream>
#include <vector>
using namespace std;

//������������ �����鿡 ���� �ݺ����� ������
//K>=����[i]��� K-=����[i], cnt++�� ����
//�������� cout<<cnt;

int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int>coins(n);  //�������� ����� ���� ����

	for (int i = n - 1; i >= 0; --i)
	{
		cin >> coins[i];  //�迭�� �������� ����(������������ �Է�->������������ ����)
	}

	int cnt = 0;  //���� ���� ���� �ʱ�ȭ


	for (int i = 0; i < n; ++i)  //�ٸ� ������� Ǯ��
	{
		if (k == 0)
		{
			break;  //������ ����
		}

		else if (k >= coins[i])
		{
			cnt += k / coins[i];  //���� ������ ��ġ�� / ���� ������ ��
			k %= coins[i];  //��ġ���� ������ ��ġ�� % ���� ������ ��

			//�̷��� �ϸ� i���� ���� ���� ������ ���� �ʾƵ� �ȴ�.
			//�ð��� 56ms -> 0ms �� ����
		}

	}


	/*
	for (int i = 0; i < n; ++i)
	{
		if (k == 0)
		{
			break;  //��ġ���� 0�̶�� break;
		}

		else if (k >= coins[i])  //���� ������ ���� ��ġ���� ���� �ʴ´ٸ�
		{
			k -= coins[i];  //��ġ�� ����
			cnt++;

			i--;  
			//i���� �Ѿ�� �ʰ�(���� �ݾ��� ������ ����� �� �ְ�) --����
			//���� ++�� ������ i���� �����ǰ� ����1���� 4200���� 1000�� ��� ���� ����� �� �ִ�. 
		}
	}
	*/

	cout << cnt;


	return 0;
}