#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


int B3_2455(void)
{
	vector<int> trainStop;
	int sum = 0;
	int temp = 0;

	for (int i = 0; i < 8; ++i)
	{
		int num;
		scanf("%d", &num);

		trainStop.push_back(num);
	}

	for (int i = 1; i < 9; ++i)
	{
		if (i % 2 != 0)  //내린사람
		{
			sum -= trainStop[i-1];
		}

		else
		{
			sum += trainStop[i-1];

			if (sum > temp)
			{
				temp = sum;
			}
		}
	}

	cout << temp;


	return 0;
}