#include <iostream>
#include <algorithm>
using namespace std;

int table_2751[1000000];

//B1_2750�� �����ϴ�... 
//���߿� �ٸ� ����� ������ ����Ͽ� Ǯ���

int S5_2751(void)
{
	//�ð� ���Ҹ� ���� ��ũ�� Ǯ���ֱ�
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int intN;
	cin >> intN;


	//���Ϳ� �� ����ֱ�
	for (int i = 0; i < intN; ++i)
	{
		cin >> table_2751[i];
	}

	sort(table_2751, table_2751 + intN);  //�������� ����

	for (int i = 0; i < intN; ++i)
	{
		cout << table_2751[i] << "\n";  //endl��� \n�Է�(�ð� ������)
	}

	return 0;
}