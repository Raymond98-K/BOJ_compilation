#include <iostream>
#include <string>
using namespace std;

//N의 최댓값이 10000이고 제한시간 2초. 넉넉하다.

int S5_1436(void)
{
	int cnt = 0;  //n과 비교를 위한 count값
	int sixCnt;  //3이 되면 종말의 수
	int n;
	cin >> n;

	int target = 666;  //기본 시작값

	while (1)  //탐색 시작
	{
		int temp = target;  //temp값에 target값을 복사
		sixCnt = 0;  //초기값 0으로 시작

		while (1)
		{
			if (temp % 10 == 6)  //temp의 일의자리 숫자를 검사
			{
				sixCnt++;  //6이라면 sixCnt++

				if (sixCnt == 3)  //연속된 6이 3개가 모였다면
				{
					cnt++;  //해당 값이 cnt번째 종말의 수
					sixCnt = 0;  //sixCnt 초기화

					break;  //반복 종료
				}
			}

			else  //만약 일의 자리가 6이 아니라면
			{
				sixCnt = 0;  //연속된 6의 수를 계산해야 하므로 0으로 초기화
			}

			temp = temp / 10;  //temp값 갱신
			
			if (!temp)  //만약 temp가 0이라면
			{
				break;  //target에 해당하는 수를 모두 검사했다는 뜻으므로 반복 종료
			}
		}

		if (cnt == n)  //만약 cnt가 입력받은 수와 같다면
		{
			cout << target;  //정답 출력

			return 0;
		}

		else  //cnt가 입력받은 수가 아니라면
		{
			target++;  //target을 다음수로 변경
		}
	}

	
}