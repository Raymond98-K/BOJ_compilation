#include <iostream>
#include <vector>
using namespace std;

//sudoku(n)을 호출해서 1~81까지 검사를 하고 n == 82이 되면 cout << sudoku
//함수 내부에선 [i][j] == 0 이면 k를 1~9까지 가로줄에 있는지, 세로줄에 있는지, 작은 사각형(3*3)에 있는지 검사
//검사 통과시 [i][j] = k 하고 sudoku(n+1) 호출
//검사벡터 checkRow[i][j] == true 라면 i번째 행에 j숫자가 이미 있다는 뜻으로 false라면 그 숫자가 아직 없다는 뜻


void MakeSudoku(int tile);

vector<vector<int>> sudoku(10, vector<int>(10));  //스도쿠 저장용 벡터(pushback사용을 위해 첫번째 칸에 하나만 넣어준다.)
vector<vector<bool>> in_row(10, vector<bool>(10, false));  //가로열에 숫자 판단용 벡터
vector<vector<bool>> in_col(10, vector<bool>(10, false));  //세로열에 숫자 판단용 벡터
vector<vector<bool>> in_box(10, vector<bool>(10, false));  //작은 사각형에 숫자 판단용 벡터

int G4_2580(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 0; i < 9; ++i)
	{
		vector<int> line(10);

		for (int j = 0; j < 9; ++j)
		{
			int num;
			cin >> num;

			line[j] = num;  //한줄씩 입력 받기

			if (num != 0)
			{
				in_row[i][num] = true;  //해당 행의 num에 해당하는 숫자 등장 갱신
				in_col[j][num] = true;  //해당 열의 num에 해당하는 숫자 등장 갱신
				in_box[((i / 3) * 3) + (j / 3)][num] = true;
				//해당 박스의 num에 해당하는 숫자 등장 갱신
				//(행번호/3)*3 + (열번호/3) 하면 왼쪽위부터 0번 박스, 오른쪽 맨 아래가 8번 박스가 된다.
			}
		}

		sudoku[i] = line;

	}


	MakeSudoku(0);  // 첫번째 칸부터 서치 시작

	return 0;
}



void MakeSudoku(int tile)
{
	if (tile == 81)  //tile == 81 이라면 모든 타일을 다 채웠다는 뜻이므로
	{
		for (int i = 0; i < 9; ++i)  //요구조건에 맞게 출력한다.
		{
			for (int j = 0; j < 9; ++j)
			{
				cout << sudoku[i][j] << " ";
			}

			cout << "\n";
		}

		exit(0);  //답이 여러개라도(ex 전부 빈칸) 바로 끝나야 하므로 바로 종료해준다.
	}


	//tile이 81이 아니라면
	//이중 반복문을 사용시 무한 루프가 발생하여 tile을 통해 현재 행과 열을 계산한다.
	//행은 tile을 9로 나눈 몫 열은 9로 나눈 나머지 값이다.
	int row = tile / 9;
	int col = tile % 9;

	if (sudoku[row][col] != 0)  //만약 해당칸이 빈칸이 아니라면
	{
		MakeSudoku(tile + 1);  //다음칸으로 넘어간다.
	}

	else  //해당 칸이 빈칸이라면
	{
		for (int k = 1; k <= 9; ++k)  //넣을 수 있는 수 1~9까지를 검사한다.
		{
			if (!in_row[row][k] && !in_col[col][k] && !in_box[((row / 3) * 3) + (col / 3)][k])
				//행,열,박스 검사에서 모두 false가 나와야 넣을 수 있는 값이다.
			{
				in_row[row][k] = true;
				in_col[col][k] = true;
				in_box[((row / 3) * 3) + (col / 3)][k] = true;  //해당 행,열,박스에 대해 숫자의 등장 여부를 true로 갱신
				sudoku[row][col] = k;  //스도쿠에 입력한다.

				MakeSudoku(tile + 1);  //다음 칸으로 진행한다.

				//이 아래로 진행된다는 것은 k를 넣고 다음 빈칸에 1~9까지의 수중 넣을 수 있는 수가 없다는 뜻이다.
				//즉 다음칸 호출 이전시점에 넣은 k가 잘못되었다는 뜻이므로 해당 수를 다시 빼야한다.

				in_row[row][k] = false;
				in_col[col][k] = false;
				in_box[((row / 3) * 3) + (col / 3)][k] = false;  //행, 열, 박스에 대해 숫자의 등장 여부를 false로 갱신
				sudoku[row][col] = 0;  //다시 빈칸으로 만들고 다음으로 가능한 k를 찾는다.

			}
		}
	}




}