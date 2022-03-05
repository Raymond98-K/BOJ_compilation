#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//최단 이므로 BFS 사용
//이중 배열로 저장후 좌표이동(위, 아래, 왼쪽, 오른쪽)
//해당 토마토가 무슨 상태인지 체크 후 상태 변경 (이전 값이 1일 경우)
//계산 후 출력

#define MAX_NUM 1001

int tomato_box[MAX_NUM][MAX_NUM] = { 0, };  //토마토 상자를 나타내는 배열 선언
int movement_x[5] = { 0, 0, 0, -1, 1 };
int movement_y[5] = { 0, -1, 1, 0, 0 };  //위, 아래, 왼쪽, 오른쪽 이동에 대한 더해질 좌표값. (맨 앞 0은 인덱스 맞추기용. 무시)
queue<pair<int, int>> queue_tomtato;  //BFS용 큐 선언
int m, n;  //문제의 가로, 세로
int day_cnt = 0;  //날짜 경과 변수 선언

void BFS(int x, int y);  //사용할 BFS함수 선언

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> m >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> tomato_box[i][j];  //토마토 상태 입력  1=익음 0=안익음 -1=토마토 없음
			
			if (tomato_box[i][j] == 1)
			{
				queue_tomtato.push(make_pair(j, i));  //큐에 시작지점 입력
			}
		}
	}

	BFS(queue_tomtato.front().first, queue_tomtato.front().second);  //해당 지점을 시작점으로 BFS 실행


	int day_cnt = 0;  //토마토가 모두 익을 수 있는지에 대한 판단 변수 선언
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (tomato_box[i][j] == 0)  //만약 익지 않은 토마토가 있다면
			{
				cout << -1;  //-1출력

				exit(0);  //즉시 종료
			}

			if (day_cnt < tomato_box[i][j])  //만약 해당 칸의 토마토가 익었다면
			{
				day_cnt = tomato_box[i][j];  //day_cnt를 해당 칸의 토마토가 익은 날짜로 변경
			}
		}
	}

	cout << day_cnt - 1;  //처음 토마토 값이 1이므로 -1 해서 출력


	return 0;
}

void BFS(int x, int y)
{
	while (queue_tomtato.empty() == false)  //큐가 공백이 될때까지
	{
		x = queue_tomtato.front().first;
		y = queue_tomtato.front().second;  //큐 front의 x, y값을 복사
		queue_tomtato.pop();  //pop을 통해 큐를 갱신

		for (int i = 1; i <= 4; ++i)
		{
			int next_x = x + movement_x[i];
			int next_y = y + movement_y[i];  //위, 아래, 왼쪽, 오른쪽에 대하여 체크

			if (next_x > 0 && next_x <= m && next_y > 0 && next_y <= n)  //다음 좌표가 상자 내부일 경우
			{
				if (tomato_box[next_y][next_x] == 0)  //다음 칸의 토마토가 익지 않은 상태라면
				{
					tomato_box[next_y][next_x] = tomato_box[y][x] + 1;  //다음 칸의 토마토를 익음으로 바꿈
					queue_tomtato.push(make_pair(next_x, next_y));  //큐에 다음 좌표를 입력
				}

			}
		}
	}
}

//좌표 생각을 잘하자. BFS아래쪽 코드가 너무 엉망이다...