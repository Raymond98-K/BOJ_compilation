#include <iostream>
using namespace std;

//그냥 string으로 정렬하면 된다.  //char'1' < char'2' 가 성립하기 때문

int S5_1427(void)
{
	string stringN;
	cin >> stringN;

	for (int i = 0; i < stringN.length() - 1; ++i)  //문자열 길이만큼 반복
	{
		char tmp;  //임시 변수 선언

		for (int j = i + 1; j < stringN.length(); ++j)  //i보다 한 칸 다음값부터
		{
			if (stringN[i] < stringN[j])  //만약 현재값이 다음값보다 작다면
			{
				tmp = stringN[i];
				stringN[i] = stringN[j];
				stringN[j] = tmp;  //두 값의 위치 교환
			}
		}
	}

	cout << stringN;  //정답 출력

	return 0;
}