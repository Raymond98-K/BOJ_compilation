#include <iostream>
#include <algorithm>
using namespace std;

//8<=N,M<=50에 2초이므로 시간은 넉넉
//백으로 시작하는 케이스1과 흑으로 시작하는 케이스2를 두고
//전체 경우의 수를 뽑은 후 제일 작은 값을 출력


int S5_1018(void)
{
	//흰색으로 시작하는 경우
	string firstCase[8] = { "WBWBWBWB",
							"BWBWBWBW",
							"WBWBWBWB",
							"BWBWBWBW",
							"WBWBWBWB",
							"BWBWBWBW",
							"WBWBWBWB",
							"BWBWBWBW" };

	//검은색으로 시작하는 경우
	string secondCase[8] = { "BWBWBWBW",
							 "WBWBWBWB",
							 "BWBWBWBW",
							 "WBWBWBWB",
							 "BWBWBWBW",
							 "WBWBWBWB",
							 "BWBWBWBW",
							 "WBWBWBWB" };


	int v, h;
	cin >> v >> h;  //vertic 세로, horizon 가로

	string board[50];  //문제상황 초기화, 입력

	for (int i = 0; i < v; ++i)
	{
		string line;
		cin >> line;

		board[i] = line;
	}

	int isMin = 65;  //최종 출력값. 65=8*8+1;

	//board의 세로, 가로가 가능한 만큼 8*8 탐색 반복
	for (int i = 0; i + 7 < v; ++i)
	{
		for (int j = 0; j + 7 < h; ++j)
		{
			int firstNum = 0;
			int secondNum = 0; //각 케이스별 최솟값

			for (int k = 0; k < 8; ++k)  //8*8만큼 각 케이스와 비교
			{
				for (int l = 0; l < 8; ++l)
				{
					if (board[i + k][j + l] != firstCase[k][l])
					{
						firstNum++;  //첫번째 경우와 다른경우 firstNum++
					}

					if (board[i + k][j + l] != secondCase[k][l])
					{
						secondNum++;  //두번째 경우와 다른경우 secondNum++;
					}
				}
			}

			isMin = min(isMin, min(firstNum, secondNum));  
			//최종값은 first와 second비교 후 작은 값에서
			//기존 값과 비교해 가장 작은 값으로 갱신

		}

		
	}


	cout << isMin;  //결과 출력


	return 0;
}