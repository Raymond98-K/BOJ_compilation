#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
int main(void)
{
	vector<int> tall;  //배열
	int sum = 0;

	for (int i = 0; i < 9; ++i)
	{
		int num;
		cin >> num;

		tall.push_back(num);
		sum += num;	
	}

	int cnt = 0;  //에이 설마 
	for (int i = 0; i < 8; ++i)
	{
		for (int j = i+1; j < 9; ++j)
		{
			if (sum - (tall[i] + tall[j]) == 100 && cnt == 0)
			{
				tall[i] = 0;
				tall[j] = 0;
			
				cnt++;  //아니 진짜 이게 문제라고???
			}
		}
	}

	sort(tall.begin(), tall.end());



	for (int i = 2; i < tall.size(); ++i)
	{
		cout << tall[i] << endl;
	}


	return 0;
}
*/

// 처음에는 오름차순인거 안보고 풀다가 틀렸고
// 그 이후 수십분동안 세상에 저 cnt저거때문에 말아먹음
// 아니 여러개가 0이 되는 경우는 생각지도 못했네 진짜....