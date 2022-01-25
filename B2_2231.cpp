#include <iostream>
using namespace std;

//최대 intN = 1000000 자릿수는 7이니 둘이 곱해도 시간은 넉넉하다. 그냥 반복 돌리자.

int B2_2231() {

	int intN;
	cin >> intN;  //N값을 입력 받는다.


	//분해합은 기본적으로 자기자신이 더해짐으로 입력받은 값을 넘을 수 없다.
	for (int i = 1; i <= intN; ++i)  
	{
		int j = i;  //변수 j에 i값을 복사
		int check = i;  //변수 check에 i값 복사


		//자릿수 만큼 반복후 break되는 반복 실행
		while (1) 
		{
			check += j % 10;  //현재 j값의 1의 자릿수를 더하기


			//만약 j값이 더이상 10으로 나누어지지 않고 check == inN일 경우
			if (!(j/10) && check == intN) 
			{
				cout << i;  //답 출력

				return 0;  //프로그램 종료
			}


			//j값이 10으로 나누어질 경우
			else 
			{
				j = j / 10;  //j값 갱신

				if (!j)  //갱신 후 만약 j값이 0이라면
				{
					break;  //while문 종료
				}
			}

		}
		
	}

	cout << 0;  //위의 반복문으로 해당하는 값을 찾을 수 없는 경우 0 출력

	return 0;
}