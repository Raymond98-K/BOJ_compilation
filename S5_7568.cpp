#include <iostream>
#include <vector>
using namespace std;

//N이 최대 50까지이므로 현대과학을 믿고 그냥 반복문을 쓰자

int S5_7568(void)
{
	vector<pair<int, int>> table;

	int n;
	cin >> n;

	//N수 만큼 입력받아 pair에 저장 후 벡터에 넣기
	for (int i = 0; i < n; ++i)
	{
		int weight, tall;
		cin >> weight >> tall;

		pair<int, int> people(weight, tall);

		table.push_back(people);
	}

	vector<int> level(n, 1);//기본값이 1인 n만큼의 등수 벡터


	//몸무게와 키가 모두 다른 누군가 보다 작다면 등수를 ++
	for (int i = 0; i < n; ++i)
	{
		int targetWeight = table[i].first;
		int targetTall = table[i].second;

		for (int j = 0; j < n; ++j)
		{
			//자기 자신과 비교할 경우 의미가 없으므로 continue
			if (i == j)
			{
				continue;
			}
			int otherWeight = table[j].first;
			int otherTall = table[j].second;

			
			//몸무게와 키 둘다 비교
			if (targetWeight < otherWeight && targetTall < otherTall)
			{
				level[i]++;  //해당 target의 등수를 증가(등수가 1에 가까워야 덩치가 크다)
			}
		}
	}


	//마지막으로 모든 대상의 등수를 출력
	for (int i = 0; i < level.size(); ++i)
	{
		cout << level[i] << " ";
	}




	return 0;
}