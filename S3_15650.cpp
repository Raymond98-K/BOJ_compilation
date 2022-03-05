#include <iostream>
#include <vector>
using namespace std;

//DFS + 백트래킹
//15649와 기본적으로 같지만 오름차순이라는 조건을 하나 더 추가한다.

void MyDFS_15650(int N, int M, int cnt, int num, vector<int> table, vector<bool> isVisited);  //DFS함수 선언, num값을 통해 오름차순 조건을 만족시킨다.

int S3_15650(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> table(9, 0);
	vector<bool> isVisited(9, false);  //벡터들 초기화 (1~8 이니 넉넉하게 + 직관성을 위해 9)

	int intN, intM;
	cin >> intN >> intM;

	MyDFS_15650(intN, intM, 0, 1, table, isVisited);  //함수 호출, num의 초기값은 1

	return 0;
}


//cnt == intM이라면 이전까지의 모든 저장된 순서를 출력하고
//cnt != intM이라면 isVisited를 true로 하고 MyDFS(int N, int M, cnt + 1)을 호출
void MyDFS_15650(int N, int M, int cnt, int num, vector<int> table, vector<bool> isVisited)
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

	for (int i = num; i <= N; ++i)  //그게 아니라면 백트래킹 개시, 이번엔 i=num부터다.
	{
		if (isVisited[i] == false)  //아직 방문을 안했을 때만
		{
			isVisited[i] = true;  //방문했음으로 갱신
			table[cnt + 1] = i;  //벡터에 값 저장
			MyDFS_15650(N, M, cnt + 1, i + 1, table, isVisited);  //다음 순서를 호출, i+1을 호출해서 이전값보다 같거나 작을 경우를 배제한다.
			isVisited[i] = false;  //해당 경우의 모든 수를 체크한 이후 방문을 다시 안했음으로 갱신
		}
	}

	return;
}