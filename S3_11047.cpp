#include <iostream>
#include <vector>
using namespace std;

//내림차순으로 동전들에 대해 반복문을 돌려서
//K>=동전[i]라면 K-=동전[i], cnt++을 진행
//마지막에 cout<<cnt;

int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int>coins(n);  //동전들이 저장될 벡터 선언

	for (int i = n - 1; i >= 0; --i)
	{
		cin >> coins[i];  //배열에 역순으로 저장(오름차순으로 입력->내림차순으로 저장)
	}

	int cnt = 0;  //사용될 동전 갯수 초기화


	for (int i = 0; i < n; ++i)  //다른 방법으로 풀기
	{
		if (k == 0)
		{
			break;  //기존과 동일
		}

		else if (k >= coins[i])
		{
			cnt += k / coins[i];  //사용될 갯수는 가치값 / 현재 동전의 값
			k %= coins[i];  //가치값의 갱신은 가치값 % 현재 동전의 값

			//이렇게 하면 i값을 굳이 따로 조정해 주지 않아도 된다.
			//시간이 56ms -> 0ms 로 단축
		}

	}


	/*
	for (int i = 0; i < n; ++i)
	{
		if (k == 0)
		{
			break;  //가치값이 0이라면 break;
		}

		else if (k >= coins[i])  //현재 동전의 값이 가치값을 넘지 않는다면
		{
			k -= coins[i];  //가치값 갱신
			cnt++;

			i--;  
			//i값이 넘어가지 않게(같은 금액을 여러번 계산할 수 있게) --실행
			//위의 ++와 겹쳐져 i값이 고정되고 예제1기준 4200에서 1000을 계속 빼며 계산할 수 있다. 
		}
	}
	*/

	cout << cnt;


	return 0;
}