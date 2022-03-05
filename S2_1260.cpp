#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//쫄지말고 천천히 작성하는것이 중요함
//기본적으로 DFS는 스택, BFS는 큐 사용
//일반적인 구조체로 이전노드, 다음노드를 만들어 연결할 경우 여러 간선 제한에 걸려 만들기 힘들어짐
//인접행렬을 사용해 각 노드간 간선 확인

#define MAX_NUM 1001

vector<vector<int>> my_graph(MAX_NUM, vector<int>(MAX_NUM));  //인접행렬로 사용할 배열 초기화
//기본값 0, 서로 이어져 있다면 [a][b] == [b][a] == 1
vector<bool> is_visited(MAX_NUM, false);  //노드 방문여부 확인용 배열 초기화 기본값 false
stack<int> stack_for_DFS;  //스택 선언
queue<int> queue_for_BFS;  //큐 선언

void DFS(int first_node, int total_node);  //DFS 함수 선언
void BFS(int first_node, int total_node);  //BFS 함수 선언

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
		my_graph[second_node][first_node] = 1;  //인접행렬 초기화
	}

	DFS(v, n);  //DFS 호출

	cout << "\n";

	for (int i = 1; i <= n; ++i)
	{
		is_visited[i] = false;  //방문 초기화
	}

	BFS(v, n);  //BFS 호출

	return 0;
}


void DFS(int first_node, int total_node)  //깊이 우선 탐색
{
	//스택을 통해 판단
	//현재 노드 기준 방문하지 않은 주변 노드가 있다면 현재 노드를 스택에 push
	//다음 노드를 방문하고 계속 방문
	//주변 노드를 모두 방문했다면 스택에서 pop 하여 마지막으로 방문한 정점에서 재확인
	//스택이 공백이 됐다면 종료

	is_visited[first_node] = true;  //방문 표시
	stack_for_DFS.push(first_node);  //스택에 입력

	cout << first_node << " ";  //처음 값 출력

	while (stack_for_DFS.empty() == false)  //스택이 공백이 아닐때 까지 반복
	{
		int top_of_stack = stack_for_DFS.top();  //top값 반환
		stack_for_DFS.pop();  //pop을 통해 stack값 갱신

		for (int i = 1; i <= total_node; ++i)
		{
			if (my_graph[top_of_stack][i] == 1 && is_visited[i] == false)  //현재노드와 연결된 간선이 존재하고 방문하지 않았다면
			{
				DFS(i, total_node);  //재귀 호출로 다음 노드로 넘어간다.
			}
		}
	}
}


void BFS(int first_node, int total_num)
{
	//큐를 통해 판단
	//최초 노드를 큐에 enqueu하고 현재 노드 기준 방문하지 않은 주변 노드를 차례대로 enqueue
	//방문하지 않은 노드가 없다면 큐에서 dequeue 하여 반복
	//큐가 공백이 되었다면 종료

	is_visited[first_node] = true;  //방문 표시
	queue_for_BFS.push(first_node);  //큐에 입력(enqueue, STL이라 용어만 push)

	cout << first_node << " ";  //처음 값 출력

	while (queue_for_BFS.empty() == false)  //큐가 공백이 아닐때까지 반복
	{
		int front_of_queue = queue_for_BFS.front();  //front 값 반환
		queue_for_BFS.pop();  //dequeue(마찬가지로 용어만 pop)를 통해 큐 값 갱신

		for (int i = 1; i <= total_num; ++i)
		{
			if (my_graph[front_of_queue][i] == 1 && is_visited[i] == false)  //현재노드와 연결된 간선이 존재하고 방문하지 않았다면
			{
				queue_for_BFS.push(i);  //큐에 enqueue
				is_visited[i] = true;  //방문 표시

				cout << i << " ";  //출력
			}
		}
	}
}