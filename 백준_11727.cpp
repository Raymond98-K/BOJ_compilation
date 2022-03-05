//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void)
//{
//	vector<int> dp(1002);
//	int num;
//	cin >> num;
//
//	dp[0] = 1;
//	dp[1] = 1;
//
//	for (int i = 2; i <= num; ++i)
//	{
//		dp[i] = (dp[i - 1] + (dp[i - 2] * 2)) % 10007;
//	}
//
//	cout << dp[num];
//
//	return 0;
//}