#include <iostream>
#include <vector>
using namespace std;

//�׳� ���ٺ��� ��Ģ�� ���Դ�. �Ǻ���ġ�� �����ϰ� DP[N} = DP[N-2] + DP[N-1]
//DP[N-2]��°�� ���鿡�� �ڿ� 00�� ���̴� ��� + DP[N-1]��°�� ��쿡�� �տ� 1�� ���̴� ���
//���� ��Ĵ�� �ϸ� �ߺ��Ǵ� �͵� ���� ����ϰ� ���´�.

#define MAX_NUM 1000001
#define MOD 15746
vector<int> table(MAX_NUM);  //����� DP����

//int search(int cnt);  //����� �Լ� ���� - �Լ����� �޸� 21432KB �ð�24ms
//�ݺ��� ���� �޸� 5928KB �ð� 8ms�� �ݺ����� �ξ� ������. ���� ��ʹ� ���̴�...

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	table[1] = 1;
	table[2] = 2;  //���� ���� ����

	int n;
	cin >> n;

	/*
	int answer;
	answer = search(n);  //�Լ� ȣ��

	cout << answer;  //���� ���
	*/

	for (int i = 3; i <= n; ++i)  //�׳� �ݺ������� DP ä���
	{
		table[i] = (table[i - 2] + table[i - 1]) % MOD;
	}

	cout << table[n];


	return 0;
}

/*
int search(int cnt)
{
	if (table[cnt] != 0)  //���� DP�� ����� ���� �ִٸ�
	{
		return table[cnt];  //�ش� ���� ���� ����Ѵ�.
	}

	else  //�׷��� �ʰ� ����� ���� ���ٸ�
	{
		table[cnt] = (search(cnt - 2) + search(cnt - 1)) % MOD;  //��ȭ�Ŀ� �°� ����Ѵ�.
		return table[cnt];
	}
}
*/
