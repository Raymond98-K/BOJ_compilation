#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//DFS를 통해 서치 -> 만약 한 덩어리에 대해서 끝났다면 갯수를 벡터에 저장
//마지막에 오름차순 정렬 후 출력

#define MAX_NUM 26

int n;  //문제의 N
string apt_matrix[MAX_NUM]= { "0", };  //아파트 배열 저장용 이중 배열 선언  (0은 인덱스를 1부터로 맞추기 위해서. 무시)
bool is_checked[MAX_NUM][MAX_NUM] = { false, };  //체크 여부 확인용 이중 배열 선언
int movement_x[5] = { 0, 0, 0, -1, 1 };
int movement_y[5] = { 0, -1, 1, 0, 0 };  //x와 y에 대한 위, 아래, 왼쪽, 오른쪽 이동시 더해질 좌표값(맨앞 0은 인덱스를 위한것. 무시)
int total_house = 0;  //단지의 총 집 수
vector<int> apt_sort;  //각각의 단지 내 집의 수를 저장할 배열

void DFS(int x, int y);  //현재 좌표를 받아 실행하는 BFS함수 선언

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;  //n 입력 받기
	
	for (int i = 1; i <= n; ++i)
	{
		string my_string;
		cin >> my_string;
		my_string = "0" + my_string;  //인덱스를 맞추기 위해 앞에 "0" 입력 후 배열에 저장

		apt_matrix[i] = my_string;  
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (apt_matrix[i][j] == '1' && is_checked[i][j] == false)  //순서대로 맨 왼쪽 위부터 오른쪽 아래까지 집이 있고 체크하지 않았다면
			{
				total_house = 0;  //각 단지별 집 수 초기화
				DFS(i, j);  //좌표를 넘겨주며 DFS실행
				apt_sort.push_back(total_house);  //벡터에 집 수 넘겨주기
			}
		}
	}

	sort(apt_sort.begin(), apt_sort.end());  //벡터 오름차순 정렬

	cout << apt_sort.size() << "\n";  //총 단지 수 출력(벡터에 저장된 원소 수)

	for (int i = 0; i < apt_sort.size(); ++i)
	{
		cout << apt_sort[i] << "\n";  //각 단지별 집 수를 오름차순으로 출력
	}

	return 0;
}


void DFS(int x, int y)
{
	is_checked[x][y] = true;  //체크 여부 표시
	total_house++;  //집 갯수 증가

	for (int i = 1; i <= 4; ++i)
	{
		int next_x = x + movement_x[i];
		int next_y = y + movement_y[i];  //위, 아래, 왼쪽, 오른쪽에 대해 다음 좌표로 이동

		if (next_x > 0 && next_x <= n && next_y > 0 && next_y <= n)  //다음 좌표가 주어진 지도 내부에 위치한다면
		{
			if (apt_matrix[next_x][next_y] == '1' && is_checked[next_x][next_y] == false)  //다음 좌표에 집이 있고 아직 체크를 하지 않았다면
			{
				DFS(next_x, next_y);  //다음 좌표에 대해 DFS 실행
			}
		}
	}
	
}