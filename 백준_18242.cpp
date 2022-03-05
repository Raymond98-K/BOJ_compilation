//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void)
//{
//	vector<string> matrix;
//	vector<int> line;  //[0]=UP, 1=DOWN 2=LEFT 3=RIGHT
//	
//	int maxCol;//세로 (여기, 0)
//	int maxRow;//가로 (0, 여기)
//	cin >> maxCol >> maxRow;
//
//	/*string str;
//	vector<string> s;
//	cin >> str;
//	s.push_back(str);
//	cout << char(s[0][0]);*/
//	
//
//	for (int i = 0; i < maxCol; ++i)
//	{
//		string ss;
//		cin >> ss;
//		
//		matrix.push_back(ss);
//	}
//
//	//가로 탐색
//	int isBlankUD = 0;
//
//	for (int i = 0; i < maxCol; ++i)
//	{
//		
//		isBlankUD = 0;
//
//		for (int j = 0; j < maxRow; ++j)
//		{
//			if (char(matrix[i][j]) == '#')
//			{
//				isBlankUD++;
//			}
//		}
//
//		if (isBlankUD > 3)
//		{
//			line.push_back(isBlankUD);
//		}
//	}
//
//	//세로 탐색
//	int isBlankLR = 0;
//
//	for (int i = 0; i < maxRow; ++i)
//	{
//		isBlankLR = 0;
//
//		for (int j = 0; j < maxCol; ++j)
//		{
//			if (char(matrix[j][i]) == '#')
//			{
//				isBlankLR++;
//			}
//		}
//
//		if (isBlankLR > 3)
//		{
//			line.push_back(isBlankLR);
//		}
//	}
//
//	if (line[0] % 2 == 0)
//	{
//		cout << "UP";
//	}
//
//	if (line[1] % 2 == 0)
//	{
//		cout << "DOWN";
//	}
//
//	if (line[2] % 2 == 0)
//	{
//		cout << "LEFT";
//	}
//
//	if (line[3] % 2 == 0)
//	{
//		cout << "RIGHT";
//	}
//
//	return 0;
//}