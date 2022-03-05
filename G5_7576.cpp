#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//�ִ� �̹Ƿ� BFS ���
//���� �迭�� ������ ��ǥ�̵�(��, �Ʒ�, ����, ������)
//�ش� �丶�䰡 ���� �������� üũ �� ���� ���� (���� ���� 1�� ���)
//��� �� ���

#define MAX_NUM 1001

int tomato_box[MAX_NUM][MAX_NUM] = { 0, };  //�丶�� ���ڸ� ��Ÿ���� �迭 ����
int movement_x[5] = { 0, 0, 0, -1, 1 };
int movement_y[5] = { 0, -1, 1, 0, 0 };  //��, �Ʒ�, ����, ������ �̵��� ���� ������ ��ǥ��. (�� �� 0�� �ε��� ���߱��. ����)
queue<pair<int, int>> queue_tomtato;  //BFS�� ť ����
int m, n;  //������ ����, ����
int day_cnt = 0;  //��¥ ��� ���� ����

void BFS(int x, int y);  //����� BFS�Լ� ����

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
			cin >> tomato_box[i][j];  //�丶�� ���� �Է�  1=���� 0=������ -1=�丶�� ����
			
			if (tomato_box[i][j] == 1)
			{
				queue_tomtato.push(make_pair(j, i));  //ť�� �������� �Է�
			}
		}
	}

	BFS(queue_tomtato.front().first, queue_tomtato.front().second);  //�ش� ������ ���������� BFS ����


	int day_cnt = 0;  //�丶�䰡 ��� ���� �� �ִ����� ���� �Ǵ� ���� ����
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (tomato_box[i][j] == 0)  //���� ���� ���� �丶�䰡 �ִٸ�
			{
				cout << -1;  //-1���

				exit(0);  //��� ����
			}

			if (day_cnt < tomato_box[i][j])  //���� �ش� ĭ�� �丶�䰡 �;��ٸ�
			{
				day_cnt = tomato_box[i][j];  //day_cnt�� �ش� ĭ�� �丶�䰡 ���� ��¥�� ����
			}
		}
	}

	cout << day_cnt - 1;  //ó�� �丶�� ���� 1�̹Ƿ� -1 �ؼ� ���


	return 0;
}

void BFS(int x, int y)
{
	while (queue_tomtato.empty() == false)  //ť�� ������ �ɶ�����
	{
		x = queue_tomtato.front().first;
		y = queue_tomtato.front().second;  //ť front�� x, y���� ����
		queue_tomtato.pop();  //pop�� ���� ť�� ����

		for (int i = 1; i <= 4; ++i)
		{
			int next_x = x + movement_x[i];
			int next_y = y + movement_y[i];  //��, �Ʒ�, ����, �����ʿ� ���Ͽ� üũ

			if (next_x > 0 && next_x <= m && next_y > 0 && next_y <= n)  //���� ��ǥ�� ���� ������ ���
			{
				if (tomato_box[next_y][next_x] == 0)  //���� ĭ�� �丶�䰡 ���� ���� ���¶��
				{
					tomato_box[next_y][next_x] = tomato_box[y][x] + 1;  //���� ĭ�� �丶�並 �������� �ٲ�
					queue_tomtato.push(make_pair(next_x, next_y));  //ť�� ���� ��ǥ�� �Է�
				}

			}
		}
	}
}

//��ǥ ������ ������. BFS�Ʒ��� �ڵ尡 �ʹ� �����̴�...