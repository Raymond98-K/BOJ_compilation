#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"

//숫자를 저장하는 벡터 1개와 사용가능한 연산자의 횟수를 저장하는 벡터 1개, 연산시 사용할 벡터 1개 사용
//함수(결과값, 연산자 벡터, 현재 숫자 사용 횟수, n) 선언
//연산자 사용횟수가 0 보다 크면 해당 인덱스에 따라 switch문으로 +-*/ 계산시 사용용 벡터에 저장 후 연산자 횟수--
//함수(결과값,연산자 벡터, 현재 횟수 + 1, n) 재귀호출 후 숫자 사용 횟수 == n 이면 계산 후 max, min 비교 실행
//최종적으로 cout <<max<<min;

void solve(int result, vector<int> operators, int cnt, int n);
vector<int> table_14888(11);  //숫자 저장용 벡터
vector<int> available_operators_14888(4);  //연산자 사용 가능 횟수 저장용 벡터
vector<int> use_operators_14888;  //계산시 사용할 연산자 순서 벡터

int max_result = -1000000001;  //초기 최댓값
int min_result = 1000000001;  //초기 최솟값

int S1_14888(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)  //숫자들 저장
	{
		cin >> table_14888[i];
	}

	for (int i = 0; i < 4; ++i)  //연산자 사용 횟수 저장
	{
		cin >> available_operators_14888[i];
	}

	solve(table_14888[0], available_operators_14888, 1, n);  //result의 초깃값은 첫번째 수 cnt의 초깃값은 1


	cout << max_result << endl << min_result;

	return 0;
}


void solve(int result, vector<int> operators, int cnt, int n)
{
	if (cnt == n)  
	//만약 숫자 사용 횟수가 n과 같으면 현재 시행에서 사용할 연산자를 모두 저장한 것이다.
	{

		for (int i = 1; i <= use_operators_14888.size(); ++i)  //사용할 연산자 벡터 크기 만큼 반복
		{
			switch (use_operators_14888[i - 1])  //사용할 연산자의 번호에 따라 switch
			{
			case 0:  // +=
			{
				result += table_14888[i];
				break;
			}

			case 1:  // -=
			{
				result -= table_14888[i];
				break;
			}

			case 2:  // *=
			{
				result *= table_14888[i];
				break;
			}

			case 3:  // /=
			{
				result /= table_14888[i];
				break;
			}
			}
		}

		//현재 시행의 최종값인 result에 대하여 max, min 비교

		if (result > max_result)
		{
			max_result = result;
		}

		if (result < min_result)
		{
			min_result = result;
		}

		return;  //함수 종료
	}

	for (int i = 0; i < 4; ++i)  //사용 가능한 연산자 모두 체크
	{
		if (available_operators_14888[i] > 0)  //만약 사용 가능한 연산자 횟수가 남아있다면
		{
			switch (i)  //연산자의 번호에 따라 사용할 연산자에 저장
			{
			case 0:
			{
				use_operators_14888.push_back(0);
				available_operators_14888[i]--;  //연산자 횟수 감소
				break;
			}

			case 1:
			{
				use_operators_14888.push_back(1);
				available_operators_14888[i]--;
				break;
			}

			case 2:
			{
				use_operators_14888.push_back(2);
				available_operators_14888[i]--;
				break;
			}

			case 3:
			{
				use_operators_14888.push_back(3);
				available_operators_14888[i]--;
				break;
			}
			}

			solve(result, available_operators_14888, cnt + 1, n);  //사용된 수를 하나 늘리고 재귀호출

			switch (i)  //함수 호출이 끝나면 연산자 횟수를 사용 전으로 롤백 시킨다.
			{
			case 0:
			{
				use_operators_14888.pop_back();  //사용할 연산자에서 pop()
				available_operators_14888[i]++;  //사용횟수 복구
				break;
			}

			case 1:
			{
				use_operators_14888.pop_back();
				available_operators_14888[i]++;
				break;
			}

			case 2:
			{
				use_operators_14888.pop_back();
				available_operators_14888[i]++;
				break;
			}

			case 3:
			{
				use_operators_14888.pop_back();
				available_operators_14888[i]++;
				break;
			}
			}

		}

	}

}