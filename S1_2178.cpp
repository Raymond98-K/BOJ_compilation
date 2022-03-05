#include <iostream>
#include <queue>
using namespace std;

//�ִܰ�δ� BFS�� Ǯ��� �ð��ʰ��� �߻����� �ʴ´�!!!!
//��ǥ�̵�üũ(�̷� ���� ���� �̵�����), ��üũ(�ش� ĭ�� 1���� 0����), �湮üũ(�̹� �湮 �� ������)
//��ǥ �̵����� �̵� ���� ������ ��, �Ʒ�, ����, �������̴�.

#define MAX_NUM 101

string maze[MAX_NUM] = { "0", };  //�̷� �ʱ�ȭ
bool is_visited[MAX_NUM][MAX_NUM] = { false, };  //�湮 ���� �ʱ�ȭ
int move_cnt[MAX_NUM][MAX_NUM] = { 0, };  //�� ĭ�� �̵� Ƚ�� �迭 �ʱ�ȭ
int movement_x[5] = { 0, 0, 0, -1, 1 };  //�� �Ʒ� ���� �����ʿ� ���� x��ǥ ��ȭ��(ù 0�� ����)
int movement_y[5] = { 0, -1, 1, 0, 0 };  //�� �Ʒ� ���� �����ʿ� ���� y��ǥ ��ȭ��(ù 0�� ����)
queue<pair<int, int>> maze_queue;  //����� ť �ʱ�ȭ. ��ǥ�� ������� pair������ ����
int n, m;  //������ N�� M

void BFS(int x, int y);  //BFS �Լ� ����

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
		my_string = "0" + my_string;  //��ǥ ������ ���� �տ� "0"�� ���� ���·� �̷ο� �־��ش�.

		maze[i] = my_string;
	}

	BFS(1, 1);  //�Լ� ȣ��

	return 0;
}

void BFS(int x, int y)
{
	maze_queue.push(make_pair(x, y));  //ť�� ��ǥ �Է�
	is_visited[x][y] = true;  //�湮 ǥ��
	move_cnt[x][y] = 1;

	while (maze_queue.empty() == false)  //ť�� ������ �ɶ�����
	{
		int location_x = maze_queue.front().first;
		int location_y = maze_queue.front().second;  //x, y ��ǥ�� ����
		maze_queue.pop(); //pop�� ���� ť ����

		for (int i = 1; i <= 4; ++i)
		{
			int next_x = location_x + movement_x[i];
			int next_y = location_y + movement_y[i];  //���� ��ǥ ���(��, �Ʒ�, ����, ������ ����)

			if (next_x > 0 && next_x <= m && next_y > 0 && next_y <= n)  //�̷� ���� ������ üũ
			{
				if (maze[next_y][next_x] == '1' && is_visited[next_x][next_y] == false)  //ĭ�� '1'�̰�(��ǥ ����) �湮������ ������ üũ
				{
					maze_queue.push(make_pair(next_x, next_y));  //ť�� ����
					is_visited[next_x][next_y] = true;  //�湮 ǥ��
					move_cnt[next_x][next_y] = move_cnt[location_x][location_y] + 1;  //�̵�Ƚ�� ����

					if (next_x == m && next_y == n)  //���� �������� ���
					{
						cout << move_cnt[next_x][next_y];

						exit(0);  //���α׷� ��� ����
					}


				}
			}

		}

	}

}