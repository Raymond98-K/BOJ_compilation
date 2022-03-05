#include <iostream>
#include <queue>
using namespace std;

//깊이 우선이던 넓이 우선이던 1260번과 비슷하게 풀이하면 된다.

#define MAX_CNT 101

int computer_graph[MAX_CNT][MAX_CNT] = { 0, };  //사용할 인접행렬 초기화, 초깃값 == 0
bool is_infected[MAX_CNT] = { false, };  //감염여부 확인용 배열 초기화
int worm_cnt = 0;  //출력할 답안
queue<int> queue_worm;  //BFS에서 사용할 큐 선언

void DFS(int infected, int total);  //깊이 우선 탐색 함수 선언
void BFS(int infected, int total);  //너비 우선 탐색 함수 선언

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int computer_total;
	cin >> computer_total;

	int computer_linked;
	cin >> computer_linked;

	for (int i = 1; i <= computer_linked; ++i)
	{
		int first_computer;
		int second_computer;
		cin >> first_computer >> second_computer;

		computer_graph[first_computer][second_computer] = 1;
		computer_graph[second_computer][first_computer] = 1;  //컴퓨터간 간선 초기화
	}

	//DFS(1, computer_total);

	BFS(1, computer_total);
	
	cout << worm_cnt;

	return 0;
}


void DFS(int infected, int total)
{
	is_infected[infected] = 1;  //최초 감염인 1번 컴퓨터 감염 표시

	for (int i = 1; i <= total; ++i)
	{
		if (computer_graph[infected][i] == 1 && is_infected[i] == 0)  //컴퓨터끼리 연결되어 있고 감염이 되어 있지 않다면
		{
			is_infected[i] = 1;  //다음 컴퓨터의 감염 표시
			worm_cnt++;  //카운트 증가

			DFS(i, total);  //다음 컴퓨터를 기준으로 반복
		}
	}


}

void BFS(int infected, int total)
{
	is_infected[infected] = 1;  //감염된 컴퓨터 감염 표시
	queue_worm.push(infected);  //큐에 enqueue

	while (queue_worm.empty() == false)
	{
		infected = queue_worm.front();  //front값 할당
		queue_worm.pop();  //pop을 통해 큐 갱신

		for (int i = 1; i <= total; ++i)
		{
			if (computer_graph[infected][i] == 1 && is_infected[i] == 0)  //컴퓨터끼리 연결되어 있고 감염이 되어 있지 않다면
			{
				is_infected[i] = 1;  //감염여부 갱신
				queue_worm.push(i);  //큐에 push
				worm_cnt++;  //카운트 증가
			}
		}
	}

}
