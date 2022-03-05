#include <iostream>
#include <vector>
using namespace std;

//DFS + 백트래킹
//15650 + 15651 즉, 오름차순만 뽑아내기 + 중복된거 허용하기 로 정리된다.
//비내림차순은 오름차순 중 중복이 허용됨을 나타내는 말임을 알 수 있다. 
//말 그대로 1 1 1 2 라도 내림차순은 아니니까 조건을 만족한다.

//DFS함수 선언, num값을 통해 일단 오름차순 조건을 만족시킨다.
void MyDFS(int N, int M, int cnt, int num, vector<int> table, vector<bool> isVisited);  

int S3_15652(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> table(9, 0);
	vector<bool> isVisited(9, false);  //벡터들 초기화 (1~8 이니 넉넉하게 + 직관성을 위해 9)

	int intN, intM;
	cin >> intN >> intM;

	MyDFS(intN, intM, 0, 1, table, isVisited);  //함수 호출, num의 초기값은 1

	return 0;
}


void MyDFS(int N, int M, int cnt, int num, vector<int> table, vector<bool> isVisited)
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
			table[cnt + 1] = i;  //벡터에 값 저장

			//다음 순서를 호출, 이번엔 i+1이 아닌 i를 호출해서 이전값과 같을 경우도 고려한다.
			MyDFS(N, M, cnt + 1, i, table, isVisited);  
		}

		//중복이 허용 되므로 반복의 마지막에 방문했음으로 갱신
		isVisited[i] = true;  
		
		
	}

	return;
}