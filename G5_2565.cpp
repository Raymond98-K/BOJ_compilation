#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//�Է����� ���� pair()���� (A,B)��� �Ҷ� A�������� ���� �� �� ���¿���
//B���� ���� �� ���������� ����� ��츦 ã���� �ȴ�.
//A�������� sort()�� DP�� �̿��� ���� �� ������ ���̸� ã�� ��ü���̿��� - �� ����� �������
//DP[n] == ù��° ���� �ش� ��ȣ���� ����� �� �� �ִ� ���� �� �������� ������ ����
//DP[N] = MAX(DP[N-1], max_length+1);

bool compare(pair<int, int> line_connect_first, pair<int, int> line_connect_second);  //sort�� ����� compare �Լ�

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;  //��ü ������ ���� �Է�

    vector<pair<int, int>> table(n + 1, make_pair(0, 0));  //������ ���¸� ������ �迭 ����

    for (int i = 1; i <= n; ++i)
    {
        int first, second;
        cin >> first >> second;

        table[i] = make_pair(first, second);  //�迭�� ����
    }

    sort(table.begin(), table.end(), compare);  //first�� �������� �������� ����

    //�ִ� �������� ���̸� ������ DP���� (A,B)���� A�� ����, B�� �ش� ������ ������ �ִ�
    vector<pair<int, int>> length_dp(n + 1, make_pair(1, 0));  
    length_dp[1].first = 1;
    length_dp[1].second = table[1].second;  //���� ����
    int max_length = 0;  //���� �������� ������ �ִ� ����


    for (int i = 2; i <= n; ++i)
    {
        //�������� ���� ������ ���̴� �ڱ��ڽ� == 1 �̸� ���� ū �� ���� �ڱ� �ڽ��̹Ƿ�
        length_dp[i].second = table[i].second;

        for (int j = 1; j < i; ++j)
        {
            if (table[i].second > length_dp[j].second)  //���� ���� ���� ������ �ִ񰪺��� ũ�ٸ�
            {
                length_dp[i].first = max(length_dp[i].first, length_dp[j].first + 1);  //���� ����
                length_dp[i].second = table[i].second;  //�ִ� ����
            }

            max_length = max(max_length, length_dp[i].first);
        }
    }

    cout << n - max_length;

    return 0;
}

bool compare(pair<int, int> line_connect_first, pair<int, int> line_connect_second)  //pair(A,B)���� A�� �������� �������� ���Ŀ� compare�Լ�
{
    return line_connect_first.first < line_connect_second.first;
}