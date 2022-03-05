//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main(void)
//{
//	vector<int> row(1);  //가로  row{ 0, 10 }
//	vector<int> col(1);  //세로
//	vector<int> afterRow;
//	vector<int> afterCol;
//
//
//	int maxRow;  //최대 가로변
//	int maxCol;  //최대 세로변
//	cin >> maxRow >> maxCol;
//
//	int cut;
//	cin >> cut;
//
//	for (int i = 0; i < cut; ++i)
//	{
//		int isWhere;
//		int cutNum;
//		cin >> isWhere;
//		cin >> cutNum;
//
//		if (isWhere == 0)
//		{
//			col.push_back(cutNum);
//		}
//		else
//		{
//			row.push_back(cutNum);
//		}
//	}
//
//	col.push_back(maxCol);
//	row.push_back(maxRow);
//
//	sort(row.begin(), row.end());
//	sort(col.begin(), col.end());
//
//	for (int i = 0; i < col.size() - 1; ++i)
//	{
//		afterRow.push_back(col[i + 1] - col[i]);
//	}
//
//	for (int i = 0; i < row.size() - 1; ++i)
//	{
//		afterCol.push_back(row[i + 1] - row[i]);
//	}
//
//	sort(afterRow.begin(), afterRow.end());
//	sort(afterCol.begin(), afterCol.end());
//
//	cout << afterRow[afterRow.size() - 1] * afterCol[afterCol.size() - 1];
//
//}