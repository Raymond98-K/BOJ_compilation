#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//pair ���, �������� ������ ���� �ð��� �켱���� ���� �Ѵ�.
//���۽ð��� ���� ����ð��� ���� �Ķ�� �����ؼ� �ȵǱ� ������ ����ð� �������� �����ؾ��Ѵ�!!
//���Ϳ� ����� ������ �����ϰ� ���� ������ �ð��� ���� ���۽ð��� ��ġ�� �ʰ� cnt++

bool compare(pair<unsigned int, unsigned int> pair1, pair<unsigned int, unsigned int> pair2);  //sort����� ���� compare �Լ�

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<unsigned int, unsigned int>> time_table(n);

	for (int i = 0; i < n; ++i)
	{
		pair<unsigned int, unsigned int> schedule;

		cin >> schedule.first >> schedule.second;

		time_table[i] = schedule;  //��� �ð�ǥ�� ���Ϳ� ����
	}


	sort(time_table.begin(), time_table.end(), compare);  //first�� second���� ���� ���ĵǵ��� ����

	int cnt = 1;  //��µ� ȸ���� ���� �ʱ�ȭ. �̹� ù ȸ�Ǵ� ���� �ϴ� ���� Ȯ�� �̹Ƿ� �ʱ갪==1
	unsigned int end_time = time_table[0].second;  //���� ȸ�� ���� �ð� �ʱ�ȭ. �ʱ갪�� ù��° ȸ���� ����ð�

	for (int i = 1; i < n; ++i)  //������ ����!!
	{
		if (time_table[i].first >= end_time)  //���� ȸ���� ���� �ð��� ���� ȸ���� ����ð� �̻��� ���
		{
			end_time = time_table[i].second;  //���� ȸ���� ����ð� ���� ���� ȸ���� ����ð����� ����
			cnt++;  //Ƚ��++
		}
	}

	cout << cnt;  //���

	return 0;
}



bool compare(pair<unsigned int, unsigned int> pair1, pair<unsigned int, unsigned int> pair2)
{
	if (pair1.second == pair2.second)  //���� �� ȸ���� ���� �ð��� ���ٸ�
	{
		return pair1.first < pair2.first;  //���� �ð� ���� �������� ����
	}

	else
	{
		return pair1.second < pair2.second;  //���� �ð��� �ٸ��ٸ� ���� �ð� ���� �������� ����
	}
}