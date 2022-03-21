#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//DP ���̺��� �ε����� �ش� ������ �ε���, ���� �κм����� ����
// � ���� ���ؼ� �� �������� �κм����� �ִ� ���̴� �� �� ������ ���� �� �� ������ ���� ���� ������ �κм��� ������ �ִ�+1��
// �׷� �� ������ ��� ���� �� üũ�ؾ� �ϴϱ� max()�� ���� �ݺ��� ���
//DP[N] = max(DP[N], DP[N-1] + 1)

vector <int> table(1001, 0); //�迭 ����
vector <int> dp(1001, 1);  //����� DP ����, �ʱⰪ�� 1(�κ� ������ �ּ� ����)

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> table[i];  //�迭 �Է�
    }

    int answer = 0;  //����� ���� �ʱ�ȭ

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i - 1; ++j)  //���� ���� ���� ���鿡 ���ؼ� �ݺ�
        {
            if (table[i] > table[j])  //���簪�� ���� ������ �۴ٸ�
            {
                dp[i] = max(dp[i], dp[j] + 1);  //��ȭ�Ŀ� �°� ���
            }
        }

        answer = max(answer, dp[i]);  //���� �� ������ ���� ����
    }

    cout << answer;  //���� ���

    return 0;
}