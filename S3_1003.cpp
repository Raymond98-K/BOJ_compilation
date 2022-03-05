#include <iostream>
#include <vector>
using namespace std;

vector<int> fibo_DP_1003(41);  //사용할 DP 초기화

//문제에 있던 함수를 그대로 사용하면 시간제한에 걸린다.
//DP를 사용하도록 개조 하여 시간 단축을 해 보자.
//설계하면서 알게 된 사실. fibo(n)에서 0의 등장 횟수는 fibo(n-1)과 같고
//1의 등장 횟수는 fibo(n)과 같다. 헐...

int fibonacci_1003(int n) {
	if (n == 0) {  //만약 0일 경우 zero 카운트 증가

		return 0;
	}
	else if (n == 1) {  //만약 1일 경우 one 카운트 증가

		return 1;
	}

	if (fibo_DP_1003[n] != 0)  //만약 DP에 저장된 값이 있을 경우
	{
		return fibo_DP_1003[n];  //해당 값을 리턴
	}


	else {
		fibo_DP_1003[n] = fibonacci_1003(n - 1) + fibonacci_1003(n - 2);

		return fibo_DP_1003[n];  //DP에 값을 저장 후 해당 값을 리턴
	}
}

int S3_1003(void)
{
	fibo_DP_1003[0] = 0;
	fibo_DP_1003[1] = 1;
	fibo_DP_1003[2] = 1;
	//DP의 기저조건(처음에 지정해줘야 하는 값) 초기화
	//해당 문제에선 0 1 1 2 3 5 ... 로 진행하기때문에 그에 맞게 초기화 해준다.


	int testCase;
	cin >> testCase;

	vector<int> table(testCase + 1);  //테스트 케이스 만큼 배열 초기화(0번 원소 = 0)

	for (int i = 1; i <= testCase; ++i)
	{
		cin >> table[i];
	}

	for (int i = 1; i <= testCase; ++i)
	{
		fibonacci_1003(table[i]);

		if (table[i] == 0)  //값이 0일경우 따로 출력(고정 값)
		{
			cout << 1 << " " << 0 << "\n";
		}

		else  //그 외의 경우 해당 수 이전 번째 피보나치 수열 값과 해당 수번째의 피보나치 수열 값 출력
		{
			cout << fibo_DP_1003[table[i] - 1] << " " << fibo_DP_1003[table[i]] << "\n";  //정답 출력
		}

	}

	return 0;
}