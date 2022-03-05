#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

//시간제한 10초???? 재귀에 반복문 같은걸 끼얹나..?
//문제 설명이 이해가 안돼서 그냥 N-Queen을 검색해 보고 이해했다.
//예를 들어 8*8 체스판에 퀸 8개를 놓는다. 
//이때 그 어떤 퀸도 다른 퀸의 공격 경로와 겹치지 않게 위치하는 경우의 수를 구하면 된다.
//검사는 세로, 대각선을 check하고 만약에 겹친다면 이전상황으로 돌아가는 백트레킹 사용
//좌표로 계산해야하니 이중벡터를 사용해 하면 된다.
//------------------------------------------------------------------
//이중벡터로 하니 10초를 그냥 넘어가 다른 방법으로 접근 필요
//대각선은 기울기로 체크하고 가로줄에 퀸이 한개 이상 존재할 수 없기 때문에 가로줄에 대한 검사는 pass
//가로줄이 생략됬으므로 굳이 이중벡터를 사용하지 않아도 된다.

void isNQueen(vector<int> chess, int checker, int N);  
//백트래킹 함수. checker는 현재 체크중인 행의 번호 이다.

int answer = 0;  //최종적으로 출력될 값

int G5_9663(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int intN;
	cin >> intN;

	vector<int> chessBoard(15);  
	//퀸의 위치가 기록될 벡터. 인덱스는 행의 번호, 요소는 열의 번호
	//ex [0] = 1 이라면 (0,1) 즉, 첫번째 행의 1번(두번째) 열에 퀸이 있다는 뜻

	isNQueen(chessBoard, 0, intN);  //함수 호출. checker의 초기값은 0이며 intN과 함께 넘겨준다.

	cout << answer;  //답 출력

	return 0;
}



void isNQueen(vector<int> chess, int checker, int N)
{
	if (checker == N)  //만약 현재 행이 intN = N과 같다면(모든 행을 다 검사했다면)
	{
		answer++;  //경우의 수 1 추가

		return;  //종료
	}

	//그게 아니라면 해당 행에 대한 검사 개시
	for (int i = 0; i < N; ++i)
	{
		chess[checker] = i;  //해당 행(checker)의 i번째 열에 퀸을 놓아 본다.
		int isAttacked = 0;  //겹친 횟수. 1이상이라면 적어도 하나 이상의 퀸과 경로가 겹친다는 뜻이다.

		for (int j = 0; j < checker; ++j)  //이후 진행한 행(checker)까지 안전한지 검사한다.
		{
			//어차피 행이 겹치는 경우는 배열 구조상 불가능하니 열과 대각선만 겹치지 않는지 검사한다.
			//현재 퀸이 놓아진 칸과 지금까지 놓아진 각 퀸의 요소가 같을 경우 열이 겹치므로 배제한다
			//또한 두 퀸의 (행-행) 값과 (열-열) 값의 절대값이 같을 경우 대각선상에 위치한것이므로 배제한다.

			if ((chess[checker] == chess[j]) || (abs(checker - j) == abs(chess[checker] - chess[j])))
			{
				//위의 조건을 만족한다면 이미 놓여진 퀸과 경로가 겹친다는 뜻이다.
				isAttacked++;  //따라서 겹친 횟수를 증가시킨다.

				break;  //이후의 반복은 의미가 없으므로 검사를 종료한다.
			}

		}

		if (isAttacked == 0)  //안전검사가 끝난 후 겹친 횟수가 0이라면
		{
			isNQueen(chess, checker + 1, N);  //놓아도 되는 곳에 놓았다는 뜻이므로 다음 행으로 넘어가 반복한다.
		}

	}
	
}