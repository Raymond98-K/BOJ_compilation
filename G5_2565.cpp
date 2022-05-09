#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//입력으로 들어온 pair()셋을 (A,B)라고 할때 A기준으로 정렬 후 그 상태에서
//B에서 가장 긴 오름차순을 만드는 경우를 찾으면 된다.
//A기준으로 sort()후 DP를 이용해 가장 긴 수열의 길이를 찾고 전체길이에서 - 해 결과를 출력하자
//DP[n] == 첫번째 부터 해당 번호까지 만들어 질 수 있는 가장 긴 오름차순 수열의 길이
//DP[N] = MAX(DP[N-1], max_length+1);

bool compare(pair<int, int> line_connect_first, pair<int, int> line_connect_second);  //sort시 사용할 compare 함수

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;  //전체 전깃줄 갯수 입력

    vector<pair<int, int>> table(n + 1, make_pair(0, 0));  //전깃줄 상태를 저장할 배열 선언

    for (int i = 1; i <= n; ++i)
    {
        int first, second;
        cin >> first >> second;

        table[i] = make_pair(first, second);  //배열에 저장
    }

    sort(table.begin(), table.end(), compare);  //first를 기준으로 오름차순 정렬

    //최대 오름차순 길이를 저장할 DP선언 (A,B)에서 A는 길이, B는 해당 길이의 수열의 최댓값
    vector<pair<int, int>> length_dp(n + 1, make_pair(1, 0));  
    length_dp[1].first = 1;
    length_dp[1].second = table[1].second;  //기저 조건
    int max_length = 0;  //현재 오름차순 수열의 최대 길이


    for (int i = 2; i <= n; ++i)
    {
        //판정이전 최초 수열의 길이는 자기자신 == 1 이며 가장 큰 값 또한 자기 자신이므로
        length_dp[i].second = table[i].second;

        for (int j = 1; j < i; ++j)
        {
            if (table[i].second > length_dp[j].second)  //현재 값이 이전 수열의 최댓값보다 크다면
            {
                length_dp[i].first = max(length_dp[i].first, length_dp[j].first + 1);  //길이 갱신
                length_dp[i].second = table[i].second;  //최댓값 갱신
            }

            max_length = max(max_length, length_dp[i].first);
        }
    }

    cout << n - max_length;

    return 0;
}

bool compare(pair<int, int> line_connect_first, pair<int, int> line_connect_second)  //pair(A,B)에서 A를 기준으로 오름차순 정렬용 compare함수
{
    return line_connect_first.first < line_connect_second.first;
}