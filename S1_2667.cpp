#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//DFS�� ���� ��ġ -> ���� �� ����� ���ؼ� �����ٸ� ������ ���Ϳ� ����
//�������� �������� ���� �� ���

#define MAX_NUM 26

int n;  //������ N
string apt_matrix[MAX_NUM]= { "0", };  //����Ʈ �迭 ����� ���� �迭 ����  (0�� �ε����� 1���ͷ� ���߱� ���ؼ�. ����)
bool is_checked[MAX_NUM][MAX_NUM] = { false, };  //üũ ���� Ȯ�ο� ���� �迭 ����
int movement_x[5] = { 0, 0, 0, -1, 1 };
int movement_y[5] = { 0, -1, 1, 0, 0 };  //x�� y�� ���� ��, �Ʒ�, ����, ������ �̵��� ������ ��ǥ��(�Ǿ� 0�� �ε����� ���Ѱ�. ����)
int total_house = 0;  //������ �� �� ��
vector<int> apt_sort;  //������ ���� �� ���� ���� ������ �迭

void DFS(int x, int y);  //���� ��ǥ�� �޾� �����ϴ� BFS�Լ� ����

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;  //n �Է� �ޱ�
	
	for (int i = 1; i <= n; ++i)
	{
		string my_string;
		cin >> my_string;
		my_string = "0" + my_string;  //�ε����� ���߱� ���� �տ� "0" �Է� �� �迭�� ����

		apt_matrix[i] = my_string;  
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (apt_matrix[i][j] == '1' && is_checked[i][j] == false)  //������� �� ���� ������ ������ �Ʒ����� ���� �ְ� üũ���� �ʾҴٸ�
			{
				total_house = 0;  //�� ������ �� �� �ʱ�ȭ
				DFS(i, j);  //��ǥ�� �Ѱ��ָ� DFS����
				apt_sort.push_back(total_house);  //���Ϳ� �� �� �Ѱ��ֱ�
			}
		}
	}

	sort(apt_sort.begin(), apt_sort.end());  //���� �������� ����

	cout << apt_sort.size() << "\n";  //�� ���� �� ���(���Ϳ� ����� ���� ��)

	for (int i = 0; i < apt_sort.size(); ++i)
	{
		cout << apt_sort[i] << "\n";  //�� ������ �� ���� ������������ ���
	}

	return 0;
}


void DFS(int x, int y)
{
	is_checked[x][y] = true;  //üũ ���� ǥ��
	total_house++;  //�� ���� ����

	for (int i = 1; i <= 4; ++i)
	{
		int next_x = x + movement_x[i];
		int next_y = y + movement_y[i];  //��, �Ʒ�, ����, �����ʿ� ���� ���� ��ǥ�� �̵�

		if (next_x > 0 && next_x <= n && next_y > 0 && next_y <= n)  //���� ��ǥ�� �־��� ���� ���ο� ��ġ�Ѵٸ�
		{
			if (apt_matrix[next_x][next_y] == '1' && is_checked[next_x][next_y] == false)  //���� ��ǥ�� ���� �ְ� ���� üũ�� ���� �ʾҴٸ�
			{
				DFS(next_x, next_y);  //���� ��ǥ�� ���� DFS ����
			}
		}
	}
	
}