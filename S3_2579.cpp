#include <iostream>
#include <algorithm>
using namespace std;
//어떤 계단 n에 대해서 그 계단을 밟았을때의 최댓값은 바로 이전 계단을 밟았을 경우 혹은 2칸 전의 계단을 밟았을 경우로 나눌 수 있다.
//그런데 마지막 계단은 무조건 밟아야 한다는 조건이 있다.
//그렇다면 마지막 계단기준으로 그 전칸을 밟지 않았다면 DP[N] = DP[N-2] + 마지막 계단 점수
//그 전칸을 밟았다면 DP[N] = DP[N-3] + 마지막 전 계단 점수 + 마지막 계단 점수가 된다.
//따라서 이 둘을 비교해 더 큰 값을(max함수 활용) DP로 저장하면 된다.
//추가) 배열을 DP하나만 사용할 경우 원래 저장된 각 계단의 점수가 덮어씌워져 사용할 수 없게 된다. 그냥 배열 두개 쓰자.

#define MAX_NUM 301

int table[MAX_NUM] = { 0, };  //사용할 DP 배열 선언
int stairs[MAX_NUM] = { 0, };  //입력받을 계단 점수 저장용 배열 선언

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int total_stairs;
	cin >> total_stairs;  //총 계단 갯수 입력

	for (int i = 1; i <= total_stairs; ++i)
	{
		cin >> stairs[i];  //각 계단의 점수 입력
	}

	table[1] = stairs[1];
	table[2] = stairs[1] + stairs[2];
	table[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);  //기저 조건 초기화
	//각각 첫번째, 두번째, 세번째 계단에 대해서 DP용 배열에 값을 저장했다.
	//첫번째는 그냥 첫번째 계단의 점수, 두번째는 첫번째와 두번째 계단을 모두 밟았을 때,
	//마지막으로 세번째는 (첫번째 + 세번째)의 경우와 (두번째 + 세번째)에 대해서 비교해 큰 값을 저장한다.
	
	for (int i = 4; i <= total_stairs; ++i)  //이후 4번째 계단에서 부터
	{
		//점화식에 맞게 값을 비교해 저장
		table[i] = max(table[i - 2] + stairs[i], table[i - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << table[total_stairs];  //최종 답 출력

	return 0;
}
