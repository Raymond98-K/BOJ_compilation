#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �ϴ� �Է��� �ް� ���͸� ������ sort()�� �������� ����, unique�� erase�� ����� �����Ѵ�.
// ���� lower_bound()�� ���� �ε����� ����Ѵ�.

int S2_18870(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<int> table;  //���� ����

	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)
	{
		int num;
		cin >> num;

		table.push_back(num);  //���� �Է�
	}

	vector<int> afterTable(table);  //�ι�° ���Ϳ� ����

	sort(afterTable.begin(), afterTable.end());  //�ϴ� �������� ������ ���� ���͸� �����ϰ�

	afterTable.erase(unique(afterTable.begin(), afterTable.end()), afterTable.end());  //�ߺ��� ���� erase�� unique�� ���� �������ش�.



	for (int i = 0; i < intN; ++i)
	{
		cout << lower_bound(afterTable.begin(), afterTable.end(), table[i]) - afterTable.begin() << " ";
	}
	//lower_bound(����, ��, ���ذ�) => ���������� ���ذ����� ���ų� ū ���ڰ� ó�� ������ �ε����� �ּҸ� ��ȯ
	//�������� �����̱� ������ �ش� ���� �ε��� = �ڱ⺸�� ���� ���� ���� �̴�.
	//�ּҰ��� ��ȯ�Ǳ� ������ ������ ���� �ּҸ� ���־� ��Ȯ�� �ε����� ã�� ����ϸ� �ȴ�.
	


	return 0;
}