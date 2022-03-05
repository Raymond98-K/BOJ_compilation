/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main(void)
{
	int target;
	cin >> target;

	vector<int> result;

	for (int i = 1; i < 224; ++i)
	{
		if (i * i == target)
		{
			result.push_back(1);
			break;
		}

		for (int j = i; j < 224; ++j)
		{
			if (i * i + j * j == target)
			{
				result.push_back(2);
				break;
			}

			for (int k = j; k < 224; ++k)
			{
				if (i * i + j * j + k * k == target)
				{
					result.push_back(3);
					break;
				}

				for (int l = k; l < 224; ++l)
				{
					if (i * i + j * j + k * k + l * l == target)
					{
						result.push_back(4);
						break;
					}
				}
				
			}
			
		}
		
		
	}
	sort(result.begin(), result.end());
	cout << result[0];

	return 0;
}
*/



/*
DP = Dynamic Programming = ���� ��ȹ��

����-����(ū ������ ���� ����� ������ �ذ��� �ٽ� ����)���� �ַ� ����
�̷��� �������� ������ ������ ���߿� �ٽ� Ǭ�ٴ� ������ �ִ�.
������� �Ǻ���ġ �������� 
[5]=[4]+[3]�̴�.
�̶� [4] = [3]+[2]�̹Ƿ� ���� [5]�� ���Ҷ� [3]�� �ѹ� ���ϰ� �� [4]�� ���Ҷ��� �ѹ� �� ���ϰ� �ȴ�.
�ð����⵵�� 2^N���� ���� ����.

�׷� ����� ���� �غ��߽��ϴ�. 500rpm DP��!!
�ϳ��� ������ <<�� �ѹ�>>�� Ǯ���� ��ȹ�Ѵ�. �ｼ ��� �迭���� ���� ����� ������ �ΰ� ���߿� �� �� ������
Ǯ��� �ϴ� ��Ȳ�� ���� �迭���� �������� ������ ���ð��� 0 �� �ǰ� �̷��� �ð����⵵�� ���� N�� �ȴ�.
�ٽ� �Ǻ���ġ ��������
[1] = 1
[2] = 1 <--����Ǿ� ����
[3] = [2]+[1] = 1+1 = 2 <--����!!
[4] = [3]+[2] = �̹� ����� ����� 2�� 1�� ������ ��� = 3
[5] = [4]+[3] = �̹� ����� 3�� 2�� ������ ��� = 5
���� ���� �ٸ��� [5]���� 3�� �ι� ��������� �ʰ� �ξ� ������!!
+��ȭ���� �������� �����ϴ�!!! �� ��� nx = nx-1 + nx-2
*/

/*
int save[100];
int DP(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 1;

	if (save[x] != 0) return save[x];
	return save[x] = DP(x - 1) + DP(x - 2);
}

or

int DP(int x)
{
	save[0] = 0; 
	save[1] = 1;
	save[2] = 1;
	for (int i = 2; i <= x; ++i)
	{
		save[i] = save[i - 1] + save[i - 2];
	}

	return save[x];
}

*/

/*
//DP�� Ǯ���
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> DP(50001);
	int target;
	cin >> target;

	for (int i = 1; i <= target; ++i)
	{
		DP[i] = i;  //���� 1^2�� �� ���� �ʱ�ȭ
		
		for (int j = 2; j * j <= i; ++j)
		{
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}

	cout << DP[target];

	return 0;
}

//�׳� �밡�� -> 76ms
//DP -> 16ms ������� �� 20%�� ����.(�տ������� -80%)
*/