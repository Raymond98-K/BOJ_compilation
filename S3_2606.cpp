#include <iostream>
#include <queue>
using namespace std;

//���� �켱�̴� ���� �켱�̴� 1260���� ����ϰ� Ǯ���ϸ� �ȴ�.

#define MAX_CNT 101

int computer_graph[MAX_CNT][MAX_CNT] = { 0, };  //����� ������� �ʱ�ȭ, �ʱ갪 == 0
bool is_infected[MAX_CNT] = { false, };  //�������� Ȯ�ο� �迭 �ʱ�ȭ
int worm_cnt = 0;  //����� ���
queue<int> queue_worm;  //BFS���� ����� ť ����

void DFS(int infected, int total);  //���� �켱 Ž�� �Լ� ����
void BFS(int infected, int total);  //�ʺ� �켱 Ž�� �Լ� ����

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
		computer_graph[second_computer][first_computer] = 1;  //��ǻ�Ͱ� ���� �ʱ�ȭ
	}

	//DFS(1, computer_total);

	BFS(1, computer_total);
	
	cout << worm_cnt;

	return 0;
}


void DFS(int infected, int total)
{
	is_infected[infected] = 1;  //���� ������ 1�� ��ǻ�� ���� ǥ��

	for (int i = 1; i <= total; ++i)
	{
		if (computer_graph[infected][i] == 1 && is_infected[i] == 0)  //��ǻ�ͳ��� ����Ǿ� �ְ� ������ �Ǿ� ���� �ʴٸ�
		{
			is_infected[i] = 1;  //���� ��ǻ���� ���� ǥ��
			worm_cnt++;  //ī��Ʈ ����

			DFS(i, total);  //���� ��ǻ�͸� �������� �ݺ�
		}
	}


}

void BFS(int infected, int total)
{
	is_infected[infected] = 1;  //������ ��ǻ�� ���� ǥ��
	queue_worm.push(infected);  //ť�� enqueue

	while (queue_worm.empty() == false)
	{
		infected = queue_worm.front();  //front�� �Ҵ�
		queue_worm.pop();  //pop�� ���� ť ����

		for (int i = 1; i <= total; ++i)
		{
			if (computer_graph[infected][i] == 1 && is_infected[i] == 0)  //��ǻ�ͳ��� ����Ǿ� �ְ� ������ �Ǿ� ���� �ʴٸ�
			{
				is_infected[i] = 1;  //�������� ����
				queue_worm.push(i);  //ť�� push
				worm_cnt++;  //ī��Ʈ ����
			}
		}
	}

}
