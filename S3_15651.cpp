#include <iostream>
#include <vector>
using namespace std;

//DFS + 백트래킹
//15650과 살짝 다르다. 이번엔 중복을 신경쓰지 않고 계산해야 한다.
//사실 말이 어려워서 그렇지 까놓고 보면 중복을 신경안쓴다 -> 그냥 모든 경우를 다 뽑아라다
//수열이 중복될 수는 없다. 1 1 1 2 와 1 1 2 1은 다르니까.

//DFS함수 선언
void MyDFS(int N, int M, int cnt, vector<int> table);

int S3_15651(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> table(9, 0);
	//이번에는 방문을 체크하는 벡터가 따로 존재할 필요가 없다.

	int intN, intM;
	cin >> intN >> intM;

	MyDFS(intN, intM, 0, table);  //함수 호출

	return 0;
}


//cnt == intM이라면 이전까지의 모든 저장된 순서를 출력하고
//cnt != intM이라면 isVisited를 true로 하고 MyDFS(int N, int M, cnt + 1)을 호출
void MyDFS(int N, int M, int cnt, vector<int> table)
{
	if (cnt == M)  //intM만큼의 수가 배열에 저장되었다면 출력
	{
		for (int i = 1; i <= cnt; ++i)
		{
			cout << table[i] << " ";
		}

		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; ++i)  //그게 아니라면
	{
		//특별한 조건 없이 전체를 다 반복한다.

		table[cnt + 1] = i;  //벡터에 값 저장
		MyDFS(N, M, cnt + 1, table);  //다음 순서를 호출. 

	}

	return;
}