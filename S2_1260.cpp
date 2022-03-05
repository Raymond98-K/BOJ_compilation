#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//�������� õõ�� �ۼ��ϴ°��� �߿���
//�⺻������ DFS�� ����, BFS�� ť ���
//�Ϲ����� ����ü�� �������, ������带 ����� ������ ��� ���� ���� ���ѿ� �ɷ� ����� �������
//��������� ����� �� ��尣 ���� Ȯ��

#define MAX_NUM 1001

vector<vector<int>> my_graph(MAX_NUM, vector<int>(MAX_NUM));  //������ķ� ����� �迭 �ʱ�ȭ
//�⺻�� 0, ���� �̾��� �ִٸ� [a][b] == [b][a] == 1
vector<bool> is_visited(MAX_NUM, false);  //��� �湮���� Ȯ�ο� �迭 �ʱ�ȭ �⺻�� false
stack<int> stack_for_DFS;  //���� ����
queue<int> queue_for_BFS;  //ť ����

void DFS(int first_node, int total_node);  //DFS �Լ� ����
void BFS(int first_node, int total_node);  //BFS �Լ� ����

int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 1; i <= m; ++i)
	{
		int first_node;
		int second_node;
		cin >> first_node >> second_node;

		my_graph[first_node][second_node] = 1;
		my_graph[second_node][first_node] = 1;  //������� �ʱ�ȭ
	}

	DFS(v, n);  //DFS ȣ��

	cout << "\n";

	for (int i = 1; i <= n; ++i)
	{
		is_visited[i] = false;  //�湮 �ʱ�ȭ
	}

	BFS(v, n);  //BFS ȣ��

	return 0;
}


void DFS(int first_node, int total_node)  //���� �켱 Ž��
{
	//������ ���� �Ǵ�
	//���� ��� ���� �湮���� ���� �ֺ� ��尡 �ִٸ� ���� ��带 ���ÿ� push
	//���� ��带 �湮�ϰ� ��� �湮
	//�ֺ� ��带 ��� �湮�ߴٸ� ���ÿ��� pop �Ͽ� ���������� �湮�� �������� ��Ȯ��
	//������ ������ �ƴٸ� ����

	is_visited[first_node] = true;  //�湮 ǥ��
	stack_for_DFS.push(first_node);  //���ÿ� �Է�

	cout << first_node << " ";  //ó�� �� ���

	while (stack_for_DFS.empty() == false)  //������ ������ �ƴҶ� ���� �ݺ�
	{
		int top_of_stack = stack_for_DFS.top();  //top�� ��ȯ
		stack_for_DFS.pop();  //pop�� ���� stack�� ����

		for (int i = 1; i <= total_node; ++i)
		{
			if (my_graph[top_of_stack][i] == 1 && is_visited[i] == false)  //������� ����� ������ �����ϰ� �湮���� �ʾҴٸ�
			{
				DFS(i, total_node);  //��� ȣ��� ���� ���� �Ѿ��.
			}
		}
	}
}


void BFS(int first_node, int total_num)
{
	//ť�� ���� �Ǵ�
	//���� ��带 ť�� enqueu�ϰ� ���� ��� ���� �湮���� ���� �ֺ� ��带 ���ʴ�� enqueue
	//�湮���� ���� ��尡 ���ٸ� ť���� dequeue �Ͽ� �ݺ�
	//ť�� ������ �Ǿ��ٸ� ����

	is_visited[first_node] = true;  //�湮 ǥ��
	queue_for_BFS.push(first_node);  //ť�� �Է�(enqueue, STL�̶� �� push)

	cout << first_node << " ";  //ó�� �� ���

	while (queue_for_BFS.empty() == false)  //ť�� ������ �ƴҶ����� �ݺ�
	{
		int front_of_queue = queue_for_BFS.front();  //front �� ��ȯ
		queue_for_BFS.pop();  //dequeue(���������� �� pop)�� ���� ť �� ����

		for (int i = 1; i <= total_num; ++i)
		{
			if (my_graph[front_of_queue][i] == 1 && is_visited[i] == false)  //������� ����� ������ �����ϰ� �湮���� �ʾҴٸ�
			{
				queue_for_BFS.push(i);  //ť�� enqueue
				is_visited[i] = true;  //�湮 ǥ��

				cout << i << " ";  //���
			}
		}
	}
}