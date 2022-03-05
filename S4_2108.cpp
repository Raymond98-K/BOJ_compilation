#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//������� �켱 �������� ����( sort() )�� �� ��
//�������� �׳� ���
//�߾Ӱ��� ������ �߾Ӱ�
//�ֺ��� �������
//������ �׳� ���

int S4_2108(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> table;  //�Է¹��� ������ ������ ����
	vector<int> tableMode(8001);  //�ֺ� ���� ����
	double arithmetic = 0;  //������ �ʱ�ȭ. ������ ����� double�� ����

	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)
	{
		int num;
		cin >> num;

		tableMode[4000 + num]++;  //4000�� �������� ����
		
		table.push_back(num);  //��ü �� ���Ϳ� push back

		arithmetic += num;  //������ ���
	}

	cout << round(arithmetic/intN) << "\n";  //������ ������� �� ���

	sort(table.begin(), table.end());  //�������� ����

	cout << table[intN / 2] << "\n";  //�߾Ӱ� ��� �� ���


	int count = -1;  //�ֺ� ����Ƚ�� �ʱ�ȭ
	int mode = 8001;  //�ֺ� �ʱ�ȭ
	int isSecond = 2;  //�ι�° ������ �Ǵ��ϴ� ��� 2�� �ι�° ���̴�.

	for (int i = 0; i < 8001; ++i)
	{
		if (count < tableMode[i])
		{
			count = tableMode[i];  //����Ƚ�� ����
			mode = i - 4000;  //�ֺ� ����
			isSecond = 1;  //ù�����̹Ƿ� ����
		}

		else if (count == tableMode[i] && isSecond == 1)
		{
			mode = i - 4000;
			isSecond = 2;  //�ι�° �������� �˸��� ���̻��� ������ ����
		}
	}

	cout << mode << "\n";  //�ֺ� ���
	

	cout << table[intN - 1] - table[0];  //���� ��� �� ���




	return 0;
}