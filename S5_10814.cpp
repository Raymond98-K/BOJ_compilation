#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//�̰� ����ü�� �ǳ�??  -> �ǳ�...
//������� ����, �̸�, ������ �����ϴ� ����ü ���� �� ���Ϳ� push back
//sort()�� compare �Լ��� ���ǿ� �°� ���� �� ���


struct members  //������� ���̿� �̸�, ������ ������ ����ü ����
{
	int age;
	string name;
	int cnt;
};


bool compare(members first, members second);  //sort()�� ���� compare�Լ� ����

int S5_10814_1(void)
{
	vector<members> table;
	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)  //����ü�� ���� ���� �� ���Ϳ� push back
	{
		members people;
		cin >> people.age >> people.name;
		people.cnt = i;
		
		table.push_back(people);
	}

	sort(table.begin(), table.end(), compare);  //�䱸 ���ǿ� �°� ����

	for (int i = 0; i < intN; ++i)
	{
		cout << table[i].age << " " << table[i].name << "\n";  //���
	}

	return 0;
}

bool compare(members first, members second)
{
	if (first.age == second.age)  //���� �� ȸ���� ���̰� ���ٸ�
	{
		return first.cnt < second.cnt;  //���� ������ �� �������� �켱��
	}

	else
	{
		return first.age < second.age;  //���̰� �ٸ��ٸ� �� ����� �켱��
	}
}




bool cmp(pair<int, string> fst, pair<int, string> snd)
{
	return fst.first < snd.first;
}



//stable sort ����ϱ�
int S5_10814_2(void)
{
	vector<pair<int, string>> table;  //������ ���������� ����� ���̹Ƿ� �������� �ʾƵ� �ȴ�.
	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)
	{
		pair<int, string> members;
		cin >> members.first >> members.second;  //����ϰ� pair�� ���� �Է¹ް� ���Ϳ� push back

		table.push_back(members);
	}

	stable_sort(table.begin(), table.end(), cmp);
	//���� ����
	// 5 2 1 4(1) 7 4(2) 8 �϶� 4�� �ι��̴�. ������� 4(1) 4(2)�϶� �̰� �������� ���� ��
	// 1 2 4(1) 4(2) 5 7 8 �� ���� �Ǵ� ���� ���� �����̶� �Ѵ�.
	//�� �ߺ��� ������ ������ �����ϸ� ���� ����, �׷��� ������ �Ҿ��� �����̴�.
	//�� �������� �������Ľ� ������ ��������� ������ �����ȴ�.

	for (int i = 0; i < intN; ++i)
	{
		cout << table[i].first << " " << table[i].second << "\n";  //���
	}


	return 0;
}