#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
int main(void)
{
	vector<int> tall;  //�迭
	int sum = 0;

	for (int i = 0; i < 9; ++i)
	{
		int num;
		cin >> num;

		tall.push_back(num);
		sum += num;	
	}

	int cnt = 0;  //���� ���� 
	for (int i = 0; i < 8; ++i)
	{
		for (int j = i+1; j < 9; ++j)
		{
			if (sum - (tall[i] + tall[j]) == 100 && cnt == 0)
			{
				tall[i] = 0;
				tall[j] = 0;
			
				cnt++;  //�ƴ� ��¥ �̰� �������???
			}
		}
	}

	sort(tall.begin(), tall.end());



	for (int i = 2; i < tall.size(); ++i)
	{
		cout << tall[i] << endl;
	}


	return 0;
}
*/

// ó������ ���������ΰ� �Ⱥ��� Ǯ�ٰ� Ʋ�Ȱ�
// �� ���� ���ʺе��� ���� �� cnt���Ŷ����� ���Ƹ���
// �ƴ� �������� 0�� �Ǵ� ���� �������� ���߳� ��¥....