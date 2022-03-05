#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int G3_24337(void)
{
	int totalApt;
	int leftStart;
	int rightStart;
	cin >> totalApt >> leftStart >> rightStart;

	if (totalApt < leftStart || totalApt < rightStart)
	{
		cout << -1;

		return 0;
	}

	if (totalApt + 1 < leftStart + rightStart)
	{
		cout << -1;

		return 0;
	}

	
	
	vector<int> arrApt(totalApt, 1);
	int isMax = leftStart > rightStart ? leftStart : rightStart;
	int isMin = leftStart < rightStart ? leftStart : rightStart;


	for (int i = 0; i < isMax; ++i)
	{
		arrApt[i] += i;
	}

	int cnt = 1;
	int add = 0;

	for (int i = isMax; i < totalApt; ++i)
	{
		cnt++;
		if (cnt <= isMin)
		{
			arrApt[i] += add;
			add++;
		}

		else
		{
			break;
		}
		
	}

	sort(arrApt.begin(), arrApt.end());

	for (int i = 0; i < totalApt; ++i)
	{
		cout << arrApt[i] << " ";
	}


	return 0;
}