#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//DP 테이블에서 인덱스는 해당 숫자의 인덱스, 값은 부분수열의 길이
// 어떤 수에 대해서 그 수까지의 부분수열중 최대 길이는 그 수 이전의 수들 중 그 수보다 작은 수가 가지는 부분수열 길이중 최댓값+1임
// 그럼 그 수까지 모든 수를 다 체크해야 하니까 max()에 이중 반복문 사용
//DP[N] = max(DP[N], DP[N-1] + 1)

vector <int> table(1001, 0); //배열 선언
vector <int> dp(1001, 1);  //사용할 DP 선언, 초기값은 1(부분 수열의 최소 길이)

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> table[i];  //배열 입력
    }

    int answer = 0;  //출력할 정답 초기화

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i - 1; ++j)  //현재 값의 이전 값들에 대해서 반복
        {
            if (table[i] > table[j])  //현재값이 이전 값보다 작다면
            {
                dp[i] = max(dp[i], dp[j] + 1);  //점화식에 맞게 계산
            }
        }

        answer = max(answer, dp[i]);  //가장 긴 수열의 길이 갱신
    }

    cout << answer;  //정답 출력

    return 0;
}