#include <iostream>
#include <cstdio>
using namespace std;


int B4_10797()
{
	int day;
	int num[5];
	int sum = 0;

	cin >> day;

	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < 5; ++i)
	{
		if (day == num[i])
		{
			sum++;
		}
	}

	cout << sum;
	
	return 0;
}