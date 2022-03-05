//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main(void)
//{
//	vector<vector<int>> matrix;
//
//	vector<int> minRed(1001);  //첫번째 선택이 R일 경우
//	vector<int> minGreen(1001);  //G일 경우
//	vector<int> minBlue(1001);  //B일 경우
//
//	int totalHouse;
//	cin >> totalHouse;
//
//	int cnt = 0;
//
//	for (int i = 0; i < totalHouse; ++i)
//	{
//		vector<int> rgb;
//
//		for (int j = 0; j < 3; ++j)
//		{
//			int a;
//			scanf("%d", &a);
//
//			rgb.push_back(a);
//		}
//		matrix.push_back(rgb);
//	}
//
//
//	//matrix[0][0]=R, [0][1]=G, [0][2]=B
//	minRed[0] = matrix[0][0];
//	minGreen[0] = matrix[0][1];
//	minBlue[0] = matrix[0][2];
//
//	for (int i = 1; i < matrix.size(); ++i)
//	{
//		minRed[i] = matrix[i][0] + min(minBlue[i - 1], minGreen[i - 1]);
//
//		minGreen[i] = matrix[i][1] + min(minRed[i - 1], minBlue[i - 1]);
//
//		minBlue[i] = matrix[i][2] + min(minRed[i - 1], minGreen[i - 1]);
//
//	}
//
//
//	cout << min(minRed[totalHouse-1], min(minGreen[totalHouse-1], minBlue[totalHouse-1]));
//
//	
//
//
//	return 0;
//}