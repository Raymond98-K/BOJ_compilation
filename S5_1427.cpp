#include <iostream>
using namespace std;

//�׳� string���� �����ϸ� �ȴ�.  //char'1' < char'2' �� �����ϱ� ����

int S5_1427(void)
{
	string stringN;
	cin >> stringN;

	for (int i = 0; i < stringN.length() - 1; ++i)  //���ڿ� ���̸�ŭ �ݺ�
	{
		char tmp;  //�ӽ� ���� ����

		for (int j = i + 1; j < stringN.length(); ++j)  //i���� �� ĭ ����������
		{
			if (stringN[i] < stringN[j])  //���� ���簪�� ���������� �۴ٸ�
			{
				tmp = stringN[i];
				stringN[i] = stringN[j];
				stringN[j] = tmp;  //�� ���� ��ġ ��ȯ
			}
		}
	}

	cout << stringN;  //���� ���

	return 0;
}