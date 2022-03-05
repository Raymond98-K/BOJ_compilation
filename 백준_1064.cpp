//#include <iostream>
//#include <cmath>
//using namespace std;
//
//void search(double ff, double ss);
//
//double maxl = 0;  //
//double minl = 1000000000000000000;  //10^18
//double temp = 0;
//
//int main(void)
//{
//	int xA, yA, xB, yB, xC, yC;
//	cin >> xA >> yA >> xB >> yB >> xC >> yC;
//
//	double AB, BC, CA;
//
//	//각 실선의 길이
//	AB = sqrt(pow(xA - xB, 2) + pow(yA - yB, 2));
//	BC = sqrt(pow(xB - xC, 2) + pow(yB - yC, 2));
//	CA = sqrt(pow(xC - xA, 2) + pow(yC - yA, 2));
//
//	double sAB, sAC;
//	double sABx, sABy, sACx, sACy;
//
//	if (xA < xB)
//	{
//		sABx = xB - xA;
//	}
//	else
//	{
//		sABx = xA - xB;
//	}
//
//	if (yA < yB)
//	{
//		sABy = yB - yA;
//	}
//	else
//	{
//		sABy = yA - yB;
//	}
//
//	sAB = sABy / sABx;
//	//AB의 x증가량, y증가량을 토대로 기울기 구하기
//
//
//	if (xA < xC)
//	{
//		sACx = xC - xA;
//	}
//	else
//	{
//		sACx = xA - xC;
//	}
//
//	if (yA < yC)
//	{
//		sACy = yC - yA;
//	}
//	else
//	{
//		sACy = yA - yC;
//	}
//
//	sAC = sACy / sACx;
//	//AC도 동일하게 기울기 구하기
//
//
//	if (sAB == sAC)  //만약 두 선의 기울기가 같으면 -1 출력
//	{
//		cout << -1;
//	}
//
//	else  //만들어 질 수 있다면
//	{
//		search(AB, CA);
//		search(AB, BC);
//		search(BC, CA);
//		//세번 호출해서 전역변수 바꿈
//
//		cout << fixed;
//		cout.precision(16);  //소수점 아래 16자리로 출력 고정
//		cout << maxl - minl;
//	}
//	
//
//	return 0;
//}
//
//void search(double ff, double ss)
//{
//	temp = 2 * (ff + ss);  //둘레 구하기
//
//	if (maxl <= temp)  //최댓값 갱신
//	{
//		maxl = temp;
//	}
//
//	if (minl > temp)  //최솟값 갱신
//	{
//		minl = temp;
//	}
//
//}