//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(NULL);
//	
//	//�� �ڵ� �����ϱ� 512ms -> 140ms�� ������ ����
//	//��� �޸𸮴� 6036kb�� ��¦ ����
//		
//
//	stack<pair<int, int>> total;
//	int finalScore = 0;
//
//	int minT;
//	cin >> minT;
//
//	for (int i = 0; i < minT; ++i)
//	{
//		int isProject;
//		cin >> isProject;
//
//		if (isProject)
//		{
//			int score, time;
//			cin >> score >> time;
//			
//			pair<int, int> project (score, time);
//			total.push(project);
//		}
//
//		if (!total.empty())
//		{
//			total.top().second--;
//			
//			if (!total.top().second)
//			{
//				finalScore += total.top().first;
//
//				total.pop();
//			}
//		}
//
//
//	}
//
//	cout << finalScore;
//
//	return 0;
//}
////���� �ڵ�� �޸� 28352kb�� 580ms
////�� �ڵ�� �޸� 5920kb�� 512ms
//
//
////
////int main(void)
////{
////	stack<vector<int>> total;
////	vector<int> project(3, 1);
////	int finalScore = 0;
////
////	int minT;
////	cin >> minT;
////
////	for (int i = 0; i < minT; ++i)
////	{
////	
////		int isP;
////		cin >> isP;
////
////		if (isP == 1)
////		{
////			int score, time;
////			cin >> score >> time;
////
////			project[1] = score;
////			project[2] = time - 1;
////
////			if (project[2] == 0)
////			{
////				finalScore += project[1];
////				continue;
////			}
////
////			else 
////			{
////				total.push(project);
////			}
////		}
////
////		else if (isP == 0 && total.empty())
////		{
////			project[0] = 0;
////			project[1] = 0;
////			project[2] = 1;
////
////			total.push(project);
////		}
////
////		else
////		{
////			total.top()[2]--;
////
////			if (total.top()[2] == 0)
////			{
////				finalScore += total.top()[1];
////
////				total.pop();
////			}
////		}
////
////		project[0] = 1;
////		project[1] = 1;
////		project[2] = 1;
////
////	}
////
////
////	cout << finalScore;
////
////	return 0;
////}