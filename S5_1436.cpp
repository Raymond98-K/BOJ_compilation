#include <iostream>
#include <string>
using namespace std;

//N�� �ִ��� 10000�̰� ���ѽð� 2��. �˳��ϴ�.

int S5_1436(void)
{
	int cnt = 0;  //n�� �񱳸� ���� count��
	int sixCnt;  //3�� �Ǹ� ������ ��
	int n;
	cin >> n;

	int target = 666;  //�⺻ ���۰�

	while (1)  //Ž�� ����
	{
		int temp = target;  //temp���� target���� ����
		sixCnt = 0;  //�ʱⰪ 0���� ����

		while (1)
		{
			if (temp % 10 == 6)  //temp�� �����ڸ� ���ڸ� �˻�
			{
				sixCnt++;  //6�̶�� sixCnt++

				if (sixCnt == 3)  //���ӵ� 6�� 3���� �𿴴ٸ�
				{
					cnt++;  //�ش� ���� cnt��° ������ ��
					sixCnt = 0;  //sixCnt �ʱ�ȭ

					break;  //�ݺ� ����
				}
			}

			else  //���� ���� �ڸ��� 6�� �ƴ϶��
			{
				sixCnt = 0;  //���ӵ� 6�� ���� ����ؾ� �ϹǷ� 0���� �ʱ�ȭ
			}

			temp = temp / 10;  //temp�� ����
			
			if (!temp)  //���� temp�� 0�̶��
			{
				break;  //target�� �ش��ϴ� ���� ��� �˻��ߴٴ� �����Ƿ� �ݺ� ����
			}
		}

		if (cnt == n)  //���� cnt�� �Է¹��� ���� ���ٸ�
		{
			cout << target;  //���� ���

			return 0;
		}

		else  //cnt�� �Է¹��� ���� �ƴ϶��
		{
			target++;  //target�� �������� ����
		}
	}

	
}