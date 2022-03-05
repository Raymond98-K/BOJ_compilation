#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

//15650?? �� ����� ���� �ε� �״�� �ϴϱ� �ð��ʰ��� ��� 
//14/23�� �������� 23/14�� �� �ʿ䰡 �����ϱ� �̸� �ذ��ؾ� �Ѵ�.
//���� ���Ͷ� �����ǰ�?????

#define maxMembers 21  //���� �ִ� �ο�

void MakeTeam(int member, int cnt, int n);  
//member�� ���� ������ ���� ��� ��ȣ, cnt�� ���� �� ������ ���� ��� ��
int result = 999999999;  //���� ��� ��. �ʱⰪ�� �������� �Ұ����� ������ ����.
int soccer[maxMembers][maxMembers];  //���� ���� ���� -> �迭�� ����
bool is_in_team[maxMembers];  //�ش� ��ȣ�� ����� ���� ���� �ִ��� Ȯ�ο� ���� -> �迭�� ����

int S2_14889(void)
{
	time_t start, end;
	double time_check;

	start = time(NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> soccer[i][j];
		}
	}

	MakeTeam(1, 0, n);  //�Լ� ȣ��

	cout << result;  //���


	end = time(NULL);

	time_check = (double)(end - start);
	cout << time_check/CLOCKS_PER_SEC;

	return 0;
}


void MakeTeam(int member, int cnt, int n)
{
	if (cnt == n / 2)  //������ �Ǹ� �� ������ �Ϸ�� ��
	{
		int sum_of_start = 0;  //start ���� �Ŀ� �ʱ�ȭ
		int sum_of_link = 0;  //link ���� �Ŀ� �ʱ�ȭ
		int calc = 0;  //�� �� �Ŀ� ���� �ʱ�ȭ

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (is_in_team[i] == true && is_in_team[j] == true)  //�Ѵ� start ���� �ִٸ�
				{
					sum_of_start += soccer[i][j];  //start�� ���Ŀ� ����
				}

				if (is_in_team[i] == false && is_in_team[j] == false)  //�Ѵ� link ���� �ִٸ�
				{
					sum_of_link += soccer[i][j];  //link�� ���Ŀ� ����
				}
			}

		}

		//���Ŀ��� ���� ������ result ����
		calc = abs(sum_of_start - sum_of_link);

		if (result > calc)
		{
			result = calc;
		}

		return;  //�Լ� ����
	}

	//�װ� �ƴ϶�� ������ ��츦 ���� ã�ƺ���.
	//��, �ο��� 6���� ��츦 ���÷� ù��° ������ i=1�϶� ������ ������ 156 / 234 �� 
	//ù��° ������ i=2�϶� �� ó�� ������ 234/ 156 �� ����.
	//���� ������ cnt+1<= i < N ���� �ϸ� �� �¾� ��������.
	
	for (int i = member; i < n; ++i)
	{
		is_in_team[i] = true;  //�ش� �ο��� ��(start) ���� ���θ� ���� false -> true 
		MakeTeam(member + 1, cnt + 1, n);  //���� �ο��� ���� �Լ� ȣ��
		//�Լ��� �����ٸ� �ش� �ο��� ���� ������ ���� ��
		is_in_team[i] = false;  //�ش� �ο��� �� ���� ���θ� ���� true -> false
	}

}


//���Ͷ� �迭 �ð����� �� 30ms





