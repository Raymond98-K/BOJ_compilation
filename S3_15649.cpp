#include <iostream>
#include <vector>
using namespace std;

//DFS + 백트래킹
//cnt가 M과 같아 질 때 까지 isVisited값을 갱신해 가며 벡터를 만들고 출력

void MyDFS_15649(int N, int M, int cnt);  //DFS함수 선언

vector<int> table_15649(9, 0);
vector<bool> isVisited_15649(9, false);  //벡터들 초기화 (1~8 이니 넉넉하게 + 직관성을 위해 9)

int S3_15649(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int intN, intM;
	cin >> intN >> intM;

	MyDFS_15649(intN, intM, 0);  //함수 호출

	return 0;
}


//cnt == intM이라면 이전까지의 모든 저장된 순서를 출력하고
//cnt != intM이라면 isVisited를 true로 하고 MyDFS(int N, int M, cnt + 1)을 호출
void MyDFS_15649(int N, int M, int cnt)
{
	if (cnt == M)  //intM만큼의 수가 배열에 저장되었다면 출력
	{
		for (int i = 1; i <= cnt; ++i)
		{
			cout << table_15649[i] << " ";
		}

		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; ++i)  //그게 아니라면 백트래킹 개시
	{
		if (isVisited_15649[i] == false)  //아직 방문을 안했을 때만
		{
			isVisited_15649[i] = true;  //방문했음으로 갱신
			table_15649[cnt + 1] = i;  //벡터에 값 저장
			MyDFS_15649(N, M, cnt + 1);  //다음 순서를 호출
			isVisited_15649[i] = false;  //해당 경우의 모든 수를 체크한 이후 방문을 다시 안했음으로 갱신
		}
	}

	return;
}