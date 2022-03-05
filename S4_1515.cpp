#include <iostream>
#include <string>
using namespace std;

int S4_1515(void)
{
	string erased;
	cin >> erased;

	int checker = 0;
	int i = 0;

	while(i++<=30000)
	{
		cout << i;
		string testNum = to_string(i);

		for (int j = 0; j < testNum.length(); ++j)
		{
			if (testNum.at(j) == erased.at(checker))
			{
				checker++;
			}

			if (checker == erased.length())
			{
				cout << i;

				return 0;
			}

		}

	}

}