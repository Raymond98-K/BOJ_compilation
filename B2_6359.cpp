#include <iostream>
#include <vector>
using namespace std;


int B2_6359(void)
{
	int T;
	cin >> T;

	while (T--)
	{
		int rooms;
		cin >> rooms;

		vector<int> isOpen(rooms + 1, 0);
		
		for (int i = 1; i <= rooms; ++i)
		{
			for (int j = 1; j*i <= rooms; ++j)
			{
				if (isOpen[i * j] == 0)
				{
					isOpen[i * j] = 1;
				}

				else
				{
					isOpen[i * j] = 0;
				}
			}
		}

		int sum = 0;
		for (int i = 1; i < rooms + 1; ++i)
		{
			sum += isOpen[i];
		}
		cout << sum << endl;
	}

	return 0;
}

/*
int main(void)
{
	int T;
	cin >> T;
	vector<int> rooms;

	for (int i = 0; i < T; ++i)
	{
		int a;
		cin >> a;

		rooms.push_back(a);
	}

	
	
	for (int i = 0; i < T; ++i)
	{
		int cnt = 0;
		for (int j = 1; j < rooms[i]; ++j)
		{
			if (j * j <= rooms[i])
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}

	

}
*/