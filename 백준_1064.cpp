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
//	//�� �Ǽ��� ����
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
//	//AB�� x������, y�������� ���� ���� ���ϱ�
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
//	//AC�� �����ϰ� ���� ���ϱ�
//
//
//	if (sAB == sAC)  //���� �� ���� ���Ⱑ ������ -1 ���
//	{
//		cout << -1;
//	}
//
//	else  //����� �� �� �ִٸ�
//	{
//		search(AB, CA);
//		search(AB, BC);
//		search(BC, CA);
//		//���� ȣ���ؼ� �������� �ٲ�
//
//		cout << fixed;
//		cout.precision(16);  //�Ҽ��� �Ʒ� 16�ڸ��� ��� ����
//		cout << maxl - minl;
//	}
//	
//
//	return 0;
//}
//
//void search(double ff, double ss)
//{
//	temp = 2 * (ff + ss);  //�ѷ� ���ϱ�
//
//	if (maxl <= temp)  //�ִ� ����
//	{
//		maxl = temp;
//	}
//
//	if (minl > temp)  //�ּڰ� ����
//	{
//		minl = temp;
//	}
//
//}