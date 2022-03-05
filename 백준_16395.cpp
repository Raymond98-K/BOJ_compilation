//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void)
//{
//	int n, k;   //몇행, 몇번째
//	cin >> n >> k;
//
//	vector<vector<int>> pascalT;
//	vector<int> line(31);
//
//	line[0] = 0;
//	pascalT.push_back(line);
//
//	line[0] = 0;
//	line[1] = 1;
//	pascalT.push_back(line);
//
//	line[1] = 0;
//
//	for (int i = 2; i <= n; ++i)
//	{
//		for (int j = 1; j <= i; ++j)
//		{
//			line[j] = pascalT[i - 1][j - 1] + pascalT[i - 1][j];
//		}
//
//		pascalT.push_back(line);
//	}
//
//	cout << pascalT[n][k];
//
//	return 0;
//}