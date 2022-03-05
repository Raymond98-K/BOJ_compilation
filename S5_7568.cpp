#include <iostream>
#include <vector>
using namespace std;

//N�� �ִ� 50�����̹Ƿ� ��������� �ϰ� �׳� �ݺ����� ����

int S5_7568(void)
{
	vector<pair<int, int>> table;

	int n;
	cin >> n;

	//N�� ��ŭ �Է¹޾� pair�� ���� �� ���Ϳ� �ֱ�
	for (int i = 0; i < n; ++i)
	{
		int weight, tall;
		cin >> weight >> tall;

		pair<int, int> people(weight, tall);

		table.push_back(people);
	}

	vector<int> level(n, 1);//�⺻���� 1�� n��ŭ�� ��� ����


	//�����Կ� Ű�� ��� �ٸ� ������ ���� �۴ٸ� ����� ++
	for (int i = 0; i < n; ++i)
	{
		int targetWeight = table[i].first;
		int targetTall = table[i].second;

		for (int j = 0; j < n; ++j)
		{
			//�ڱ� �ڽŰ� ���� ��� �ǹ̰� �����Ƿ� continue
			if (i == j)
			{
				continue;
			}
			int otherWeight = table[j].first;
			int otherTall = table[j].second;

			
			//�����Կ� Ű �Ѵ� ��
			if (targetWeight < otherWeight && targetTall < otherTall)
			{
				level[i]++;  //�ش� target�� ����� ����(����� 1�� ������� ��ġ�� ũ��)
			}
		}
	}


	//���������� ��� ����� ����� ���
	for (int i = 0; i < level.size(); ++i)
	{
		cout << level[i] << " ";
	}




	return 0;
}