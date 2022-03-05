#include <iostream>
#include <vector>
using namespace std;

//계수정렬(counting sort)를 사용해 보자

vector<int> counting(10001);  //계수정렬용

int S5_10989(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int intN;
	cin >> intN;
	
	for (int i = 0; i < intN; ++i)
	{
		int num;
		cin >> num;

		counting[num]++;
	}


	for (int i = 1; i < 10001; ++i)
	{
		if (counting[i])
		{
			for (int j = counting[i]; j > 0; --j)
			{
				cout << i << "\n";
			}
		}
	}

	return 0;
}