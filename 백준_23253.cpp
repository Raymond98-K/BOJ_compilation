//#include <iostream>
//#include <vector>
//#include <cstdio>
//using namespace std;
//
//
//int main(void)
//{
//	vector<vector<int>> total;
//
//
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 0; i < m; ++i)
//	{
//		vector<int> books;
//
//		int num;
//		cin >> num;
//
//		for (int j = 0; j < num; ++j)
//		{
//			int bNum;
//			scanf("%d", &bNum);
//			books.push_back(bNum);
//		}
//
//		total.push_back(books);
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < total[i].size() - 1; ++j)
//		{
//			if (total[i][j] > total[i][j + 1])
//			{
//				continue;
//			}
//
//			else
//			{
//				cout << "No";
//
//				return 0;
//			}
//		}
//	}
//
//	cout << "Yes";
//
//	return 0;
//
//
//
//	return 0;
//}
//
//
