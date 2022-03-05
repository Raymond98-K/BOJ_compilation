#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 일단 입력을 받고 벡터를 복사해 sort()로 오름차순 정렬, unique와 erase를 사용해 정리한다.
// 이후 lower_bound()를 통해 인덱스를 출력한다.

int S2_18870(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<int> table;  //벡터 선언

	int intN;
	cin >> intN;

	for (int i = 0; i < intN; ++i)
	{
		int num;
		cin >> num;

		table.push_back(num);  //벡터 입력
	}

	vector<int> afterTable(table);  //두번째 벡터에 복사

	sort(afterTable.begin(), afterTable.end());  //일단 오름차순 정렬을 통해 벡터를 정렬하고

	afterTable.erase(unique(afterTable.begin(), afterTable.end()), afterTable.end());  //중복된 값을 erase와 unique를 통해 제거해준다.



	for (int i = 0; i < intN; ++i)
	{
		cout << lower_bound(afterTable.begin(), afterTable.end(), table[i]) - afterTable.begin() << " ";
	}
	//lower_bound(시작, 끝, 기준값) => 범위내에서 기준값보다 같거나 큰 숫자가 처음 나오는 인덱스의 주소를 반환
	//오름차순 정렬이기 때문에 해당 수의 인덱스 = 자기보다 낮은 수의 갯수 이다.
	//주소값이 반환되기 때문에 벡터의 시작 주소를 빼주어 정확한 인덱스를 찾아 출력하면 된다.
	


	return 0;
}