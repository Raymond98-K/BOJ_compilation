#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;


int B2_13458(void)
{
	long long totalRoom;  //��ü �� ����
	long long B;  //�Ѱ������� Ŀ��ĥ �� �ִ� �ο� ��
	long long C;  //�ΰ������� ""

	long long sum = 0;  //��ü ������ ��

	cin >> totalRoom;
	vector<int> people;  //�� �溰 �ο� �� ����

	for (int i = 0; i < totalRoom; ++i)
	{
		long long pp;  //�溰 �ο� ��

		scanf("%d", &pp);

		people.push_back(pp);

	}

	cin >> B >> C;



	for (int i = 0; i < totalRoom; ++i)
	{
		if (people[i] <= B)
		{
			sum += 1;
		}

		else {
			int isZero = 0;

			isZero = (people[i] - B) % C;

			if (isZero == 0)
			{
				sum += 1 + (people[i] - B) / C;
			}

			else
			{
				sum += 2 + (people[i] - B) / C;
			}
		}
	}

	cout << sum;

	return 0;
}