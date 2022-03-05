#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"

//���ڸ� �����ϴ� ���� 1���� ��밡���� �������� Ƚ���� �����ϴ� ���� 1��, ����� ����� ���� 1�� ���
//�Լ�(�����, ������ ����, ���� ���� ��� Ƚ��, n) ����
//������ ���Ƚ���� 0 ���� ũ�� �ش� �ε����� ���� switch������ +-*/ ���� ���� ���Ϳ� ���� �� ������ Ƚ��--
//�Լ�(�����,������ ����, ���� Ƚ�� + 1, n) ���ȣ�� �� ���� ��� Ƚ�� == n �̸� ��� �� max, min �� ����
//���������� cout <<max<<min;

void solve(int result, vector<int> operators, int cnt, int n);
vector<int> table_14888(11);  //���� ����� ����
vector<int> available_operators_14888(4);  //������ ��� ���� Ƚ�� ����� ����
vector<int> use_operators_14888;  //���� ����� ������ ���� ����

int max_result = -1000000001;  //�ʱ� �ִ�
int min_result = 1000000001;  //�ʱ� �ּڰ�

int S1_14888(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)  //���ڵ� ����
	{
		cin >> table_14888[i];
	}

	for (int i = 0; i < 4; ++i)  //������ ��� Ƚ�� ����
	{
		cin >> available_operators_14888[i];
	}

	solve(table_14888[0], available_operators_14888, 1, n);  //result�� �ʱ갪�� ù��° �� cnt�� �ʱ갪�� 1


	cout << max_result << endl << min_result;

	return 0;
}


void solve(int result, vector<int> operators, int cnt, int n)
{
	if (cnt == n)  
	//���� ���� ��� Ƚ���� n�� ������ ���� ���࿡�� ����� �����ڸ� ��� ������ ���̴�.
	{

		for (int i = 1; i <= use_operators_14888.size(); ++i)  //����� ������ ���� ũ�� ��ŭ �ݺ�
		{
			switch (use_operators_14888[i - 1])  //����� �������� ��ȣ�� ���� switch
			{
			case 0:  // +=
			{
				result += table_14888[i];
				break;
			}

			case 1:  // -=
			{
				result -= table_14888[i];
				break;
			}

			case 2:  // *=
			{
				result *= table_14888[i];
				break;
			}

			case 3:  // /=
			{
				result /= table_14888[i];
				break;
			}
			}
		}

		//���� ������ �������� result�� ���Ͽ� max, min ��

		if (result > max_result)
		{
			max_result = result;
		}

		if (result < min_result)
		{
			min_result = result;
		}

		return;  //�Լ� ����
	}

	for (int i = 0; i < 4; ++i)  //��� ������ ������ ��� üũ
	{
		if (available_operators_14888[i] > 0)  //���� ��� ������ ������ Ƚ���� �����ִٸ�
		{
			switch (i)  //�������� ��ȣ�� ���� ����� �����ڿ� ����
			{
			case 0:
			{
				use_operators_14888.push_back(0);
				available_operators_14888[i]--;  //������ Ƚ�� ����
				break;
			}

			case 1:
			{
				use_operators_14888.push_back(1);
				available_operators_14888[i]--;
				break;
			}

			case 2:
			{
				use_operators_14888.push_back(2);
				available_operators_14888[i]--;
				break;
			}

			case 3:
			{
				use_operators_14888.push_back(3);
				available_operators_14888[i]--;
				break;
			}
			}

			solve(result, available_operators_14888, cnt + 1, n);  //���� ���� �ϳ� �ø��� ���ȣ��

			switch (i)  //�Լ� ȣ���� ������ ������ Ƚ���� ��� ������ �ѹ� ��Ų��.
			{
			case 0:
			{
				use_operators_14888.pop_back();  //����� �����ڿ��� pop()
				available_operators_14888[i]++;  //���Ƚ�� ����
				break;
			}

			case 1:
			{
				use_operators_14888.pop_back();
				available_operators_14888[i]++;
				break;
			}

			case 2:
			{
				use_operators_14888.pop_back();
				available_operators_14888[i]++;
				break;
			}

			case 3:
			{
				use_operators_14888.pop_back();
				available_operators_14888[i]++;
				break;
			}
			}

		}

	}

}