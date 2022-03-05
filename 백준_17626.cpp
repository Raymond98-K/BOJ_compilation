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
DP = Dynamic Programming = 동적 계획법

분할-정복(큰 문제를 작은 덩어리로 나누어 해결후 다시 취합)에서 주로 사용됨
이러한 문제들은 동일한 문제를 나중에 다시 푼다는 단점이 있다.
예를들어 피보나치 수열에서 
[5]=[4]+[3]이다.
이때 [4] = [3]+[2]이므로 위의 [5]를 구할때 [3]을 한번 구하고 또 [4]를 구할때도 한번 더 구하게 된다.
시간복잡도가 2^N으로 답이 없다.

그런 당신을 위해 준비했습니다. 500rpm DP법!!
하나의 문제를 <<단 한번>>만 풀도록 기획한다. 즉슨 어디 배열같은 곳에 결과를 저장해 두고 나중에 또 그 문제를
풀어야 하는 상황이 오면 배열에서 가져오기 때문에 계산시간이 0 이 되고 이러면 시간복잡도가 무려 N이 된다.
다시 피보나치 수열에서
[1] = 1
[2] = 1 <--저장되어 있음
[3] = [2]+[1] = 1+1 = 2 <--저장!!
[4] = [3]+[2] = 이미 저장된 결과값 2와 1을 가져와 계산 = 3
[5] = [4]+[3] = 이미 저장된 3과 2를 가져와 계산 = 5
위의 경우와 다르게 [5]에서 3을 두번 계산하지도 않고 훨씬 가볍다!!
+점화식이 구해져야 가능하다!!! 이 경우 nx = nx-1 + nx-2
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
//DP로 풀어보기
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
		DP[i] = i;  //전부 1^2로 한 경우로 초기화
		
		for (int j = 2; j * j <= i; ++j)
		{
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}

	cout << DP[target];

	return 0;
}

//그냥 노가다 -> 76ms
//DP -> 16ms 기존대비 약 20%로 감소.(합연산으로 -80%)
*/