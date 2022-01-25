#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;


int B2_13458(void)
{
	long long totalRoom;  //전체 방 갯수
	long long B;  //총감독관이 커버칠 수 있는 인원 수
	long long C;  //부감독관이 ""

	long long sum = 0;  //전체 감독관 수

	cin >> totalRoom;
	vector<int> people;  //각 방별 인원 수 벡터

	for (int i = 0; i < totalRoom; ++i)
	{
		long long pp;  //방별 인원 수

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