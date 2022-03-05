#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//마실수 있는 경우에 대하여 DP사용, 최댓값 갱신
//table이 와인의 배열, wine이 DP라고 했을 때
//i번째 까지의 와인에서 선택할때 가장 많이 마실 수 있는 양 wine[i]는
// 1. i번째를 마시지 않고 그 이전까지의 마신 양(3연속 불가때문에 가능)
// 2. i번째를 마시고 i-1번째를 안마시고, i-2번째까지의 마신 양
// 3. i번째와 i-1번째를 마시고 i-3번째까지의 마신양 
//이렇게 3개중 max값이 된다.


int table[10001] = { 0, };  //포도주 잔 배열 초기화
int wine[10001] = { 0, };  //사용할 DP 초기화

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> table[i];
	}

	wine[1] = table[1];
	wine[2] = wine[1] + table[2];  //기저조건 초기화


	for (int i = 3; i <= n; ++i)
	{
		wine[i] = max(wine[i - 1], max(table[i] + wine[i - 2], table[i] + table[i - 1] + wine[i - 3]));
		//위에서 구한 점화식을 사용해 DP저장
		//순서대로 1번의 경우, 2번의 경우, 3번의 경우 이다.
	}


	cout << wine[n];  //답 출력


	return 0;
}