#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;


int B1_4884(void)
{
	vector<long> inputTest;

	long a;  //�ڷ��� ����!!
	int cnt = 0;

	do
	{
		scanf("%ld", &a);
		inputTest.push_back(a);

		if (a == -1)
		{
			cnt++;
		}

	} while (cnt != 4);  //-1 4�� ���ö����� �Է� �ޱ�


	for (long i = 0; i < inputTest.size(); ++i)
	{
		long X = 0;
		long Y = 0;
		long search = 0;  //2�� �¼�
		//i=G, i+1=T, i+2=A, i+3=D

		if (i % 4 == 0 && inputTest[i] != -1 )//4������� ��� ����
		{
			while (true) //Y�� ã��
			{

				if ( (pow(2, search)) <= (inputTest[i] * inputTest[i + 2] + inputTest[i + 3]) && (inputTest[i] * inputTest[i + 2] + inputTest[i + 3]) < pow(2, search + 1) )
				{
					if (pow(2, search) == (inputTest[i] * inputTest[i + 2] + inputTest[i + 3]))
					{
						Y = 0;
					}

					else
					{
						Y = pow(2, search + 1) - (inputTest[i] * inputTest[i + 2] + inputTest[i + 3]);
					}

					break;
				}

				else
				{
					search++;
				}
			}

			if (Y == 0)
			{
				X = (((inputTest[i + 1] * (inputTest[i + 1] - 1)) / 2) * inputTest[i]) + (pow(2, search) - 1);
			}

			else
			{
				X = (((inputTest[i + 1] * (inputTest[i + 1] - 1)) / 2) * inputTest[i]) + (pow(2, search + 1) - 1);
			}

			cout << inputTest[i] << "*" << inputTest[i + 2] << "/" << inputTest[i + 1] << "+" << inputTest[i + 3] << "=" << X << "+" << Y << endl;

		}

		else
		{
			continue;
		}
	}
	


	return 0;
}