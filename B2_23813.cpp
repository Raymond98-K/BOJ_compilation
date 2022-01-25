#include <iostream>
#include <cmath>
using namespace std;

int B2_23813(void)
{
	long sum = 0;

	long number;
	cin >> number;

	long temp = number;
	long first = number;

	long sizeTemp = 0;
	while (temp != 0)
	{
		temp = temp / 10;

		sizeTemp++;
	}

	long size = pow(10, sizeTemp - 1);
	

	do
	{
		sum += number;
		number = (number % 10) * size + (number / 10);

	} while (first != number);
	cout << sum;

	return 0;
}








/*
#include <iostream>
#include <cmath>
using namespace std;

int B2_23813(void)
{
	long a = 0, b1 = 0, b2 = 0, sum = 0, count = 0, x = 0;

	cin >> a;
	b1 = a;
	while (a != 0) {
		a = a / 10;
		count++;
	}// 자리수 구함
	x = pow(10, count - 1);//자리수 저장

	b2 = (b1 % x) * 10 + (b1 / x);// 첫 회전
	sum = b2;
	while (b1 != b2) {
		b2 = (b2 % x) * 10 + (b2 / x);
		sum = sum + b2;
	}
	cout << sum;
}
*/