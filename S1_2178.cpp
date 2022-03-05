#include <iostream>
#include <queue>
using namespace std;

//최단경로는 BFS로 풀어야 시간초과가 발생하지 않는다!!!!
//좌표이동체크(미로 범위 내의 이동인지), 길체크(해당 칸이 1인지 0인지), 방문체크(이미 방문 한 곳인지)
//좌표 이동에서 이동 가능 방향은 위, 아래, 왼쪽, 오른쪽이다.

#define MAX_NUM 101

string maze[MAX_NUM] = { "0", };  //미로 초기화
bool is_visited[MAX_NUM][MAX_NUM] = { false, };  //방문 여부 초기화
int move_cnt[MAX_NUM][MAX_NUM] = { 0, };  //각 칸별 이동 횟수 배열 초기화
int movement_x[5] = { 0, 0, 0, -1, 1 };  //위 아래 왼쪽 오른쪽에 대한 x좌표 변화량(첫 0은 무시)
int movement_y[5] = { 0, -1, 1, 0, 0 };  //위 아래 왼쪽 오른쪽에 대한 y좌표 변화량(첫 0은 무시)
queue<pair<int, int>> maze_queue;  //사용할 큐 초기화. 좌표를 담기위해 pair형으로 선언
int n, m;  //문제의 N과 M

void BFS(int x, int y);  //BFS 함수 선언

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		string my_string;
		cin >> my_string;
		my_string = "0" + my_string;  //좌표 통일을 위해 앞에 "0"을 넣은 상태로 미로에 넣어준다.

		maze[i] = my_string;
	}

	BFS(1, 1);  //함수 호출

	return 0;
}

void BFS(int x, int y)
{
	maze_queue.push(make_pair(x, y));  //큐에 좌표 입력
	is_visited[x][y] = true;  //방문 표시
	move_cnt[x][y] = 1;

	while (maze_queue.empty() == false)  //큐가 공백이 될때까지
	{
		int location_x = maze_queue.front().first;
		int location_y = maze_queue.front().second;  //x, y 좌표값 복사
		maze_queue.pop(); //pop을 통해 큐 갱신

		for (int i = 1; i <= 4; ++i)
		{
			int next_x = location_x + movement_x[i];
			int next_y = location_y + movement_y[i];  //다음 좌표 계산(위, 아래, 왼쪽, 오른쪽 순서)

			if (next_x > 0 && next_x <= m && next_y > 0 && next_y <= n)  //미로 범위 내인지 체크
			{
				if (maze[next_y][next_x] == '1' && is_visited[next_x][next_y] == false)  //칸이 '1'이고(좌표 주의) 방문한적이 없는지 체크
				{
					maze_queue.push(make_pair(next_x, next_y));  //큐에 삽입
					is_visited[next_x][next_y] = true;  //방문 표시
					move_cnt[next_x][next_y] = move_cnt[location_x][location_y] + 1;  //이동횟수 갱신

					if (next_x == m && next_y == n)  //만약 도착했을 경우
					{
						cout << move_cnt[next_x][next_y];

						exit(0);  //프로그램 즉시 종료
					}


				}
			}

		}

	}

}