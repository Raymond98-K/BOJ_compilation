#include <iostream>
#include <vector>
using namespace std;

//�յڷ� ������ �����ϴ� �κм��� ~ ������ ~ �����ϴ� �κм��� ���� �� ���ϸ� �Ǵ� ����
//�ش� ������ �ε����� �������� ���� ���Ұ� �۴ٸ�/ũ�ٸ� DP����
//DP[n] = n��° ���ҿ� ���ؼ� ���� �� ������� ������ ����
//DP[N] = MAX( DP[������] + 1, DP[N] )

#define MAX_NUM 1001

vector<int> table(MAX_NUM);  //���� �Է¹��� �⺻ �迭
vector<int> going_up(MAX_NUM, 1);  //������ ���� ������ �����ϴ� �κм���. �ʱⰪ�� �ڱ��ڽ��� ���ԵǹǷ� 1
vector<int> going_down(MAX_NUM, 1);  //������ ���� �������� �����ϴ� �κм���. �ʱⰪ�� ���� ���� ������ 1

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

	for (int i = 1; i <= n; ++i)  //���ذ� �ݺ�
	{
		for (int j = 1; j <= i; ++j)  //���ذ� �������� �ݺ�
		{
			//���ذ��� ���簪���� ũ�� DP ���̰� ������ �ȴٸ�
			if (table[i] > table[j] && going_up[i] < going_up[j] + 1)
			{
				going_up[i] = going_up[j] + 1;  //DP ��¹迭 ����
			}
		}
	}

	for (int i = n; i > 0; --i)  //���� ����� ���������� �ڿ��� ����
	{
		for (int j = n; j >= i; --j)  //���� ����, �ڿ��� ����
		{
			//���ذ��� ���簪���� ũ�� DP ���̰� ������ �ȴٸ�
			if (table[i] > table[j] && going_down[i] < going_down[j] + 1)
			{
				going_down[i] = going_down[j] + 1;
			}
		}
	}

	int max_length = going_up[1] + going_down[1] - 1;  //-1 ���ϸ� �ش� ���ذ��� ��ħ!!!

	for (int i = 2; i <= n; ++i)
	{
		if (max_length < going_up[i] + going_down[i] - 1)  //���� �ִ� ���̰� ���� �κм������� �պ��� �۴ٸ�
		{
			max_length = going_up[i] + going_down[i] - 1;  //�ִ� ���� ����
		}
	}

	cout << max_length;  //���� ���

	return 0;
}